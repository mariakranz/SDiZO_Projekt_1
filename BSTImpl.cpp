//
// Created by szef on 08.04.2023.
//

#include <string>
#include <iostream>
#include <ctgmath>
#include "BSTImpl.h"

std::string cr, cl, cp;

BSTImpl::BSTImpl(int size, int *data) {
    root = nullptr;
    this->size = 0;
    for(int i = 0; i<size; i++){
        treeInsert(data[i]);
    }
}

void BSTImpl::printValues() {
    cr = cl = cp = "  ";
    cr [ 0 ] = 218; cr [ 1 ] = 196;
    cl [ 0 ] = 192; cl [ 1 ] = 196;
    cp [ 0 ] = 179;

    printBT ( "", "", root );
}

void BSTImpl::printBT (std::string sp, std::string sn, BSTNode * v )
{
    std::string s;

    if( v )
    {
        s = sp;
        if( sn == cr ) s [ s.length( ) - 2 ] = ' ';
        printBT ( s + cp, cr, v->right );

        s = s.substr ( 0, sp.length( )-2 );
        std::cout << s << sn << v->key << std::endl;

        s = sp;
        if( sn == cl ) s [ s.length( ) - 2 ] = ' ';
        printBT ( s + cp, cl, v->left );
    }
}

void BSTImpl::treeInsert(int val) {
    size++;
    auto* z = new BSTNode{val, nullptr, nullptr, nullptr};

    BSTNode* y = nullptr;
    BSTNode* x = root;
    while(x!= nullptr){
        y = x;
        if(z->key < x->key) x = x->left;
        else x = x->right;
    }
    z->p = y;
    if (y == nullptr) root = z;
    else if (z->key < y->key) y->left = z;
    else y->right = z;
}

void BSTImpl::treeDelete(BSTNode* z) {
    if(root == nullptr) return;
    size--;

    BSTNode* y;
    BSTNode* x;

    if (z->left == nullptr || z->right == nullptr) y = z;
    else y = treeSuccessor(z);

    if (y->left != nullptr) x = y->left;
    else x = y->right;

    if ( x!= nullptr) x->p = y->p;

    if (y->p == nullptr) root = x;
    else if (y == y->p->left) y->p->left = x;
    else y->p->right = x;


    if ( y != z) z->key = y->key;
    delete y;
}

BSTNode *BSTImpl::treeSearch(BSTNode *x, int k) {
    if (x == nullptr || x->key == k) return x;
    if (k < x->key) return treeSearch(x->left, k);
    else return treeSearch(x->right, k);
}

BSTNode* BSTImpl::treeIterativeSearch(int val) {
    BSTNode* x = root;
    while(x != nullptr && val != x->key){
        if (val < x->key) x = x->left;
        else x = x->right;
    }
    return x;
}

void BSTImpl::rotateRight(BSTNode* ynode) {     //przerobilam analogicznie do rotateLeft
    BSTNode* x = ynode ->left;
    if (x == nullptr) return;                   //jesli wezel ynode nie ma lewego syna - roatcja niemozliwa, mogloby zwracac -1
    ynode->left = x->right;
    if (x->right != nullptr) x->right->p = ynode;
    x->p = ynode->p;
    if(ynode->p == nullptr) root = x;
    else if (ynode == ynode->p->right) ynode->p->right = x;
    else ynode->p->left = x;
    x->right = ynode;
    ynode->p = x;
}

void BSTImpl::rotateLeft(BSTNode* xnode) {
    BSTNode* y = xnode->right;                               //prawy syn wezla  wchodzi na miejsce wezla
    if (y == nullptr) return;                               //jesli prawy syn jest pusty to nie mozna zrobic rotacji (CHYBA)
    xnode->right =  y->left;                                 //lewy potomek y staje sie prawym potomkiem wezla
    if (y->left != nullptr) y->left->p = xnode;              //rodzicem lewego potomka y staje sie wezel xnode
    y->p = xnode->p;                                         //rodzice y staje sie dotychczasowy rodzic wezla xnode
    if (xnode->p == nullptr) root = y;                       //jesli xnode byl korzeniem
    else if(xnode == xnode->p->left) xnode->p->left = y;       //jesli xnode byl lewym synem ojca, to ustaw y jako lewego syna
    else xnode->p->right = y;                                // w przeciwnym wypadku ustaw y jako prawego syna
    y->left = xnode;                                         //ustawia xnode jako lewego syna y
    xnode->p = y;                                            //ustawia y jako ojca xnode

}

BSTNode *BSTImpl::treeMinimum(BSTNode *x) {
    while(x->left != nullptr){
        x = x->left;
    }
    return x;
}

BSTNode *BSTImpl::treeSuccessor(BSTNode *x) {
    if (x->right != nullptr) return treeMinimum(x->right);
    BSTNode* y = x->p;
    while (y != nullptr && x == y->right){
        x = y;
        y = y->p;
    }
    return y;
}

void BSTImpl::treeToVine() {
    BSTNode* tmp = root;
    while (tmp != nullptr){
        if (tmp->left != nullptr){
            rotateRight(tmp);
            tmp = tmp->p;                   //ustawianie na lewe dziecko, ktore stalo sie rodzicem
        }else{
            tmp = tmp->right;
        }
    }
}

void BSTImpl::vineToTree() {
    BSTNode* tmp = root;
    int m = pow(2, floor(log2(size+1)))-1;
    for(int i = 0; i < size - m; i++){
        rotateLeft(tmp);
        tmp = tmp->p->right;
    }
    while (m>1) {
        m = m / 2;
        tmp = root;
        for (int i = 0; i < m; i++) {
            rotateLeft(tmp);
            tmp = tmp->p->right;
        }
    }

}

void BSTImpl::balanceTree() {
    if(root == nullptr) return;
    treeToVine();
    vineToTree();
}

BSTImpl::~BSTImpl() {
    int i = size;
    for(; i>0; i--){
        treeDelete(root);
    }
}
