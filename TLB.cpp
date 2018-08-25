//
// Created by delbertbeta on 18-8-24.
//

#include "TLB.h"

int TLB::accessNum = 0;
int TLB::hitNum = 0;
std::vector<TLBItem> TLB::TLBContainer;

int TLB::getAccessNum() {
    return accessNum;
}

int TLB::getHitNum() {
    return hitNum;
}

const TLBItem* const TLB::search(p_size address) {
    accessNum++;
    int targetVPN = AddressHandler::getVP(address);
    auto iter = TLBContainer.begin();
    while(iter != TLBContainer.end()) {
        TLBItem item = *iter;
        if (item.VPN == targetVPN) {
            hitNum++;
            iter = TLBContainer.erase(iter);
            TLBContainer.insert(TLBContainer.begin(), item);
            return &(*iter);
        }
        iter++;
    }
    return nullptr;
}


void TLB::insert(p_size address, p_size pageFrame) {
    p_size targetVPN = AddressHandler::getVP(address);
    if (TLBContainer.size() == TLB_SIZE) {
        TLBContainer.pop_back();
    }
    TLBContainer.insert(TLBContainer.begin(), TLBItem {
       targetVPN, pageFrame
    });
}


void TLB::reset() {
    TLBContainer.clear();
    accessNum = 0;
    hitNum = 0;
}
