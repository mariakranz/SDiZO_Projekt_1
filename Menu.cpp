//
// Created by szef on 04.04.2023.
//


#include <iostream>
#include "Menu.h"
#include "TableImpl.h"
#include "ListImpl.h"
#include "HeapImpl.h"
#include "FileData.h"
#include "BSTImpl.h"
#include "RBTImpl.h"


using namespace std;

Menu::Menu(FileData* data) {
    this->data = data;
}

void Menu::table() {
    char tableChoice;
    auto* tab = new TableImpl(data->size, data->tab);
    int val, result;
    int index;
    tab->printValues();

    do {
        cout << "TABLICA DYNAMICZNA - Dostepne operacje: \n"
                "0. Wyjdz.\n"
                "1. Dodaj element na poczatku.\n"
                "2. Dodaj element na koncu.\n"
                "3. Dodaj element na indeks.\n"
                "4. Usun element na poczatku.\n"
                "5. Usun element na koncu.\n"
                "6. Usun element o indeksie.\n"
                "7. Wyszukaj wartosc.\n"
                "8. Zobacz tablice.\n"
                "Wpisz numer: "<< endl;
        cin >> tableChoice;

        switch (tableChoice) {
            default: cout << "Nie ma takiej opcji." << endl;
                break;
            case '0':
            case '8':
                break;
            case '1':       //dodaj element na poczatek
                cout << "Podaj wartosc: ";
                cin >> val;
                tab->insertHead(val);
                break;
            case '2':       //dodaj element na koniec
                cout << "Podaj wartosc: ";
                cin >> val;
                tab->insertTail(val);
                break;
            case '3':       //dodaj element na indeks
                cout << "Podaj wartosc: ";
                cin >> val;
                cout << "\nPodaj numer indeksu: ";
                cin >> index;
                tab->insert(val, index);
                cout << endl;
                break;
            case '4':       //usun element na poczatku
                tab->removeHead();
                break;
            case '5':       //usun element na koncu
                tab->removeTail();
                break;
            case '6':       //usun element z indeksu
                cout << "Podaj indeks: ";
                cin >> index;
                tab->remove(index);
                break;
            case '7':       //wyszukaj wartosc o indeksie
                cout << "Podaj wartosc: ";
                cin >> val;
                result = tab->findValue(val);
                if ( result == -1) cout << "Wartosc nieodnaleziona." << endl;
                else cout << "Index: " << result << endl;
                break;
        }
        tab->printValues();
        system("PAUSE");
    } while (tableChoice != '0');

    delete tab;
}

void Menu::list() {
    auto* list = new ListImpl(data->size, data->tab);
    list->printValues();

    int val, result;
    int index;

    char choice;
    do{
        cout << "LISTA DWUKIERUNKOWA - Dostepne operacje: \n"
                "0. Wyjdz.\n"
                "1. Dodaj element na poczatku.\n"
                "2. Dodaj element na koncu.\n"
                "3. Dodaj element na indeks.\n"
                "4. Usun element na poczatku.\n"
                "5. Usun element na koncu.\n"
                "6. Usun element o indeksie.\n"
                "7. Wyszukaj wartosc.\n"
                "8. Zobacz liste.\n"
                "Wpisz numer: "<< endl;
        cin >> choice;

        switch (choice) {
            default: cout << "Nie ma takiej opcji." << endl;
                break;
            case '0':
            case '8':
                break;
            case '1':       //dodaj element na poczatku
                cout << "Podaj wartosc: ";
                cin >> val;
                list->listInsertHead(val);
                break;
            case '2':       //dodaj element na koncu
                cout << "Podaj wartosc: ";
                cin >> val;
                list->listInsertTail(val);
                break;
            case '3':       //dodaj elem na indeks
                cout << "Podaj wartosc: ";
                cin >> val;
                cout << "Podaj indeks: ";
                cin >> index;
                list->listInsert(val, index);
                break;
            case '4':       //usun elem na poczatku
                list->listDeleteHead();
                break;
            case '5':       //usun elem na koncu
                list->listDeleteTail();
                break;
            case '6':       //usun elem z indeksu
                cout << "Podaj indeks: ";
                cin >> index;
                list->listDelete(index);
                break;
            case '7':       //wyszukaj wartosc
                cout << "Podaj wartosc:";
                cin >> val;
                result = list->listSearch(val);
                if (result == -1) cout << "Wartosc nieodnaleziona.";
                else cout << "Index: " << result;
                cout << endl;
                break;
        }
        list->printValues();
        system("PAUSE");
    }while (choice != '0');
    delete list;
}

