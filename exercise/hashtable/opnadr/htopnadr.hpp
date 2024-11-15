
#ifndef HTOPNADR_HPP
#define HTOPNADR_HPP

/* ************************************************************************** */

#include "../hashtable.hpp"
// #include ...
#include "../../vector/vector.hpp"
/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class HashTableOpnAdr : virtual public HashTable<Data> {
  // Must extend HashTable<Data>

private:

  // ...

protected:

  // using HashTable<Data>::???;
  using HashTable<Data>::tablesize;  
    using HashTable<Data>::INIT_TABLE_SIZE;  
  using HashTable<Data>::size;
  // ...
  unsigned long int dirtysize = 0;
  static constexpr float FACTOR = 2;
    Vector<Data> table;
  Vector<char> flags;
  // '0' empty cell
  // '~' special cell (is empty for Insert and full for Find)
  // '1' full cell
public:

  // Default constructor
  // HashTableOpnAdr() specifiers;
 HashTableOpnAdr();
  /* ************************************************************************ */

  // Specific constructors
  // HashTableOpnAdr(argument) specifiers; // A hash table of a given size
HashTableOpnAdr(unsigned long newsize);
  // HashTableOpnAdr(argument) specifiers; // A hash table obtained from a TraversableContainer
HashTableOpnAdr(const TraversableContainer<Data>&) noexcept;
  // HashTableOpnAdr(argument) specifiers; // A hash table of a given size obtained from a TraversableContainer
HashTableOpnAdr(ulong,const TraversableContainer<Data>& ) noexcept;
  // HashTableOpnAdr(argument) specifiers; // A hash table obtained from a MappableContainer
HashTableOpnAdr( MappableContainer<Data>&&) noexcept;
  // HashTableOpnAdr(argument) specifiers; // A hash table of a given size obtained from a MappableContainer
HashTableOpnAdr( ulong,MappableContainer<Data>&&) noexcept;
  /* ************************************************************************ */

  // Copy constructor
  // HashTableOpnAdr(argument) specifiers;

  // Move constructor
  // HashTableOpnAdr(argument) specifiers;
  HashTableOpnAdr(const HashTableOpnAdr<Data>& other) {*this = other;}
  HashTableOpnAdr(HashTableOpnAdr<Data>&& other) noexcept {*this = std::move(other);}
  /* ************************************************************************ */

  // Destructor
  // ~HashTableOpnAdr() specifiers;
  ~HashTableOpnAdr() {
    table.Clear();
    flags.Clear();
  }
  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument) specifiers;

  

  // Move assignment
  // type operator=(argument) specifiers;
  HashTableOpnAdr<Data>& operator=(const HashTableOpnAdr<Data>&);
  HashTableOpnAdr<Data>& operator=(HashTableOpnAdr<Data>&&) noexcept;
  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  // type operator!=(argument) specifiers;

  bool operator==(const HashTableOpnAdr<Data>& other) const noexcept ;
  bool operator!=(const HashTableOpnAdr<Data>& other) const noexcept ;
  /* ************************************************************************ */

  // Specific member functions (inherited from DictionaryContainer)

  // type Insert(argument) specifiers; // Override DictionaryContainer member (Copy of the value)
  // type Insert(argument) specifiers; // Override DictionaryContainer member (Move of the value)
  // type Remove(argument) specifiers; // Override DictionaryContainer member
  bool Insert(const Data&) override; 
  bool Insert(Data&&) noexcept override; 
  bool Remove(const Data&) override;
  /* ************************************************************************ */

  // Specific member functions (inherited from TestableContainer)

  // type Exists(argument) specifiers; // Override TestableContainer member
  bool Exists(const Data&) const noexcept override;
  /* ************************************************************************ */

  // Specific member functions (inherited from ResizableContainer)

  // type Resize(argument) specifiers; // Resize the hashtable to a given size
void Resize(unsigned long) override; 
  /* ************************************************************************ */

  // Specific member functions (inherited from ClearableContainer)

  // type Clear() specifiers; // Override Container member
  using Container::Empty;
  void Clear() override;
  void InitFlags();
  void Init(unsigned long newsize);
  void Init();




  protected:

  // Auxiliary member functions

  // type HashKey(argument) specifiers;
    using HashTable<Data>::HashKey;
  unsigned long HashKey(const Data&, unsigned long) const noexcept;
  // type Find(argument) specifiers;
  // type FindEmpty(argument) specifiers;

  
  unsigned long* Find(const Data&) const noexcept;
  unsigned long* FindEmpty(const Data&) const noexcept;
  // type Remove(argument) specifiers;

};

/* ************************************************************************** */

}

#include "htopnadr.cpp"

#endif
