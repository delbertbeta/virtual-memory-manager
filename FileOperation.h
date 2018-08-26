//
// Created by delbertbeta on 18-8-25.
//

#ifndef VIRTUAL_MEMORY_MANAGER_FILEOPERATION_H
#define VIRTUAL_MEMORY_MANAGER_FILEOPERATION_H

#include <string>
#include <fstream>
#include <cstdio>
#include <sstream>

class FileOperation {
public:
    static void init(int count);
    static void writeFile(std::string& filename, std::stringstream& content);
};


#endif //VIRTUAL_MEMORY_MANAGER_FILEOPERATION_H
