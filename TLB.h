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
    int VPN;
    int PFN;
};

class TLB {
private:
    static int accessNum;
    static int hitNum;
    static std::vector<TLBItem> TLBContainer;

public:
    static int getAccessNum();
    static int getHitNum();
    static int search(int address);
    static void insert(int address, int pageFrame);
    static void reset();

public:

};


#endif //VIRTUAL_MEMORY_MANAGER_TLB_H