void Menu::heap() {
    char choice;
    int val, result;
    auto* heap = new HeapImpl(data->size, data->tab);

    heap->printHeap("", "", 0);
    do {
        cout << "KOPIEC BINARNY - Dostepne operacje: \n"
                "0. Wyjdz.\n"
                "1. Dodaj element.\n"
                "2. Usun element (ze szytu).\n"
                "3. Wyszukaj wartosc.\n"
                "4. Zobacz kopiec.\n"
                "Wpisz numer: " << endl;
        cin >> choice;

        switch (choice) {
            default:
                cout << "Nie ma takiej opcji." << endl;     //mozna usunac break
                break;
            case '0':
            case '4':
                break;
            case '1':
                cout << "Podaj wartosc: ";
                cin >> val;
                heap->heapInsert(val);
                break;
            case '2':
                heap->deleteRoot();
                break;
            case '3':
                cout << "Podaj wartosc: ";
                cin >> val;
                result = heap->searchValue(val);
                if ( result == -1) cout << "Wartosc nieodnaleziona." << endl;
                else cout << "Index: " << result << endl;
                break;
        }
        heap->printHeap("", "", 0);
        system("PAUSE");
    }while (choice != '0');
    delete heap;
}

void Menu::BST() {
    auto* tree = new BSTImpl(data->size, data->tab);
    tree->printValues();

    char choice;
    int val;
    BSTNode* node;

    do{
        cout << "DRZEWO POSZUKIWAN BINARNYCH - Dostepne operacje: \n"
                "0. Wyjdz.\n"
                "1. Dodaj element.\n"
                "2. Usun element.\n"
                "3. Wyszukaj wartosc.\n"
                "4. Zrownowaz drzewo (algorytm DSW).\n"
                "5. Rotacja w prawo dla wezla.\n"
                "6. Rotacja w lewo dla wezla. \n"
                "7. Zobacz drzewo.\n"
                "Wpisz numer: " << endl;
        cin >> choice;
        switch (choice) {
            default:
                cout << "Nie ma takiej opcji." << endl;
            case '0':
            case '7':
                break;
            case '1':       //dodaj el
                cout << "Podaj wartosc: ";
                cin >> val;
                cout << endl;
                tree->treeInsert(val);
                break;
            case '2':       //usun el
                cout << "Podaj wartosc: ";
                cin >> val;
                cout << endl;
                node = tree->treeIterativeSearch(val);
                if(node != nullptr) tree->treeDelete(node);     //jesli znaleziono taki wezel to go usun
                break;
            case '3':       //wyszukaj el
                cout << "Podaj wartosc: ";
                cin >> val;
                cout << endl;
                //if(tree->treeSearchValue(val)) cout << "Wartosc znaleziona. \n";
                if(tree->treeIterativeSearch(val) != nullptr) cout << "Wartosc znaleziona. \n";
                else cout << "Wartosc nieznaleziona.\n";
                break;
            case '4':       //DSW
                tree->balanceTree();
                break;
            case '5':       //rotacja w prawo
                cout << "Podaj wartosc: ";
                cin >> val;
                cout << endl;
                node = tree->treeIterativeSearch(val);
                if(node != nullptr) tree->rotateRight(node);
                else cout << "Wartosc nieznaleziona.\n";
                break;
            case '6':       //rotacja w lewo
                cout << "Podaj wartosc: ";
                cin >> val;
                cout << endl;
                node = tree->treeIterativeSearch(val);
                if(node != nullptr) tree->rotateLeft(node);
                else cout << "Wartosc nieznaleziona.\n";
                break;
        }
        tree->printValues();
        system("PAUSE");
    }while(choice!='0');
    delete tree;
}

void Menu::RBT() {
    auto* RBtree = new RBTImpl(data->size, data->tab);
    RBtree->print();

    char choice;
    int val;
    RBNode* node;

    do {
        cout << "DRZEWO CZERWONO-CZARNE - Dostepne operacje: \n"
                "0. Wyjdz.\n"
                "1. Dodaj element.\n"
                "2. Usun element.\n"
                "3. Wyszukaj wartosc.\n"
                "4. Zobacz drzewo.\n"
                "Wpisz numer: " << endl;
        cin >> choice;

        switch (choice) {
            default:
                cout << "Nie ma takiej opcji." << endl;
            case '0':
            case '4':
                break;
            case '1':
                cout << "Podaj wartosc: ";
                cin >> val;
                RBtree->RBTInsert(val);
                break;
            case '2':
                cout << "Podaj wartosc: ";
                cin >> val;
                node = RBtree->RBTSearch(val);
                if( node != nullptr ) RBtree->RBTDelete(node);
                else cout << "Wartosc nieodnaleziona." << endl;
                break;
            case '3':
                cout << "Podaj wartosc: ";
                cin >> val;
                if(RBtree->RBTSearch(val) != nullptr ) cout << "Wartosc odnaleziona." << endl;
                else cout << "Wartosc nieodnaleziona." << endl;
                break;
        }
        RBtree->print();
        system("PAUSE");
    }while (choice != '0');
    delete RBtree;
}

Menu::~Menu() = default;




