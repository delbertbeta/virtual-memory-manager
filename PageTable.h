//
// Created by delbertbeta on 18-8-25.
//

#ifndef VIRTUAL_MEMORY_MANAGER_PAGETABLE_H
#define VIRTUAL_MEMORY_MANAGER_PAGETABLE_H

#include <map>
#include <iterator>
#include "AddressHandler.h"


class PageTable {
private:
    std::map< int, std::map< int, int >* > PT1;

public:
    int search(int address);
    void remove(int pageFrame);

};


#endif //VIRTUAL_MEMORY_MANAGER_PAGETABLE_H
