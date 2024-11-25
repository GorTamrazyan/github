#ifndef __HASH_TABLE_HPP__
#define __HASH_TABLE_HPP__

#include <cstddef>
#include <ostream>

template <typename K, typename V>
class HashTable
{

private:
    struct Node
    {
        K key_;
        V value_;
        Node* next_;
        Node() : key_(), value_(), next_(nullptr) {}
        Node(const K key, V value) : key_(key), value_(value), next_(NULL) {};
    };

public:
    HashTable(int cap = 100);
    ~HashTable();
    void setCapacity(int cap);    
    int getCapacity() const;
    bool anagram(const K& key1, const K& key2);
    int getSize() const;
    bool isEmpty() const;
    void insert(const K& key, const V& value);
    int hash(const K& key);
    bool find(const K& key,const V& value);
    void remove(const K& key);
    
    void printValue(const K& key);

private:
    std::vector<Node*> table_;
    int capacity_;
    int size_;
};

#include "../templates/HashTable.cpp"
#endif /// __HASH_TABLE_HPP__

