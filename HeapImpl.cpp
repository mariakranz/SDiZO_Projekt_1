//
// Created by szef on 28.03.2023.
//

#include <iostream>
#include "HeapImpl.h"

HeapImpl::HeapImpl(int size, int* data) {
    this->size = size;
    heap = new int[size];                               //kopiec to tablica dynamiczna
    for(int i = 0; i<size; i++){
        heap[i] = data[i];
    }
    buildHeap();
}

void HeapImpl::printHeap(std::string sp, std::string sn, int v)
{
    std::string s;
    std::string cr, cl, cp;
    cr = cl = cp = "  ";
    cr[0] = 218; cr[1] = 196;
    cl[0] = 192; cl[1] = 196;
    cp[0] = 179;

    if (v < size)
    {
        s = sp;
        if (sn == cr) s[s.length() - 2] = ' ';
        printHeap(s + cp, cr, 2 * v + 2);

        s = s.substr(0, sp.length() - 2);

        std::cout << s << sn << heap[v] << std::endl;

        s = sp;
        if (sn == cl) s[s.length() - 2] = ' ';
        printHeap(s + cp, cl, 2 * v + 1);
    }

}

void HeapImpl::buildHeap() {
    for (int i = (size/2) - 1; i >= 0 ; i--){
        heapify(i);
    }
}

void HeapImpl::heapify(int index) {
    int l = left(index);
    int r = right(index);
    int largest;
    if (l<size && heap[l] > heap[index]){
        largest = l;
    }else{
        largest = index;
    }
    if (r<size && heap[r] > heap[largest]){
        largest = r;
    }
    if (largest != index){
        int tmpVal = heap[largest];
        heap[largest] = heap[index];
        heap[index] = tmpVal;
        heapify(largest);
    }
}

int HeapImpl::parent(int index) {
    return (index-1) / 2;
}

int HeapImpl::left(int index) {
    return 2 * index + 1;
}

int HeapImpl::right(int index) {
    return 2 * index + 2;
}

void HeapImpl::heapInsert(int key) {
    size++;
    int *tmp = new int[size];
    for(int i = 0; i<size-1; i++){
        tmp[i] = heap[i];
    }
    delete [] heap;
    heap = tmp;

    int i = size -1;
    while (i>0 && heap[parent(i)] < key ){
        heap[i] = heap[parent(i)];
        i = parent(i);
    }
    heap[i] = key;
}

void HeapImpl::deleteRoot() {
    if(size<1) return;
    heap[0] = heap[size-1];
    size--;
    heapify(0);
    int *tmp = new int[size];
    for(int i = 0; i<size; i++){
        tmp[i] = heap[i];
    }
    delete [] heap;
    heap = tmp;
}

int HeapImpl::searchValue(int val) {
    for(int i = 0; i<size; i++){
        if (heap[i]==val) return i;
    }
    return -1;
}

HeapImpl::~HeapImpl() {
    size = 0;
    delete [] heap;
}

int HeapImpl::search(int val, int index) {
    while(index < size){
        if(heap[index] == val) return index;
        else if(heap[index] > val){
            int l = search(val, left(index));
            if ( l != -1) return l;
            return search(val,right(index));
        }else break;
    }
    return -1;
}           //proba implementacji przeszukiwania kopca, korzystajac z wlasnosci kopca
                                                         //wstepne testy wskazaly gorsze czasy niz metoda po tablicy,
                                                         // wiec wnioskuje, że implementacja jest niepoprawna chociaz moze
                                                         //trzeba bylo i tak sprawdzic zlozonosc czy bedzie rowna O(lgn)




