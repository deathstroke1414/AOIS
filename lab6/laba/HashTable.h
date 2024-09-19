//Author: Vodohleb04
#pragma once

#ifndef _HASH_TABLE_
#define _HASH_TABLE_
#define HASH_FUNCTION_P 129
#define HASH_FUNCTION_MOD 1.84467e+19
#define REHASH_SIZE_COEFFICIENT 3/4.
#define REHASH_ELEMENTS_AMOUNT_COEFFICIENT 4/3.
#define BASIC_TABLE_SIZE 13

#include <stdexcept>
#include <vector>
#include <forward_list>
#include <string>
#include <iostream>

#include <fstream>


class HashTable;

std::ostream& operator<<(std::ostream& out, const HashTable& hash_table);

class HashTable
{
public:
    class HashTableElement
        {
        private:

            unsigned long hash;

            std::string data;

            std::string key;

            friend std::ostream& operator<<(std::ostream& out, const HashTable::HashTableElement& hash_element)
            {
                out << "Hash: " << hash_element.hash << ",\tkey: " << hash_element.key << ",\tdata: " << hash_element.data;
                return out;
            }

        public:

            HashTableElement();

            HashTableElement(unsigned long hash, std::string key, std::string data);

            HashTableElement(const HashTableElement& other);

            HashTableElement& operator= (const HashTableElement& other);

            bool operator== (const HashTableElement& other);

            bool operator != (const HashTableElement& other);

            std::string& getData();

            void setData(std::string data);

            void setData(const char* data);

            std::string& getKey();

            unsigned long getHash();

            bool empty();

        };

    HashTable();
    HashTable(const HashTable& other);
    HashTable& operator=(const HashTable& other);
    
    size_t elementsAmount();
    size_t elementsAmount() const;

    size_t size();
    size_t size() const; 

    void add(const char* key, const char* value);
    void add(const char* key, std::string value);
    void add(std::string key, const char* value);
    void add(std::string key, std::string value);

    void remove(const char* key_to_find);
    void remove(std::string key_to_find);

    HashTableElement& find(const char* key_to_find);
    HashTableElement& find(std::string key_to_find);

    std::ofstream logout;

private:

    bool collisionsAtIndex(int index);
    bool collisionsAtIndex(int index) const;

    friend std::ostream& operator<<(std::ostream& out, const HashTable& hash_table);

    unsigned long hashFunction(std::string key);
    unsigned long hashFunction(const char* key);

    std::vector<std::forward_list<HashTableElement>> table;
    size_t elements_amount;

    size_t countUsedIndexes();

    void emplaceElementIntoTable(HashTableElement new_element);

    void rehashTable();

};


#endif //!_HASH_TABLE_
