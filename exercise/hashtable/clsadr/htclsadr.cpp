#include "htclsadr.hpp"
#include "../../vector/vector.hpp"
#include "../../list/list.hpp"
#include <iostream>
namespace lasd {

/* ************************************************************************** */

// ...

/* ************************************************************************** */
  /* Default constructor */
template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr() {
  tablesize=127;
  table.Resize(tablesize); 
  size=0;
}

/* Constructor with specified size */
template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(const unsigned long sizew) {
  table.Resize(sizew);
  tablesize = sizew;
  size=0;
}

template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(const TraversableContainer<Data>& container) noexcept {
  tablesize=container.Size();
  table.Resize(tablesize); 
  size=0;
  container.Traverse([this](const Data& dat) { Insert(dat); });
}

template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(ulong sizew, const TraversableContainer<Data>& container) noexcept {
  table.Resize(sizew);
  tablesize = sizew;
  size=0;
  container.Traverse([this](const Data& dat) { this->Insert(dat); });
}

/* Constructor from MappableContainer */
template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(MappableContainer<Data>&& container) noexcept {
    tablesize=container.Size();
  table.Resize(tablesize);  
  size=0;
  container.Map([this](Data& dat) { Insert(std::move(dat)); });
}

/* Constructor with size from MappableContainer */
template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(ulong sizew, MappableContainer<Data>&& container) noexcept {
  table.Resize(sizew);
  tablesize = sizew;
  size=0;
  container.Map([this](Data& dat) { Insert(std::move(dat)); });
}



/* Destructor */
template <typename Data>
HashTableClsAdr<Data>::~HashTableClsAdr() {
  Clear();
}

template <typename Data>
HashTableClsAdr<Data>& HashTableClsAdr<Data>::operator=(const HashTableClsAdr<Data>& other) {
    if (this != &other) {  
        Clear();  
        
        tablesize = other.tablesize;
        table.Resize(tablesize);
        size = 0;

        for (unsigned long i = 0; i < other.tablesize; ++i) {
            other.table[i].Traverse([this](const Data& element) {
                this->Insert(element);
            });
        }
    }
    return *this;
}

template <typename Data>
bool HashTableClsAdr<Data>::operator==(const HashTableClsAdr<Data>& other) const noexcept {
    if (size != other.size)
        return false;



    for (ulong i = 0; i < tablesize; ++i) {
        bool allMatch = true;
        table[i].Traverse([&](const Data& element) {
            if (!other.Exists(element)) {
                allMatch = false;
                return false; 
            }
            return true; 
        });
        if (!allMatch) {
            return false;
        }
    }

    for (ulong i = 0; i < other.tablesize; ++i) {
        bool allMatch = true;
        other.table[i].Traverse([&](const Data& element) {
            if (!Exists(element)) {
                allMatch = false;
                return false; 
            }
            return true; 
        });
        if (!allMatch) {
            return false;
        }
    }

    return true;
}

    
template <typename Data>
bool HashTableClsAdr<Data>::Insert(const Data& dat) {
 if(!this->Exists(dat)){
  if (table[HashKey(dat)% tablesize ].Insert(dat)) {
 
    ++size;
    return true;
  }
  return false;
 }
 return false;

}

template <typename Data>
bool HashTableClsAdr<Data>::Insert(Data&& dat) {
     if(!this->Exists(dat)){
  if (table[HashKey(dat)% tablesize ].Insert(std::move(dat))) {
    ++size;
    return true;
  }
  return false;
}
return false;}

/* Remove */
template <typename Data>
bool HashTableClsAdr<Data>::Remove(const Data& dat) {

  if (table[HashKey(dat) % tablesize].Remove(dat)) {
    --size;
    return true;
  }
  return false;
}

template <typename Data>
bool HashTableClsAdr<Data>::Exists(const Data& dat) const noexcept {
        unsigned long index = HashKey(dat) % tablesize;
        return table[index].Exists(dat);
}
template <typename Data>
HashTableClsAdr<Data>& HashTableClsAdr<Data>::operator=(HashTableClsAdr<Data>&& other) noexcept {
    if (this != &other) {  
        Clear();

       tablesize = other.tablesize;
        table.Resize(tablesize);
        size = 0;

        for (unsigned long i = 0; i < other.tablesize; ++i) {
            other.table[i].Traverse([this](const Data& element) {
                this->Insert((element));
            });
        }

        other.Clear();
        other.tablesize = 0;
        other.size = 0;
    }
    return *this;
}

template <typename Data>
void HashTableClsAdr<Data>::Resize(unsigned long newSize) {
  if (newSize == tablesize) 
    return;

  Vector<List<Data>> newTable(newSize); 
size=0;
  for (unsigned long i = 0; i < tablesize; ++i) {
    while (!table[i].Empty()) {
      Data element = table[i].FrontNRemove();
      unsigned long newIndex = HashKey(element) % newSize; 
      if(newTable[newIndex].Insert(element)){
size++;}

    }
  }

  table = std::move(newTable); 
  tablesize = newSize; 

}
/* Clear */
template <typename Data>
void HashTableClsAdr<Data>::Clear() {
  table.Clear();
  table.Resize(tablesize);
  size = 0;
}

}
