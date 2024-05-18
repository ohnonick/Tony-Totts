#include "arrayDictionary.h"
using namespace std;

template<class KeyType, class ValueType>
ArrayDictionary<KeyType, ValueType>::ArrayDictionary(){
    entries = new Node<Entry<KeyType, ValueType>>*[DEFAULT_CAPACITY];
    numEntries = 0;
}

template<class KeyType, class ValueType>
ArrayDictionary<KeyType, ValueType>::~ArrayDictionary(){
    delete [] entries;
    entries = nullptr;
}

template<class KeyType, class ValueType>
bool ArrayDictionary<KeyType, ValueType>::isEmpty() const{
    return(numEntries == 0);
}

template<class KeyType, class ValueType>
int ArrayDictionary<KeyType, ValueType>::getNumberOfEntries() const{
    return numEntries;
}

template<class KeyType, class ValueType>
bool ArrayDictionary<KeyType, ValueType>::add(const KeyType& newKey, const ValueType& newValue){
    if(contains(newKey)){ // Stop if dupe key
        return false;
    }

    Entry<KeyType, ValueType> newEntry(newKey, newValue); // Make new node to add
    Node<Entry<KeyType, ValueType>>* newNode = new Node(newEntry);

    int index = newKey % DEFAULT_CAPACITY; // Find index
    
    if(entries[index] == nullptr){ // If nothing is at index
        entries[index] = newNode;
    }else{ // If index is shared, add to end
        Node<Entry<KeyType, ValueType>>* lastNode = entries[index];
        while(lastNode->getNext() != nullptr){
            lastNode = lastNode->getNext();
        }
        lastNode->setNext(newNode);
    }

    return true;
}

template<class KeyType, class ValueType>
bool ArrayDictionary<KeyType, ValueType>::remove(const KeyType& targetKey){
    if(!contains(targetKey)){ // Stop if non-existent key
        return false;
    }
    
    int index = targetKey % DEFAULT_CAPACITY; // Find index

    Node<Entry<KeyType, ValueType>>* deleting = entries[index];
    if(entries[index]->getItem().getKey() == targetKey){ // If it's the first value at index
        entries[index] = entries[index]->getNext();
        delete deleting;
    }else{ // If index is shared, search and delete
        Node<Entry<KeyType, ValueType>>* prevNode;
        while(deleting->getItem().getKey() != targetKey){
            prevNode = deleting;
            deleting = deleting->getNext();
        }
        prevNode->setNext(deleting->getNext());
        delete deleting;
    }

    return true;
}

template<class KeyType, class ValueType>
void ArrayDictionary<KeyType, ValueType>::clear(){
    delete [] entries;
    entries = new Node<Entry<KeyType, ValueType>>*[DEFAULT_CAPACITY];
}

template<class KeyType, class ValueType>
bool ArrayDictionary<KeyType, ValueType>::contains(const KeyType& targetKey) const{
    int index = targetKey % DEFAULT_CAPACITY; // Find index
    if(entries[index] != nullptr){ // If something is at index
        Node<Entry<KeyType, ValueType>>* temp = entries[index];
        while(temp != nullptr){ // Parse
            if(temp->getItem().getKey() == targetKey){
                return true;
            }
            temp = temp->getNext();
        }
    }

    return false;
}

template<class KeyType, class ValueType>
ValueType ArrayDictionary<KeyType, ValueType>::getValue(const KeyType& targetKey) const{
    if(!contains(targetKey)){ // Stop if non-existent key
        throw -1;
    }
    
    int index = targetKey % DEFAULT_CAPACITY; // Find index

    Node<Entry<KeyType, ValueType>>* temp = entries[index];
    while(temp->getNext() != nullptr){ // Parse
        if(temp->getItem().getKey() == targetKey){
            break;
        }
        temp = temp->getNext();
    }
    return temp->getItem().getValue();
}