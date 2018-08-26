//
// Created by delbertbeta on 18-8-26.
//

#include "Emulator.h"

void Emulator::run(Process &process) {
    // Get addresses and write into file.
    const auto addresses = RandomAddressGenerator::generateAddress(process);
    stringstream s;
    process.newRound();
    s << "Round " <<  process.getRound() << ":" << endl;
    for (auto address : addresses) {
        s << "0x" << hex << setw(8) << setfill('0') << address << endl;
    }
    s << endl;
    FileOperation::writeFile("addr_seq_" + to_string(process.getId()) + ".txt", s);

    s.clear();
    s << "Round " << process.getRound() << ": " << endl;
    s << "Address\tVP Number\tPF Number\tTLB hit/no hit\tPT hit/no hit";

    // Clear TLB
    TLB::reset();

    auto pageTable = process.getPageTable();

    for (auto address : addresses) {
        p_size pageFrame;
        process.addPageAccess();
        auto tlbResult = TLB::search(address);
        if (tlbResult == nullptr) {
            auto ptResult = pageTable.search(address);
            if (ptResult.status) {
                process.addPageHit();
                TLB::insert(address, ptResult.pageFrame);
                pageFrame = ptResult.pageFrame;
            } else {
                const p_size newPageFrame = Memory::allocate(process);
                pageTable.insertOrModify(address, newPageFrame);
                TLB::insert(address, newPageFrame);
                pageFrame = newPageFrame;
            }
        } else {
//            Memory::search(tlbResult->PFN);
            process.addPageHit();
            pageFrame = tlbResult->PFN;
        }
        s << "0x" << hex << setw(8) << setfill('0') << address << "\t"
            << hex << AddressHandler::getVP(address) << "\t" << pageFrame << "\t"
            << TLB::getAccessNum() - TLB::getHitNum() << "/" << TLB::getHitNum() << "\t"
            << pageTable.getAccessNum() - pageTable.getHitNum() << "/" << pageTable.getHitNum() << endl;
    }

    s << endl;

    FileOperation::writeFile("visit_seq_" + to_string(process.getId()) + ".txt", s);
}
