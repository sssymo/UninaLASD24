
#ifndef QUEUE_HPP
#define QUEUE_HPP

/* ************************************************************************** */

#include "../container/container.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class Queue : virtual public ClearableContainer  {
  // Must extend ClearableContainer

private:

  // ...

protected:

  // ...

public:

  // Destructor
  // ~Queue() specifiers
virtual ~Queue() = default;
  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument); // Copy assignment of abstract types is not possible.
  
    Queue & operator=(const Queue&) = delete; 

  

  // Move assignment
  // type operator=(argument); // Move assignment of abstract types is not possible.
    Queue & operator=(Queue&&) noexcept = delete; 

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers; // Comparison of abstract types is not possible.
  // type operator!=(argument) specifiers; // Comparison of abstract types is not possible.
    bool operator==(const Queue&) const noexcept = delete; 
    bool operator!=(const Queue&) const noexcept = delete; 

  /* ************************************************************************ */

  // Specific member functions

  // type Head() specifiers; // (non-mutable version; concrete function must throw std::length_error when empty)
  // type Head() specifiers; // (mutable version; concrete function must throw std::length_error when empty)
  // type Dequeue() specifiers; // (concrete function must throw std::length_error when empty)
  // type HeadNDequeue() specifiers; // (concrete function must throw std::length_error when empty)
  // type Enqueue(argument) specifiers; // Copy of the value
  // type Enqueue(argument) specifiers; // Move of the value
    virtual const Data& Head() const = 0;
    virtual Data& Head() = 0;
    virtual void Dequeue() = 0; 
    virtual Data HeadNDequeue() = 0; 
    virtual void Enqueue(const Data&) = 0; 
    virtual void Enqueue(Data&&) = 0; 
};

/* ************************************************************************** */

}

#endif
