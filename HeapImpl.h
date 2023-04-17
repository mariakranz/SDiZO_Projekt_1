//
// Created by szef on 28.03.2023.
//

#ifndef SDIZO_PROJEKT_1_HEAPIMPL_H
#define SDIZO_PROJEKT_1_HEAPIMPL_H

#include <string>


class HeapImpl {
    int * heap;                         //wskaznik na korzen kopca
    int size;                           //rozmiar kopca
    int parent(int);                    //zwraca numer indeksu rodzica
    int left(int);                      //zwraca numer indeksu lewego syna
    int right(int);                     //zwraca numer indeksu prawego syna
    void heapify(int);                  //przywracanie wlasnosci kopca dla zadanego wezla
    void buildHeap();                   //przywracanie wlasnosci kopca dla kazdego wezla

public:
    HeapImpl(int size, int* data);
    ~HeapImpl();
    void heapInsert(int);                                       // dodaje element na wlasciwe miejsce w kopcu
    void deleteRoot();                                          // usuwa korzen i przywraca wlasnosc kopca
    int searchValue(int);                                       // iteracyjnie wyszukuje wartosc w kopcu jak w tablicy, jesli jej nie znajdzie - zwraca -1 (uzyta do testow)
    void printHeap(std::string sp, std::string sn, int v);      // drukuje kopiec
    int search(int val, int index);                             // rekurencyjnie wyszukuje wartosc korzystając z własności kopca, jesli jej nie znajdzie - zwraca -1 (nie uzyta w testach)
};


#endif //SDIZO_PROJEKT_1_HEAPIMPL_H
