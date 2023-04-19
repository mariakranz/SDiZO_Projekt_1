//
// Created by szef on 11.04.2023.
//

#include <iostream>
#include "RBTImpl.h"

RBTImpl::RBTImpl(int dataSize, int *data) {
    cr = cl = cp = "  ";
    cr [ 0 ] = 218; cr [ 1 ] = 196;
    cl [ 0 ] = 192; cl [ 1 ] = 196;
    cp [ 0 ] = 179;

    TNULL = new RBNode;
    TNULL->c = BLACK;
    TNULL->left = nullptr;
    TNULL->right = nullptr;
    root = TNULL;

    this->size = 0;
    for(int i = 0; i < dataSize; i++){
        RBTInsert(data[i]);
    }
}

void RBTImpl::rotateRight(RBNode* y) {     //przerobilam analogicznie do rotateLeft
    RBNode* x = y ->left;
    if (x == TNULL) return;                   //jesli wezel ynode nie ma lewego syna - roatcja niemozliwa
    y->left = x->right;
    if (x->right != TNULL) x->right->p = y;
    x->p = y->p;
    if(y->p == nullptr) root = x;
    else if (y == y->p->right) y->p->right = x;
    else y->p->left = x;
    x->right = y;
    y->p = x;
}

void RBTImpl::rotateLeft(RBNode* x) {
    RBNode* y = x->right;                               //prawy syn wezla  wchodzi na miejsce wezla
    if (y == TNULL) return;                               //jesli prawy syn jest pusty to nie mozna zrobic rotacji (CHYBA)
    x->right =  y->left;                                 //lewy potomek y staje sie prawym potomkiem wezla
    if (y->left != TNULL) y->left->p = x;              //rodzicem lewego potomka y staje sie wezel x
    y->p = x->p;                                         //rodzice y staje sie dotychczasowy rodzic wezla x
    if (x->p == nullptr) root = y;                       //jesli x byl korzeniem
    else if(x == x->p->left) x->p->left = y;       //jesli x byl lewym synem ojca, to ustaw y jako lewego syna
    else x->p->right = y;                                // w przeciwnym wypadku ustaw y jako prawego syna
    y->left = x;                                         //ustawia x jako lewego syna y
    x->p = y;                                            //ustawia y jako ojca x

}

void RBTImpl::treeInsert(RBNode* z) {
    size++;

    RBNode* y = nullptr;
    RBNode* x = this->root;
    while(x != TNULL){                          //dopoki nie wskazuje na wartownik
        y = x;
        if(z->key < x->key) x = x->left;        //jesli wartosc z mniejsza od warosci x to zejdz do lewego syna
        else x = x->right;                      //w innym wypadku zejdz do prawego syna
    }
    z->p = y;                                   //przypisz y jako rodzica z
    if (y == nullptr) root = z;                 //jesli y bylo nullem, to znaczy ze z jest korzeniem
    else if (z->key < y->key) y->left = z;      //jesli wartosc z jest mniejsza niz wartosc y to przypisz z jako lewego syna
    else y->right = z;                          //w przeciwnym wypadku jako prawego
}

void RBTImpl::RBTInsert(int val) {
    auto* x = new RBNode{val, TNULL, TNULL, nullptr, RED};

    treeInsert(x);                          //wloz do drzewa na odpowiednie miejsce
    RBNode* y;                                 //a teraz napraw kolory
    //x->c = RED;
    while ( x!= root && x->p->c == RED){
        if ( x->p == x->p->p->left){            //jesli rodzic x jest lewym dzieckiem swojego ojca
            y = x->p->p->right;                 //ustaw y jako prawego syna dziadka x, czyli prawego wujka
            if (y->c == RED) {                  //jesli y jest czerwony
                x->p->c = BLACK;                //ustaw ojca x na czarno
                y->c = BLACK;                   //i tego wujka na czarno
                x->p->p->c = RED;               //a ich ojca na czerwono
                x = x->p->p;                    //i usatw x na tego ojca
            }else {
                if (x == x->p->right) {         //jesli x jest prawym dzieckiem
                    x = x->p;                   //ustaw x na rodzica
                    rotateLeft(x);              //i obroc w lewo (czyli te prawe dziecko wokol tego rodzica)
                }
                x->p->c = BLACK;                //ustaw kolor rodzica x na czarny
                x->p->p->c = RED;               //ustaw kolor dziadka x na czerwony
                rotateRight(x->p->p);        //i obroc w prawo tego dziadka
            }

        }else{                                  //tutaj symetrycznie do powyzszego
            y = x->p->p->left;
            if ( y->c == RED){
                x->p->c = BLACK;
                y->c = BLACK;
                x->p->p->c = RED;
                x = x->p->p;
            }else {
                if (x == x->p->left) {
                    x = x->p;
                    rotateRight(x);
                }
                x->p->c = BLACK;
                x->p->p->c = RED;
                rotateLeft(x->p->p);
            }
        }
    }
    root->c = BLACK;                    //pokoloruj korzen na czarno
}

