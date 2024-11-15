
#ifndef STACK_HPP
#define STACK_HPP

/* ************************************************************************** */

#include "../container/container.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class Stack : virtual public ClearableContainer{
  // Must extend ClearableContainer

private:

  // ...

protected:

  // ...

public:

  // Destructor
  // ~Stack() specifiers
  virtual ~Stack() noexcept = default;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument); // Copy assignment of abstract types is not possible.
Stack & operator=(const Stack&) noexcept= delete;
  // Move assignment
  // type operator=(argument); // Move assignment of abstract types is not possible.
 Stack & operator=(Stack&&)  noexcept= delete;
  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers; // Comparison of abstract types is not possible.
  // type operator!=(argument) specifiers; // Comparison of abstract types is not possible.
 bool operator==(const Stack&) const noexcept = delete;
  bool operator!=(const Stack&) const noexcept = delete;
  /* ************************************************************************ */

  // Specific member functions

  // type Top() specifiers; // (non-mutable version; concrete function must throw std::length_error when empty)
  // type Top() specifiers; // (mutable version; concrete function must throw std::length_error when empty)
  // type Pop() specifiers; // (concrete function must throw std::length_error when empty)
  // type TopNPop() specifiers; // (concrete function must throw std::length_error when empty)
  // type Push(argument) specifiers; // Copy of the value
  // type Push(argument) specifiers; // Move of the value
virtual const Data & Top() const = 0;
virtual Data & Top() = 0;
  virtual void Pop() = 0;
  virtual Data TopNPop() = 0;
  virtual void Push(const Data&) = 0;
  virtual void Push(Data&&) = 0;

};

/* ************************************************************************** */

}

#endif
