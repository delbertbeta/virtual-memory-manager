//
// Created by delbertbeta on 18-8-25.
//

#include "Memory.h"

std::list<MemoryItem> Memory::memory;

int Memory::accessNum = 0;
int Memory::hitNum = 0;

bool Memory::search(p_size pageFrame) {
    accessNum++;
    for (auto item : memory) {
        if (item.pageFrame == pageFrame) {
            hitNum++;
            return true;
        }
    }
    return false;
}

const p_size Memory::allocate(Process& process) {
    if (memory.size() < MEMORY_SIZE) {
        memory.push_back(MemoryItem{
            &process,
            (p_size)memory.size() - 1
        });
        return (p_size)memory.size() - 1;
    } else {
        const auto front = memory.front();
        front.process->modifyPT(front.pageFrame);
        memory.pop_front();
        memory.push_back(MemoryItem{
            &process,
            front.pageFrame
        });
        return front.pageFrame;
    }
}
