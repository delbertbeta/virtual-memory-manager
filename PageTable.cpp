//
// Created by delbertbeta on 18-8-25.
//

#include "PageTable.h"

PageTableResult PageTable::search(p_size address) {
    accessNum++;
    p_size pt1 = AddressHandler::getPT1(address);

    if (PT1.count(pt1)) {
        PT1[pt1] = new std::map<p_size, p_size>;
    }
    auto pt2Container = *(PT1[pt1]);
    int pt2 = AddressHandler::getPT2(address);

    if (pt2Container.count(pt2)) {
        hitNum++;
        return PageTableResult{
            true,
            pt2Container[pt2]
        };
    } else {
        return PageTableResult {
            false,
            0
        };
    }
}

void PageTable::remove(p_size pageFrame) {
    auto pt1Iter = PT1.begin();
    while (pt1Iter != PT1.end()) {
        auto pt2Container = *((*pt1Iter).second);
        auto pt2Iter = pt2Container.begin();
        while (pt2Iter != pt2Container.end()) {
            if ((*pt2Iter).second == pageFrame) {
                pt2Container.erase(pt2Iter);
                return;
            }
            pt2Iter++;
        }
        pt1Iter++;
    }
}

void PageTable::print(std::string filename) {
    std::stringstream content;
    content << "Level 1 Page Table: " << endl;
    content  << "PT1\tPointer To PT2" << endl;
    for(auto item : PT1) {
        content << hex  << item.first << "\t" << hex << item.second << endl;
    }

    content << endl;
    content << "Level 2 Page Table: " << endl;

    for(auto item : PT1) {
        content << hex << item.second << ": " << endl;
        for (auto pt2 : *(item.second)) {
            content << hex << pt2.first << "\t" << hex << pt2.second << endl;
        }
        content << "\n\n" << endl;
    }
    FileOperation::writeFile(filename, content);
}
