//
// Created by szef on 11.04.2023.
//

#ifndef SDIZO_PROJEKT_1_TESTS_H
#define SDIZO_PROJEKT_1_TESTS_H

#include "FileData.h"

class Tests {
    long long int frequency, start, elapsed;
public:
    Tests(FileData* data);
    ~Tests();
    FileData* data;
    void tableReport();
    void listReport();
    void heapReport();
    void BSTReport();
    void RBTReport();

    void RBTReport1();
    void RBTReport2();
    void RBTReport3();

    void printTime();
};


#endif //SDIZO_PROJEKT_1_TESTS_H
