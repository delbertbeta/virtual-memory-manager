#include <vector>
#include "FileOperation.h"
#include "Process.h"
#include "Emulator.h"

using namespace std;

int main(int argc, const char *argv[]) {

    vector<Process> processes;
    processes.emplace_back(Process(1 * 1024));
    processes.emplace_back(Process(32 * 1024));
    processes.emplace_back(Process(64 * 1024));
    processes.emplace_back(Process(128 * 1024));
    processes.emplace_back(Process(256 * 1024));

    FileOperation::init(processes.size());

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < processes.size(); j++) {
            Emulator::run(processes[j]);
        }
    }

    for (auto process : processes) {
        stringstream s;
        s << "Page Fault Rate: " << setprecision(2) << fixed << (1.0 - ((double)process.getPageHit()/(double)process.getPageAccess())) << endl;
        string filename =  "visit_seq_" + to_string(process.getId()) + ".txt";
        FileOperation::writeFile(filename, s);
        filename = "page_table_" + to_string(process.getId()) + ".txt";
        process.getPageTable()->print(filename);
    }

//    cout << "0x" << hex << setw(8) << setfill('0') << process.lowRange.lowerBound << " 0x" << hex << setw(8)
//         << setfill('0') << process.lowRange.upperBound << endl;
//    cout << "0x" << hex << setw(8) << setfill('0') << process.highRange.lowerBound << " 0x" << hex << setw(8)
//         << setfill('0') << process.highRange.upperBound << endl;

    return 0;
}