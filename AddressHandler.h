//
// Created by delbertbeta on 18-8-24.
//

#ifndef VIRTUAL_MEMORY_MANAGER_ADDRESSHANDLER_H
#define VIRTUAL_MEMORY_MANAGER_ADDRESSHANDLER_H

#include "Config.h"

class AddressHandler {
public:
    static int getPT1(int address);
    static int getPT2(int address);
    static int getVP(int address);
    static int getOffset(int address);
};


#endif //VIRTUAL_MEMORY_MANAGER_ADDRESSHANDLER_H
