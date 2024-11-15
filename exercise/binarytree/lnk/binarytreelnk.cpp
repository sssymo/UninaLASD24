#include "../../binarytree/lnk/binarytreelnk.hpp"
#include "../../binarytree/binarytree.hpp"
#include "binarytreelnk.hpp"

namespace lasd {

/* ************************************************************************** */





/* ************************************************************************** */

// Specific constructors

template <typename Data>
BinaryTreeLnk<Data>::BinaryTreeLnk(const TraversableContainer<Data>& con) {
size=con.Size();
QueueVec<NodeLnk **> Queue;
Queue.Enqueue(&root);
con.Traverse([&Queue](const Data & dat){
    NodeLnk *&cur=*Queue.HeadNDequeue();
    cur=new NodeLnk(std::move(dat));
    Queue.Enqueue(&cur->left);
    Queue.Enqueue(&cur->right);
});

}

template <typename Data>
BinaryTreeLnk<Data>::BinaryTreeLnk(MappableContainer<Data>&& con)  {
size=con.Size();
QueueVec<NodeLnk **> Queue;
Queue.Enqueue(&root);
con.Map([&Queue](const Data & dat){
    NodeLnk *&cur=*Queue.HeadNDequeue();
    cur=new NodeLnk(std::move(dat));
    Queue.Enqueue(&cur->left);
    Queue.Enqueue(&cur->right);
});
}


template <typename Data>
BinaryTreeLnk<Data>::BinaryTreeLnk(const BinaryTreeLnk& btl) noexcept{
    if(btl.root !=nullptr){
        root= new NodeLnk(*btl.root);
        size=btl.size;
    }
}


template <typename Data>
BinaryTreeLnk<Data>::BinaryTreeLnk(BinaryTreeLnk&& tree) noexcept {
    std::swap(root,tree.root);
    std::swap(size,tree.size);
}

// Destructor

template <typename Data>
BinaryTreeLnk<Data>::~BinaryTreeLnk()  {
    delete root;
}


template <typename Data>
BinaryTreeLnk<Data>& BinaryTreeLnk<Data>::operator=(const BinaryTreeLnk<Data>& btl) noexcept {
    
    if (this != &btl) {
        
        if (root == nullptr) {
            
            if (btl.root != nullptr) {
                root = new NodeLnk(*btl.root);
            }
        } else { 
            
            if (btl.root == nullptr) {
                delete root;
                root = nullptr;
            } else { 
                
                *root = *btl.root;
            }
        }
        
        size = btl.size;
    }
    
    return *this;
}

template <typename Data>
BinaryTreeLnk<Data>& BinaryTreeLnk<Data>::operator=(BinaryTreeLnk&& tree) noexcept {
        std::swap(root,tree.root);
    std::swap(size,tree.size);
    return *this;
}


template <typename Data>
bool BinaryTreeLnk<Data>::operator==(const BinaryTreeLnk& tree) const noexcept {
    
    bool sameSize = (size == tree.size);

  
    bool bothEmpty = (root == nullptr && tree.root == nullptr);

    if (sameSize && bothEmpty)
        return true;
    else if (bothEmpty || root == nullptr || tree.root == nullptr)
        return false;
    else
        return (*root == *tree.root);
}
template <typename Data>
bool BinaryTreeLnk<Data>::operator!=(const BinaryTreeLnk<Data> & btl) const noexcept {
    return !(*this==btl);
}

template <typename Data>
typename BinaryTreeLnk<Data>::MutableNode & BinaryTreeLnk<Data>::Root(){
    if (root == nullptr) {
        throw std::length_error("cannot access root of an empty tree");
    }
    else{
    return *root;
}}
template<typename Data>
typename BinaryTreeLnk<Data>::NodeLnk& BinaryTreeLnk<Data>::Root() const
{
  if(size > 0)
    return *root;
  else
    throw std::length_error("L'albero non ha radice, è vuoto...");
}
template <typename Data>
void BinaryTreeLnk<Data>::Clear() noexcept {
    delete root;
    root=nullptr;
    size=0;
}

//nodelnk

template<typename Data>
bool BinaryTreeLnk<Data>::NodeLnk::operator==(const NodeLnk& o) const noexcept {
    return element == o.element && left == o.left && right == o.right;
}

template<typename Data>
bool BinaryTreeLnk<Data>::NodeLnk::operator!=(const NodeLnk& o) const noexcept {
    return !(*this == o);
}
template<typename Data>
BinaryTreeLnk<Data>::NodeLnk::~NodeLnk()
{
  if(left != nullptr)
    delete left;
  if(right != nullptr)
    delete right;

}
template<typename Data>
inline Data& BinaryTreeLnk<Data>::NodeLnk::Element() noexcept {
    return element;
}
template<typename Data>
inline const Data& BinaryTreeLnk<Data>::NodeLnk::Element()const noexcept {
    return element;
}
template<typename Data>
bool BinaryTreeLnk<Data>::NodeLnk::IsLeaf() const noexcept {
    return !left && !right;
}
template<typename Data>
bool BinaryTreeLnk<Data>::NodeLnk::HasLeftChild() const noexcept {
    return left != nullptr;
}

template<typename Data>
bool BinaryTreeLnk<Data>::NodeLnk::HasRightChild() const noexcept {
    return right != nullptr;
}
template<typename Data>
typename BinaryTreeLnk<Data>::NodeLnk& BinaryTreeLnk<Data>::NodeLnk::LeftChild() const
{
   if(HasLeftChild())
     return *left;
   else
     throw std::out_of_range("LeftChild does not exist");

}

// RightChild
template<typename Data>
typename BinaryTreeLnk<Data>::NodeLnk& BinaryTreeLnk<Data>::NodeLnk::RightChild() const{
  if(HasRightChild())
    return *right;
  else
    throw std::out_of_range("questo nodo non ha figlio destro");

}
/* ************************************************************************** */

template<typename Data>
BinaryTreeLnk<Data>::NodeLnk::NodeLnk(const NodeLnk& o) : element(o.element) {
    
    if (o.left) {
        left = new NodeLnk(*o.left);
    }
    if (o.right) {
        right = new NodeLnk(*o.right);
    }
}

template<typename Data>
BinaryTreeLnk<Data>::NodeLnk::NodeLnk(NodeLnk&& o) noexcept : element(std::move(o.element)), left(o.left), right(o.right) {

    o.left = nullptr;
    o.right = nullptr;
}

template<typename Data>
BinaryTreeLnk<Data>::NodeLnk& BinaryTreeLnk<Data>::NodeLnk::operator=(const NodeLnk& o) {
   
    if (this != &o) {
      
        element = o.element;
        delete left;
        delete right;
       
        if (o.left) {
            left = new NodeLnk(*o.left);
        } else {
            left = nullptr;
        }
        if (o.right) {
            right = new NodeLnk(*o.right);
        } else {
            right = nullptr;
        }
    }
    return *this;
}

template<typename Data>
BinaryTreeLnk<Data>::NodeLnk& BinaryTreeLnk<Data>::NodeLnk::operator=(NodeLnk&& o) noexcept {

    if (this != &o) {
        element = std::move(o.element);
        std::swap(left, o.left);
        std::swap(right, o.right);
        o.left = nullptr;
        o.right = nullptr;
    }
    return *this;
}


}
