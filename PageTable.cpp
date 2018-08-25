//
// Created by delbertbeta on 18-8-25.
//

#include "PageTable.h"

p_size PageTable::search(p_size address) {
    accessNum++;
    p_size pt1 = AddressHandler::getPT1(address);

    if (PT1.count(pt1)) {
        PT1[pt1] = new std::map<p_size, p_size>;
    }
    auto pt2Container = *(PT1[pt1]);
    int pt2 = AddressHandler::getPT2(address);

    if (pt2Container.count(pt2)) {
        hitNum++;
        return pt2Container[pt2];
    } else {

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
//    std::ofstream file;
//    file.open(filename, std::ios::out | std::ios::trunc);
//    file << "Level 1 Page Table: " << std::endl;
}
