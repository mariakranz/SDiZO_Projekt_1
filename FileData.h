//
// Created by szef on 22.03.2023.
//

#ifndef SDIZO_PROJEKT_1_FILEDATA_H
#define SDIZO_PROJEKT_1_FILEDATA_H
#include <string>

class FileData {
public:
    FileData();
    ~FileData();
    int size;
    int* tab;
    void readDataFromFile(std::string filePath);
    static int generateRandomValue();
    static void writeRandomDataToFile(std:: string filePath, int number);

};


#endif //SDIZO_PROJEKT_1_FILEDATA_H
