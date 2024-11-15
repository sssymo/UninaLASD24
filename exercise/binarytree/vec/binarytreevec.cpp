#include "../../binarytree/vec/binarytreevec.hpp"
#include "../../vector/vector.hpp"
#include "binarytreevec.hpp"
namespace lasd {

/* ************************************************************************** */

template<typename Data>
BinaryTreeVec<Data>::BinaryTreeVec(const TraversableContainer<Data>& container)noexcept
{
    vector.Resize(container.Size());
    size = container.Size();

    container.Traverse([this, index = 0](const Data& data) mutable {
        vector[index] = new NodeVec();
        vector[index]->element = data;
        vector[index]->indexCurrNode = index;
        vector[index]->v = &vector;
        index++;
    });
}

template<typename Data>
BinaryTreeVec<Data>::BinaryTreeVec(MappableContainer<Data>&& container) noexcept
{
    vector.Resize(container.Size());
    size = container.Size();

    container.Map([this, index = 0](Data&& data) mutable {
        vector[index] = new NodeVec();
        vector[index]->element = std::move(data);
        vector[index]->indexCurrNode = index;
        vector[index]->v = &vector;
        index++;
    });
}

template <typename Data>
bool BinaryTreeVec<Data>::NodeVec::HasRightChild() const noexcept
{
    if (v != nullptr && indexCurrNode >= 0) {
      
        ulong rightChildIndex = 2 * indexCurrNode + 2;
       
        return rightChildIndex < v->Size();
    } else {
        
        return false;
    }
}

template <typename Data>
BinaryTreeVec<Data>::BinaryTreeVec(const BinaryTreeVec<Data>& tree)
{

  vector.Resize(tree.size);
  for(unsigned int i = 0; i < tree.size; i++)
  {
    vector[i] = new NodeVec();
    vector[i] -> element = tree.vector[i] -> element;
    vector[i] -> indexCurrNode = tree.vector[i] -> indexCurrNode;
    vector[i] -> v = &vector;
  }
  size = tree.size;

}

template <typename Data>
BinaryTreeVec<Data>::BinaryTreeVec(BinaryTreeVec<Data>&& tree) noexcept
{
  std::swap(vector, tree.vector);
  std::swap(size, tree.size);
}


// Copy constructor
template <typename Data>
BinaryTreeVec<Data>::NodeVec::NodeVec(const NodeVec& node) : MutableBinaryTree<Data>::MutableNode(node), indexCurrNode(node.indexCurrNode), element(node.element), v(node.v) {}

// Move constructor
template <typename Data>
BinaryTreeVec<Data>::NodeVec::NodeVec(NodeVec&& node) noexcept : MutableBinaryTree<Data>::MutableNode(std::move(node)), indexCurrNode(std::move(node.indexCurrNode)), element(std::move(node.element)), v(std::move(node.v)) {}

// Copy assignment
template <typename Data>
typename BinaryTreeVec<Data>::NodeVec& BinaryTreeVec<Data>::NodeVec::operator=(const NodeVec& node) {
    if (this != &node) {
        indexCurrNode = node.indexCurrNode;
        element = node.element;
        v = node.v;
    }
    return *this;
}
template <typename Data>
bool BinaryTreeVec<Data>::NodeVec::operator==(const NodeVec& node) const noexcept {
    return (indexCurrNode == node.indexCurrNode) && (element == node.element) && (*v == *(node.v));
}
template<typename Data>
void BinaryTreeVec<Data>::BreadthMap(MapFun fun) const {
    if (vector.Empty())
        return;

    for (auto& element : vector) {
       
        vector = fun(element);
    }
}
template <typename Data>
bool BinaryTreeVec<Data>::NodeVec::operator!=(const NodeVec& node) const noexcept {
    return !(*this == node);
}
// Move assignment
template <typename Data>
typename BinaryTreeVec<Data>::NodeVec& BinaryTreeVec<Data>::NodeVec::operator=(NodeVec&& node) noexcept {
    if (this != &node) {
        indexCurrNode = std::move(node.indexCurrNode);
        element = std::move(node.element);
        v = std::move(node.v);
    }
    return *this;
}
template<typename Data>
BinaryTreeVec<Data>::~BinaryTreeVec()
{
  Clear();
}


template<typename Data>
void BinaryTreeVec<Data>::BreadthTraverse(TraverseFun fun) const {
    if (vector.Empty())
        return;

    for (size_t i = 0; i < vector.Size(); ++i) {
     
        fun(vector[i]->Element());
    }
}
template <typename Data>
BinaryTreeVec<Data>& BinaryTreeVec<Data>::operator=(BinaryTreeVec<Data>&& tree) noexcept
{
  std::swap(vector, tree.vector);
  std::swap(size, tree.size);
  return *this;
}

template <typename Data>
Data& BinaryTreeVec<Data>::NodeVec::Element() noexcept
{
  return element;
}


template <typename Data>
const Data& BinaryTreeVec<Data>::NodeVec::Element() const noexcept
{
  return element;
}


template <typename Data>
bool BinaryTreeVec<Data>::NodeVec::HasLeftChild() const noexcept{
    if (v != nullptr && indexCurrNode >= 0 && indexCurrNode < v->Size()) {
        ulong leftChildIndex = 2 * indexCurrNode + 1;
        return leftChildIndex < v->Size();
    } else {
        return false;
    }
}



template <typename Data>
bool BinaryTreeVec<Data>::NodeVec::IsLeaf() const noexcept
{
  if((!HasLeftChild() && !HasRightChild()))
    return true;
  else
    return false;

}


template <typename Data>
typename BinaryTreeVec<Data>::NodeVec & BinaryTreeVec<Data>::NodeVec::LeftChild() const
{
  if(HasLeftChild())
    return (*((*v)[2*(indexCurrNode) + 1]));
  else
    throw std::out_of_range("Questo nodo non ha figlio sinistro");

}


template <typename Data>
typename BinaryTreeVec<Data>::NodeVec & BinaryTreeVec<Data>::NodeVec::RightChild() const
{
  if(HasRightChild())
    return *((*v)[2*(indexCurrNode) + 2]);
  else
    throw std::out_of_range("Questo nodo non ha figlio destro ");

}

template <typename Data>
 typename BinaryTreeVec<Data>::NodeVec & BinaryTreeVec<Data>::Root() const
{
   if(vector.Empty())
     throw std::length_error("BinaryTreeVec empty");
   else
     return *(vector[0]);

}
template <typename Data>
typename BinaryTreeVec<Data>::MutableNode & BinaryTreeVec<Data>::Root(){
    if (vector.Empty()) {
        throw std::length_error("Cannot access root of an empty tree");
    }
    else{
    return *(vector[0]);
}}
template <typename Data>
bool BinaryTreeVec<Data>::operator==(const BinaryTreeVec& tree) const noexcept
{
  bool x = true;
  if(vector.Size() == tree.vector.Size())
  {
    for(unsigned int i = 0; i < vector.Size(); i++)
    {
      if(x && tree.vector[i]->Element() != vector[i]->Element())
        x = false;
      else
        x = true;
    }
  }
  else
    x = false;

  return x;
}

template <typename Data>
bool BinaryTreeVec<Data>::operator!=(const BinaryTreeVec& tree) const noexcept
{
  return !(*this == tree);
}
// Clear
template <typename Data>
void BinaryTreeVec<Data>::Clear()
{
  for(unsigned int i = 0; i < vector.Size(); i++)
  {
    delete vector[i];
  }
  vector.Clear();
  size = 0;
}



template <typename Data>
BinaryTreeVec<Data>& BinaryTreeVec<Data>::operator=(const BinaryTreeVec<Data>& tree)
{
  Clear();
  vector.Resize(tree.vector.Size());
  for(unsigned int i = 0; i < tree.vector.Size(); i++)
  {
    vector[i] = new NodeVec();
    vector[i] -> element = tree.vector[i] -> element;
    vector[i] -> indexCurrNode = i;
    vector[i] -> v = &vector;
  }
  size = tree.Size();
  return *this;
}
/* ************************************************************************** */

}
