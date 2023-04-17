//
// Created by szef on 11.04.2023.
//


#include <iomanip>
#include <windows.h>
#include <iostream>
#include "Tests.h"
#include "TableImpl.h"
#include "ListImpl.h"
#include "HeapImpl.h"
#include "FileData.h"
#include "RBTImpl.h"


using namespace std;

long long int read_QPC()
{
    LARGE_INTEGER count;
    QueryPerformanceCounter(&count);
    return((long long int)count.QuadPart);
}

Tests::Tests(FileData* data) {
    this->data = data;
    QueryPerformanceFrequency((LARGE_INTEGER *)&frequency);
}

void Tests::printTime() {
    cout << "\nTime [s] = " << fixed << setprecision(3) << (float)elapsed /
                                                           frequency << endl;
    cout << "Time [ms] = " << setprecision(0) << (1000.0 * elapsed) /
                                                 frequency << endl;
    cout << "Time [us] = " << setprecision(0) << (1000000.0 * elapsed) /
                                                 frequency << endl << endl;
    cout << "Time [ns] = " << setprecision(0) << (1000000000.0 * elapsed) /
                                                 frequency << endl << endl;
}

void Tests::tableReport() {
    auto* tab = new TableImpl(data->size, data->tab);
    int val;
    int index;

    cout << "Testy tablicy.\nRozmiar struktury: " << data->size << endl;

    cout << "1. Dodaj element na poczatku.\n";
    val = data->generateRandomValue();
    start = read_QPC();
    tab->insertHead(val);
    elapsed = read_QPC() - start;
    printTime();

    cout << "2. Dodaj element na koncu.\n";
    val = data->generateRandomValue();
    start = read_QPC();
    tab->insertTail(val);
    elapsed = read_QPC() - start;
    printTime();

    cout << "3. Dodaj element na indeks.\n";
    val = data->generateRandomValue();
    index = abs(data->generateRandomValue()%tab->getSize());
    start = read_QPC();
    tab->insert(val, index);
    elapsed = read_QPC() - start;
    printTime();

    cout << "4. Usun element na poczatku.\n";
    start = read_QPC();
    tab->removeHead();
    elapsed = read_QPC() - start;
    printTime();

    cout << "5. Usun element na koncu.\n";
    start = read_QPC();
    tab->removeTail();
    elapsed = read_QPC() - start;
    printTime();

    cout << "6. Usun element o indeksie.\n";
    index = abs(data->generateRandomValue()%tab->getSize());
    start = read_QPC();
    tab->remove(index);
    elapsed = read_QPC() - start;
    printTime();

    cout << "7. Wyszukaj wartosc.\n";
    val = data->generateRandomValue();
    start = read_QPC();
    tab->findValue(val);
    elapsed = read_QPC() - start;
    printTime();

    delete tab;
}

void Tests::listReport() {
    auto* list = new ListImpl(data->size, data->tab);
    int val;
    int index;

    cout << "Testy listy.\nRozmiar struktury: " << data->size << endl;

    cout << "1. Dodaj element na poczatku.\n";
    val = data->generateRandomValue();
    start = read_QPC();
    list->listInsertHead(val);
    elapsed = read_QPC() - start;
    printTime();

    cout << "2. Dodaj element na koncu.\n";
    val = data->generateRandomValue();
    start = read_QPC();
    list->listInsertTail(val);
    elapsed = read_QPC() - start;
    printTime();

    cout << "3. Dodaj element na indeks.\n";
    val = data->generateRandomValue();
    index = abs(data->generateRandomValue()%list->getSize());
    start = read_QPC();
    list->listInsert(val, index);
    elapsed = read_QPC() - start;
    printTime();

    cout << "4. Usun element na poczatku.\n";
    start = read_QPC();
    list->listDeleteHead();
    elapsed = read_QPC() - start;
    printTime();

    cout << "5. Usun element na koncu.\n";
    start = read_QPC();
    list->listDeleteTail();
    elapsed = read_QPC() - start;
    printTime();

    cout << "6. Usun element o indeksie.\n";
    index = abs(data->generateRandomValue()%list->getSize());
    start = read_QPC();
    list->listDelete(index);
    elapsed = read_QPC() - start;
    printTime();

    cout << "7. Wyszukaj wartosc.\n";
    val = data->generateRandomValue();
    start = read_QPC();
    list->listSearch(val);
    elapsed = read_QPC() - start;
    printTime();

    delete list;
}

void Tests::heapReport() {
    auto* heap = new HeapImpl(data->size, data->tab);
    int val;

    cout << "Testy kopca.\nRozmiar struktury: " << data->size << endl;

    cout << "1. Dodaj element.\n";
    val = data->generateRandomValue();
    start = read_QPC();
    heap->heapInsert(val);
    elapsed = read_QPC() - start;
    printTime();

    cout << "2. Usun element (ze szytu).\n";
    start = read_QPC();
    heap->deleteRoot();
    elapsed = read_QPC() - start;
    printTime();

    cout << "3. Wyszukaj wartosc (przeszukiwanie jak tablice).\n";
    val = data->generateRandomValue();
    start = read_QPC();
    heap->searchValue(val);
    elapsed = read_QPC() - start;
    printTime();

    delete heap;
}

void Tests::BSTReport() {   //nie zaimplementowane bo robilam testy RBT
    cout << "Testy drzewa BST.\nRozmiar struktury: " << data->size << endl;
}

void Tests::RBTReport() {
    auto* RBtree = new RBTImpl(data->size, data->tab);
    int val;
    RBNode* node = nullptr;

    cout << "Testy drzewa czerwono-czarnego.\nRozmiar struktury: " << data->size << endl;

    cout << "1. Dodaj element.\n";
    val = data->generateRandomValue();
    start = read_QPC();
    RBtree->RBTInsert(val);
    elapsed = read_QPC() - start;
    printTime();

    cout << "2. Usun element.\n";
    while ( node == nullptr) {
        val = data->generateRandomValue();
        node = RBtree->RBTSearch(val);
    }
    start = read_QPC();
    RBtree->RBTDelete(node);
    elapsed = read_QPC() - start;
    printTime();

    cout << "3. Wyszukaj wartosc.\n";
    val = data->generateRandomValue();
    start = read_QPC();
    RBtree->RBTSearch(val);
    elapsed = read_QPC() - start;
    printTime();

    delete RBtree;
}

Tests::~Tests() = default;