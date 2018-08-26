//
// Created by delbertbeta on 18-8-26.
//

#include "Emulator.h"

void Emulator::run(Process &process) {
    const auto addresses = RandomAddressGenerator::generateAddress(process);
    FileOperation::writeFile()
}
