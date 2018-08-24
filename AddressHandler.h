//
// Created by delbertbeta on 18-8-24.
//

#ifndef VIRTUAL_MEMORY_MANAGER_ADDRESSHANDLER_H
#define VIRTUAL_MEMORY_MANAGER_ADDRESSHANDLER_H

#include "AddressConfig.h"

class AddressHandler {
public:
    static int getPT1();
    static int getPT2();
    static int getPT();
    static int getOffset();
};


#endif //VIRTUAL_MEMORY_MANAGER_ADDRESSHANDLER_H
