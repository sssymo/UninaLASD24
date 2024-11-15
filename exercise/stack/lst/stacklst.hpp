#ifndef STACKLST_HPP
#define STACKLST_HPP

/* ************************************************************************** */

#include "../stack.hpp"
#include "../../list/list.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class StackLst :virtual public Stack<Data>, virtual public List<Data>{
  // Must extend Stack<Data>,
  //             List<Data>

private:

  // ...

protected:

  // using List<Data>::???;
//ndsulla
  // ...

public:

  // Default constructor
  // StackLst() specifier;
inline StackLst()=default;
  /* ************************************************************************ */

  // Specific constructor
  // StackLst(argument) specifiers; // A stack obtained from a TraversableContainer
  // StackLst(argument) specifiers; // A stack obtained from a MappableContainer
StackLst(const TraversableContainer<Data> & con):List<Data>(con){};
StackLst(MappableContainer<Data> && con): List<Data>(std::move(con)){};
  /* ************************************************************************ */

  // Copy constructor
  // StackLst(argument);
inline StackLst(const StackLst & stk):List<Data>(stk){};
  // Move constructor
  // StackLst(argument);
inline StackLst( StackLst && stk):List<Data>(std::move(stk)){};
  /* ************************************************************************ */

  // Destructor
  // ~StackLst() specifier;
virtual ~StackLst() =default;
  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument);
  StackLst& operator=(const StackLst& stk);


  // Move assignment
  // type operator=(argument);

  StackLst& operator=(StackLst&& stk) noexcept;
  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  // type operator!=(argument) specifiers;
  bool operator==(const StackLst& stk) const noexcept;
  bool operator!=(const StackLst& stk) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from Stack)

  // type Top() specifiers; // Override Stack member (non-mutable version; must throw std::length_error when empty)
  // type Top() specifiers; // Override Stack member (non-mutable version; must throw std::length_error when empty)
  // type Pop() specifiers; // Override Stack member (must throw std::length_error when empty)
  // type TopNPop() specifiers; // Override Stack member (must throw std::length_error when empty)
  // type Push(argument) specifiers; // Override Stack member (copy of the value)
  // type Push(argument) specifiers; // Override Stack member (move of the value)
  const Data& Top() const override;

  Data& Top() override;


  void Pop() override;

Data TopNPop() override;

void Push(const Data& value) override;

 void Push(Data&& value) override;
  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  // using List<Data>::Clear;
using List<Data>::Clear;
protected:

  // Auxiliary functions, if necessary!

};

/* ************************************************************************** */

}

#include "stacklst.cpp"

#endif
