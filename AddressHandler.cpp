//
// Created by delbertbeta on 18-8-24.
//

#include "AddressHandler.h"

int AddressHandler::getPT1(int address) {
    int result = address >> (OFFSET + PT2);
    return result;
}

int AddressHandler::getPT2(int address) {
    int result = (address >> OFFSET) & ((1 << PT2) - 1);
    return result;
}

int AddressHandler::getVP(int address) {
    int result = (address >> OFFSET);
    return result;
}

int AddressHandler::getOffset(int address) {
    int result = (address & ((1 << OFFSET) - 1));
    return result;
}
