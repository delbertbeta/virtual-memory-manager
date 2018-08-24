//
// Created by delbertbeta on 18-8-23.
//

#include "AddressConfig.h"
#include "Process.h"

int Process::count = 0;

Process::Process (int neededMemoryInKB) {
    int dividedMemorySize = neededMemoryInKB / 2;
    int pt2BitNeeded = log(dividedMemorySize / 8) / log(2);
    int pt1 = 0 + (this->count << (OFFSET + PT2));
    this->lowRange = {
            pt1,
            pt1 + (((int)pow(2, pt2BitNeeded) - 1) << OFFSET)
    };
    pt1 = 0 + ((0xf - this->count) << (OFFSET + PT2));
    this->highRange = {
            pt1,
            pt1 + (((int)pow(2, pt2BitNeeded) - 1) << OFFSET)
    };
}