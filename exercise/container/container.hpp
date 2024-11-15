
#ifndef CONTAINER_HPP
#define CONTAINER_HPP

/* ************************************************************************** */
#include <cstddef>
namespace lasd {

/* ************************************************************************** */

class Container {

private:

  // ...

protected:

  // ...

  /* ************************************************************************ */
unsigned long size=0;
  // Default constructor
  // Container() specifiers;

public:

  // Destructor
  // ~Container() specifiers
virtual ~Container() = default;
  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument); // Copy assignment of abstract types is not possible.
Container & operator=(const Container &)=delete;
  // Move assignment
  // type operator=(argument); // Move assignment of abstract types is not possible.
Container & operator=( Container && )noexcept=delete;
  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers; // Comparison of abstract types is not possible.
  // type operator!=(argument) specifiers; // Comparison of abstract types is not possible.
bool operator==(const Container &)const noexcept=delete;
bool operator!=(const Container &)const noexcept=delete;
  /* ************************************************************************ */

  // Specific member functions

  // type Empty() specifiers; // (concrete function should not throw exceptions)
virtual inline bool Empty()const noexcept{return(size==0);};
  // type Size() specifiers; // (concrete function should not throw exceptions)
virtual inline unsigned long Size()const noexcept {return size;}
};

/* ************************************************************************** */

class ClearableContainer: public virtual Container {
  // Must extend Container

private:

  // ...

protected:

  // ...

public:

  // Destructor
  // ~ClearableContainer() specifiers
virtual ~ClearableContainer() noexcept = default;
  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument); // Copy assignment of abstract types is not possible.
 ClearableContainer & operator=(const ClearableContainer &) = delete;
  // Move assignment
  // type operator=(argument); // Move assignment of abstract types is not possible.
  ClearableContainer & operator=(ClearableContainer &&) noexcept = delete;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers; // Comparison of abstract types is not possible.
  // type operator!=(argument) specifiers; // Comparison of abstract types is not possible.
  bool operator==(const ClearableContainer &) const noexcept = delete;
  bool operator!=(const ClearableContainer &) const noexcept = delete;


  /* ************************************************************************ */

  // Specific member functions

  // type Clear() specifiers;
 virtual void Clear() = 0;
};

/* ************************************************************************** */

class ResizableContainer : public virtual ClearableContainer{
  // Must extend ClearableContainer

private:

  // ...

protected:

  // ...

public:

  // Destructor
  // ~ResizableContainer() specifiers
virtual ~ResizableContainer() noexcept = default;
  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument); // Copy assignment of abstract types is not possible.
  ResizableContainer & operator=(const ResizableContainer &) = delete;

  // Move assignment
  // type operator=(argument); // Move assignment of abstract types is not possible.
  ResizableContainer & operator=(ResizableContainer &&) noexcept = delete;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers; // Comparison of abstract types is not possible.
  // type operator!=(argument) specifiers; // Comparison of abstract types is not possible.
  bool operator==(const ResizableContainer &) const noexcept = delete;
  bool operator!=(const ResizableContainer &) const noexcept = delete;

  /* ************************************************************************ */

  // Specific member functions

  // type Resize(argument) specifiers;
virtual void Resize(size_t) = 0;
  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  // type Clear() specifiers; // Override ClearableContainer member
virtual void Clear() =0 ;
};

/* ************************************************************************** */

}

#endif