void RBTImpl::printRBT(std::string sp, std::string sn, RBNode *p) {
    std::string t;

    if( p != TNULL )
    {
        t = sp;
        if( sn == cr ) t [ t.length( ) - 2 ] = ' ';
        printRBT ( t+cp, cr, p->right );

        t = t.substr ( 0, sp.length( ) - 2 );
        switch (p->c) {
            case RED:
                std::cout << t << sn << "R" << ":" << p->key << std::endl;
                break;
            case BLACK:
                std::cout << t << sn << "B" << ":" << p->key << std::endl;
        }


        t = sp;
        if( sn == cl ) t [ t.length( ) - 2 ] = ' ';
        printRBT ( t+cp, cl, p->left );
    }

}   //algorytm wyświetlania kopca zaczerpnięty ze strony I-LO w Tarnowie
                                                                          //autorstwa mgr Jerzego Wałaszka

void RBTImpl::print() {
    printRBT ( "", "", root );
}

void RBTImpl::RBTDelete(RBNode *z) {
    if(root == nullptr) return;
    size--;

    RBNode* y;
    RBNode* x;

    if (z->left == TNULL || z->right == TNULL) y = z;       //przypadek1 - jesli usuwany wezel nie ma synow, po prostu go usun
    else y = treeSuccessor(z);                           //w przeciwnym wypadku znajdz jego nastepnik

    if (y->left != TNULL) x = y->left;                      //jesli y ma lewgo syna, ustaw x w lewym synie
    else x = y->right;                                      //w przeciwnym wypadku ustaw x w prawym synie

    if ( x!= nullptr) x->p = y->p;                          //jesli z nie jest nullem to ojcowi x przypisz ojca y
    if (y->p == nullptr) root = x;                          //jesli ten ojciec y to null to ustaw x jako roota
    else if ( y == y->p->left) y->p->left = x;              //jesli y jest lewym synem, ustaw tego syna na x
    else y->p->right = x;                                   //w przecwnym wypadku ustaw x jako prawego syna

    if (y!=z) z->key = y->key;                              //jesli y nie jest tym samym elementam co y to przekopiuj wartosc z y do z

    if (y->c == BLACK) RBTDeleteFixup(x);                   //jesli y ma czarny kolor, to napraw kolory
    delete y;                                               //usun wezel
}

RBNode *RBTImpl::treeSuccessor(RBNode *x) {
    if (x->right != TNULL) return treeMinimum(x->right);    //jesli prawe poddrzewo istnieje idz jeden wezel w prawo i szukaj minimum
    RBNode* y = x->p;                                          //w przeciwnym wypadku przejdz do rodzica (rodzicow) dopoki nie sa lewymi synami
    while (y != TNULL && x == y->right){                       //wtedy zwroc ich rodzica
        x = y;
        y = y->p;
    }
    return y;
}

RBNode *RBTImpl::treeMinimum(RBNode *x) {       //wartosc najbardziej w lewo w poddrzewie
    while(x->left != TNULL){
        x = x->left;
    }
    return x;
}

void RBTImpl::RBTDeleteFixup(RBNode *x) {
    RBNode* w;
    while (x != root && x->c == BLACK){
        if (x == x->p->left){                                   //jesli z jest lewym synem
            w =x->p->right;                                     //ustaw w na prawego syna (brata x)
            if ( w->c == RED){                                  //jesli jest on czerwony
                w->c = BLACK;                                   //zmien kolory
                x->p->c = RED;
                rotateLeft(x->p);                            //obroc w lewo ojca x
                w = x->p->right;                                //ustaw z powrotem w jako prawego syna
            }

            if(w->left->c == BLACK && w->right->c == BLACK){        //jesli lewy i prawy syn w maja czarny kolor
                w->c = RED;                                         //pokoloruj w na czerwono
                x = x->p;                                           //ustaw x na rodzica
            }else {                                                 //w przeciwnym wypadku
                if (w->right->c == BLACK){                          //jesli prawy syn w ma kolor czarny
                    w->left->c = BLACK;                             //pokoloruj lewego syna w na czarno
                    w->c = RED;                                     //a semego w na czerwowno
                    rotateRight(w);                              //obroc w prawo
                    w = x->p->right;                                //ustaw w na prawego brata x
                }
                w->c = x->p->c;                                     //ustaw kolor w na kolor ojca x
                x->p->c = BLACK;                                    //a tego ojca na czarny
                w->right->c = BLACK;                                //prawego syna w pokoloruj na czarno
                rotateLeft(x->p);                                //obroc w lewo
                x = root;                                           //ustaw x na roota
            }
        }else{                                                      //symatrycznie do powyzszego
            w = x->p->left;
            if (w->c == RED) {
                w->c = BLACK;
                x->p->c = RED;
                rotateRight(x->p);
                w = x->p->left;
            }

            if (w->right->c == BLACK && w->left->c == BLACK) {
                w->c = RED;
                x = x->p;
            } else {
                if (w->left->c == BLACK) {
                    w->right->c = BLACK;
                    w->c = RED;
                    rotateLeft(w);
                    w = x->p->left;
                }
                w->c = x->p->c;
                x->p->c = BLACK;
                w->left->c = BLACK;
                rotateRight(x->p);
                x = root;
            }
        }
    }
    x->c = BLACK;
}

RBTImpl::~RBTImpl() {
    int i = size;
    for (; i>0; i--){
        RBTDelete(root);
    }
    delete TNULL;
}

RBNode *RBTImpl::RBTSearch(int val) {
    RBNode* x = root;
    while(x != TNULL && val != x->key){
        if (val < x->key) x = x->left;
        else x = x->right;
    }
    if (x != TNULL) return x;
    return nullptr;
}
