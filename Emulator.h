//
// Created by delbertbeta on 18-8-26.
//

#ifndef VIRTUAL_MEMORY_MANAGER_EMULATOR_H
#define VIRTUAL_MEMORY_MANAGER_EMULATOR_H

#include "TLB.h"
#include "Memory.h"
#include "Process.h"
#include "RandomAddressGenerator.h"
#include "FileOperation.h"

class Emulator {
public:
    static void run(Process& process);
};


#endif //VIRTUAL_MEMORY_MANAGER_EMULATOR_H
