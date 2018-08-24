//
// Created by delbertbeta on 18-8-24.
//

#ifndef VIRTUAL_MEMORY_MANAGER_TLB_H
#define VIRTUAL_MEMORY_MANAGER_TLB_H

#include <vector>

struct TLBItem {
//    int ;
//    int
};

class TLB {
private:
    static int accessNum;
    static int hitNum;

public:
    static int getAccessNum();
    static int getHitNum();
    static int search();
    static int insert();
    static void reset();

public:

};


#endif //VIRTUAL_MEMORY_MANAGER_TLB_H
