#ifndef BINARYTREE_HPP
#define BINARYTREE_HPP

/* ************************************************************************** */

#include "../container/container.hpp"
#include "../container/mappable.hpp"

#include "../iterator/iterator.hpp"

#include "../stack/vec/stackvec.hpp"
// #include "../stack/lst/stacklst.hpp"
#include "../queue/vec/queuevec.hpp"
// #include "../queue/lst/queuelst.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class BinaryTree : virtual public PreOrderTraversableContainer<Data>,
                  virtual public PostOrderTraversableContainer<Data>,
                  virtual public InOrderTraversableContainer<Data>,
                  virtual public BreadthTraversableContainer<Data> {
  // Must extend PreOrderTraversableContainer<Data>,
  //             PostOrderTraversableContainer<Data>,
  //             InOrderTraversableContainer<Data>,
  //             BreadthTraversableContainer<Data>

private:

  // ...

protected:

  // ...
using InOrderTraversableContainer<Data>::size;

public:

  struct Node {

    
  protected:

    // Comparison operators
    // type operator==(argument) specifiers; // Comparison of abstract types is possible, but is not visible.
    // type operator!=(argument) specifiers; // Comparison of abstract types is possible, but is not visible.
    virtual bool operator==(const Node&) const noexcept ;
    virtual bool operator!=(const Node&) const noexcept ;
  public:

    // friend class BinaryTree<Data>;
    friend class BinaryTree<Data>;

    /* ********************************************************************** */

    // Destructor
    // ~Node() specifiers
 virtual ~Node()  = default;
    /* ********************************************************************** */

    // Copy assignment
    // type operator=(argument); // Copy assignment of abstract types is not possible.
 virtual Node& operator=(const Node&) noexcept = delete;
    // Move assignment
    // type operator=(argument); // Move assignment of abstract types is not possible.
virtual Node& operator=(Node&&) noexcept = delete;
    /* ********************************************************************** */

    // Specific member functions
virtual Data& Element() noexcept = 0;
    // type Element() specifiers; // Immutable access to the element (concrete function should not throw exceptions)
virtual const Data& Element() const noexcept = 0;
    // type IsLeaf() specifiers; // (concrete function should not throw exceptions)
    virtual bool IsLeaf() const noexcept = 0;
    // type HasLeftChild() specifiers; // (concrete function should not throw exceptions)
    virtual bool HasLeftChild() const noexcept = 0;
    // type HasRightChild() specifiers; // (concrete function should not throw exceptions)
virtual bool HasRightChild() const noexcept = 0;
    // type LeftChild() specifiers; // (concrete function must throw std::out_of_range when not existent)
    virtual  Node& LeftChild() const = 0;
    // type RightChild() specifiers; // (concrete function must throw std::out_of_range when not existent)
    virtual  Node& RightChild() const = 0;

  };

  /* ************************************************************************ */

  // Destructor
  // ~BinaryTree() specifiers
virtual ~BinaryTree() noexcept = default;
  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument); // Copy assignment of abstract types is not possible.
 BinaryTree& operator=(const BinaryTree&) noexcept = delete;
  
  // type operator=(argument); // Move assignment of abstract types is not possible.
  BinaryTree& operator=(BinaryTree&&) noexcept = delete;
  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers; // Comparison of abstract binary tree is possible.
  // type operator!=(argument) specifiers; // Comparison of abstract binary tree is possible.
    bool operator==(const BinaryTree&) const noexcept ;
     bool operator!=(const BinaryTree&) const noexcept ;
  /* ************************************************************************ */

  // Specific member functions

  // type Root() specifiers; // (concrete function must throw std::length_error when empty)
 virtual  Node& Root() const = 0;
  /* ************************************************************************ */

  // Specific member function (inherited from TraversableContainer)

  // using typename TraversableContainer<Data>::TraverseFun;
