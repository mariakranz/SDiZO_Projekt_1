//
// Created by szef on 16.03.2023.
//

#ifndef SDIZO_PROJEKT_1_TABLEIMPL_H
#define SDIZO_PROJEKT_1_TABLEIMPL_H

#include <string>


class TableImpl {
    int *tab;
    int size;

public:
    TableImpl(int size, int *data);
    ~TableImpl();

    void insertHead(int val);                   //dodaj na poczatek

    void insertTail(int val);                   //dodaj na koniec

    void insert(int val, int index);            //dodaj w dowolne miejsce

    void removeHead();                          //usun z poczatku

    void removeTail();                          //usun z konca

    void remove(int index);                     //usun z dowolnego miejsca

    void printValues();                         //drukuj tablice

    int findValue(int val);                     //zwraca indeks pierwszego napotkanego elementu o zadanej wartosci

    int getSize();                              //zwroc aktualny rozmiar tablicy
};


#endif //SDIZO_PROJEKT_1_TABLEIMPL_H
