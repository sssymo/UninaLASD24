
#include "./binarytree.hpp"
#include "../queue/queue.hpp"
#include "../queue/lst/queuelst.hpp"
#include "../queue/vec/queuevec.hpp"
#include "../stack/lst/stacklst.hpp"
#include "../stack/vec/stackvec.hpp"
#include "binarytree.hpp"
namespace lasd {

/* ************************************************************************** */

// ...
//traverse 
template<typename Data>
void BinaryTree<Data>::Traverse(TraverseFun fun) const {
    PreOrderTraverse(fun); 
}

template<typename Data>
void BinaryTree<Data>::PreOrderTraverse(TraverseFun fun) const {
    PreOrderTraverse(&Root(), fun); 
}

template<typename Data>
void BinaryTree<Data>::PostOrderTraverse(TraverseFun fun) const {
    PostOrderTraverse(&Root(), fun);
}

template<typename Data>
void BinaryTree<Data>::InOrderTraverse(TraverseFun fun) const {
    InOrderTraverse(&Root(), fun); 
}

template<typename Data>
void BinaryTree<Data>::PreOrderTraverse(const Node* root, TraverseFun fun) const {
    if (root != nullptr) {
        fun(root->Element()); 
        if (root->HasLeftChild()) { 
        PreOrderTraverse(&root->LeftChild(), fun);
        } 
        if (root->HasRightChild()) { 
            PreOrderTraverse(&root->RightChild(), fun); 
        }
        return;
    }
    return;
}

template<typename Data>
void BinaryTree<Data>::PostOrderTraverse(const Node* root, TraverseFun fun) const {
    if (root != nullptr) {
      if (root->HasLeftChild()) {
        PostOrderTraverse(&root->LeftChild(), fun); 
        }
        if (root->HasRightChild()) {
            PostOrderTraverse(&root->RightChild(), fun); 
        }
        fun(root->Element()); 
    }
}

template<typename Data>
void BinaryTree<Data>::InOrderTraverse(const Node* root, TraverseFun fun) const {
    if (root != nullptr) {
        if (root->HasLeftChild()) { 
            InOrderTraverse(&root->LeftChild(), fun);
        }
        fun(root->Element()); 
        if (root->HasRightChild()) { 
            InOrderTraverse(&root->RightChild(), fun); 
        }
    }
}

template<typename Data>
void BinaryTree<Data>::BreadthTraverse(TraverseFun fun) const {

    BreadthTraverse(&Root(),fun);

}
template<typename Data>
void BinaryTree<Data>::BreadthTraverse(const Node* root,TraverseFun fun) const {
   
    QueueVec<const Node*> queue;

    if (this->Empty()) {
        return;
    }

    queue.Enqueue(&Root());

    while (!queue.Empty()) {
        const Node* node = queue.HeadNDequeue();

        fun(node->Element());

        if (node->HasLeftChild()) {
            queue.Enqueue(&node->LeftChild());
        }

        if (node->HasRightChild()) {
            queue.Enqueue(&node->RightChild());
        }
    }
}

template<typename Data>
bool BinaryTree<Data>::Node::operator==(const Node& node) const noexcept{
  bool val = true;

  if(Element() == node.Element())
  {
    if(HasLeftChild() && node.HasLeftChild())
    {
      val = (LeftChild() == node.LeftChild());
    }
    else if (HasLeftChild() || node.HasLeftChild())
    {
      val = false;
    }
    if(val)
    {
      if(HasRightChild() && node.HasRightChild())
      {
        val = RightChild() == node.RightChild();
      }
      else if(HasRightChild() || node.HasRightChild())
      {
        val = false;
      }
    }
  }
  else
    val = false;
  return val;
}

template<typename Data>
bool BinaryTree<Data>::Node::operator!=(const Node& Nodee) const noexcept
{
  return !(*this == Nodee);
}

template<typename Data>
bool BinaryTree<Data>::operator==(const BinaryTree<Data>& tree) const noexcept
{
  if(!(this->Empty()) && !(tree.Empty()))
    return Root() == tree.Root();

  if((this->Empty()) && tree.Empty())
    return true;
  else
    return false;
}


template<typename Data>
bool BinaryTree<Data>::operator!=(const BinaryTree<Data>& treee) const noexcept
{
  return !(*this == treee);
}


/******************************************************************* PRE ORDER ***********************/


template<typename Data>
BTPreOrderIterator<Data>::BTPreOrderIterator(const BinaryTree<Data>& bt){
    Treee=&bt;
    if(!Treee->Empty()){
        nodo = &bt.Root();
        if (nodo->HasRightChild()) {
            stack.Push(&nodo->RightChild());
        }
        if (nodo->HasLeftChild()) {
            stack.Push(&nodo->LeftChild());
        }
    }else{nodo = nullptr;}

}

template<typename Data>
void BTPreOrderIterator<Data>::Reset() noexcept {
    if (Treee != nullptr) {
        if (!Treee->Empty()) {
            index = 0;
            stack.Clear();
            nodo = &Treee->Root();
            if (nodo->HasRightChild()) {
                stack.Push(&nodo->RightChild());
            }
            if (nodo->HasLeftChild()) {
                stack.Push(&nodo->LeftChild());
            }
        }
    }
}

template<typename Data>
 const Data &BTPreOrderIterator<Data>::operator*() const {
    if(!Terminated()) {
        return nodo->Element();
    }
    else {
        throw std::out_of_range("BTPreOrderIterator is pointingto to nullptr");
    }
}

template<typename Data>
BTPreOrderIterator<Data> & BTPreOrderIterator<Data>::operator++() {
    if(nodo== nullptr){
        throw std::out_of_range("btpreOrderIterator is pointingto nullptr");
    }
    else{
        if(!stack.Empty()){
        nodo = stack.Top();
        stack.Pop();
        if (nodo->HasRightChild()) {
            stack.Push(&nodo->RightChild());
        }
        if (nodo->HasLeftChild()) {
            stack.Push(&nodo->LeftChild());
        }
        index++;
        }
        else{nodo= nullptr;}
    }
    return *this;
}

template<typename Data>
bool BTPreOrderIterator<Data>::operator==(const BTPreOrderIterator<Data> & o) const noexcept {
    return (Treee == o.Treee) && (index == o.index);
}

template<typename Data>
bool BTPreOrderIterator<Data>::operator!=(const BTPreOrderIterator<Data> & o) const noexcept {
    return !(*this==o);
}

template<typename Data>
BTPreOrderIterator<Data>::BTPreOrderIterator(BTPreOrderIterator<Data> && o)  {
    *this=std::move(o);
}

template<typename Data>
BTPreOrderIterator<Data>::BTPreOrderIterator(const BTPreOrderIterator<Data> & o) {
    *this=o;
}

template<typename Data>
BTPreOrderIterator<Data> &BTPreOrderIterator<Data>::operator=(const BTPreOrderIterator<Data>& o) {
    if(this != &o) {
        Treee = o.Treee;
        index = o.index;
        nodo=o.nodo;
        stack = o.stack;
    }
}

template<typename Data>
BTPreOrderIterator<Data> &BTPreOrderIterator<Data>::operator=(BTPreOrderIterator<Data>&& o) noexcept {
    if(this != &o) {
        std::swap(Treee, o.Treee);
        std::swap(index, o.index);
        std::swap(nodo, o.nodo);
        stack = std::move(o.stack);
    }
    return *this;
}
template<typename Data>
bool BTPreOrderIterator<Data>::Terminated() const noexcept
{
  return (nodo == nullptr && stack.Empty());
}
//****************************************************************************** POST ORDER
template <typename Data>
BTPostOrderIterator<Data>::BTPostOrderIterator(const BinaryTree<Data>& bt) {
    Treee = &bt;
    if (!Treee->Empty()) {
        MoveToLeftmostLeafNode(Treee->Root());
    }else{
        nodo= nullptr;
    }
}

template <typename Data>
BTPostOrderIterator<Data>::BTPostOrderIterator(const BTPostOrderIterator<Data>& o) {
    *this = o;
}

template <typename Data>
BTPostOrderIterator<Data>::BTPostOrderIterator(BTPostOrderIterator<Data>&& p)  {
    *this = std::move(p);
}

template <typename Data>
BTPostOrderIterator<Data>& BTPostOrderIterator<Data>::operator=(const BTPostOrderIterator<Data>& g) {
    if (this != &g) {
        Treee = g.Treee;
        index = g.index;
        nodo = g.nodo;
        stack = g.stack;
    }
    return *this;
}

template <typename Data>
BTPostOrderIterator<Data>& BTPostOrderIterator<Data>::operator=(BTPostOrderIterator<Data>&& o)  {
    if (this != &o) {
        std::swap(Treee, o.Treee);
        std::swap(index, o.index);
        std::swap(nodo, o.nodo);
        stack = std::move(o.stack);
    }
    return *this;
}

template <typename Data>
bool BTPostOrderIterator<Data>::operator==(const BTPostOrderIterator<Data>& h) const noexcept {
    return (Treee == h.Treee) && (index == h.index);
}

template <typename Data>
bool BTPostOrderIterator<Data>::operator!=(const BTPostOrderIterator<Data>& s) const noexcept {
    return !(*this == s);
}

template <typename Data>
const Data& BTPostOrderIterator<Data>::operator*() const {
    if (Terminated())
        throw std::out_of_range("The BTPostOrderIterator is pointing tonullptr");
    return nodo->Element();
}

template <typename Data>
BTPostOrderIterator<Data> & BTPostOrderIterator<Data>::operator++() {
    if (Terminated())
        throw std::out_of_range("The BTPostOrderIterator is pointing to nullptr");

    if (stack.Empty())
        nodo = nullptr;
    else {
        typename BinaryTree<Data>::Node* parent = stack.Top();
        if (parent->HasRightChild() && nodo==&parent->RightChild()) {
            nodo = parent;
            stack.Pop();
        }
        else if (parent->HasLeftChild() && nodo==&parent->LeftChild()) {
            if (parent->HasRightChild())
                MoveToLeftmostLeafNode(parent->RightChild());
            else {
                nodo = parent;
                stack.Pop();
            }
        }
    }
    index++;
    return *this;
}

template <typename Data>
void BTPostOrderIterator<Data>::Reset() noexcept {
    if (Treee != nullptr) {
        if(!Treee->Empty()) {
            index = 0;
            stack.Clear();
            MoveToLeftmostLeafNode(Treee->Root());
        }
    }
}

template <typename Data>
void BTPostOrderIterator<Data>::MoveToLeftmostLeafNode(typename BinaryTree<Data>::Node& root) noexcept {
    nodo = &root;
    while (!nodo->IsLeaf()) {

        while (nodo->HasLeftChild()) {
            stack.Push(nodo);
            nodo = &nodo->LeftChild();
        }

        if (nodo->HasRightChild()) {
            stack.Push(nodo);
            nodo = &nodo->RightChild();
        }
    }
}

template<typename Data>
bool BTPostOrderIterator<Data>::Terminated() const noexcept
{
  return (nodo == nullptr && stack.Empty());
}
/**************** IN ORDER *************************/

template<typename Data>
BTInOrderIterator<Data>::BTInOrderIterator(const BinaryTree<Data> & bt){
    Treee=&bt;
    if(!Treee->Empty()) {




        MoveToLeftmostNode(Treee->Root());
        
        
        out=nodo;
    }else{nodo= nullptr;}
}

template<typename Data>
void BTInOrderIterator<Data>::Reset() noexcept {
    if (Treee != nullptr) {
        if (!Treee->Empty()) {
        
            index = 0;
        
            stack.Clear();
        


            MoveToLeftmostNode(Treee->Root());
        
        
            out=nodo;
        }
    }
}

template<typename Data>
 const Data &BTInOrderIterator<Data>::operator*() const {
    if(!Terminated()) {
        return out->Element();
    }
    else {
        throw std::out_of_range("it is pointing to to nullptr");
    }
}

template<typename Data>
bool BTInOrderIterator<Data>::Terminated() const noexcept
{
  return (nodo == nullptr && stack.Empty());
}
template<typename Data>
BTInOrderIterator<Data> & BTInOrderIterator<Data>::operator++() {
        if (Terminated()) {
            throw std::out_of_range("The BTInOrderIterator is pointing nullpttr");
        }
        if(!stack.Empty()) {
            nodo = stack.Top();
            stack.Pop();
            out=nodo;
            if(nodo->HasRightChild()) {
                MoveToLeftmostNode(nodo->RightChild());
            }
            index++;
        }else{nodo= nullptr;}
        return *this;
}

template<typename Data>
bool BTInOrderIterator<Data>::operator==(const BTInOrderIterator<Data> & c) const noexcept {
    return (Treee == c.Treee) && (index == c.index);
}

template<typename Data>
bool BTInOrderIterator<Data>::operator!=(const BTInOrderIterator<Data> & c) const noexcept {
    return !(*this==c);
}

template<typename Data>
BTInOrderIterator<Data>::BTInOrderIterator(BTInOrderIterator<Data> && o) noexcept {
    *this=std::move(o);
}

template<typename Data>
BTInOrderIterator<Data>::BTInOrderIterator(const BTInOrderIterator<Data> & o) {
    *this=o;
}

template<typename Data>
BTInOrderIterator<Data> &BTInOrderIterator<Data>::operator=(const BTInOrderIterator<Data> & o) {
    if(this != &o) {
        Treee = o.Treee;
        index = o.index;
        nodo = o.nodo;
        out = o.out;
        stack = o.stack;

    }
    return *this;
}

template<typename Data>
BTInOrderIterator<Data> &BTInOrderIterator<Data>::operator=(BTInOrderIterator<Data> && o) noexcept {
    if(this != &o) {
        std::swap(Treee, o.Treee);
        std::swap(index, o.index);
        std::swap(nodo, o.nodo);
        std::swap(out, o.out);
        stack = std::move(o.stack);
    }
    return *this;
}