using typename TraversableContainer<Data>::TraverseFun;
  // type Traverse(arguments) specifiers; // Override TraversableContainer member

     void Traverse(TraverseFun) const ;


  /* ************************************************************************ */

  // Specific member function (inherited from PreOrderTraversableContainer)

  // type PreOrderTraverse(arguments) specifiers; // Override PreOrderTraversableContainer member
     void PreOrderTraverse(TraverseFun) const ;
  /* ************************************************************************ */

  // Specific member function (inherited from PostOrderTraversableContainer)

  // type PostOrderTraverse(arguments) specifiers; // Override PostOrderTraversableContainer member
     void PostOrderTraverse(TraverseFun) const;

  /* ************************************************************************ */

  // Specific member function (inherited from InOrderTraversableContainer)

  // type InOrderTraverse(arguments) specifiers; // Override InOrderTraversableContainer member
     void InOrderTraverse(TraverseFun) const  ;

     void PreOrderTraverse(const Node *node, TraverseFun fun) const;

     void PostOrderTraverse(const Node *node, TraverseFun fun) const;

     /* ************************************************************************ */

     // Specific member function (inherited from BreadthTraversableContainer)

     void InOrderTraverse(const Node *node, TraverseFun fun) const;

     // type BreadthTraverse(arguments) specifiers; // Override BreadthTraversableContainer member
     void BreadthTraverse(TraverseFun) const;

     void BreadthTraverse(const Node *root, TraverseFun fun) const;

 protected:
     // Auxiliary functions, if necessary!

};

/* ************************************************************************** */

template <typename Data>
class MutableBinaryTree : 
virtual public ClearableContainer, 
virtual public BinaryTree<Data> ,
 virtual public PreOrderMappableContainer<Data>,
virtual public PostOrderMappableContainer<Data>,
virtual public InOrderMappableContainer<Data>,
 virtual public BreadthMappableContainer<Data>{
  // Must extend ClearableContainer,
  //             BinaryTree<Data>,
  //             PreOrderMappableContainer<Data>,
  //             PostOrderMappableContainer<Data>,
  //             InOrderMappableContainer<Data>,
  //             BreadthMappableContainer<Data>

private:

  // ...

protected:

  // ...
using BinaryTree<Data>::size;
public:

  struct MutableNode : virtual public BinaryTree<Data>::Node{
    // Must extend Node

    // friend class MutableBinaryTree<Data>;
friend class MutableBinaryTree<Data>;
    /* ********************************************************************** */
    using BinaryTree<Data>::Node::operator=;
    using BinaryTree<Data>::Node::operator==;
    using BinaryTree<Data>::Node::operator!=;
    using BinaryTree<Data>::Node::Element;
    using BinaryTree<Data>::Node::RightChild;
    using BinaryTree<Data>::Node::LeftChild;
    // Destructor
    // ~MutableNode() specifiers
 ~MutableNode() noexcept = default;
    /* ********************************************************************** */

    // Copy assignment
    // type operator=(argument); // Copy assignment of abstract types is not possible.
 MutableNode& operator=(const MutableNode&) = delete;
    // Move assignment
    // type operator=(argument); // Move assignment of abstract types is not possible.
MutableNode& operator=(MutableNode&&) = delete;
    /* ********************************************************************** */
virtual bool HasRightChild() const noexcept = 0;
    // Specific member functions
virtual bool HasLeftChild() const noexcept = 0;
    // type Element() specifiers; // Mutable access to the element (concrete function should not throw exceptions)
virtual Data& Element() noexcept = 0;
 virtual bool IsLeaf() const noexcept = 0;
virtual const Data& Element() const noexcept = 0;
    // type LeftChild() specifiers; // (concrete function must throw std::out_of_range when not existent)
    virtual MutableNode& LeftChild() const  = 0;
    // type RightChild() specifiers; // (concrete function must throw std::out_of_range when not existent)
virtual MutableNode& RightChild() const  = 0;
  };

  /* ************************************************************************ */
using BinaryTree<Data>::Root;
  // Destructor
  // ~MutableBinaryTree() specifiers
 ~MutableBinaryTree() noexcept = default;
  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument); // Copy assignment of abstract types is not possible.
 MutableBinaryTree& operator=(const MutableBinaryTree&) = delete;
  // Move assignment
  // type operator=(argument); // Move assignment of abstract types is not possible.
MutableBinaryTree& operator=(MutableBinaryTree&&) = delete;
  /* ************************************************************************ */

  // Specific member functions
using typename BinaryTree<Data>::Node;
  // type Root() specifiers; // (concrete function must throw std::length_error when empty)
virtual Node & Root() const = 0;
  /* ************************************************************************ */

  // Specific member function (inherited from MappableContainer)

  // using typename MappableContainer<Data>::MapFun;
using typename MappableContainer<Data>::MapFun;
  // type Map(argument) specifiers; // Override MappableContainer member
void Map(MapFun) override;
  /* ************************************************************************ */

  // Specific member function (inherited from PreOrderMappableContainer)

  // type PreOrderMap(argument) specifiers; // Override PreOrderMappableContainer member
