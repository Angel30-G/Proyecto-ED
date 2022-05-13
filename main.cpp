#include <iostream>
#include "Trie.h"
using namespace std;

int main()
{
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
    delete palabras;
    return 0;
}
