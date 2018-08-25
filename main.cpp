#include <iostream>
#include <iomanip>
#include <fstream>
#include "Process.h"

using namespace std;

int main(int argc, const char *argv[]) {

    Process process(128 * 1024);

    cout << "0x" << hex << setw(8) << setfill('0') << process.lowRange.lowerBound << " 0x" << hex << setw(8)
         << setfill('0') << process.lowRange.upperBound << endl;
    cout << "0x" << hex << setw(8) << setfill('0') << process.highRange.lowerBound << " 0x" << hex << setw(8)
         << setfill('0') << process.highRange.upperBound << endl;

    return 0;
}