#include "../container/traversable.hpp"
#include "../container/mappable.hpp"
#include "../container/container.hpp"
#include "../container/linear.hpp"
#include "../container/dictionary.hpp"
#include "../container/testable.hpp"
#include <stdexcept>
using ulong = unsigned long;
#include "vector.hpp"
namespace lasd {

/* ************************************************************************** */
 //Specific constructors (Vector)
 template <typename Data>
    Vector<Data>::Vector(const unsigned long newsize){
        size = newsize;
        Elements = new Data[size] {};
    }

    template<typename Data>
    Vector<Data>::Vector(const TraversableContainer<Data> & con) : Vector ( con.Size()){
        ulong index = 0;
        con.Traverse(
            [this, &index](const Data & dat){
                Elements[index++] = dat;
            }
        );

    }


    template<typename Data>
    Vector<Data>::Vector(MappableContainer<Data> && con) : Vector ( con.Size() ){
        ulong index = 0;
        con.Map(
            [this, &index](Data & dat){
                Elements[index++] = std::move(dat);
            }
        );
    }

    //Copy constructor
    template<typename Data>
    Vector<Data>::Vector(const Vector<Data> & vec){
        size = vec.size;
        Elements = new Data[size];
        std::copy(vec.Elements, vec.Elements + size, Elements);
    }

    //Move constructor (Vector)
    template<typename Data>
    Vector<Data>::Vector(Vector<Data> && vec) noexcept{
        std::swap(size, vec.size);
        std::swap(Elements, vec.Elements);
    }

    //Destructor(vector)
    template<typename Data>
    Vector<Data>::~Vector(){
        delete[] Elements;
    }


    // Copy assignment
    template<typename Data>
    Vector<Data> & Vector<Data>::operator=(const Vector<Data> & vec) {
        Vector<Data> * tmpvec = new Vector<Data>(vec);
        std::swap(*tmpvec, *this);
        delete tmpvec;
        return *this;
    }

        // move assignment
    template<typename Data>
    Vector<Data> & Vector<Data>::operator=(Vector<Data> && vec) noexcept {

        std::swap(size, vec.size);
std::swap(Elements, vec.Elements);
        return *this;
    }

    //Comparison operators (Vector)
    template<typename Data>
    bool Vector<Data>::operator==(const Vector<Data> & vec) const noexcept{
        if(size == vec.size ){
            for(ulong index = 0; index < size; ++index){
                if(Elements[index] != vec.Elements[index]){
                    return false;
                }
            }
            return true;
        }else{
            return false;
        }
    }
    template<typename Data>
    inline bool Vector<Data>::operator!=(const Vector<Data> & vec) const noexcept{
        return !(*this == vec);
    }

    //Specific member functions (Vector) inherited from ClearableContainer
    template<typename Data>
    void Vector<Data>::Clear(){
        delete[] Elements;
        Elements = nullptr;
        size = 0;
    }

    //Specific member functions (Vector) (inherited from ResizableContainer)
    template<typename Data>
    void Vector<Data>::Resize(const ulong newsize){
        if(newsize == 0){
            Clear();
        }else if ( size != newsize ){
            Data * TmpElements = new Data[newsize] {};
            ulong minsize = (size < newsize) ? size : newsize;
            for(ulong index = 0; index < minsize; ++index){
                std::swap(Elements[index], TmpElements[index]);
            }
            std::swap(Elements, TmpElements);
            size = newsize;
            delete[] TmpElements;
        }
    }
template<typename Data>
    const Data & Vector<Data>::operator[]( ulong index) const {
        if(index < size){
            return Elements[index];
        }else{
            throw std::out_of_range("Access at index"+std::to_string(index));
        }
    }

    template<typename Data>
    Data & Vector<Data>::operator[]( ulong index){
        if(index < size){
            return Elements[index];
        }else{
            throw std::out_of_range("Access at index"+std::to_string(index));
        }
    }

    template<typename Data>
    const Data & Vector<Data>::Front() const {
        if(size != 0){
            return Elements[0];
        }else{
             throw std::length_error("Accesso a vettore vouoto");
        }
    }



    template<typename Data>
    Data & Vector<Data>::Front()  {
        if(size != 0){
            return Elements[0];
        }else{
             throw std::length_error("Accesso a vettore vouoto");
        }
    }

template<typename Data>
Data & Vector<Data>::Back(){
    if(size!=0){
        return Elements[size-1];

    }else{
       throw std::length_error("Accesso a vettore vouoto");
    }
}

template<typename Data>
const Data & Vector<Data>::Back() const {
    if(size!=0){
        return Elements[size-1];

    }else{
       throw std::length_error("Accesso a vettore vouoto");
    }
}







//specific constructor di sortablevector
template <typename Data>
SortableVector<Data>::SortableVector(const ulong newsize) :Vector<Data>(newsize){}

template <typename Data>
SortableVector<Data>::SortableVector(const TraversableContainer<Data> & con) :Vector<Data>(con){}

template <typename Data>
SortableVector<Data>::SortableVector(MappableContainer<Data> && con) :Vector<Data>(std::move(con)){}

//copyconstracutoor di sortablevector
template <typename Data>
SortableVector<Data>::SortableVector(const SortableVector<Data> & vec) :Vector<Data>(vec){}

//move constructor di sortablevector
template <typename Data>
SortableVector<Data>::SortableVector(SortableVector<Data> && vec) noexcept :Vector<Data>(std::move(vec)){}



    //Copy assignment(SortableVector)
    template<typename Data>
    SortableVector<Data> & SortableVector<Data>::operator=(const SortableVector<Data> & vec){
        Vector<Data>::operator=(vec);
        return *this;
    }

    //Move assignment
    template<typename Data>
    SortableVector<Data> & SortableVector<Data>::operator=(SortableVector<Data> && vec)noexcept{
        Vector<Data>::operator=(std::move(vec));
        return *this;
    }

    template <typename Data>
void SortableVector<Data>::Resize(const ulong newSize) {
    Vector<Data>::Resize(newSize);
}

template <typename Data>
void SortableVector<Data>::Clear() {
    Vector<Data>::Clear();
}
}

// ...

/* ************************************************************************** */


;