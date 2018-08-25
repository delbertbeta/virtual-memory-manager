//
// Created by delbertbeta on 18-8-25.
//

#include "PageTable.h"

int PageTable::search(int address) {
    int pt1 = AddressHandler::getPT1(address);
    auto pt2Container = PT1[pt1];
    if (pt2Container == nullptr) {
        pt2Container = new std::map<int, int>;
        PT1[pt1] = pt2Container;
    }
    int pt2 = AddressHandler::getPT2(address);
    auto pageFrame = (*pt2Container)[pt2];
    if (pageFrame == 0) {
        // TO-DO: Adapt with MainMemory to allocate new page frame.
    } else {
        return pageFrame;
    }
}

void PageTable::remove(int pageFrame) {
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
