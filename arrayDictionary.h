#ifndef ARRAY_DICTIONARY
#define ARRAY_DICTIONARY

#include "dictionary.h"
#include "node.h"
#include "entry.h"

template<class KeyType, class ValueType>
class ArrayDictionary : public DictionaryInterface<KeyType, ValueType>{
    private:
        static const int DEFAULT_CAPACITY = 10;
        Node<Entry<KeyType, ValueType>>** entries;
        int numEntries;
        
    public:
        ArrayDictionary();
        ~ArrayDictionary();
        bool isEmpty() const;
        int getNumberOfEntries() const;
        bool add(const KeyType& newKey, const ValueType& newValue);
        bool remove(const KeyType& targetKey);
        void clear();
        bool contains(const KeyType& targetKey) const;
        ValueType getValue(const KeyType& targetKey) const;
};

#include "arrayDictionary.cpp"
#endif