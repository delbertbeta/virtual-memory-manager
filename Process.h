//
// Created by delbertbeta on 18-8-23.
//

#ifndef VIRTUAL_MEMORY_MANAGER_PROCESS_H
#define VIRTUAL_MEMORY_MANAGER_PROCESS_H

#include <cmath>
#include <limits>
#include "Config.h"
#include "PageTable.h"
#include <fstream>

struct Range {
    p_size lowerBound;
    p_size upperBound;
};

class Process {
    static int count;
    PageTable pageTable;
    int id;

public:
    Process(int neededMemoryInKB);
    const int getId() const;
    void modifyPT(p_size pageFrame);
    Range lowRange;
    Range highRange;
};

#endif //VIRTUAL_MEMORY_MANAGER_PROCESS_H