void PreOrderMap(MapFun) override;
void PreOrderMap(typename MappableContainer<Data>::MapFun function, typename BinaryTree<Data>::Node &node);
/* ************************************************************************ */

// Specific member function (inherited from PostOrderMappableContainer)

// type PostOrderMap(argument) specifiers; // Override PostOrderMappableContainer member
void PostOrderMap(MapFun) override;
void PostOrderMap(typename MappableContainer<Data>::MapFun function, typename BinaryTree<Data>::Node &node);
/* ************************************************************************ */

// Specific member function (inherited from InOrderMappableContainer)

// type InOrderMap(arguments) specifiers; // Override InOrderMappableContainer member
void InOrderMap(MapFun) override;
void InOrderMap(typename MappableContainer<Data>::MapFun function, typename BinaryTree<Data>::Node &node);
/* ************************************************************************ */

// Specific member function (inherited from BreadthMappableContainer)

// type BreadthMap(arguments) specifiers; // Override BreadthMappableContainer member
void BreadthMap(MapFun) override;
protected:

  // Auxiliary functions, if necessary!

};

/* ************************************************************************** */

template <typename Data>
class BTPreOrderIterator :virtual public ForwardIterator<Data> , virtual public ResettableIterator<Data>{
  // Must extend ForwardIterator<Data>,
  //             ResettableIterator<Data>

private:

  // ...

protected:

  // ...
  const BinaryTree<Data>* Treee = nullptr;
  unsigned long int index = 0;
  typename BinaryTree<Data>::Node* nodo = nullptr;
  StackVec<typename BinaryTree<Data>::Node*> stack;
  
public:

  // Specific constructors
  // BTPreOrderIterator(argument) specifiers; // An iterator over a given binary tree
BTPreOrderIterator(const BinaryTree<Data>&);
  /* ************************************************************************ */

  // Copy constructor
  // BTPreOrderIterator(argument) specifiers;
BTPreOrderIterator(const BTPreOrderIterator& o);
  // Move constructor
  // BTPreOrderIterator(argument) specifiers;
BTPreOrderIterator(BTPreOrderIterator&& o);
  /* ************************************************************************ */

  // Destructor
  // ~BTPreOrderIterator() specifiers;
  ~BTPreOrderIterator() = default;
  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument) specifiers;
 BTPreOrderIterator& operator=(const BTPreOrderIterator& o)  ;
  // Move assignment
  // type operator=(argument) specifiers;
BTPreOrderIterator& operator=(BTPreOrderIterator&& o) noexcept ;
  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  // type operator!=(argument) specifiers;
    bool operator==(const BTPreOrderIterator& o) const noexcept ;
    bool operator!=(const BTPreOrderIterator& o) const noexcept ;

  /* ************************************************************************ */

  // Specific member functions (inherited from Iterator)

  // type operator*() specifiers; // (throw std::out_of_range when terminated)
 const Data& operator*() const override;
  // type Terminated() specifiers; // (should not throw exceptions)
  bool Terminated() const noexcept override;
  /* ************************************************************************ */

  // Specific member functions (inherited from ForwardIterator)

  // type operator++() specifiers; // (throw std::out_of_range when terminated)
BTPreOrderIterator& operator++() override; 
  /* ************************************************************************ */

  // Specific member functions (inherited from ResettableIterator)

  // type Reset() specifiers; // (should not throw exceptions)
void Reset() noexcept;
};

/* ************************************************************************** */

template <typename Data>
class BTPreOrderMutableIterator : virtual public MutableIterator<Data>, virtual public
BTPreOrderIterator<Data>{
  // Must extend MutableIterator<Data>,
  //             BTPreOrderIterator<Data>

private:

  // ...

protected:

  // ...

public:
using BTPreOrderIterator<Data>::stack;
  // Specific constructors
  // BTPreOrderMutableIterator(argument) specifiers; // An iterator over a given mutable binary tree
BTPreOrderMutableIterator(MutableBinaryTree<Data>&);
  /* ************************************************************************ */

  // Copy constructor
  // BTPreOrderMutableIterator(argument) specifiers;
   BTPreOrderMutableIterator(const BTPreOrderMutableIterator& o);
  // Move constructor
  // BTPreOrderMutableIterator(argument) specifiers;

    BTPreOrderMutableIterator(BTPreOrderMutableIterator&& o);
  /* ************************************************************************ */

  // Destructor
  // ~BTPreOrderMutableIterator() specifiers;
 ~BTPreOrderMutableIterator();
  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument) specifiers;

  // Move assignment
  // type operator=(argument) specifiers;
   BTPreOrderMutableIterator& operator=(const BTPreOrderMutableIterator& o);
    BTPreOrderMutableIterator& operator=(BTPreOrderMutableIterator&& o);
  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  // type operator!=(argument) specifiers;
  bool operator==(const BTPreOrderMutableIterator& o) const;
    bool operator!=(const BTPreOrderMutableIterator& o) const;

  /* ************************************************************************ */

  // Specific member functions (inherited from MutableIterator)

  // type operator*() specifiers; // (throw std::out_of_range when terminated)
