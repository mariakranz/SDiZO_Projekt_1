//
// Created by szef on 08.04.2023.
//

#ifndef SDIZO_PROJEKT_1_BSTIMPL_H
#define SDIZO_PROJEKT_1_BSTIMPL_H

struct BSTNode{
    int key;
    BSTNode* right = nullptr;
    BSTNode* left = nullptr;
    BSTNode* p = nullptr;
};

class BSTImpl {
    BSTNode* root;
    int size;
    //metda pomocnicza do wydruku drzewa
    void printBT(std::string sp, std::string sn, BSTNode * v );
    //metody poocnicze do usuwania wartosci z drzewa
    BSTNode* treeMinimum(BSTNode* x);                               //wyszukuje minimum dla danego wezla x
    BSTNode* treeSuccessor(BSTNode* x);                             //wyszukuje nastepnik dla zadanego wezla x (element o najmniejszym ale większym kluczu)
    //metody pomocnicze do rownowazenia drzewa
    void treeToVine();                                              //tworzenie listy niemalejacej poprzez rotacje w prawo
    void vineToTree();                                              //tworzenie drzewa z listy poprzez rotacje w lewo
public:
    BSTImpl(int size, int* data);
    ~BSTImpl();
    void printValues();                         //drukuje drzewo

    void treeInsert(int val);                   //wstawia wezel o wartosci val w odpowiednie miejsce

    void treeDelete(BSTNode* z);                //usuwa wezel z z drzewa

    BSTNode* treeSearch(BSTNode* x, int k);     //rekurencyjnie szuka wezla o wartosci val, jesli nie znajdzie zwraca -1

    BSTNode* treeIterativeSearch(int val);      //iteracyjnie szuka wezla o wartosci val, jesli nie znajdzie zwraca -1

    void rotateRight(BSTNode* ynode);           //obraca w prawo wezel ynode (jesli ynode nie ma lewego syna - rotacja niemozliwa)

    void rotateLeft(BSTNode* xnode);            //obraca w lewo wezel xnode (jesli xnode nie ma prawego syna - rotacja niemozliwa)

    void balanceTree();                         //algorytm DSW równoważenia drzewa
};


#endif //SDIZO_PROJEKT_1_BSTIMPL_H
