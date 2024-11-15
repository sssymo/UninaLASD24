#include "stackvec.hpp"
#include "../../../../../../usr/include/x86_64-linux-gnu/sys/types.h"

namespace lasd {

/* ************************************************************************** */

// ...

/* ************************************************************************** */
//copy e move ass
template <typename Data>
StackVec<Data>& StackVec<Data>::operator=(const StackVec<Data> & stk) {
    Vector<Data>::operator=(stk);
    index = stk.index;
    return *this;
}

template <typename Data>
StackVec<Data> & StackVec<Data>::operator=(StackVec<Data> && stk) noexcept {
    Vector<Data>::operator=(std::move(stk));
    std::swap(index,stk.index);
    return *this;
}

//sst
//move const
template <typename Data>
StackVec<Data>::StackVec(StackVec<Data> && stk) noexcept : Vector<Data>(std::move(stk)) {
std::swap(index,stk.index);
}


template<typename Data>
bool StackVec<Data>::operator==(const StackVec<Data> & stk)const noexcept{
    if(index==stk.index){
        for(ulong idx=0 ;idx<index;++idx){
            if(Elements[idx]!=stk.Elements[idx]){
                return false;
            }
        }
        return true;
    }else{
        return false;
    }
}

template<typename Data>
inline bool StackVec<Data>::operator!=(const StackVec<Data> & stk) const noexcept{
    return !(*this == stk);
}

//specific memeber func from stack
template <typename Data>
Data& StackVec<Data>::Top() {
if(index!=0){
    return Elements[index - 1];
}else{
    throw std::length_error("accesso to an empty stackk");
}

}

template <typename Data>
const Data& StackVec<Data>::Top() const {
if(index!=0){
    return Elements[index - 1];
}else{
    throw std::length_error("stack is emptu");
}

}

template <typename Data>
Data StackVec<Data>::TopNPop() {
    if (index!=0){
        Reduce();
        return std::move(Elements[--index]);
    }else{
        throw std::length_error("empty stack");
    }
}
template <typename Data>
void StackVec<Data>::Push(const Data& value) {   
    Expand();
    Elements[index++] = value;
}

template <typename Data>
void StackVec<Data>::Push(Data&& value) {
    Expand();
    Elements[index++] = std::move(value);
}
template <typename Data>
void StackVec<Data>::Pop() {
    if(index!=0){
        Reduce();
        index--;
    }else{
throw std::length_error("stack is empty");
    }
        
    
}



// Specific member functions (inherited from Container)

template <typename Data>
bool StackVec<Data>::Empty() const noexcept {
    return (index == 0);
}

template <typename Data>
ulong StackVec<Data>::Size() const noexcept {
    return index;
}



//ausilierea


template <typename Data>
void StackVec<Data>::Clear() {
    index = 0;
    Vector<Data>::Resize(1);
}

template <typename Data>
void StackVec<Data>::Expand() {
    if(index==size){
    Vector<Data>::Resize(size * 2);}
}

template <typename Data>
void StackVec<Data>::Reduce() {
    if(index==size/4){
Vector<Data>::Resize(size / 2);
    }
    
}

};
