//
// Created by delbertbeta on 18-8-25.
//

#ifndef VIRTUAL_MEMORY_MANAGER_MEMORY_H
#define VIRTUAL_MEMORY_MANAGER_MEMORY_H

#include "Config.h"
#include "Process.h"
#include <list>

struct MemoryItem {
    Process* process;
    p_size pageFrame;
};

class Memory {
private:
    static std::list<MemoryItem> memory;
    static int accessNum;
    static int hitNum;

public:
    static bool search(p_size pageFrame);
    static const p_size allocate(Process& process);
};


#endif //VIRTUAL_MEMORY_MANAGER_MEMORY_H
