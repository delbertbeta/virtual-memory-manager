//
// Created by delbertbeta on 18-8-25.
//

#ifndef VIRTUAL_MEMORY_MANAGER_PAGETABLE_H
#define VIRTUAL_MEMORY_MANAGER_PAGETABLE_H

#include <string>
#include <map>
#include <iterator>
#include "Memory.h"
#include "AddressHandler.h"


class PageTable {
private:
    std::map< p_size, std::map< p_size, p_size >* > PT1;
    int hitNum = 0;
    int accessNum = 0;

public:
    p_size search(p_size address);
    void remove(p_size pageFrame);
    void print(std::string filename);

};


#endif //VIRTUAL_MEMORY_MANAGER_PAGETABLE_H
