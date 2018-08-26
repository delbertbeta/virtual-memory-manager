//
// Created by delbertbeta on 18-8-24.
//

#ifndef VIRTUAL_MEMORY_MANAGER_CONFIG_H
#define VIRTUAL_MEMORY_MANAGER_CONFIG_H

#include <limits>

typedef unsigned int p_size;

const short PT1 = 4;
const short PT2 = 15;
const short OFFSET = 13;
const short TLB_SIZE = 16;
const int MEMORY_SIZE = 32 * 1024 / 8;
const p_size UPPER = std::numeric_limits<p_size>::max();

#endif //VIRTUAL_MEMORY_MANAGER_CONFIG_H
