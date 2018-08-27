//
// Created by delbertbeta on 18-8-23.
//

#include "RandomAddressGenerator.h"

vector<p_size> RandomAddressGenerator::generateAddress(const Process& process) {
    std::default_random_engine generator((unsigned int)(time(0)));
    vector<p_size> addresses;
    for (int i = 0; i < 50; i++) {
        std::uniform_int_distribution<int> chooseDistribution(0, 1);
        bool choose = (bool)chooseDistribution(generator);
        std::uniform_int_distribution<p_size> addressDistribution;
        if (choose) {
            addressDistribution = std::uniform_int_distribution<p_size>(process.lowRange.lowerBound, process.lowRange.upperBound);
        } else {
            addressDistribution = std::uniform_int_distribution<p_size>(process.highRange.lowerBound, process.highRange.upperBound);
        }
        p_size address = addressDistribution(generator);
        while (address + (9 * (1 << OFFSET)) < address) {
            address = addressDistribution(generator);
        }
        addresses.push_back(address);
        for (int j = 0; j < 9; j++) {
            address += (1 << OFFSET);
            addresses.push_back(address);
        }
    }
    return addresses;
}