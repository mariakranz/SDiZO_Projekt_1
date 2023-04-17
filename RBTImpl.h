//
// Created by szef on 11.04.2023.
//

#ifndef SDIZO_PROJEKT_1_RBTIMPL_H
#define SDIZO_PROJEKT_1_RBTIMPL_H


#include <string>

enum color{RED, BLACK};

struct RBNode{
    int key;
    RBNode* right;
    RBNode* left;
    RBNode* p;
    color c;
};

class RBTImpl{
    int size;
    RBNode* root;
    RBNode* TNULL;          //wartownik

    std::string cr, cl, cp;
    void treeInsert(RBNode* x);                         //procedura jak dla BST
    void rotateRight(RBNode* y);                        //procedura jak dla BST
    void rotateLeft(RBNode* x);                         //procedura jak dla BST
    RBNode* treeMinimum(RBNode* x);                     //procedura jak dla BST
    RBNode* treeSuccessor(RBNode* x);                   //procedura jak dla BST
    void RBTDeleteFixup(RBNode* x);                     //naprawia kolory w drzewie
    void printRBT(std::string sp, std::string sn, RBNode * p);  //metoda pomocnicza do wydruku drzewa
public:
    RBTImpl(int dataSize, int* data);
    ~RBTImpl();
    void RBTInsert(int val);                            //wstawianie elementu
    void RBTDelete(RBNode* z);                          //usuwanie elementu
    RBNode* RBTSearch(int val);                         //poszukiwanie elementu
    void print();                                       //drukowanie kopca
};


#endif //SDIZO_PROJEKT_1_RBTIMPL_H
