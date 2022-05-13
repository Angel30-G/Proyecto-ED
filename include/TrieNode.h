#ifndef TRIENODE_H
#define TRIENODE_H

#include "BSTreeDictionary.h"

class TrieNode
{
private:
    Dictionary<char, TrieNode*> *children;
public:
    bool isFinal;
    int prefixCount;

    TrieNode() {
        isFinal = false;
        prefixCount = 0;
        children = new BSTreeDictionary<char, TrieNode*> ();
    }
    ~TrieNode(){
        delete children;
    }
    bool getIsFinal(){
        return isFinal;
    }
    void setIsFinal(bool isFinal){
        this->isFinal = isFinal;
    }
    int getPrefixCount(){
        return prefixCount;
    }
    void setPrefixCount(int prefixCount){
        this->prefixCount = prefixCount;
    }
    void increaseCount(){
        prefixCount++;
    }
    void decreaseCount(){
        prefixCount--;
    }
    bool contains(char c){
        return children->contains(c);
    }
    void add(char c){
        TrieNode *newNode = new TrieNode();
        children->insert(c, newNode);
    }
    TrieNode* getChild(char c){
        return children->getValue(c);
    }
    void remove(char c){
        children->remove(c);
    }
    List<char>* getChildren(){
        return children->getKeys();
    }
    List<TrieNode*>* getChildrenPointers(){
        return children->getValues();
    }
};

#endif // TRIENODE_H
