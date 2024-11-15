#include "hashtable.hpp"

namespace lasd {

/* ************************************************************************** */

// ...

/* ************************************************************************** */
    template <>
    class Hashable<int> {
    public:
        unsigned long int operator()(const int& k) const noexcept {
            return k*k;
        }
    };

    template <>
    class Hashable<double> {
    public:
        unsigned long int operator()(const double& k) const noexcept {
            long int integer_part = std::floor(k);
            long int fractional_part = pow(2, 24) * (k - integer_part);
            return integer_part*fractional_part;
        }
    };

    template <>
    class Hashable<std::string> {
    public:
        unsigned long int operator()(const std::string& k) const noexcept {
            unsigned long int hash = 5381;
            for(unsigned long int i=0; i << k.length(); i++)
                hash = (hash << 5) + k[i];
            return hash;
        }
    };
    template<typename Data>
    HashTable<Data> &HashTable<Data>::operator=(HashTable&& other) noexcept {
        if(this != &other) {
            std::swap(a, other.a);
            std::swap(b, other.b);
            std::swap(tablesize, other.tablesize);
            std::swap(size, other.size);
        }
        return *this;
    }

    template<typename Data>
    HashTable<Data> &HashTable<Data>::operator=(const HashTable& other) {
        if(this != &other) {
            a = other.a;
            b = other.b;
            tablesize=other.tablesize;
            size=other.size;
        }
        return *this;
    }
    template<typename Data>
    HashTable<Data>::HashTable() {
        std::default_random_engine gen=std::default_random_engine (std::random_device{}());
        std::uniform_int_distribution<unsigned long> dista=std::uniform_int_distribution<unsigned long> (1, prime);
        std::uniform_int_distribution<unsigned long> distb=std::uniform_int_distribution<unsigned long> (0, prime);
        a=dista(gen);
        b=distb(gen);
    }



    template<typename Data>
    unsigned long HashTable<Data>::HashKey(const Data& k) const noexcept {
        return ((a*hash(k)+b)%prime);
    }





}
