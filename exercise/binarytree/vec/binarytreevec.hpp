#ifndef BINARYTREEVEC_HPP
#define BINARYTREEVEC_HPP

/* ************************************************************************** */

#include "../binarytree.hpp"
#include "../../vector/vector.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class BinaryTreeVec : virtual public MutableBinaryTree<Data> {
  // Must extend MutableBinaryTree<Data>

private:

  // ...

protected:
 using Container::size;
  // ...
   
  using typename BinaryTree<Data>::Node;
  using typename MutableBinaryTree<Data>::MutableNode;
  struct NodeVec : virtual public MutableBinaryTree<Data>::MutableNode { // Must extend MutableNode

  private:

    // ...

  protected:

    // ...

  public:

    // ...
    ulong indexCurrNode;
    Data element;
    using typename BinaryTree<Data>::Node::operator=;
    using BinaryTree<Data>::Node::operator==;
    using BinaryTree<Data>::Node::operator!=;
    Vector<NodeVec*> *v;

    Data& Element() noexcept ;
    const Data& Element() const noexcept ;
    bool IsLeaf() const noexcept ;
    bool HasLeftChild() const noexcept ;
    bool HasRightChild() const noexcept ;
    NodeVec& LeftChild() const ;
    NodeVec& RightChild() const  ;
NodeVec()=default;

        NodeVec(const Data & dat)noexcept:element(dat){};
        
        NodeVec(const NodeVec &);
        NodeVec(NodeVec &&) noexcept;
        NodeVec &operator=(const NodeVec &node);
        bool operator==(const NodeVec &node) const noexcept;
        bool operator!=(const NodeVec &node) const noexcept;
        NodeVec &operator=(NodeVec &&node) noexcept;
        ~NodeVec() = default;
  };
 Vector<NodeVec*> vector;
public:

  // Default constructor
  // BinaryTreeVec() specifiers;
 BinaryTreeVec() =default;
  /* ************************************************************************ */

  // Specific constructors
  // BinaryTreeVec(argument) specifiers; // A binary tree obtained from a TraversableContainer
  // BinaryTreeVec(argument) specifiers; // A binary tree obtained from a MappableContainer
BinaryTreeVec(const TraversableContainer<Data>&) noexcept;
BinaryTreeVec( MappableContainer<Data>&&) noexcept;
  /* ************************************************************************ */

  // Copy constructor
  // BinaryTreeVec(argument) specifiers;
BinaryTreeVec(const BinaryTreeVec&) ;
  // Move constructor
  // BinaryTreeVec(argument) specifiers;
BinaryTreeVec(BinaryTreeVec&&) noexcept;
  /* ************************************************************************ */

  // Destructor
  // ~BinaryTreeVec() specifiers;
~BinaryTreeVec() ;
  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument) specifiers;
BinaryTreeVec& operator=(const BinaryTreeVec&) ;

  // Move assignment
  // type operator=(argument) specifiers;
BinaryTreeVec& operator=(BinaryTreeVec&&)noexcept ;
  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  // type operator!=(argument) specifiers;
bool operator==(const BinaryTreeVec<Data>&) const noexcept;

bool operator!=(const BinaryTreeVec<Data>&) const noexcept;
  /* ************************************************************************ */

  // Specific member functions (inherited from BinaryTree)

  // type Root() specifiers; // Override BinaryTree member (throw std::length_error when empty)
 NodeVec& Root() const override;
  /* ************************************************************************ */

  // Specific member function (inherited from MutableBinaryTree)

  // type Root() specifiers; // Override MutableBinaryTree member (throw std::length_error when empty)
typename BinaryTreeVec<Data>::MutableNode & Root();

  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  // type Clear() specifiers; // Override ClearableContainer member
  void Clear() override;
  /* ************************************************************************ */

  // Specific member function (inherited from BreadthTraversableContainer)
 using typename TraversableContainer<Data>::TraverseFun;
  // type BreadthTraverse(arguments) specifiers; // Override BreadthTraversableContainer member
void BreadthTraverse(TraverseFun) const;
  /* ************************************************************************ */

  // Specific member function (inherited from BreadthMappableContainer)
using typename MappableContainer<Data>::MapFun;
using MutableBinaryTree<Data>::BreadthMap;
  // type BreadthMap(arguments) specifiers; // Override BreadthMappableContainer member
void BreadthMap(MapFun) const;
protected:

  // Auxiliary functions, if necessary!

};

/* ************************************************************************** */

}

#include "binarytreevec.cpp"

#endif
