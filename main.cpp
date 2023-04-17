#include <iostream>
#include "Menu.h"
#include "FileData.h"
#include "Tests.h"

using namespace std;

FileData* file;
void menuStructures(char option);

int main(){
    char choice;
    string fileName;

    do{
        cout << "----Menu----\n"
                "1. Sprawdzenie poprawnosci implementacji struktur.\n"
                "2. Testy struktur.\n"
                "3. Generuj plik z randomowymi wartosciami.\n"
                "0. Zakoncz program.\n"
                "Wpisz numer: " << endl;
        cin >> choice;
        switch (choice) {
            default:
                cout << "Wybrano: " << choice << " - Nie ma takiej opcji." << endl;
                break;
            case '0':
                break;
            case '1':
            case '2':
                menuStructures(choice);
                break;
            case '3':
                cout << "Podaj pelna sciezke do pliku do ktorego maja byc zapisane dane "
                            "(jesli nie istnieje, to zostanie utworzony, w przeciwnym wypadku zostanie nadpisany): ";
                cout << "Podaj nazwe pliku txt: ";
                cin >> fileName;

                cout << "Podaj ilosc danych: ";
                int size;
                cin >> size;

                file->writeRandomDataToFile(fileName, size);
                cout << "Plik zapisany w: " << fileName << endl;
                break;
        }
    }while(choice != '0');

    return 0;
}

void menuStructures(char option){                               //'1' - sprawdzenie poprawnosci stuktur, '2' - przeprowadzenie testow

    string fileName;

    cout << "Podaj pelna sciezke do pliku z danymi: ";
    cin >> fileName;

    file = new FileData();
    file->readDataFromFile(fileName);
    cout << "Dane odczytano z: " << fileName << endl;

    Menu *menu = new Menu(file);
    auto *tests = new Tests(file);
    char choice;
    do{
        cout << "----Menu struktur----\n"
                "1. Tablica dynamiczna.\n"
                "2. Lista dwukierunkowa.\n"
                "3. Kopiec binarny.\n"
                "4. Drzewo BST.\n"
                "5. Drzewo czerowono-czarne\n"
                "6. Zmien plik.\n"
                "0. Wroc do Menu.\n"
                "Wpisz numer: " << endl;
        cin >> choice;

        switch (choice) {
            default:
                cout << "Wybrano: " << choice << " - Nie ma takiej opcji." << endl;
                break;
            case '0':                   //wyjscie
                break;
            case '1':
                if (option == '1') menu->table();
                else {
                    tests->tableReport();
                }
                break;
            case '2':
                if (option == '1') menu->list();
                else tests->listReport();
                break;
            case '3':
                if (option =='1') menu->heap();
                else tests->heapReport();
                break;
            case '4':
                if (option =='1') menu->BST();
                else tests->BSTReport();
                break;
            case '5':
                if (option == '1') menu->RBT();
                else tests->RBTReport();
                break;
            case '6':       //zmien plik
                cout << "Podaj pelna sciezke do pliku z danymi: ";
                cin >> fileName;
                cout << endl;
                file->readDataFromFile(fileName);
                cout << "Dane odczytano z: " << fileName << endl;
                break;
        }
    } while (choice != '0');

    delete file;
    delete menu;
}





