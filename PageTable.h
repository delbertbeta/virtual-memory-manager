//
// Created by delbertbeta on 18-8-25.
//

#ifndef VIRTUAL_MEMORY_MANAGER_PAGETABLE_H
#define VIRTUAL_MEMORY_MANAGER_PAGETABLE_H

#include <string>
#include <map>
#include <iterator>
#include <sstream>
#include <iomanip>
#include <cmath>
#include "FileOperation.h"
#include "AddressHandler.h"

using namespace std;

struct PageTableResult {
    bool status;
    p_size pageFrame;
};


class PageTable {
private:
    std::map< p_size, std::map< p_size, p_size >* > PT1;
    int hitNum = 0;
    int accessNum = 0;
public:
    int getHitNum() const;

    int getAccessNum() const;

public:
    PageTableResult search(p_size address);
    void remove(p_size pageFrame);
    void print(std::string& filename) const;
    void insertOrModify(p_size address, p_size pageFrame);

};


#endif //VIRTUAL_MEMORY_MANAGER_PAGETABLE_H
