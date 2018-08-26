#include <vector>
#include "FileOperation.h"
#include "Process.h"
#include "Emulator.h"

using namespace std;

int main(int argc, const char *argv[]) {

    vector<Process> processes;
    processes.emplace_back(Process(1 * 1024));
    processes.emplace_back(Process(32 * 1024));
    processes.emplace_back(Process(64 * 1024));
    processes.emplace_back(Process(128 * 1024));
    processes.emplace_back(Process(256 * 1024));

    FileOperation::init(processes.size());

    for (int i = 0; i < 3; i++) {
        for (auto process : processes) {
            Emulator::run(process);
        }
    }

    for (auto process : processes) {
        stringstream s;
        s << "Page Fault Rate: " << setprecision(2) << fixed << (1 - process.getPageAccess()/process.getPageHit()) << endl;
        FileOperation::writeFile("visit_seq_" + to_string(process.getId()) + ".txt", s);
        process.getPageTable().print("page_table_" + to_string(process.getId()) + ".txt");
    }

//    cout << "0x" << hex << setw(8) << setfill('0') << process.lowRange.lowerBound << " 0x" << hex << setw(8)
//         << setfill('0') << process.lowRange.upperBound << endl;
//    cout << "0x" << hex << setw(8) << setfill('0') << process.highRange.lowerBound << " 0x" << hex << setw(8)
//         << setfill('0') << process.highRange.upperBound << endl;

    return 0;
}