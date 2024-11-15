#ifndef QUEUEVEC_HPP
#define QUEUEVEC_HPP

/* ************************************************************************** */

#include "../queue.hpp"
#include "../../vector/vector.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class QueueVec :virtual public  Queue<Data>,virtual public Vector<Data>{
  // Must extend Queue<Data>,
  //             Vector<Data>

private:

  // ...

protected:

  // using Vector<Data>::???;
ulong head=0;
ulong tail=0;
using Vector<Data>::size;
using Vector<Data>::Elements;
  // ...

public:

  // Default constructor
  // QueueVec() specifier;
QueueVec() : Vector<Data>(4){};
  /* ************************************************************************ */

  // Specific constructor
  // QueueVec(argument) specifiers; // A stack obtained from a TraversableContainer
  // QueueVec(argument) specifiers; // A stack obtained from a MappableContainer

  QueueVec(const  TraversableContainer<Data> &);
  QueueVec(  MappableContainer<Data> &&);
  /* ************************************************************************ */

  // Copy constructor
  // QueueVec(argument);

  // Move constructor
  // QueueVec(argument);

  QueueVec(const QueueVec&);

  QueueVec(QueueVec&&) noexcept;
  /* ************************************************************************ */

  // Destructor
  // ~QueueVec() specifier;
  ~QueueVec()=default;
  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument);
  QueueVec & operator=(const QueueVec&);
  // Move assignment
  // type operator=(argument);

  QueueVec & operator=(QueueVec &&) noexcept;
  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  // type operator!=(argument) specifiers;
 bool operator==(const QueueVec&) const noexcept;
  inline bool operator!=(const QueueVec&) const noexcept;
  /* ************************************************************************ */

  // Specific member functions (inherited from Queue)

  // type Head() specifiers; // Override Queue member (non-mutable version; must throw std::length_error when empty)
  // type Head() specifiers; // Override Queue member (mutable version; must throw std::length_error when empty)
  // type Dequeue() specifiers; // Override Queue member (must throw std::length_error when empty)
  // type HeadNDequeue() specifiers; // Override Queue member (must throw std::length_error when empty)
  // type Enqueue(argument) specifiers; // Override Queue member (copy of the value)
  // type Enqueue(argument) specifiers; // Override Queue member (move of the value)


  const Data & Head() const override;
  Data & Head() override;

  void Dequeue() override;

  Data HeadNDequeue() override;

void Enqueue(const Data &) override;
void Enqueue(Data && )override;
  /* ************************************************************************ */

  // Specific member functions (inherited from Container)

  // type Empty() specifiers; // Override Container member
inline bool Empty()const noexcept override;
  // type Size() specifiers; // Override Container member
inline ulong Size() const noexcept override;
  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  // type Clear() specifiers; // Override ClearableContainer member
void Clear()override;
protected:

  // Auxiliary functions, if necessary!
void Expand();
void Reduce();
void Resize(ulong , ulong);
};

/* ************************************************************************** */

}

#include "queuevec.cpp"

#endif
