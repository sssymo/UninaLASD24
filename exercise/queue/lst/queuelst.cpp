#include "queuelst.hpp"
namespace lasd {

/* ************************************************************************** */

// ...

/* ************************************************************************** */


template<typename Data>
const Data& QueueLst<Data>::Head() const {
    if (List<Data>::Size() == 0) {
        throw std::length_error("accesso a coda vuota");
    }
    return List<Data>::Front();
}

template<typename Data>
Data& QueueLst<Data>::Head() {
    if (List<Data>::Size() == 0) {
        throw std::length_error("accesso a coda vuota");
    }
    return List<Data>::Front();
}

template<typename Data>
void QueueLst<Data>::Dequeue() {
    if (List<Data>::Size() == 0) {
        throw std::length_error("dequeue from an empty queue");
    }
    List<Data>::RemoveFromFront();
}

template<typename Data>
Data QueueLst<Data>::HeadNDequeue() {
    return List<Data>::FrontNRemove();
}

template<typename Data>
void QueueLst<Data>::Enqueue(const Data& value) {
    return List<Data>::InsertAtBack(value);
}

template<typename Data>
void QueueLst<Data>::Enqueue(Data&& value) {
    return List<Data>::InsertAtBack(value);
}

//copy asss
template<typename Data>
QueueLst<Data>& QueueLst<Data>::operator=(const QueueLst<Data>& queue) {
    List<Data>::operator=(queue);
    return *this;
}

// Move assignment
template<typename Data>
QueueLst<Data>& QueueLst<Data>::operator=(QueueLst<Data>&& queue) noexcept {
    List<Data>::operator=(std::move(queue));
    return *this;
}

template<typename Data>
bool QueueLst<Data>::operator==(const QueueLst<Data>& queue) const noexcept {
    return static_cast<const List<Data>&>(*this) == static_cast<const List<Data>&>(queue);
}

template<typename Data>
bool QueueLst<Data>::operator!=(const QueueLst<Data>& queue) const noexcept {
    return !(*this == queue);
}
}
