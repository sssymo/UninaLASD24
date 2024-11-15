
#include "bst.hpp"
#include "../container/dictionary.hpp"
#include "../binarytree/lnk/binarytreelnk.hpp"
namespace lasd {

/* ************************************************************************** */

// ...

/* ************************************************************************** */

template<typename Data>
bool BST<Data>::Exists(const Data& val) const noexcept 
{
    return (FindPointerTo(root, val) != nullptr);
}
template<typename Data>
BST<Data>::BST(const BST<Data>& tree):BinaryTreeLnk<Data>::BinaryTreeLnk(tree) {}

template<typename Data>
typename BST<Data>::NodeLnk& BST<Data>::Root() const 
{
    if (BinaryTreeLnk<Data>::Empty()) {
        throw std::length_error("the tree is empty");
    }else{
  return *BinaryTreeLnk<Data>::root;
    }
}
template<typename Data>
BST<Data>::BST(BST<Data>&& tree) noexcept : BinaryTreeLnk<Data>::BinaryTreeLnk(std::move(tree)) {}

template<typename Data>
BST<Data>& BST<Data>::operator=(const BST<Data>& tree)
{
  BinaryTreeLnk<Data>::operator=(tree);
  return *this;
}

template<typename Data>
BST<Data>& BST<Data>::operator=(BST<Data>&& tree) noexcept
{
  BinaryTreeLnk<Data>::operator=(std::move(tree));
  return *this;
}


template<typename Data>
bool BST<Data>::operator==(const BST<Data>& tree) const noexcept
{

  if(size != tree.size){
    return false;
  }
    
  if(size == 0 && tree.size==0){
    return true;
}

    BTInOrderIterator<Data> it1(*this);

    BTInOrderIterator<Data> it2(tree);
 
    bool ret = true;
    while(!it1.Terminated() && !it2.Terminated() )
    {
      if(*it1 != *it2){
      return false;
      }  
      ++it1;
      ++it2;
      return ret;
    
  }
  return false;
}

template<typename Data>
bool BST<Data>::operator!=(const BST<Data>& tree) const noexcept
{
  return !(*this == tree);
}

template<typename Data>
bool BST<Data>::Insert(const Data& val)
{
  NodeLnk*& insert = FindPointerTo(root, val);
  if(insert == nullptr)
  {
    insert = new typename BinaryTreeLnk<Data>::NodeLnk(val);
    size++;
  return true;
  }
  return false;
  
}

template<typename Data>
bool BST<Data>::Insert(Data&& val) 
{
  NodeLnk*& insert = FindPointerTo(root, val);
  if(insert == nullptr)
  {
    insert = new typename BinaryTreeLnk<Data>::NodeLnk();
    insert->Element() = std::move(val);
    size++;
    return true;
  }
  return false;
}

template<typename Data>
const Data& BST<Data>::Min() const
{
  if(BinaryTreeLnk<Data>::Empty())
     throw std::length_error("Non esiste un Minim in un albero vuoto.");
  else
    return FindPointerToMin(root)->element;
}

template<typename Data>
Data BST<Data>::MinNRemove()
{
  if(BinaryTreeLnk<Data>::Empty())
    throw std::length_error("Non puoi rimuovere da un albero vuotso");
  else
  {
    NodeLnk* min = DetachMin(root);
    Data minData = min->element;
    delete min;
    return minData;
  }
}

template<typename Data>
void BST<Data>::RemoveMin()
{
  if(root != nullptr)
    delete DetachMin(root);
  else
    throw std::length_error("Non puoi rimuovere da un albero vuotopo");

}

template<typename Data>
const Data& BST<Data>::Max() const
{
  if(BinaryTreeLnk<Data>::Empty())
     throw std::length_error("mon esiste un massimo in un albero vuotoop.");
  else
  {
    return FindPointerToMax(root)->element;
  }

}

template<typename Data>
Data BST<Data>::MaxNRemove()
{
  if(BinaryTreeLnk<Data>::Empty())
    throw std::length_error("Non puoi rimuovere da un albero vuotooo");
  else
  {
    NodeLnk* max = DetachMax(root);
    Data maxData = max->element;
    delete max;
    return maxData;
  }
}

template<typename Data>
void BST<Data>::RemoveMax()
{
  if(root != nullptr)
    delete DetachMax(root);
  else
    throw std::length_error("Non puoi rimuovere da un albero vuotnkooo");

}

template<typename Data>
const Data& BST<Data>::Predecessor(const Data& val) const
{
  if(BinaryTreeLnk<Data>::Empty())
     throw std::length_error("Non esist un Predecessore in un albero vuoto.");
  else
  {
    NodeLnk *pre = FindPointerToPredecessor(root, val);
    if(pre == nullptr)
       throw std::length_error("Nonn esiste un Predecessore");
    else
      return pre->element;
  }


}

template<typename Data>
Data BST<Data>::PredecessorNRemove(const Data& val)
{
  Data pre = Predecessor(val);
  Remove(pre);
  return pre;
}

template<typename Data>
void BST<Data>::RemovePredecessor(const Data& val)
{
   const Data& pre = Predecessor(val);
   Remove(pre);
}

template<typename Data>
const Data& BST<Data>::Successor(const Data& val) const
{
  if(BinaryTreeLnk<Data>::Empty())
     throw std::length_error("non esiste un successore in un albero vuoto.");
  else
  {
    NodeLnk *pre = FindPointerToSuccessor(root, val);
    if(pre == nullptr)
       throw std::length_error("non esiste un successore");
    else
      return pre->element;
  }
}

template<typename Data>
Data BST<Data>::SuccessorNRemove(const Data& val)
{
  Data succ = Successor(val);
  Remove(succ);
  return succ;
}

template<typename Data>
void BST<Data>::RemoveSuccessor(const Data& val)
{
  const Data& succ = Successor(val);
  Remove(succ);
}



template <typename Data>
typename BinaryTreeLnk<Data>::NodeLnk* const& BST<Data>::FindPointerTo(NodeLnk* const& nodo,const Data& element) const noexcept
{
  if(nodo != nullptr)
  {
    if(element != nodo->element)
    {
      if(element < nodo->element)
        return FindPointerTo(nodo->left, element);
      if(element > nodo->element)
        return FindPointerTo(nodo->right, element);
    }
  }
  return nodo;

}

template <typename Data>
typename BinaryTreeLnk<Data>::NodeLnk* const& BST<Data>::FindPointerToMin(NodeLnk* const& nodo) const noexcept
{
  if(nodo != nullptr)
  {
    if(nodo->left != nullptr)
      return FindPointerToMin(nodo->left);
  }
  return nodo;
}
template <typename Data>
typename BinaryTreeLnk<Data>::NodeLnk* const& BST<Data>::FindPointerToMax(NodeLnk* const& nodo) const noexcept
{
  if(nodo != nullptr)
  {
    if(nodo->right != nullptr)
      return FindPointerToMax(nodo->right);
  }
  return nodo;
}

template <typename Data>
typename BinaryTreeLnk<Data>::NodeLnk*&  BST<Data>::FindPointerToMin(NodeLnk*& nodo) noexcept
{
  return const_cast<NodeLnk*&>(static_cast<const BST<Data>*>(this)->FindPointerToMin(nodo));
}
template <typename Data>
typename BinaryTreeLnk<Data>::NodeLnk*&  BST<Data>::FindPointerToMax(NodeLnk*& nodo) noexcept
{
  return const_cast<NodeLnk*&>(static_cast<const BST<Data>*>(this)->FindPointerToMax(nodo));
}
template <typename Data>
typename BinaryTreeLnk<Data>::NodeLnk*&  BST<Data>::FindPointerTo(NodeLnk*& nodo,const Data& element) noexcept
{
  return const_cast<NodeLnk*&>(static_cast<const BST<Data>*>(this)->FindPointerTo(nodo,element));
}
template <typename Data>
typename BinaryTreeLnk<Data>::NodeLnk*&  BST<Data>::FindPointerToPredecessor(NodeLnk*& nodo, const Data& val) noexcept
{
  return const_cast<NodeLnk*&>(static_cast<const BST<Data>*>(this)->FindPointerToPredecessor(nodo, val));
}
template <typename Data>
typename BinaryTreeLnk<Data>::NodeLnk*&  BST<Data>::FindPointerToSuccessor(NodeLnk*& nodo, const Data& val) noexcept
{
  return const_cast<NodeLnk*&>(static_cast<const BST<Data>*>(this)->FindPointerToSuccessor(nodo, val));
}

/* ************************************************************************** */

template<typename Data>
bool BST<Data>::Remove(const Data& val)
{
      NodeLnk*& nodoPtr = FindPointerTo(root, val);

    if (nodoPtr != nullptr) {
        delete Detach(nodoPtr);
        return true;
    }

    return false;
}

template<typename Data>
typename BinaryTreeLnk<Data>::NodeLnk* const& BST<Data>::FindPointerToPredecessor(NodeLnk* const& nodo, const Data& val) const noexcept
{
    NodeLnk* const* pred = nullptr;
    NodeLnk* const* curr = &nodo;
    while(*curr != nullptr){
      if(val > (*curr)->element){
        pred = curr;
        curr = &((*curr)->right);
      }
      else{
        curr = &((*curr)->left);
      }
    }
    if(pred == nullptr)
      return *curr;
    else
      return *pred;
}

template<typename Data>
typename BinaryTreeLnk<Data>::NodeLnk* const& BST<Data>::FindPointerToSuccessor(NodeLnk* const& nodo, const Data& val)  const noexcept
{
   NodeLnk* const* succ = nullptr;
   NodeLnk* const* curr = &nodo;
   while(*curr != nullptr)
   {
     if(val >= (*curr)->element){
       curr = &((*curr)->right);
     }
     else{
       succ = curr;
       curr = &((*curr)->left);
     }
   }
   if(succ == nullptr)
     return *curr;
   return *succ;

}

template<typename Data>
typename BinaryTreeLnk<Data>::NodeLnk* BST<Data>::Detach(NodeLnk*& root) noexcept
{
  if(root != nullptr){
    if(root->left == nullptr){
      return Skip2Right(root);
    }
    else if(root->right == nullptr){
      return Skip2Left(root);
    }
    else{
      NodeLnk* massimo = DetachMax(root->left);
      std::swap(root->element, massimo->element);
      return massimo;
    }
  }
  return nullptr;
}


template<typename Data>
typename BinaryTreeLnk<Data>::NodeLnk* BST<Data>::Skip2Right(NodeLnk*& nodo) noexcept
{
  NodeLnk* rr = nullptr;
  if(nodo != nullptr)
  {
    std::swap(rr, nodo->right);
    std::swap(rr, nodo);
    --size;
  }
  return rr;
}
template<typename Data>
typename BinaryTreeLnk<Data>::NodeLnk* BST<Data>::Skip2Left(NodeLnk*& nodo) noexcept
{
  NodeLnk* left = nullptr;
  if(nodo != nullptr)
  {
    std::swap(left, nodo->left);
    std::swap(left, nodo);
    --size;
  }
  return left;
}
template<typename Data>
typename BinaryTreeLnk<Data>::NodeLnk* BST<Data>::DetachMax(NodeLnk*& nodo) noexcept
{
  return Skip2Left(FindPointerToMax(nodo));
}
template<typename Data>
typename BinaryTreeLnk<Data>::NodeLnk* BST<Data>::DetachMin(NodeLnk*& nodo) noexcept
{
  return Skip2Right(FindPointerToMin(nodo));
}
template<typename Data>
void BST<Data>::Clear() noexcept
{
    BinaryTreeLnk<Data>::Clear();
    size = 0;
}
template<typename Data>
BST<Data>::BST(const TraversableContainer<Data>& container) noexcept {
    container.Traverse([this](const Data& val) { this->Insert(val); });
}
template<typename Data>
BST<Data>::BST(MappableContainer<Data>&& container) noexcept {
    container.Map([this](Data&& val) { 
        this->Insert(std::move(val)); 
    });
}
};
