//
// Created by delbertbeta on 18-8-24.
//

#include "AddressHandler.h"

p_size AddressHandler::getPT1(p_size address) {
    int result = address >> (OFFSET + PT2);
    return result;
}

p_size AddressHandler::getPT2(p_size address) {
    int result = (address >> OFFSET) & ((1 << PT2) - 1);
    return result;
}

p_size AddressHandler::getVP(p_size address) {
    int result = (address >> OFFSET);
    return result;
}

p_size AddressHandler::getOffset(p_size address) {
    int result = (address & ((1 << OFFSET) - 1));
    return result;
}
