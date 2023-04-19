cmake_minimum_required(VERSION 3.24)
project(SDiZO_Projekt_1)

set(CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++ -static-libgcc")

add_executable(SDiZO_Projekt_1 main.cpp TableImpl.h TableImpl.cpp FileData.h FileData.cpp ListImpl.h ListImpl.cpp HeapImpl.h HeapImpl.cpp Menu.cpp Menu.h BSTImpl.cpp BSTImpl.h RBTImpl.cpp RBTImpl.h Tests.cpp Tests.h FileData.cpp)
