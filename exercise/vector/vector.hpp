
#ifndef VECTOR_HPP
#define VECTOR_HPP

/* ************************************************************************** */

#include "../container/container.hpp"


/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class Vector : virtual public ResizableContainer,
        virtual public LinearContainer<Data> {
  // Must extend ResizableContainer,
  //             LinearContainer<Data>

private:

  // ...

protected:

  // using Container::???;

        using Container::size;

        Data * Elements = nullptr;
  // ...

public:

  // Default constructor
  // Vector() specifiers;
Vector()=default;
  /* ************************************************************************ */

    

    // Specific constructors
    // Vector(argument) specifiers; // A vector with a given initial dimension
    // Vector(argument) specifiers; // A vector obtained from a TraversableContainer
    // Vector(argument) specifiers; // A vector obtained from a MappableContainer
    Vector(MappableContainer<Data> &&con);

    
    Vector(const TraversableContainer<Data> &con);
    Vector(const unsigned long newsize);
    /* ************************************************************************ */

    // Copy constructor
    // Vector(argument) specifiers;
Vector(const Vector &);

    // Move constructor
    // Vector(argument) specifiers;
Vector(Vector &&)noexcept;

    /* ************************************************************************ */

    // Destructor
    // ~Vector() specifiers;
~Vector();
    /* ************************************************************************ */

    // Copy assignment
    // type operator=(argument) specifiers;
Vector & operator=(const Vector &);
    // Move assignment
    // type operator=(argument) specifiers;
Vector & operator=(Vector &&) noexcept;
    /* ************************************************************************ */

    // Comparison operators
    // type operator==(argument) specifiers;
    // type operator!=(argument) specifiers;
    bool operator==(const Vector &) const noexcept;
    inline bool operator!=(const Vector &) const noexcept;
    /* ************************************************************************ */

    // Specific member function (inherited from ClearableContainer)

    // type Clear() specifiers; // Override ClearableContainer member
    void Clear() override;
    /* ************************************************************************ */

    // Specific member function (inherited from ResizableContainer)

    // type Resize(argument) specifiers; // Override ResizableContainer member
    void Resize(const ulong) override;
    /* ************************************************************************ */

    // Specific member functions (inherited from LinearContainer)

    // type operator[](argument) specifiers; // Override (NonMutable) LinearContainer member (must throw std::out_of_range when out of range)
    // type operator[](argument) specifiers; // Override (Mutable) LinearContainer member (must throw std::out_of_range when out of range)
    const Data & operator[]( ulong) const override;
    Data & operator[]( ulong) override;
  // type Front() specifiers; // Override (NonMutable) LinearContainer member (must throw std::length_error when empty)
  // type Front() specifiers; // Override (Mutable) LinearContainer member (must throw std::length_error when empty)
    const Data & Front() const override;
    Data & Front() override;
  // type Back() specifiers; // Override (NonMutable) LinearContainer member (must throw std::length_error when empty)
  // type Back() specifiers; // Override (Mutable) LinearContainer member (must throw std::length_error when empty)
    const Data & Back() const override;
    Data & Back() override;
protected:

  // Auxiliary functions, if necessary!

    
};

/* ************************************************************************** */

template <typename Data>
class SortableVector : virtual public Vector<Data> , virtual public SortableLinearContainer<Data>{
  // Must extend Vector<Data>,
  //             SortableLinearContainer<Data>

private:

  // ...

protected:

  // using Container::???;
 
  // ...

public:

  // Default constructor
  // SortableVector() specifiers;
 SortableVector()=default;

  /* ************************************************************************ */

  // Specific constructors
  // SortableVector(argument) specifiers; // A vector with a given initial dimension
  // SortableVector(argument) specifiers; // A vector obtained from a TraversableContainer
  // SortableVector(argument) specifiers; // A vector obtained from a MappableContainer

  /* ************************************************************************ */

  SortableVector(const ulong newsize);

  SortableVector(const TraversableContainer<Data> &con);

  SortableVector(MappableContainer<Data> && con);

  // Copy constructor
  // SortableVector(argument) specifiers;
  SortableVector(const SortableVector &);
  // Move constructor
  // SortableVector(argument) specifiers;
SortableVector(SortableVector &&) noexcept;
  /* ************************************************************************ */

  // Destructor
  // ~SortableVector() specifiers;
~SortableVector()=default;
  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument) specifiers;
SortableVector & operator=(const SortableVector &);
  // Move assignment
  // type operator=(argument) specifiers;
SortableVector & operator=(SortableVector &&) noexcept;

void Resize(const ulong newSize)override ;

void Clear()override;

protected:

  // Auxiliary functions, if necessary!

};

/* ************************************************************************** */

}

#include "vector.cpp"

#endif
