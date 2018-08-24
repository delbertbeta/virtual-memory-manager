cmake_minimum_required(VERSION 3.12)
project(virtual_memory_manager)

set(CMAKE_CXX_STANDARD 11)

add_executable(virtual_memory_manager main.cpp Process.cpp Process.h RandomAddressGenerator.cpp RandomAddressGenerator.h TLB.cpp TLB.h AddressConfig.h AddressHandler.cpp AddressHandler.h)