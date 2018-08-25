//
// Created by delbertbeta on 18-8-23.
//

#include "Config.h"
#include "Process.h"

int Process::count = 0;

Process::Process (int neededMemoryInKB) {
    this->id = count;
    int dividedMemorySize = neededMemoryInKB / 2;
    this->lowRange = {
            0,
            (dividedMemorySize << OFFSET) | ((1 << OFFSET) - 1)
    };
    int upper = std::numeric_limits<int>::max();
    this->highRange = {
            upper - this->lowRange.upperBound,
            upper - this->lowRange.lowerBound
    };
    count++;
}

const int Process::getId() const {
    return this->id;
}

void Process::modifyPT(int pageFrame) {
    pageTable.remove(pageFrame);
}
