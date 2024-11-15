#ifndef BINARYTREELNK_HPP
#define BINARYTREELNK_HPP

/* ************************************************************************** */

#include "../binarytree.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class BinaryTreeLnk :virtual public MutableBinaryTree<Data>, virtual public ClearableContainer {
  // Must extend MutableBinaryTree<Data>

private:

  // ...

protected:

  // using BinaryTree<Data>::???;
  using Container::size;

  // ...

  struct NodeLnk : virtual public MutableBinaryTree<Data>::MutableNode { // Must extend MutableNode

  private:

    // ...

  protected:

    // ...

  public:
  using BinaryTree<Data>::Node::operator==;
  using BinaryTree<Data>::Node::operator!=;
  using BinaryTree<Data>::Node::operator=;

        Data element;
        NodeLnk* left=nullptr;
        NodeLnk* right=nullptr;
        NodeLnk()=default;
        NodeLnk(const Data & dat)noexcept:element(dat){};
        NodeLnk(Data && dat) noexcept;
        NodeLnk(const NodeLnk &);
        NodeLnk(NodeLnk &&) noexcept;
        ~NodeLnk();
        NodeLnk& operator=(const NodeLnk& o);
NodeLnk& operator=(NodeLnk&& o) noexcept;
        bool operator==(const NodeLnk &) const noexcept;
        inline bool operator!=(const NodeLnk & )const noexcept;
        inline const Data & Element()const noexcept override;
        inline Data & Element( )noexcept override;
        inline bool IsLeaf() const noexcept override;

       inline bool HasLeftChild() const noexcept override;
       inline bool HasRightChild() const noexcept override;

    NodeLnk& LeftChild() const override;
    NodeLnk& RightChild() const override;

    // ...

  };
    using typename BinaryTree<Data>::Node;
  using typename MutableBinaryTree<Data>::MutableNode;
 NodeLnk* root = nullptr;

public:


  // Default constructor
  // BinaryTreeLnk() specifiers;
BinaryTreeLnk() = default;
  /* ************************************************************************ */

  // Specific constructors
  // BinaryTreeLnk(argument) specifiers; // A binary tree obtained from a TraversableContainer
  // BinaryTreeLnk(argument) specifiers; // A binary tree obtained from a MappableContainer

BinaryTreeLnk(const TraversableContainer<Data>&) ;
BinaryTreeLnk( MappableContainer<Data>&&) ; 
  /* ************************************************************************ */

  // Copy constructor
  // BinaryTreeLnk(argument) specifiers;
BinaryTreeLnk(const BinaryTreeLnk&) noexcept;
  // Move constructor
  // BinaryTreeLnk(argument) specifiers;
BinaryTreeLnk(BinaryTreeLnk&&) noexcept;
  /* ************************************************************************ */

  // Destructor
  // ~BinaryTreeLnk() specifiers;
~BinaryTreeLnk() ;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument) specifiers;
BinaryTreeLnk& operator=(const BinaryTreeLnk&) noexcept;
  // Move assignment
  // type operator=(argument) specifiers;
BinaryTreeLnk& operator=(BinaryTreeLnk&&) noexcept;
  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  // type operator!=(argument) specifiers;
bool operator==(const BinaryTreeLnk&) const noexcept;
bool operator!=(const BinaryTreeLnk&) const noexcept;
  /* ************************************************************************ */

  // Specific member functions (inherited from BinaryTree)

  // type Root() specifiers; // Override BinaryTree member (throw std::length_error when empty)
NodeLnk& Root() const override;
  /* ************************************************************************ */

  // Specific member function (inherited from MutableBinaryTree)

typename BinaryTreeLnk<Data>::MutableNode &Root();

// type Root() specifiers; // Override MutableBinaryTree member (throw std::length_error when empty)

/* ************************************************************************ */

// Specific member function (inherited from ClearableContainer)

// type Clear() specifiers; // Override ClearableContainer member
void Clear() noexcept override;
};

/* ************************************************************************** */

}

#include "binarytreelnk.cpp"

#endif
