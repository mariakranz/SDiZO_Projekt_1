//
// Created by szef on 04.04.2023.
//

#ifndef SDIZO_PROJEKT_1_MENU_H
#define SDIZO_PROJEKT_1_MENU_H

#include "FileData.h"

class Menu {
public:
    Menu(FileData* data);
    ~Menu();
    FileData* data;
    void table();
    void list();
    void heap();
    void BST();
    void RBT();

    void printTime();
};


#endif //SDIZO_PROJEKT_1_MENU_H
