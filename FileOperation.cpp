//
// Created by delbertbeta on 18-8-25.
//

#include "FileOperation.h"

void FileOperation::init(int count) {
    for (int i = 0; i < count; i++) {;
        remove(("addr_seq_" + std::to_string(i) + ".txt").c_str());
        remove(("visit_seq_" + std::to_string(i) + ".txt").c_str());
        remove(("page_table_" + std::to_string(i) + ".txt").c_str());
    }
}

void FileOperation::writeFile(std::string& filename, std::stringstream& content) {
    std::ofstream file(filename, std::ios::out | std::ios::app);
    file << content.str() << std::endl;
    file.close();
}
