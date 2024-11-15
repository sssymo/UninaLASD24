#ifndef HASHTABLE_HPP
#define HASHTABLE_HPP

/* ************************************************************************** */

#include <random>

/* ************************************************************************** */

#include "../container/dictionary.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class Hashable {

public:

  // type operator()(argument) specifiers; // (concrete function should not throw exceptions)
 unsigned long operator()(const Data&) const noexcept=0;
};

/* ************************************************************************** */

template <typename Data>
class HashTable : virtual public ResizableContainer,virtual public DictionaryContainer<Data>{
                  // Must extend ResizableContainer,
                  //             DictionaryContainer<Data>

private:

  // ...

protected:

  // using DictionaryContainer<Data>::???;
using DictionaryContainer<Data>::size;
  // ...
ulong a=1;
ulong b=0;
static const ulong prime=1163;
static const unsigned long INIT_TABLE_SIZE=127;
  unsigned long tablesize;
static const Hashable<Data> hash;
public:

  // Destructor
  // ~HashTable() specifiers
virtual ~HashTable() = default;
  /* ************************************************************************ */
HashTable();
  // Copy assignment
  // type operator=(argument); // Copy assignment of abstract types should not be possible.
HashTable& operator=(HashTable &&other) noexcept;
HashTable& operator=(const HashTable &other);
  // Move assignment
  // type operator=(argument); // Move assignment of abstract types should not be possible.
HashTable(const HashTable & h){
  size=h.size;
  a=h.a;
  b=h.b;
  tablesize=h.tablesize;
}
HashTable( HashTable && h){
std::swap(size,h.size);
std::swap(a,h.a);
std::swap(b,h.b);
std::swap(tablesize,h.tablesize);
}
  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers; // Comparison of abstract hashtable is possible but not required.
  // type operator!=(argument) specifiers; // Comparison of abstract hashtable is possible but not required.
  bool operator==(const HashTable<Data>&) const noexcept = delete; 
  bool operator!=(const HashTable<Data>& other) const noexcept = delete;

protected:

  // Auxiliary member functions

  // type HashKey(argument) specifiers;
unsigned long HashKey(const Data&) const noexcept;

};

/* ************************************************************************** */

}

#include "hashtable.cpp"

#endif
