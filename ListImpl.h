//
// Created by szef on 26.03.2023.
//

#ifndef SDIZO_PROJEKT_1_LISTIMPL_H
#define SDIZO_PROJEKT_1_LISTIMPL_H


#include <string>

struct Element{
    Element* next;
    int key;
    Element* prev;
};

class ListImpl {
    Element *head;
    Element *tail;
    int size;

public:
    ListImpl(int size, int *data);
    ~ListImpl();

    void listInsertHead(int val);           //dodaj na poczatek

    void listInsertTail(int val);           //dodaj na koniec

    void listInsert(int val, int index);    //dodaj w dowolne miejsce

    void listDeleteHead();                  //usun z poczatku

    void listDeleteTail();                  //usun z konca

    void listDelete(int index);             //usun z dowolnego miejsca

    int listSearch(int val);                //zwraca indeks pierwszego napotkanego elementu o zadanej wartosci

    void printValues();                     //drukuj liste (od poczatku i od konca)

    int getSize();                          //zwroc aktualny rozmiar
};


#endif //SDIZO_PROJEKT_1_LISTIMPL_H
