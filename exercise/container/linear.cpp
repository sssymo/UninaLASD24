#include "linear.hpp"
namespace lasd {

/* ************************************************************************** */

// ...

/* ************************************************************************** */
    
    //specific from linearcont



   //
   //from Travcontainer
template<typename Data>
inline void LinearContainer<Data>::Traverse(TraverseFun fun) const{
    PreOrderTraverse(fun);
}


template<typename Data>
inline void LinearContainer<Data>::PostOrderTraverse(TraverseFun fun) const {
    ulong index = size;
    while (index > 0){
        fun(operator[](--index));
    }
}

template<typename Data>
inline void LinearContainer<Data>::Map(MapFun fun){
    PreOrderMap(fun);
}

template<typename Data>
inline void LinearContainer<Data>::PostOrderMap(MapFun fun)  {
    ulong index = size;
    while(index > 0){
        fun(operator[](--index));
    }
}

// from preordertraversablecontainer
template<typename Data>
inline  void LinearContainer<Data>::PreOrderTraverse(TraverseFun fun) const{
    for(ulong index = 0; index < size; ++index){
        fun(operator[](index));
    }
}
//
template<typename Data>
inline void LinearContainer<Data>::PreOrderMap( MapFun fun){
    for(ulong index = 0; index < size; ++index){
        fun(operator[](index));
    }
}

    template<typename Data>
    inline bool LinearContainer<Data>::operator==(const LinearContainer<Data> &o) const noexcept {
        if (size != o.size)
            return false;

        for (ulong i = 0; i < size; ++i) {
            if (operator[](i) != o[i])
                return false;
        }

        return true;
    }

    template<typename Data>
    inline bool LinearContainer<Data>::operator!=(const LinearContainer<Data> &o) const noexcept {
        return !(*this == o);
    }

//Specific member functions (SortableLinearContainer)
template<typename Data>
void SortableLinearContainer<Data>::Sort() noexcept {
    QuickSort(0, size - 1);
}

template<typename Data>
void SortableLinearContainer<Data>::QuickSort(ulong p, ulong r) noexcept{
    if ( p < r){
        ulong q = Partition(p, r);
        QuickSort(p, q);
        QuickSort(q+1, r);
    }
}

     //cdjsj

    template <typename Data>
    inline const Data & LinearContainer<Data>::Front() const{
        return operator[](0);
    }

    template <typename Data>
    inline Data & LinearContainer<Data>::Front(){
        return operator[](0);
    }

     template <typename Data>
    inline const Data & LinearContainer<Data>::Back() const{
        return operator[](size-1);
    }
     template <typename Data>
    inline Data & LinearContainer<Data>::Back(){
        return operator[](size-1);
    }




template<typename Data>
ulong SortableLinearContainer<Data>::Partition(ulong p, ulong r)noexcept{
    Data x = operator[](p);
    ulong i = p-1;
    ulong j = r+1;
    do{
        do{ j--; }
        while(x < operator[](j));
        do{ i++; }
        while(x > operator[](i));
        if( i < j){std::swap(operator[](i), operator[](j));}
    }while( i < j);
    return j;}

};