using BTPreOrderIterator<Data>::operator*;
    Data & operator*() override;
};

/* ************************************************************************** */

template <typename Data>
class BTPostOrderIterator : virtual public ForwardIterator<Data>, virtual public ResettableIterator<Data>{
  // Must extend ForwardIterator<Data>,
  //             ResettableIterator<Data>

private:

  // ...

protected:

  // ...
  const BinaryTree<Data>* Treee = nullptr;
  unsigned long int index = 0;
  typename BinaryTree<Data>::Node* nodo = nullptr;
  StackVec<typename BinaryTree<Data>::Node*> stack;
public:

  // Specific constructors
  // BTPostOrderIterator(argument) specifiers; // An iterator over a given binary tree
  BTPostOrderIterator(const BinaryTree<Data>&);
  /* ************************************************************************ */

  // Copy constructor
  // BTPostOrderIterator(argument) specifiers;
  BTPostOrderIterator(const BTPostOrderIterator& o);
  // Move constructor
  // BTPostOrderIterator(argument) specifiers;
   BTPostOrderIterator(BTPostOrderIterator&& o);
  /* ************************************************************************ */

  // Destructor
  // ~BTPostOrderIterator() specifiers;
    ~BTPostOrderIterator()=default;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument) specifiers;

  // Move assignment
  // type operator=(argument) specifiers;
    BTPostOrderIterator& operator=(const BTPostOrderIterator& o);
    BTPostOrderIterator& operator=(BTPostOrderIterator&& o);
  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  // type operator!=(argument) specifiers;
    bool operator==(const BTPostOrderIterator& o) const noexcept;
    bool operator!=(const BTPostOrderIterator& o) const noexcept;
  /* ************************************************************************ */

  // Specific member functions (inherited from Iterator)

  // type operator*() specifiers; // (throw std::out_of_range when terminated)
   const Data& operator*() const override;
  // type Terminated() specifiers; // (should not throw exceptions)
bool Terminated() const noexcept override;
  /* ************************************************************************ */

  // Specific member functions (inherited from ForwardIterator)

  // type operator++() specifiers; // (throw std::out_of_range when terminated)
BTPostOrderIterator& operator++() override;
  /* ************************************************************************ */

  // Specific member functions (inherited from ResettableIterator)

  // type Reset() specifiers; // (should not throw exceptions)
void Reset() noexcept;
void MoveToLeftmostLeafNode(typename BinaryTree<Data>::Node &root) noexcept;
};

/* ************************************************************************** */

template <typename Data>
class BTPostOrderMutableIterator : virtual public MutableIterator<Data> , virtual public BTPostOrderIterator<Data> {
  // Must extend MutableIterator<Data>,
  //             BTPostOrderIterator<Data>

private:

  // ...

protected:

  // ...
using BTPostOrderIterator<Data>::stack;
public:

  // Specific constructors
  // BTPostOrderMutableIterator(argument) specifiers; // An iterator over a given mutable binary tree
BTPostOrderMutableIterator( MutableBinaryTree<Data>&);
  /* ************************************************************************ */

  // Copy constructor
  // BTPostOrderMutableIterator(argument) specifiers;
   BTPostOrderMutableIterator(const BTPostOrderMutableIterator& o);

  // Move constructor
  // BTPostOrderMutableIterator(argument) specifiers;
BTPostOrderMutableIterator(BTPostOrderMutableIterator&& o);
  /* ************************************************************************ */

  // Destructor
  // ~BTPostOrderMutableIterator() specifiers;
~BTPostOrderMutableIterator()=default;
  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument) specifiers;

  // Move assignment
  // type operator=(argument) specifiers;
    BTPostOrderMutableIterator& operator=(const BTPostOrderMutableIterator& o);
    BTPostOrderMutableIterator& operator=(BTPostOrderMutableIterator&& o);
  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  // type operator!=(argument) specifiers;
    bool operator==(const BTPostOrderMutableIterator& o) const;
    bool operator!=(const BTPostOrderMutableIterator& o) const;
  /* ************************************************************************ */

  // Specific member functions (inherited from MutableIterator)

  // type operator*() specifiers; // (throw std::out_of_range when terminated)
