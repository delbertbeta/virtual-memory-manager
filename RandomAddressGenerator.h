//
// Created by delbertbeta on 18-8-23.
//

#ifndef VIRTUAL_MEMORY_MANAGER_RANDOMADDRESSGENERATOR_H
#define VIRTUAL_MEMORY_MANAGER_RANDOMADDRESSGENERATOR_H

#include <vector>
#include <ctime>
#include <random>
#include "Process.h"

using namespace std;

class RandomAddressGenerator {

public:
    static vector<p_size> generateAddress(const Process& process);
};

#endif //VIRTUAL_MEMORY_MANAGER_RANDOMADDRESSGENERATOR_H
