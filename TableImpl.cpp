//
// Created by szef on 16.03.2023.
//

#include "TableImpl.h"
#include <string>
#include <iostream>

using namespace std;

TableImpl::TableImpl(int size, int* data){       //rozmiar i dane tablicowe (tablica danych z pliku)
    this->size = size;
    tab = new int[size];
    for(int i = 0; i<size; i++){
        tab[i] = data[i];
    }
}

void TableImpl::insertHead(int val) {
    size += 1;
    int * tempTab = new int[size];      //wskaznik na poczatek tablicy o nowym rozmiarze w innym miejscu pamieci
    tempTab[0] = val;                   //wpisz val na pierwszy indeks
    for (int i = 1; i < size; i++){     //reszte wartosci przekopiuj ze starej tablicy
        tempTab[i] = tab[i-1];
    }
    delete [] tab;                      //usun stara tablice
    tab = tempTab;
}

void TableImpl::printValues() {
    cout << "Index:  ";

    for(int i = 0; i < size; i++){
        cout.width(5);
        cout << i;
    }
    cout << endl << "Values: ";

    for(int i = 0; i < size; i++){
        cout.width(5);
        cout << tab[i];
    }
    cout << endl;
}

int TableImpl::findValue(int val) {
    for(int i = 0; i < size; i++){
        if (tab[i] == val) return i;
    }
    return -1;
}

void TableImpl::insertTail(int val) {       //analogicznie do insertHead(int)
    size += 1;
    int * tempTab = new int [size];
    for (int i = 0; i < size-1; i++){
        tempTab[i] = tab[i];
    }
    tempTab[size - 1] = val;
    delete [] tab;
    tab = tempTab;
}

void TableImpl::insert(int val, int index) {
    if (index > size-1) return;
    size += 1;
    int *tempTab = new int[size];
    tempTab[index] = val;                           //wstaw wartosc do odpowiedniego indeksu
    for (int i = 0, j = 0; i < size; i++, j++){     //reszte przekopiuj
        if (i == index){                            //gdy bedzie to indeks na ktory zostala juz wpisana wartosc to go pomin
            i++;
        }
        tempTab[i] = tab[j];
    }
    delete [] tab;                                  //usun stara tablice
    tab = tempTab;                                  //ustaw wskaznik na nowa tablice
}      //przyjeto konwencje ze da sie wstawiac elementy na juz istniejace indeksy, dlatego nie mozna wstawic jako ostatni element

void TableImpl::removeHead() {
    if (tab == nullptr) return;
    size -= 1;
    int * tempTab = new int[size];
    for(int i = 1; i < size + 1; i++){              //iterowanie starej tablicy i przenoszenie z niej danych do nowej tablicy
        tempTab[i-1] = tab[i];
    }
    delete [] tab;
    if (size == 0 ) tab = nullptr;
    else tab = tempTab;
}

void TableImpl::removeTail() {                      //ananlogicznie do removeHead()
    if (tab == nullptr) return;
    size -= 1;
    int * tempTab = new int[size];
    for (int i = 0; i < size; i++){
        tempTab[i] = tab[i];
    }
    delete [] tab;
    if (size == 0 ) tab = nullptr;
    else tab = tempTab;
}

void TableImpl::remove(int index) {                 //analogicznie do insert()
    if (tab == nullptr || index > size-1) return;
    size -= 1;
    int * tempTab = new int[size];
    for (int i = 0, j = 0; j < size; i++, j++){
        if (i == index) ++i;
        tempTab[j] = tab[i];
    }
    delete [] tab;
    if (size == 0 ) tab = nullptr;
    else tab = tempTab;

}

TableImpl::~TableImpl() {
    size = 0;
    delete [] tab;
}

int TableImpl::getSize() {
    return size;
}




