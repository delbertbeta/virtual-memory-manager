//
// Created by delbertbeta on 18-8-24.
//

#ifndef VIRTUAL_MEMORY_MANAGER_ADDRESSHANDLER_H
#define VIRTUAL_MEMORY_MANAGER_ADDRESSHANDLER_H

#include "Config.h"

class AddressHandler {
public:
    static p_size getPT1(p_size address);
    static p_size getPT2(p_size address);
    static p_size getVP(p_size address);
    static p_size getOffset(p_size address);
};


#endif //VIRTUAL_MEMORY_MANAGER_ADDRESSHANDLER_H