using BTPostOrderIterator<Data>::operator*;
    Data & operator*() override;
};

/* ************************************************************************** */

template <typename Data>
class BTInOrderIterator : virtual public ForwardIterator<Data>, virtual public ResettableIterator<Data>{
  // Must extend ForwardIterator<Data>,
  //             ResettableIterator<Data>

private:

  // ...

protected:

  // ...
  const BinaryTree<Data>* Treee = nullptr;
  unsigned long int index = 0;
  typename BinaryTree<Data>::Node* nodo = nullptr;
  typename BinaryTree<Data>::Node* out = nullptr;
  StackVec<typename BinaryTree<Data>::Node*> stack;
public:

  // Specific constructors
  // BTInOrderIterator(argument) specifiers; // An iterator over a given binary tree
BTInOrderIterator(const BinaryTree<Data>&);
  /* ************************************************************************ */

  // Copy constructor
  // BTInOrderIterator(argument) specifiers;
BTInOrderIterator(const BTInOrderIterator& o) ;
  // Move constructor
  // BTInOrderIterator(argument) specifiers;
BTInOrderIterator(BTInOrderIterator&& o) noexcept;
  /* ************************************************************************ */

  // Destructor
  // ~BTInOrderIterator() specifiers;
~BTInOrderIterator() =default;
  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument) specifiers;
BTInOrderIterator& operator=(const BTInOrderIterator& o) ;
  // Move assignment
  // type operator=(argument) specifiers;
 BTInOrderIterator& operator=(BTInOrderIterator&& o) noexcept;
 void MoveToLeftmostNode(typename BinaryTree<Data>::Node &root) noexcept;
 /* ************************************************************************ */

 // Comparison operators
 // type operator==(argument) specifiers;
 // type operator!=(argument) specifiers;
 bool operator==(const BTInOrderIterator &o) const noexcept;
 bool operator!=(const BTInOrderIterator &o) const noexcept;
 /* ************************************************************************ */

 // Specific member functions (inherited from Iterator)

 // type operator*() specifiers; // (throw std::out_of_range when terminated)
  const Data &operator*() const override;
 // type Terminated() specifiers; // (should not throw exceptions)
 bool Terminated() const noexcept override;
 /* ************************************************************************ */

 // Specific member functions (inherited from ForwardIterator)

 // type operator++() specifiers; // (throw std::out_of_range when terminated)
 BTInOrderIterator& operator++() override;
  /* ************************************************************************ */

  // Specific member functions (inherited from ResettableIterator)

  // type Reset() specifiers; // (should not throw exceptions)
void Reset() noexcept;
};

/* ************************************************************************** */

template <typename Data>
class BTInOrderMutableIterator : virtual public MutableIterator<Data> , virtual public BTInOrderIterator<Data> {
  // Must extend MutableIterator<Data>,
  //             BTInOrderIterator<Data>

private:

  // ...

protected:

  // ...
using BTInOrderIterator<Data>::stack;

public:

  // Specific constructors
  // BTInOrderMutableIterator(argument) specifiers; // An iterator over a given mutable binary tree
 BTInOrderMutableIterator(MutableBinaryTree<Data>&);
  /* ************************************************************************ */

  // Copy constructor
  // BTInOrderMutableIterator(argument) specifiers;
BTInOrderMutableIterator(const BTInOrderMutableIterator& o);
  // Move constructor
  // BTInOrderMutableIterator(argument) specifiers;
BTInOrderMutableIterator(BTInOrderMutableIterator&& o);
  /* ************************************************************************ */

  // Destructor
  // ~BTInOrderMutableIterator() specifiers;
~BTInOrderMutableIterator()=default;
  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument) specifiers;
BTInOrderMutableIterator& operator=(const BTInOrderMutableIterator& o);
  // Move assignment
  // type operator=(argument) specifiers;
BTInOrderMutableIterator& operator=(BTInOrderMutableIterator&& o);
  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  // type operator!=(argument) specifiers;
   bool operator==(const BTInOrderMutableIterator& o) const;
    bool operator!=(const BTInOrderMutableIterator& o) const;
  /* ************************************************************************ */

  // Specific member functions (inherited from MutableIterator)
using BTInOrderIterator<Data>::operator*;
  // type operator*() specifiers; // (throw std::out_of_range when terminated)
Data & operator*() override;
};