    template<typename Data>
    void BTInOrderIterator<Data>::MoveToLeftmostNode(typename BinaryTree<Data>::Node& root) noexcept {
        nodo=&root;
        if(nodo->HasLeftChild()) {
            while (nodo->HasLeftChild()) {
                stack.Push(nodo);
                nodo = &nodo->LeftChild();
            }
        }
        else{stack.Push(nodo);}
    }
/********************** BREADTH ***********************/


template <typename Data>
BTBreadthIterator<Data>::BTBreadthIterator(const BinaryTree<Data>& bt) {
    Treee = &bt;
    if (!Treee->Empty()) {
        nodo = &Treee->Root();
            if (nodo->HasLeftChild())
        queue.Enqueue(&nodo->LeftChild());
    if (nodo->HasRightChild())
        queue.Enqueue(&nodo->RightChild());
    }
    else{
        nodo= nullptr;
    }
}

template <typename Data>
BTBreadthIterator<Data>::BTBreadthIterator(const BTBreadthIterator<Data>& m) {
    *this = m;
}

template <typename Data>
BTBreadthIterator<Data>::BTBreadthIterator(BTBreadthIterator<Data>&& m) noexcept {
    *this = std::move(m);
}

template <typename Data>
BTBreadthIterator<Data>& BTBreadthIterator<Data>::operator=(const BTBreadthIterator<Data>& z) {
    if (this != &z) {
        Treee = z.Treee;
        index = z.index;
        nodo = z.nodo;
        queue = z.queue;
    }
    return *this;
}

template <typename Data>
BTBreadthIterator<Data>& BTBreadthIterator<Data>::operator=(BTBreadthIterator<Data>&& z) noexcept {
    if (this != &z) {
        std::swap(Treee, z.Treee);
        std::swap(index, z.index);
        std::swap(nodo, z.nodo);
        queue = std::move(z.queue);
    }
    return *this;
}

template <typename Data>
bool BTBreadthIterator<Data>::operator==(const BTBreadthIterator<Data>& o) const noexcept {
    return (Treee == o.Treee) && (index == o.index);
}

template <typename Data>
bool BTBreadthIterator<Data>::operator!=(const BTBreadthIterator<Data>& o) const noexcept {
    return !(*this == o);
}

template <typename Data>
 const Data& BTBreadthIterator<Data>::operator*() const {
    if (Terminated())
        throw std::out_of_range("The BTBreadthIterator is pointing nullptr");
    return nodo->Element();
}

template <typename Data>
BTBreadthIterator<Data> & BTBreadthIterator<Data>::operator++() {
    if (Terminated())
        throw std::out_of_range("The BTBreadthIterator point to nullptr");

    if (queue.Empty())
        nodo = nullptr;
    else {
        nodo = queue.Head();
            if (nodo->HasLeftChild()){
        queue.Enqueue(&nodo->LeftChild());}
        
    if (nodo->HasRightChild())
    {
        queue.Enqueue(&nodo->RightChild());
        
    }
queue.Dequeue();
    }
    index++;
    return *this;
}

template <typename Data>
void BTBreadthIterator<Data>::Reset() noexcept {
    if (Treee != nullptr) {
        if(!Treee->Empty()) {
            index = 0;
            queue.Clear();
            nodo = &Treee->Root();
                if (nodo->HasLeftChild())
        queue.Enqueue(&nodo->LeftChild());
    if (nodo->HasRightChild())
        queue.Enqueue(&nodo->RightChild());
        }
    }
}


template <typename Data>
bool BTBreadthIterator<Data>::Terminated() const noexcept
{
  return nodo == nullptr && queue.Empty();
}

/* ************************************************************************** */



/**********************MUTABLE BINARY TREE****************************/
template<typename Data>
void MutableBinaryTree<Data>::Map(typename MappableContainer<Data>::MapFun function) {
    PreOrderMap(function, Root());
}
template <typename Data>
void MutableBinaryTree<Data>::PreOrderMap(typename MappableContainer<Data>::MapFun function) {
    PreOrderMap(function, Root());
}

template <typename Data>
void MutableBinaryTree<Data>::PreOrderMap(typename MappableContainer<Data>::MapFun function, typename BinaryTree<Data>::Node& node) {
    
    function(node.Element());

    if (node.HasLeftChild()) {
        PreOrderMap(function, node.LeftChild());
    }
    if (node.HasRightChild()) {
        PreOrderMap(function, node.RightChild());
    }
}

template <typename Data>
void MutableBinaryTree<Data>::BreadthMap(typename MappableContainer<Data>::MapFun function) {
    QueueVec<Node*> queue;

    if (size == 0 ) {
        return;
    }

    queue.Enqueue(&Root());

    while (!queue.Empty()) {
        Node* node = queue.HeadNDequeue();

        function(node->Element());

        if (node->HasLeftChild()) {
            queue.Enqueue(&node->LeftChild());
        }

        if (node->HasRightChild()) {
            queue.Enqueue(&node->RightChild());
        }
    }
}

template <typename Data>
void MutableBinaryTree<Data>::PostOrderMap(typename MappableContainer<Data>::MapFun function) {
    PostOrderMap(function, Root());
}

template <typename Data>
void MutableBinaryTree<Data>::PostOrderMap(typename MappableContainer<Data>::MapFun function, typename BinaryTree<Data>::Node& node) {

    if (node.HasLeftChild()) {
        PostOrderMap(function, node.LeftChild());
    }
    if (node.HasRightChild()) {
        PostOrderMap(function, node.RightChild());
    }

    function(node.Element());
}

template <typename Data>
void MutableBinaryTree<Data>::InOrderMap(typename MappableContainer<Data>::MapFun function) {
    InOrderMap(function, Root());
}

template <typename Data>
void MutableBinaryTree<Data>::InOrderMap(typename MappableContainer<Data>::MapFun function, typename BinaryTree<Data>::Node& node) {

    if (node.HasLeftChild()) {
        InOrderMap(function, node.LeftChild());
    }

    function(node.Element());

    if (node.HasRightChild()) {
        InOrderMap(function, node.RightChild());
    }
}

/***********************BTPreOrderMutableIterator*******************/
template<typename Data>
BTPreOrderMutableIterator<Data>::BTPreOrderMutableIterator( MutableBinaryTree<Data>& tree)
    : BTPreOrderIterator<Data>(tree) {}

template<typename Data>
BTPreOrderMutableIterator<Data>::BTPreOrderMutableIterator(const BTPreOrderMutableIterator& o)
    : BTPreOrderIterator<Data>(o) {}

template<typename Data>
BTPreOrderMutableIterator<Data>::BTPreOrderMutableIterator(BTPreOrderMutableIterator&& o)
    : BTPreOrderIterator<Data>(std::move(o)) {}

template<typename Data>
BTPreOrderMutableIterator<Data>::~BTPreOrderMutableIterator() {}

template<typename Data>
BTPreOrderMutableIterator<Data>& BTPreOrderMutableIterator<Data>::operator=(const BTPreOrderMutableIterator& o) {
    if (this != &o) {
        BTPreOrderIterator<Data>::operator=(o);
    }
    return *this;
}

template<typename Data>
BTPreOrderMutableIterator<Data>& BTPreOrderMutableIterator<Data>::operator=(BTPreOrderMutableIterator&& o) {
    if (this != &o) {
        BTPreOrderIterator<Data>::operator=(std::move(o));
    }
    return *this;
}

template<typename Data>
bool BTPreOrderMutableIterator<Data>::operator==(const BTPreOrderMutableIterator& o) const {
    return BTPreOrderIterator<Data>::operator==(o);
}

template<typename Data>
bool BTPreOrderMutableIterator<Data>::operator!=(const BTPreOrderMutableIterator& o) const {
    return !(*this == o);
}

template<typename Data>
Data& BTPreOrderMutableIterator<Data>::operator*()  {
   return const_cast<Data&>(BTPreOrderIterator<Data>::operator*());
}


/****************************BTPostOrderMutableIterator******************************/


template<typename Data>
BTPostOrderMutableIterator<Data>::BTPostOrderMutableIterator( MutableBinaryTree<Data>& tree)
    : BTPostOrderIterator<Data>(tree) {}

template<typename Data>
BTPostOrderMutableIterator<Data>::BTPostOrderMutableIterator(const BTPostOrderMutableIterator& o)
    : BTPostOrderIterator<Data>(o) {}

template<typename Data>
BTPostOrderMutableIterator<Data>::BTPostOrderMutableIterator(BTPostOrderMutableIterator&& o)
    : BTPostOrderIterator<Data>(std::move(o)) {}



template<typename Data>
BTPostOrderMutableIterator<Data>& BTPostOrderMutableIterator<Data>::operator=(const BTPostOrderMutableIterator& o) {
    if (this != &o) {
        BTPostOrderIterator<Data>::operator=(o);
    }
    return *this;
}

template<typename Data>
BTPostOrderMutableIterator<Data>& BTPostOrderMutableIterator<Data>::operator=(BTPostOrderMutableIterator&& o) {
    if (this != &o) {
        BTPostOrderIterator<Data>::operator=(std::move(o));
    }
    return *this;
}

template<typename Data>
bool BTPostOrderMutableIterator<Data>::operator==(const BTPostOrderMutableIterator& o) const {
    return BTPostOrderIterator<Data>::operator==(o);
}

template<typename Data>
bool BTPostOrderMutableIterator<Data>::operator!=(const BTPostOrderMutableIterator& o) const {
    return !(*this == o);
}

template<typename Data>
Data& BTPostOrderMutableIterator<Data>::operator*() {
    return const_cast<Data&>(BTPostOrderIterator<Data>::operator*());
}



/****************************BTInOrderMutableIterator****************************/
template<typename Data>
BTInOrderMutableIterator<Data>::BTInOrderMutableIterator(MutableBinaryTree<Data>& tree)
    : BTInOrderIterator<Data>(tree) {}

template<typename Data>
BTInOrderMutableIterator<Data>::BTInOrderMutableIterator(const BTInOrderMutableIterator& o)
    : BTInOrderIterator<Data>(o) {}

template<typename Data>
BTInOrderMutableIterator<Data>::BTInOrderMutableIterator(BTInOrderMutableIterator&& o)
    : BTInOrderIterator<Data>(std::move(o)) {}



template<typename Data>
BTInOrderMutableIterator<Data>& BTInOrderMutableIterator<Data>::operator=(const BTInOrderMutableIterator& o) {
    if (this != &o) {
        BTInOrderIterator<Data>::operator=(o);
    }
    return *this;
}

template<typename Data>
BTInOrderMutableIterator<Data>& BTInOrderMutableIterator<Data>::operator=(BTInOrderMutableIterator&& o) {
    if (this != &o) {
        BTInOrderIterator<Data>::operator=(std::move(o));
    }
    return *this;
}

template<typename Data>
bool BTInOrderMutableIterator<Data>::operator==(const BTInOrderMutableIterator& o) const {
    return BTInOrderIterator<Data>::operator==(o);
}

template<typename Data>
bool BTInOrderMutableIterator<Data>::operator!=(const BTInOrderMutableIterator& o) const {
    return !(*this == o);
}

template<typename Data>
Data& BTInOrderMutableIterator<Data>::operator*()  {
    return const_cast<Data&>(BTInOrderIterator<Data>::operator*());
}


}
