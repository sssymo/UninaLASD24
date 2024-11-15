#include "htopnadr.hpp"
#include "../../vector/vector.hpp"
namespace lasd {

/* ************************************************************************** */

// ...

/* ************************************************************************** */
template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr() {
    Init();
    InitFlags();
}

template<typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(unsigned long newsize) {
    Init(newsize);
    InitFlags(newsize);
}
template <typename Data>
HashTableOpnAdr<Data>& HashTableOpnAdr<Data>::operator=(const HashTableOpnAdr<Data>& other) {
    if(this != &other) {
        HashTable<Data>::operator=(other);
        dirtysize = other.dirtysize;
        table = other.table;
        flags = other.flags;
    }
    return *this;
}

template <typename Data>
HashTableOpnAdr<Data>& HashTableOpnAdr<Data>::operator=(HashTableOpnAdr<Data>&& other) noexcept {
    if(this != &other) {
   tablesize = std::move(other.tablesize);
    size = std::move(other.size);
    dirtysize = std::move(other.dirtysize);
    table = std::move(other.table);
    flags = std::move(other.flags);
    other.InitFlags();
    other.table.Clear();

    }
    return *this;
}

template <typename Data>
bool HashTableOpnAdr<Data>::Insert(const Data& dat) {
    if(tablesize == 0)
        Init();
        
    unsigned long* index = Find(dat);
    if(index != nullptr) {
        delete index;
        return false;


    }else{
unsigned long* index = FindEmpty(dat);

    if(index != nullptr) {
        table.operator[](*index) = dat;
        flags.operator[](*index) = '1';
     
        size++;
        dirtysize++;
                 
        if(size > tablesize/FACTOR)
            Resize(tablesize*FACTOR);

            
        delete index;
        return true;
    }
    delete index;
    return false;
    }
    
}

template <typename Data>
bool HashTableOpnAdr<Data>::Insert(Data&& dat) noexcept {
    if(tablesize == 0)
        Init();
        
    unsigned long* index = Find(dat);
    if(index != nullptr) {
        delete index;
        return false;


    }else{
unsigned long* index = FindEmpty(dat);

    if(index != nullptr) {
        table.operator[](*index) = std::move(dat);
        flags.operator[](*index) = '1';
     
        size++;
        dirtysize++;
                 
        if(size > tablesize/FACTOR)
            Resize(tablesize*FACTOR);

            
        delete index;
        return true;
    }
    delete index;
    return false;
    }
    
}

template <typename Data>
bool HashTableOpnAdr<Data>::Remove(const Data& dat) {
    unsigned long* index = Find(dat);
    if(index != nullptr) {
        flags.operator[](*index) = '~';
        size--;
        if(dirtysize > size*FACTOR)
            Resize(tablesize); 
        delete index;
        return true;
    }
    delete index;
    return false;
}

template <typename Data>
bool HashTableOpnAdr<Data>::Exists(const Data& dat) const noexcept {
     unsigned long* index = Find(dat);
     if(index!=nullptr){
        delete index;
        return true;
     }else{
        delete index;
        return false;
     }
}

template <typename Data>
void HashTableOpnAdr<Data>::Clear() {
    InitFlags();
}
template <typename Data>
void HashTableOpnAdr<Data>::InitFlags() {
    size = 0;
    dirtysize = 0;
    for(unsigned long i=0; i<flags.Size(); i++)
        flags.operator[](i) = '0';
}

template <typename Data>
void HashTableOpnAdr<Data>::Init(unsigned long int newsize) {

    tablesize = newsize;
    size=0;
    dirtysize=0;
    table.Resize(tablesize);
    flags.Resize(tablesize);
    InitFlags();
}
template <typename Data>
void HashTableOpnAdr<Data>::Init() {
    tablesize = INIT_TABLE_SIZE;
    size=0;
    dirtysize=0;
    table.Resize(tablesize);
    flags.Resize(tablesize);
    InitFlags();
}

template <typename Data>
unsigned long HashTableOpnAdr<Data>::HashKey(const Data& dat, unsigned long int i) const noexcept {
    std::srand(i);
    return (HashKey(dat)% tablesize + (i==0 ? 0 : std::rand()))%tablesize;
}
template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(const TraversableContainer<Data>& container) noexcept {
Init();
tablesize=container.Size();
container.Traverse([this](const Data& dat) { Insert(dat); });

}
template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(MappableContainer<Data>&& container) noexcept {

    Init();
    tablesize=container.Size();
    container.Map([this](const Data & dat){Insert(std::move(dat));});

}

template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(unsigned long newSize, MappableContainer<Data>&& container) noexcept {
    Init(newSize);

container.Map([this](const Data& dat) { Insert(std::move(dat)); });

}
template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(unsigned long newSize, const TraversableContainer<Data>& container) noexcept {
    Init(newSize);


container.Traverse([this](const Data& dat) { Insert(dat); });
}
template <typename Data>
unsigned long* HashTableOpnAdr<Data>::Find(const Data& dat) const noexcept {
    unsigned long index = HashKey(dat, 0); 
    unsigned long i = 0;
    while (i < tablesize) {
        if (flags[index] == '1' && table[index] == dat) {
            return new unsigned long(index);
        }
  
        i++;
        index = (index + 1) % tablesize;
    }
    return nullptr; 
}

template <typename Data>
unsigned long* HashTableOpnAdr<Data>::FindEmpty(const Data& dat) const noexcept {
    unsigned long i = 0;
    unsigned long index;

    
    while (i < tablesize) {
        index = HashKey(dat, i);
        if (flags[index] == '1' && table[index] == dat) {
            return nullptr; 
        }
        i++;
    }

    i = 0; 
    while (i < tablesize) {
        index = HashKey(dat, i);
        if (flags[index] != '1') {
            return new unsigned long(index); 
        }
        i++;
    }

    return nullptr; 
}
template <typename Data>
void HashTableOpnAdr<Data>::Resize(unsigned long newsize) {
    if (newsize <= tablesize) {
        return; 
    }
 
    Vector<Data> newTable(newsize); 
    Vector<char> newFlags(newsize);

    unsigned long newSize = 0;
    unsigned long newDirtySize = 0;
    for (unsigned long i = 0; i < table.Size(); ++i) {
        if (flags[i] == '1') {
            unsigned long index = HashKey(table[i], 0); 
            while (newFlags[index] == '1') { 
                index = (index + 1) % newsize;
            }
            newTable[index] = std::move(table[i]); 
            newFlags[index] = '1'; 
                        ++newSize;
            ++newDirtySize;
        } else if (flags[i] == '~') {
            ++newDirtySize;
        }
    }

   tablesize = newsize;
    table = std::move(newTable);
    flags = std::move(newFlags);
    size = newSize;
    dirtysize = newDirtySize;
}

template <typename Data>
bool HashTableOpnAdr<Data>::operator==(const HashTableOpnAdr<Data>& other) const noexcept {

    for (unsigned long i = 0; i < tablesize; ++i) {

        if (flags[i] == '1') {
            if (!other.Exists(table[i])) {
                return false;
            }
        }
    }
    for (unsigned long i = 0; i < other.tablesize; ++i) {

        if (other.flags[i] == '1') {
            if (!table.Exists(other.table[i])) {
                return false;
            }
        }
    }
    return true;
}

template <typename Data>
bool HashTableOpnAdr<Data>::operator!=(const HashTableOpnAdr<Data>& other) const noexcept {
    return !(*this == other);
}

}

