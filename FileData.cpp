//
// Created by szef on 22.03.2023.
//

#include <iostream>
#include <fstream>
#include <random>
#include "FileData.h"


using namespace std;

FileData::FileData() {
    size = 0;
    tab = nullptr;
}

void FileData::readDataFromFile(std::string filePath) {
    if (tab!= nullptr){
        size = 0;
        delete [] tab;      //usun poprzednią tablicę
    }

    int val;

    fstream file;
    file.open(filePath, ios::in);
    if(file.is_open()) {
        file >> size;
        if (file.fail())
        cout << "File error - READ SIZE" << endl;
        else
            tab = new int[size];
        for(int i = 0; i < size; i++)
        {
            file >> val;
            if(file.fail())
            {
                cout << "File error - READ DATA" << endl;
                //delete [] tab;
                break;
            }
            else
                tab[i] = val;
        }
        file.close();
    }
    else
        cout << "File error - OPEN" << endl;
}

FileData::~FileData() {
    if (tab != nullptr) delete [] tab;
}

void FileData::writeRandomDataToFile(std::string filePath, int number) {        //number = liczba wartosci
    ofstream write(filePath);
    write << number << endl;
    for (int i = 0; i < number; i++)
    {
        write << generateRandomValue() << endl; // pass the generator to the distribution
    }
    write.close();
}

int FileData::generateRandomValue() {
    random_device rd; // non-deterministic generator
    mt19937 gen(rd()); // random engine seeded with rd()
    uniform_int_distribution<> dist(INT32_MIN, INT32_MAX); // distribute results between

    return dist(gen);
}
