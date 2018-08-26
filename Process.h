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
    int round = 0;

public:
    Process(p_size neededMemoryInKB);
    const int getId() const;
    void modifyPT(p_size pageFrame);
    Range lowRange;
    Range highRange;
    int getRound();
    void newRound();
};

#endif //VIRTUAL_MEMORY_MANAGER_PROCESS_H
