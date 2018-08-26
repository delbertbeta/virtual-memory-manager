//
// Created by delbertbeta on 18-8-23.
//

#include "Config.h"
#include "Process.h"

int Process::count = 0;

Process::Process (p_size neededMemoryInKB) {
    this->id = count;
    p_size dividedMemorySize = neededMemoryInKB / 2;
    this->lowRange = {
            0,
            (dividedMemorySize << OFFSET) | ((1 << OFFSET) - 1)
    };

    this->highRange = {
            UPPER - this->lowRange.upperBound,
            UPPER - this->lowRange.lowerBound
    };
    count++;
}

const int Process::getId() const {
    return this->id;
}

void Process::modifyPT(p_size pageFrame) {
    pageTable.remove(pageFrame);
}

int Process::getRound() {
    return this->round;
}

void Process::newRound() {
    this->round++;
}

int Process::getPageHit() const {
    return pageHit;
}

int Process::getPageAccess() const {
    return pageAccess;
}

int Process::addPageHit() {
    pageHit++;
    return pageHit;
}

int Process::addPageAccess() {
    pageAccess++;
    return pageAccess;
}

PageTable* Process::getPageTable() {
    return &pageTable;
}
