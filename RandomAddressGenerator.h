//
// Created by delbertbeta on 18-8-23.
//

#ifndef VIRTUAL_MEMORY_MANAGER_RANDOMADDRESSGENERATOR_H
#define VIRTUAL_MEMORY_MANAGER_RANDOMADDRESSGENERATOR_H

#include <vector>
#include <cstdlib>
#include <ctime>
#include "Process.h"

using namespace std;

class RandomAddressGenerator {

public:
    static vector<int> generateAddress(const Process& process);
};

#endif //VIRTUAL_MEMORY_MANAGER_RANDOMADDRESSGENERATOR_H
