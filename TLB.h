//
// Created by delbertbeta on 18-8-24.
//

#ifndef VIRTUAL_MEMORY_MANAGER_TLB_H
#define VIRTUAL_MEMORY_MANAGER_TLB_H

#include "Config.h"
#include "AddressHandler.h"
#include <vector>
#include <iterator>

struct TLBItem {
    p_size VPN;
    p_size PFN;
};

class TLB {
private:
    static int accessNum;
    static int hitNum;
    static std::vector<TLBItem> TLBContainer;

public:
    static int getAccessNum();
    static int getHitNum();
    static const TLBItem* const search(p_size address);
    static void insert(p_size address, p_size pageFrame);
    static void reset();

};


#endif //VIRTUAL_MEMORY_MANAGER_TLB_H
