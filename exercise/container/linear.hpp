
#ifndef LINEAR_HPP
#define LINEAR_HPP

/* ************************************************************************** */

#include "mappable.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class LinearContainer : virtual public PreOrderMappableContainer<Data>,
        virtual public PostOrderMappableContainer<Data>{
  // Must extend PreOrderMappableContainer<Data>,
  //             PostOrderMappableContainer<Data>

private:

  // ...

protected:
using Container::size;
  // ...

public:

  // Destructor
  // ~LinearContainer() specifiers
virtual ~LinearContainer() = default;
  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument); // Copy assignment of abstract types is not possible.
            LinearContainer & operator=(const LinearContainer &) = delete;
        
  // Move assignment
  // type operator=(argument); // Move assignment of abstract types is not possible.
LinearContainer & operator=( LinearContainer &&)noexcept = delete;
  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers; // Comparison of abstract types is possible.
  // type operator!=(argument) specifiers; // Comparison of abstract types is possible.
            inline bool operator==(const LinearContainer &) const noexcept;
            inline bool operator!=(const LinearContainer &) const noexcept;

  /* ************************************************************************ */

  // Specific member functions

  // type operator[](argument) specifiers; // (non-mutable version; concrete function must throw std::out_of_range when out of range)
  // type operator[](argument) specifiers; // (mutable version; concrete function must throw std::out_of_range when out of range)
            virtual const Data & operator[](ulong) const = 0;
            virtual Data & operator[](ulong) = 0;
  // type Front() specifiers; // (non-mutable version; concrete function must throw std::length_error when empty)
  // type Front() specifiers; // (mutable version; concrete function must throw std::length_error when empty)
            inline virtual const Data & Front() const;
            inline virtual Data & Front();
  // type Back() specifiers; // (non-mutable version; concrete function must throw std::length_error when empty)
  // type Back() specifiers; // (mutable version; concrete function must throw std::length_error when empty)
            inline virtual const Data & Back() const;
            inline virtual Data & Back();
  /* ************************************************************************ */

  // Specific member function (inherited from TraversableContainer)

  // using typename TraversableContainer<Data>::TraverseFun;
using typename TraversableContainer<Data>::TraverseFun;
  // type Traverse(argument) specifiers; // Override TraversableContainer member
inline void Traverse(TraverseFun) const override;
  /* ************************************************************************ */

  // Specific member function (inherited from PreOrderTraversableContainer)

           
  // type PreOrderTraverse(argument) specifiers; // Override PreOrderTraversableContainer member
            inline void PreOrderTraverse(TraverseFun) const override;
            
  /* ************************************************************************ */

  // Specific member function (inherited from PostOrderTraversableContainer)
// type PostOrderTraverse(argument) specifiers; // Override PostOrderTraversableContainer member
            inline void PostOrderTraverse(TraverseFun) const override;
  
  /* ************************************************************************ */

  // Specific member function (inherited from MappableContainer)

  // using typename MappableContainer<Data>::MapFun;
using typename MappableContainer<Data>::MapFun;
  // type Map(argument) specifiers; // Override MappableContainer member
inline void Map(MapFun) override;
  /* ************************************************************************ */

  // Specific member function (inherited from PreOrderMappableContainer)

  // type PreOrderMap(argument) specifiers; // Override PreOrderMappableContainer member
inline void PreOrderMap(MapFun)  override;
  /* ************************************************************************ */

  // Specific member function (inherited from PostOrderMappableContainer)

  // type PostOrderMap(argument) specifiers; // Override PostOrderMappableContainer member
inline void PostOrderMap(MapFun)  override;
};

/* ************************************************************************** */

template <typename Data>
class SortableLinearContainer : virtual public LinearContainer<Data> {
  // Must extend LinearContainer<Data>

private:

  // ...

protected:

            using Container::size;
            using LinearContainer<Data>::operator[];
  // ...

public:

  // Destructor
  // ~SortableLinearContainer() specifiers
 virtual ~SortableLinearContainer() = default;
  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument); // Copy assignment of abstract types is not possible.
        SortableLinearContainer & operator=(const SortableLinearContainer) = delete;

  // Move assignment
  // type operator=(argument); // Move assignment of abstract types is not be possible.
        SortableLinearContainer & operator=(SortableLinearContainer &&) = delete;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers; // Comparison of abstract types is possible.
  // type operator!=(argument) specifiers; // Comparison of abstract types is possible.
        inline bool operator==(const SortableLinearContainer &) const noexcept;
        inline bool operator!=(const SortableLinearContainer &) const noexcept;
   
  /* ************************************************************************ */

  // Specific member function

  // type Sort() specifiers;

    virtual void Sort() noexcept;
    ulong Partition(ulong p, ulong r) noexcept;
void QuickSort(ulong p, ulong r) noexcept;
protected:

  // Auxiliary member functions
    
    

  // ...
    

};

/* ************************************************************************** */

}

#include "linear.cpp"

#endif