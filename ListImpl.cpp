//
// Created by szef on 26.03.2023.
//

#include "ListImpl.h"
#include <iostream>


ListImpl::ListImpl(int size, int* data) {
    head = nullptr;
    tail = nullptr;
    this->size = 0;

    for (int i = 0; i<size; i++){                       //wczytywanie danych z pliku
        listInsertTail(data[i]);
    }
}

void ListImpl::listInsertTail(int val) {
    size++;
    Element* newTail = new Element{nullptr, val, nullptr};

    if(head == nullptr){                                                    //jesli lista byla pusta
        head = newTail;                                                     //glowa to ogon
        tail = head;
        return;
    }
    tail->next = newTail;
    newTail->prev = tail;
    tail = newTail;
}

void ListImpl::printValues() {
    if (head == nullptr)  return;               //jesli lista pusta to return
    std:: cout << "Lista od poczatku:\n";
    Element* el = head;
    while (el->next != nullptr)
    {
        std::cout << " -> " << el->key;
        el = el->next;
    }
    std::cout << " -> " << el->key;
    std::cout << "\nSIZE: " << size << "\n" ;

    std:: cout << "Lista od konca:\n";
    el = tail;                                  //w zasadzie to, po wczesniejszych operacjach el powinno wskazywać na ostatni element czyli tail
    std::cout << " <- ";
    while (el->prev != nullptr){

        std::cout << el->key << " <- ";
        el = el->prev;
    }
    std::cout << el->key;
    std::cout << "\nSIZE: " << size << "\n" ;

}

void ListImpl::listInsertHead(int val) {
    size++;
    Element* newHead = new Element{nullptr, val, nullptr};

    if(head == nullptr){                         //jesli lista byla pusta, to po dodaniu elementu, staje sie on glowa i ogonem
        head = newHead;
        tail = head;
        return;
    }
                                                 //jesli beda wczesniej jakies wartosci w tablicy, to nowa Glowa wskazuje na starą, a stara na nową
    head->prev = newHead;
    newHead->next = head;

    head = newHead;                              //newHead staje sie nową a glowa
}

void ListImpl::listInsert(int val, int index) {
    if (index<0 || index>size-1) return;
    if(index == 0) {
        listInsertHead(val);
        return;
    }

    Element * currentEl;
    if(index<size/2){                           //jesli index znajduje sie w pierwszej polowie, zacznij iteracje od glowy
        currentEl = head;
        for (int i = 0; i < index; i++) {
            currentEl = currentEl->next;
        }
    } else{                                     //w przeciwnym wypadku, zacznij iteracje od ogona
        currentEl = tail;
        for (int i = size-1; i > index; i--) {
            currentEl = currentEl->prev;
        }
    }

    auto* newEl = new Element{currentEl, val, currentEl->prev};    //nowy element wstawiam pomiedzy elemntem na danym indeksie (currentEl), a elementem poprzedzajacym ten indeks
    newEl->prev->next = newEl;                                              //wskaznik next poprzednika elementu na indeksie ustawiam na nowy element
    newEl->next->prev = newEl;                                              //wskaznik previous elementu na indeksie ustawiam na nowy element
    size ++;
}   //przyjeta konwencja wstawiania na istniejace indeksy (nie mozna dodac na ogon)

void ListImpl::listDeleteHead() {
    if (head == nullptr) return;       //jesli lista jest pusta, to nic nie rób
    size --;

    if (head->next == nullptr) {        //sprawdzanie czy ten nastepny element to null (czyli byl tylko jeden element w liscie)
        delete head;                    //usun glowe
        head = tail = nullptr;          //ustaw wskaznik glowy i ogona na null
        return;
    }
    head = head->next;                  //ustawia nowa glowe na nastepny element
    delete head->prev;                  //usun poprzednia glowe
    head->prev = nullptr;               //ustaw wskaznik poprzedniego elementu na null
}

void ListImpl::listDeleteTail() {
    if (tail == nullptr) return;        //jesli lista jest pusta to nic nie rob
    size--;
    if (tail->prev == nullptr){         //jesli przedostatni element to null, to znaczy ze w liscie byl tylko jeden element
        delete tail;                    //usun stary ogon
        tail = head = nullptr;          //ustaw wskaznik glowy i ogona na null
        return;
    }
    tail = tail->prev;                  //ustawianie nowego ogona na przedostatni element
    delete tail->next;                  //usun stary ogon
    tail->next = nullptr;               //ustaw wskaznik nastepnego elementu na null
}

void ListImpl::listDelete(int index) {
    if (index<0 || index>size-1) return;
    if (index == 0) {
        listDeleteHead();
        return;
    }
    if (index == size-1){
        listDeleteTail();
        return;
    }

    size--;
    Element * currentEl;
    if(index<size/2){                   //jesli index znajduje sie w pierwszej polowie, zacznij iteracje od glowy
        currentEl = head;
        for (int i = 0; i < index; i++) {
            currentEl = currentEl->next;
        }

    } else{                             //w przeciwnym wypadku, zacznij iteracje od ogona
        currentEl = tail;
        for (int i = 0; i < size-index; i++) {
            currentEl = currentEl->prev;
        }
    }

    currentEl->prev->next = currentEl->next;                    //wskaznik next poprzednika naszego elementu ustawia na nastepnik naszego elementu
    currentEl->next->prev = currentEl->prev;                    //wskaznik previous następnika naszego elementu ustawia na poprzednik naszego elementu
    delete currentEl;                                           //usuniecie naszego elementu
}

int ListImpl::listSearch(int val) {
    Element* currentEl =  head;
    for(int i = 0; currentEl!=nullptr; currentEl = currentEl->next, i++ ){
        if (currentEl->key == val) return i;
    }
    return -1;          //jesli dana wartosc nie zostanie znaleziona
}

ListImpl::~ListImpl() {
    for (int i = 0; i<size; i++){
        listDeleteTail();
    }
}

int ListImpl::getSize() {
    return size;
}


