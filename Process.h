//
// Created by delbertbeta on 18-8-23.
//

#ifndef VIRTUAL_MEMORY_MANAGER_PROCESS_H
#define VIRTUAL_MEMORY_MANAGER_PROCESS_H

#include <cmath>



struct Range {
    int lowerBound;
    int upperBound;
};

class Process {
    static int count;

public:
    Process(int neededMemoryInKB);
    Range lowRange;
    Range highRange;
};



#endif //VIRTUAL_MEMORY_MANAGER_PROCESS_H
