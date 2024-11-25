#include "../headers/HashTable.hpp"

#include <cassert>
#include <climits>
#include <iostream>
#include <cstddef>

template <typename K, typename V>
HashTable<K,V>::HashTable(int cap) : size_(0)
{
    setCapacity(cap);
    table_.resize(getCapacity()); 
}

template <typename K, typename V>
HashTable<K,V>::~HashTable()
{
    for (int i = 0; i < getCapacity(); ++i) {
        if (table_[i] != NULL) {
            Node* temp = table_[i];
            while (temp->next_ != NULL)
            {
                while (temp->next_ != NULL) {
                    temp = temp->next_;
                } 
                delete temp;
            }
        }
    }
}

template <typename K, typename V>
void 
HashTable<K,V>::setCapacity(int cap) 
{
    assert(cap >= 0);
    capacity_ = cap;
}

template <typename K, typename V>
int
HashTable<K,V>::getCapacity() const
{
    return capacity_;
}

template <typename K, typename V>
bool
HashTable<K,V>::anagram(const K& key1, const K& key2)
{
    return hash(key1) == hash(key2);
}

template <typename K, typename V>
int
HashTable<K,V>::getSize() const
{
    return size_;
}

template <typename K, typename V>
bool
HashTable<K,V>::isEmpty() const
{
    return getSize() == 0 ? true: false;
}

template <typename K, typename V>
void 
HashTable<K, V>::insert(const K& key, const V& value) 
{
    int index = hash(key);
    Node* newNode = new Node(key, value);

    if (table_[index] == nullptr) {
        table_[index] = newNode;
    } else {
        Node* temp = table_[index];
        while (temp->next_ != nullptr) {
            temp = temp->next_; 
        }
        temp->next_ = newNode; 
    }
    size_++;
}


template <typename K, typename V>
int
HashTable<K,V>::hash(const K& key)
{
    int index = 0;
    for(char c : key) {
        int asciValue = c;
        index = index + asciValue;
    }
    return index % getCapacity();
    //return std::hash<K>()(key) % getCapacity();
}

template <typename K, typename V>
bool
HashTable<K,V>::find(const K& key, const V& value)
{
    int index = hash(key);
    Node* temp = table_[index];

    while (temp != nullptr) {
        if (temp->value_ == value) {
            return true;
        }
        temp = temp->next_;
    }
    
    return false;
}

template <typename K, typename V>
void
HashTable<K,V>::remove(const K& key)
{
    int index = hash(key);
    Node* temp = table_[index];
    while (temp->next_ != NULL)
    {
        while (temp->next_ != NULL) {
            temp = temp->next_;
        } 
        delete temp;
    }
    table_[index] = NULL;
}
template <typename K, typename V>
void 
HashTable<K, V>::printValue(const K& key) 
{
    int index = hash(key);
    Node* temp = table_[index];

    while (temp != nullptr) {
        if (temp->key_ == key) {
            std::cout << "index: " << index << "   " << temp->value_ << std::endl;
            return;
        }
        temp = temp->next_;
    }
    
    std::cout << "Key not found: " << key << std::endl;
}
