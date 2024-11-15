#ifndef LIST_HPP
#define LIST_HPP

/* ************************************************************************** */

#include "../container/container.hpp"
#include "../container/linear.hpp"
#include "../container/dictionary.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class List : virtual public ClearableContainer,
    virtual public LinearContainer<Data>,
    virtual public DictionaryContainer<Data> {
  // Must extend ClearableContainer,
  //             LinearContainer<Data>,
  //             DictionaryContainer<Data>

private:

  // ...

protected:

  // using Container::???;
 using Container::size;

  struct Node {
    //aggiunto per far si che sia possibile creare nodi in hash

    // Data
    // ...
                Data element;
                Node* next = nullptr;
    /* ********************************************************************** */

    // Specific constructors
    // ...
inline Node() = default;
    /* ********************************************************************** */
inline Node(const Data & dat): element(dat){};
inline Node(Data &&) noexcept;

    // Copy constructor
    // ...
inline Node(const Node & nod):element(nod.element){};

    // Move constructor
    // ...
inline Node(Node && nod )noexcept;
               
    /* ********************************************************************** */

    // Destructor
    // ...
virtual ~Node();
    /* ********************************************************************** */



// Comparison operators
// ...
bool operator==(const Node &) const noexcept;
inline bool operator!=(const Node &) const noexcept;

/* ********************************************************************** */

// Specific member functions
virtual Node *Clone(Node *);
// ...

  };

  // ...
        Node * head = nullptr;
        Node * tail = nullptr;
public:
Node* GetHead() const { return head; }
  // Default constructor
  // List() specifiers;
List() = default;

  /* ************************************************************************ */

  // Specific constructor
  // List(argument) specifiers; // A list obtained from a TraversableContainer
  // List(argument) specifiers; // A list obtained from a MappableContainer
        List(const TraversableContainer<Data> &);
        List(MappableContainer<Data> &&);
  /* ************************************************************************ */

  // Copy constructor
  // List(argument) specifiers;
List(const List &);
  // Move constructor
  // List(argument) specifiers;

List(List &&) noexcept;
  /* ************************************************************************ */

  // Destructor
  // ~List() specifiers;
virtual ~List();
  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument) specifiers;
List & operator=(const List &);
  // Move assignment
  // type operator=(argument) specifiers;
List & operator=(List &&) noexcept;
  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  // type operator!=(argument) specifiers;
        inline bool operator==(const List &) const noexcept;
        inline bool operator !=(const List &) const noexcept;

  /* ************************************************************************ */

  // Specific member functions

  // type InsertAtFront(argument) specifier; // Copy of the value
  // type InsertAtFront(argument) specifier; // Move of the value
  // type RemoveFromFront() specifier; // (must throw std::length_error when empty)
  // type FrontNRemove() specifier; // (must throw std::length_error when empty)
        void InsertAtFront(const Data &);
        void InsertAtFront(Data &&);
        void RemoveFromFront();
        Data FrontNRemove();

  // type InsertAtBack(argument) specifier; // Copy of the value
  // type InsertAtBack(argument) specifier; // Move of the value
         void InsertAtBack(const Data &);
        void InsertAtBack(Data &&);
  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  // type Clear() specifiers; // Override ClearableContainer member
 void Clear() override;
  /* ************************************************************************ */

  // Specific member functions (inherited from DictionaryContainer)

  // type Insert(argument) specifier; // Copy of the value
  // type Insert(argument) specifier; // Move of the value
  // type Remove(argument) specifier;
  
        bool Insert(const Data &) override;
        bool Insert(Data &&) override;
        bool Remove(const Data &) override;

  /* ************************************************************************ */

  // Specific member functions (inherited from LinearContainer)

  // type operator[](argument) specifiers; // Override (NonMutable) LinearContainer member (must throw std::out_of_range when out of range)
  // type operator[](argument) specifiers; // Override (Mutable) LinearContainer member (must throw std::out_of_range when out of range)

  // type Front() specifiers; // Override (NonMutable) LinearContainer member (must throw std::length_error when empty)
  // type Front() specifiers; // Override (Mutable) LinearContainer member (must throw std::length_error when empty)

  // type Back() specifiers; // Override (NonMutable) LinearContainer member (must throw std::length_error when empty)
  // type Back() specifiers; // Override (Mutable) LinearContainer member (must throw std::length_error when empty)
        const Data & operator[](const ulong) const override;
        Data & operator[](const ulong) override;

        const Data & Front() const override;
        Data & Front() override;

        const Data & Back() const override;
        Data & Back() override;
  /* ************************************************************************ */

  // Specific member function (inherited from TraversableContainer)

  // using typename TraversableContainer<Data>::TraverseFun;
        using typename TraversableContainer<Data>::TraverseFun;

  // type Traverse(arguments) specifiers; // Override TraversableContainer member
void Traverse(TraverseFun) const override;
  /* ************************************************************************ */

  // Specific member function (inherited from PreOrderTraversableContainer)

  // type PreOrderTraverse(arguments) specifiers; // Override PreOrderTraversableContainer member
void PreOrderTraverse(TraverseFun) const override;





/* ************************************************************************ */

// Specific member function (inherited from PostOrderTraversableContainer)

// type PostOrderTraverse(arguments) specifiers; // Override PostOrderTraversableContainer member
void PostOrderTraverse(TraverseFun fun) const override;
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
  void PostOrderMap(MapFun) override;

/* ************************************************************************ */

// Specific member function (inherited from PostOrderMappableContainer)

// type PostOrderMap(argument) specifiers; // Override PostOrderMappableContainer member
void PreOrderTraverse(TraverseFun fun, const Node *cur) const;
void PostOrderTraverse(TraverseFun fun, const Node *cur) const;
  // Auxiliary functions, if necessary!
void PreOrderMap(MapFun,Node * cur) ;
void PostOrderMap(MapFun fun, Node *cur);
protected:


};

/* ************************************************************************** */

}

#include "list.cpp"

#endif