/* ************************************************************************** */

template <typename Data>
class BTBreadthIterator : virtual public ForwardIterator<Data> , virtual public ResettableIterator<Data> {
  // Must extend ForwardIterator<Data>,
  //             ResettableIterator<Data>

private:

  // ...

protected:

  // ...
  const BinaryTree<Data>* Treee = nullptr;
  unsigned long int index = 0;
  typename BinaryTree<Data>::Node* nodo = nullptr;

  QueueVec<typename BinaryTree<Data>::Node*> queue;
public:

  // Specific constructors
  // BTBreadthIterator(argument) specifiers; // An iterator over a given binary tree
BTBreadthIterator(const BinaryTree<Data>&);
  /* ************************************************************************ */

  // Copy constructor
  // BTBreadthIterator(argument) specifiers;
BTBreadthIterator (const BTBreadthIterator&);
  // Move constructor
  // BTBreadthIterator(argument) specifiers;
 BTBreadthIterator (BTBreadthIterator&&) noexcept;
  /* ************************************************************************ */

  // Destructor
  // ~BTBreadthIterator() specifiers;
~BTBreadthIterator()=default;
  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument) specifiers;
BTBreadthIterator& operator=(const BTBreadthIterator&);
  // Move assignment
  // type operator=(argument) specifiers;
  BTBreadthIterator& operator=(BTBreadthIterator&&) noexcept;
  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  // type operator!=(argument) specifiers;
   bool operator==(const BTBreadthIterator& ) const noexcept;
    bool operator!=(const BTBreadthIterator&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from Iterator)

  // type operator*() specifiers; // (throw std::out_of_range when terminated)
  const Data& operator*() const override;
  
  // type Terminated() specifiers; // (should not throw exceptions)
bool Terminated() const noexcept override;
  /* ************************************************************************ */

  // Specific member functions (inherited from ForwardIterator)

  // type operator++() specifiers; // (throw std::out_of_range when terminated)
  BTBreadthIterator& operator++() override;
  /* ************************************************************************ */

  // Specific member functions (inherited from ResettableIterator)

  // type Reset() specifiers; // (should not throw exceptions)
 void Reset() noexcept override;

};

/* ************************************************************************** */

template <typename Data>
class BTBreadthMutableIterator : virtual public MutableIterator<Data> , virtual public BTBreadthIterator<Data> {
  // Must extend MutableIterator<Data>,
  //             BTBreadthIterator<Data>

private:

  // ...

protected:

  // ...
using BTBreadthIterator<Data>::queue;
public:

  // Specific constructors
  // BTBreadthMutableIterator(argument) specifiers; // An iterator over a given mutable binary tree
BTBreadthMutableIterator(MutableBinaryTree<Data> & bt)
    : BTBreadthIterator<Data>(bt) {} ;/* ************************************************************************ */

  // Copy constructor
  // BTBreadthMutableIterator(argument) specifiers;

  // Move constructor
  // BTBreadthMutableIterator(argument) specifiers;
 
BTBreadthMutableIterator(const BTBreadthMutableIterator& o)
    : BTBreadthIterator<Data>(o) {}   ;

  
BTBreadthMutableIterator(BTBreadthMutableIterator&& o)
    : BTBreadthIterator<Data>(std::move(o)) {};/* ************************************************************************ */

  // Destructor
  // ~BTBreadthMutableIterator() specifiers;
   ~BTBreadthMutableIterator()=default;
  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument) specifiers;

  // Move assignment
  // type operator=(argument) specifiers;
    BTBreadthMutableIterator& operator=(const BTBreadthMutableIterator& o){
       BTBreadthIterator<Data>::operator=(o);
    };
   
    BTBreadthMutableIterator& operator=(BTBreadthMutableIterator&& o) noexcept{
      BTBreadthIterator<Data>::operator=(std::move(o));
    };
  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  // type operator!=(argument) specifiers;
    bool operator==(const BTBreadthMutableIterator& o)const = default;
    bool operator!=(const BTBreadthMutableIterator& o) const = default;

  /* ************************************************************************ */

  // Specific member functions (inherited from MutableIterator)

  // type operator*() specifiers; // (throw std::out_of_range when terminated)
using BTBreadthIterator<Data>::operator*;
    Data & operator*() override{
      if(!queue.Empty()){
        return const_cast<Data &>(queue.Head()->Element());
      }else{
        throw std::out_of_range("the iterator is therminatedh");
      }
    };
};

/* ************************************************************************** */

}

#include "binarytree.cpp"
#endif