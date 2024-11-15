#include "queuevec.hpp"

namespace lasd {

/* ************************************************************************** */

// ...

/* ************************************************************************** */

//copy assignment
template <typename Data>
QueueVec<Data>& QueueVec<Data>::operator=(const QueueVec<Data> & queue) {
Vector<Data>::operator=(queue);
head=queue.head;
tail=queue.tail;
return *this;
}

//move assignment
template <typename Data>
QueueVec<Data>& QueueVec<Data>::operator=(QueueVec<Data> && queue)noexcept {
    Vector<Data>::operator=(std::move(queue));
    std::swap(head,queue.head);
    std::swap(tail,queue.tail);
    return *this;
}
//cons from mappablecont
template <typename Data>
QueueVec<Data>::QueueVec(MappableContainer<Data> && con) : Vector<Data>(std::move(con)), tail(size) {
    Vector<Data>::Resize(size*2);
}

//cons from travcont
template <typename Data>
QueueVec<Data>::QueueVec(const TraversableContainer<Data> & con) : Vector<Data>(con), tail(size) {
    Vector<Data>::Resize(size*2);
}

//comparison operator
template <typename Data>
inline bool QueueVec<Data>::operator!=(const QueueVec<Data> & queue) const noexcept {
    return !(*this == queue);
}

template <typename Data>
bool QueueVec<Data>::operator==(const QueueVec<Data> & queue) const noexcept {
    if(Size()==queue.Size()){
        for(ulong idx1=head,idx2=queue.head;idx1<tail;++idx1%=size,++idx2%=queue.size){
            if(Elements[idx1]!=queue.Elements[idx2]){
                return false;
            }
        }
        return true;
    }else{
        return false;
    }
}

//specific member func
template <typename Data>
const Data& QueueVec<Data>::Head() const {
if(head!=tail){
    return Elements[head];
}else{
    throw std::length_error("access to an empy queue");
}
}
template <typename Data>
 Data& QueueVec<Data>::Head()  {
if(head!=tail){
    return Elements[head];
}else{
    throw std::length_error("access to an empy queue");
}
}

//
template <typename Data>
 void QueueVec<Data>::Enqueue(const Data & dat){
    Expand();
    Elements[tail++]=dat;
    tail %= size;
 }

 template <typename Data>
 void QueueVec<Data>::Enqueue(Data && dat){
    Expand();
    Elements[tail++]=std::move(dat);
    tail %= size;
 }

 template <typename Data>
 Data QueueVec<Data>::HeadNDequeue(){
    if(head!= tail){
        Reduce();
        Data dat(std::move(Elements[head]));
        ++head%=size;
        return dat;
    }else{
        throw std::length_error("accesso a coda vuota"); 
           }
 }

template <typename Data>
 void QueueVec<Data>::Dequeue(){
if(head!= tail){
    Reduce();
    ++head%=size;
}else{
    throw std::length_error("accesso a coda vuota");
}
 }
template <typename Data>
 inline bool QueueVec<Data>::Empty()const noexcept{
    return (head==tail);
 }

 template <typename Data>
 inline ulong QueueVec<Data>::Size()const noexcept{
    return ((( size+tail ) - head) %size);
 }

 template <typename Data>
 void QueueVec<Data>::Clear(){
head=tail=0;
Vector<Data>::Resize(4);
 }


template <typename Data>
QueueVec<Data>::QueueVec(const QueueVec<Data> & queue) : Vector<Data>(queue), head(queue.head), tail(queue.tail) {}


template <typename Data>
QueueVec<Data>::QueueVec(QueueVec<Data> && queue) noexcept : Vector<Data>(std::move(queue)){
    std::swap(head,queue.head);
    std::swap(tail,queue.tail);
}


//dubbi 
template <typename Data>
void QueueVec<Data>::Expand() {
    if ((tail + 1) % size == head) {
        Resize(size * 2, size);
    }
}

template <typename Data>
void QueueVec<Data>::Reduce() {
    if (Size() <= size / 4 && size > 4) {
        Resize(size / 2, size);
    }
}
template <typename Data>
void QueueVec<Data>::Resize(ulong newSize, ulong oldSize) {
    Data* newElements = new Data[newSize];

    for (ulong i = 0, j = head; i < Size(); ++i, ++j %= oldSize) {
        newElements[i] = std::move(Elements[j]);
    }

    delete[] Elements;
    Elements = newElements;
    size = newSize;
    head = 0;
    tail = Size();
}

};