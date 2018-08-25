//
// Created by delbertbeta on 18-8-25.
//

#ifndef VIRTUAL_MEMORY_MANAGER_MEMORY_H
#define VIRTUAL_MEMORY_MANAGER_MEMORY_H

#include <queue>

class Memory {
private:
    static std::queue<int> memory;
    static int accessNum;
    static int hitNum;

public:
    static bool search();
    static void allocate(int pageFrame);
};


#endif //VIRTUAL_MEMORY_MANAGER_MEMORY_H
