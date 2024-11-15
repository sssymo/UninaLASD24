
#ifndef HTCLSADR_HPP
#define HTCLSADR_HPP

/* ************************************************************************** */

#include "../hashtable.hpp"
// #include ...
#include "../../vector/vector.hpp"
#include "../../list/list.hpp"
/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class HashTableClsAdr :virtual public HashTable<Data> {
  // Must extend HashTable<Data>

private:

  // ...

protected:

  // using HashTable<Data>::???;

  // ...
  using HashTable<Data>::HashKey;
  using HashTable<Data>::size;
  using HashTable<Data>::tablesize;
  Vector<List<Data>> table;
 

public:

  // Default constructor
  // HashTableClsAdr() specifiers;
HashTableClsAdr();
  /* ************************************************************************ */

  // Specific constructors
  // HashTableClsAdr(argument) specifiers; // A hash table of a given size
  HashTableClsAdr(const unsigned long); 
  // HashTableClsAdr(argument) specifiers; // A hash table obtained from a TraversableContainer
  HashTableClsAdr(const TraversableContainer<Data>&) noexcept;
  // HashTableClsAdr(argument) specifiers; // A hash table of a given size obtained from a TraversableContainer
  HashTableClsAdr(ulong,const TraversableContainer<Data>& ) noexcept;
  // HashTableClsAdr(argument) specifiers; // A hash table obtained from a MappableContainer
HashTableClsAdr( MappableContainer<Data>&&) noexcept;
  // HashTableClsAdr(argument) specifiers; // A hash table of a given size obtained from a MappableContainer
HashTableClsAdr( ulong,MappableContainer<Data>&&) noexcept;
  /* ************************************************************************ */

  // Copy constructor
  // HashTableClsAdr(argument) specifiers;

  // Move constructor
  // HashTableClsAdr(argument) specifiers;
  HashTableClsAdr(const HashTableClsAdr& other){*this=other;};
  HashTableClsAdr(HashTableClsAdr&& other) noexcept{*this=std::move(other);};
  /* ************************************************************************ */

  // Destructor
  // ~HashTableClsAdr() specifiers;
  ~HashTableClsAdr();
  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument) specifiers;

  // Move assignment
  // type operator=(argument) specifiers;
  HashTableClsAdr& operator=(const HashTableClsAdr&);
  HashTableClsAdr& operator=(HashTableClsAdr&&) noexcept;
  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  // type operator!=(argument) specifiers;
  bool operator==(const HashTableClsAdr<Data>&) const noexcept;
  bool operator!=(const HashTableClsAdr<Data>& other) const noexcept{return !HashTableClsAdr<Data>::operator==(other);};
  /* ************************************************************************ */

  // Specific member functions (inherited from DictionaryContainer)

  // type Insert(argument) specifiers; // Override DictionaryContainer member (Copy of the value)
  // type Insert(argument) specifiers; // Override DictionaryContainer member (Move of the value)
  
    bool Insert(const Data &dat) override;
    
    bool Insert(Data &&dat) override;

    // type Remove(argument) specifiers; // Override DictionaryContainer member
bool Remove(const Data &dat) override;
    /* ************************************************************************ */

    // Specific member functions (inherited from TestableContainer)

    // type Exists(argument) specifiers; // Override TestableContainer member
    bool Exists(const Data &dat) const noexcept override;
   
    /* ************************************************************************ */

    // Specific member functions (inherited from ResizableContainer)

    // type Resize(argument) specifiers; // Resize the hashtable to a given size
void Resize(unsigned long) override;


/* ************************************************************************ */

// Specific member functions (inherited from ClearableContainer)

// type Clear() specifiers; // Override Container member
void Clear() override;


};

/* ************************************************************************** */

}

#include "htclsadr.cpp"

#endif
