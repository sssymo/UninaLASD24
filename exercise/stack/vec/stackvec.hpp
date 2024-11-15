
#ifndef STACKVEC_HPP
#define STACKVEC_HPP

/* ************************************************************************** */

#include "../stack.hpp"
#include "../../vector/vector.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class StackVec : virtual public Stack<Data>, virtual public Vector<Data>{
  // Must extend Stack<Data>,
  //             Vector<Data>

private:

  // ...

protected:

  // using Vector<Data>::???;
ulong index=0;
using Vector<Data>::size;
using Vector<Data>::Elements;
  // ...

public:

  // Default constructor
  // StackVec() specifier;
StackVec() :Vector<Data>(1){};
  /* ************************************************************************ */

  // Specific constructor
  // StackVec(argument) specifiers; // A stack obtained from a TraversableContainer
  // StackVec(argument) specifiers; // A stack obtained from a MappableContainer
StackVec(const TraversableContainer<Data> & con) : Vector<Data>(con),index(size){};
StackVec(MappableContainer<Data> && con) : Vector<Data>(std::move(con)),index(size){};
  /* ************************************************************************ */

  // Copy constructor
  // StackVec(argument);
StackVec(const StackVec & stk ): Vector<Data>(stk), index(stk.index){};
  // Move constructor
  // StackVec(argument);
StackVec(StackVec &&)noexcept;
  /* ************************************************************************ */

  // Destructor
  // ~StackVec() specifier;
virtual ~StackVec()=default; 
  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument);
StackVec & operator=(const StackVec &);
  // Move assignment
  // type operator=(argument);
StackVec & operator=( StackVec &&) noexcept;
  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  // type operator!=(argument) specifiers;
bool operator==(const StackVec &) const noexcept;
inline bool operator!=(const StackVec &) const noexcept;
  /* ************************************************************************ */

  // Specific member functions (inherited from Stack)

  // type Top() specifiers; // Override Stack member (non-mutable version; must throw std::length_error when empty)
  // type Top() specifiers; // Override Stack member (non-mutable version; must throw std::length_error when empty)
  // type Pop() specifiers; // Override Stack member (must throw std::length_error when empty)
  // type TopNPop() specifiers; // Override Stack member (must throw std::length_error when empty)
  // type Push(argument) specifiers; // Override Stack member (copy of the value)
  // type Push(argument) specifiers; // Override Stack member (move of the value)

  const Data & Top()const override;
  Data & Top() override;
  void Pop() override;
Data TopNPop() override;
void Push(const Data &) override;
void Push(Data &&) override;

  /* ************************************************************************ */

  // Specific member functions (inherited from Container)

  // type Empty() specifiers; // Override Container member
inline bool Empty() const noexcept override;
  // type Size() specifiers; // Override Container member
inline ulong Size() const noexcept override;
  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  // type Clear() specifiers; // Override ClearableContainer member
void Clear() override;
protected:

  // Auxiliary functions, if necessary!
void Expand();
void Reduce();
};

/* ************************************************************************** */

}

#include "stackvec.cpp"

#endif
