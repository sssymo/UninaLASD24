
#ifndef BST_HPP
#define BST_HPP

/* ************************************************************************** */

#include "../binarytree/lnk/binarytreelnk.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class BST : virtual public ClearableContainer,
virtual public DictionaryContainer<Data>,
 virtual public BinaryTree<Data>, 
  virtual public BinaryTreeLnk<Data>  {
  // Must extend ClearableContainer,
  //             DictionaryContainer<Data>,
  //             BinaryTree<Data>,
  //             BinaryTreeLnk<Data>

private:

  // ...

protected:

  // using BinaryTreeLnk<Data>::???;
    using BinaryTreeLnk<Data>::size;
  using typename BinaryTreeLnk<Data>::NodeLnk;

  using BinaryTreeLnk<Data>::root;

public:

  // Default constructor
  // BST() specifiers;
BST() = default;
  /* ************************************************************************ */

  // Specific constructors
  // BST(argument) specifiers; // A bst obtained from a TraversableContainer
  // BST(argument) specifiers; // A bst obtained from a MappableContainer
BST(const TraversableContainer<Data>&) noexcept;
BST(MappableContainer<Data>&&) noexcept;
  /* ************************************************************************ */

  // Copy constructor
  // BST(argument) specifiers;
BST(const BST&) ;
  // Move constructor
  // BST(argument) specifiers;
BST(BST&&) noexcept;
  /* ************************************************************************ */

  // Destructor
  // ~BST() specifiers;
 ~BST() = default;
  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument) specifiers;
BST& operator=(const BST<Data>&);
  // Move assignment
  // type operator=(argument) specifiers;
BST& operator=(BST<Data>&&) noexcept;
  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  // type operator!=(argument) specifiers;
  bool operator==(const BST<Data>&) const noexcept;
bool operator!=(const BST<Data>&) const noexcept;
  /* ************************************************************************ */

  // Specific member functions

  // type Min(argument) specifiers; // (concrete function must throw std::length_error when empty)
  // type MinNRemove(argument) specifiers; // (concrete function must throw std::length_error when empty)
  // type RemoveMin(argument) specifiers; // (concrete function must throw std::length_error when empty)
const Data& Min() const;
Data MinNRemove();
void RemoveMin();
  // type Max(argument) specifiers; // (concrete function must throw std::length_error when empty)
  // type MaxNRemove(argument) specifiers; // (concrete function must throw std::length_error when empty)
  // type RemoveMax(argument) specifiers; // (concrete function must throw std::length_error when empty)
const Data& Max() const;
Data MaxNRemove();
void RemoveMax();
  // type Predecessor(argument) specifiers; // (concrete function must throw std::length_error when not found)
  // type PredecessorNRemove(argument) specifiers; // (concrete function must throw std::length_error when not found)
  // type RemovePredecessor(argument) specifiers; // (concrete function must throw std::length_error when not found)
const Data& Predecessor(const Data&) const;
Data PredecessorNRemove(const Data&);
void RemovePredecessor(const Data&);
  // type Successor(argument) specifiers; // (concrete function must throw std::length_error when not found)
  // type SuccessorNRemove(argument) specifiers; // (concrete function must throw std::length_error when not found)
  // type RemoveSuccessor(argument) specifiers; // (concrete function must throw std::length_error when not found)
const Data& Successor(const Data&) const;
Data SuccessorNRemove(const Data&);
void RemoveSuccessor(const Data&);
  /* ************************************************************************ */

  // Specific member function (inherited from BinaryTree)

  // type Root(argument) specifiers; // Override BinaryTree member
 NodeLnk& Root() const override;
  /* ************************************************************************ */

  // Specific member functions (inherited from DictionaryContainer)

  // type Insert(argument) specifiers; // Override DictionaryContainer member (Copy of the value)
  // type Insert(argument) specifiers; // Override DictionaryContainer member (Move of the value)
  // type Remove(argument) specifiers; // Override DictionaryContainer member
bool Insert(const Data&) override;
bool Insert(Data&&) override; 
bool Remove(const Data&) override;
  /* ************************************************************************ */

  // Specific member functions (inherited from TestableContainer)

  // type Exists(argument) specifiers; // Override TestableContainer member
bool Exists(const Data&) const  noexcept override ;
  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  // type Clear(argument) specifiers; // Override ClearableContainer member
void Clear() noexcept override ;
protected:

  // Auxiliary functions, if necessary!

  // type DataNDelete(argument) specifiers;
 void DataNDelete(NodeLnk&) noexcept;
  // type Detach(argument) specifiers;
  NodeLnk*  Detach(NodeLnk*&) noexcept;
  NodeLnk* DetachMin(NodeLnk*&) noexcept;
  NodeLnk*  DetachMax(NodeLnk*&) noexcept;
  // type DetachMin(argument) specifiers;
  // type DetachMax(argument) specifiers;
  

  // type Skip2Left(argument) specifiers;
  // type Skip2Right(argument) specifiers;
  NodeLnk*  Skip2Left(NodeLnk*&)  noexcept;
  NodeLnk* Skip2Right(NodeLnk*&) noexcept;
  // type FindPointerToMin(argument) specifiers; // Both mutable & unmutable versions
  // type FindPointerToMax(argument) specifiers; // Both mutable & unmutable versions
  NodeLnk*& FindPointerToMin(NodeLnk*&) noexcept;
  NodeLnk* const& FindPointerToMin(NodeLnk* const&)  const noexcept;
    NodeLnk*& FindPointerToMax(NodeLnk*&) noexcept;
  NodeLnk* const& FindPointerToMax(NodeLnk* const&)  const noexcept;
  // type FindPointerTo(argument) specifiers; // Both mutable & unmutable versions
  NodeLnk* const& FindPointerTo(NodeLnk* const&, const Data&)  const noexcept;
  NodeLnk*& FindPointerTo(NodeLnk*&, const Data&) noexcept;
  // type FindPointerToPredecessor(argument) specifiers; // Both mutable & unmutable versions
  // type FindPointerToSuccessor(argument) specifiers; // Both mutable & unmutable versions
  NodeLnk* const& FindPointerToPredecessor(NodeLnk* const&, const Data&) const noexcept;
  NodeLnk*& FindPointerToPredecessor(NodeLnk*&, const Data&) noexcept;
  NodeLnk* const& FindPointerToSuccessor(NodeLnk* const&,const Data&) const noexcept;
  NodeLnk*& FindPointerToSuccessor(NodeLnk*&, const Data&) noexcept;
};

/* ************************************************************************** */

}

#include "bst.cpp"

#endif
