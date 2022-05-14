#include <iostream>
#include<stdlib.h>
#include<string.h>
#include<fstream>
#include <windows.h>
#include "Trie.h"
#include "DLinkedList.h"

using namespace std;

int main(){
    setlocale(LC_ALL, "spanish");
    SetConsoleCP(1252);
    SetConsoleOutputCP(1252);

    Trie t;
    t.insert("palabra");
    t.insert("padre");
    t.insert("padrón");
    t.insert("padrino");
    t.insert("pala");
    t.insert("palanca");
    t.insert("poeta");
    List<string> *palabras = t.getMatches("pa");
    palabras->print();
    t.lectura();
    delete palabras;


    return 0;
}

