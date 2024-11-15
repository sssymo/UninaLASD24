#include "../container/linear.hpp"
#include "list.hpp"
#include <stdexcept>
using ulong = unsigned long;
namespace lasd {

/* ************************************************************************** */

// ...

/* ************************************************************************** */

template<typename Data>
    List<Data>::List(MappableContainer<Data> && con){
        con.Map(
            [this](Data & dat){
            InsertAtBack(std::move(dat));
        }
        );
    }

    //Copy constructor (List)
    
    template<typename Data>
    List<Data>::List(const List<Data> & lst){
        if(lst.tail != nullptr){
            tail = new Node(*lst.tail);
            head = lst.head->Clone(tail);
            size = lst.size;
        }
    }



    //Move constructor (List)
    template<typename Data>
    List<Data>::List(List<Data> && lst ) noexcept{
        std::swap(head, lst.head);
        std::swap(tail, lst.tail);
        std::swap(size, lst.size);
    }

    //Destructor
    template<typename Data>
    List<Data>::~List(){
        delete head;
    }

template<typename Data>
List<Data> & List<Data>::operator=(const List<Data> & lst) {
    if(size<=lst.size){
        if(tail==nullptr){
            List<Data> * tmplst =new List<Data>(lst);
            std::swap(*tmplst,*this);
            delete tmplst;
        }else{
            Node * ocur=lst.head;
            for(Node * ncur=head;ncur!=nullptr;ncur=ncur->next , ocur=ocur->next){
                ncur->element=ocur->element;
            }
            if(ocur!=nullptr){
                Node * newtail=new Node(*lst.tail);
                tail->next=ocur->Clone(newtail);
                tail=newtail;
            }
        }
    }else{
        if(lst.tail==nullptr){
            delete head;
            head=tail=nullptr;
        }else{
            Node * ncur= head;
            for(Node * ocur =lst.head;ocur!=nullptr;ocur=ocur->next,tail=ncur,ncur=ncur->next){
                ncur->element=ocur->element;
            }delete ncur;
            tail->next=nullptr;
        }
    }
    size=lst.size;
    return *this;
}


    //MOVE ASSIGN
    template<typename Data>
List<Data>& List<Data>::operator=(List<Data> && list) noexcept {
    std::swap(head,list.head);
    std::swap(tail,list.tail);
    std::swap(size,list.size);
    return *this;
}

    //Specific constructor (Node)
    template<typename Data>
    List<Data>::Node::Node(Data && dat) noexcept {
        std::swap(element, dat);
    }

    //Move constructor (Node)
    template<typename Data>
    List<Data>::Node::Node(Node && nod) noexcept{
        std::swap(element, nod.element);
        std::swap(next, nod.next);
    }

    //Destructor
    
    template<typename Data>
    List<Data>::Node::~Node(){
        delete next;
    }


    //Comparison operators (Node)
template<typename Data>
bool List<Data>::Node::operator==(const Node &nod) const noexcept {
    return (element == nod.element) &&
           ((next == nullptr && nod.next == nullptr) || (next != nullptr && nod.next != nullptr && *next == *(nod.next)));
}

    template<typename Data>
    inline bool List<Data>::Node::operator!=(const Node & nod) const noexcept{
        return !(*this == nod);
    }

    //Specific member funcstions (Node)
    template<typename Data>
    typename List<Data>::Node * List<Data>::Node::Clone(Node * tail){
        if(next == nullptr){
            return tail;
        }else{
            Node * node = new Node(element);
            node->next = next->Clone(tail);
            return node;
        }
    }



    //Specific constructors (List)
    template<typename Data>
    List<Data>::List(const TraversableContainer<Data> & con){
        con.Traverse(
            [this](const Data & dat){
                InsertAtBack(dat);
            }
        );
    }

  
template<typename Data>
inline bool List<Data>::operator==(const List<Data> &lst) const noexcept {
    return(size==lst.size) && ((head==nullptr && lst.head==nullptr) || (head!=nullptr && lst.head!=nullptr && (*head == *lst.head)));
}
    

 
    


    template<typename Data>
    inline bool List<Data>::operator!=(const List<Data> & lst) const noexcept{
        return !(*this == lst);
    }

    //Specific member functions (List)
    template<typename Data>
    void List<Data>::InsertAtFront(const Data & dat){
        Node * begin = new Node(dat);
        begin->next = head;
        head = begin;
        if(tail == nullptr){
            tail = head;
        }
        ++size;
    }

    template<typename Data>
    void List<Data>::InsertAtFront(Data && dat){
        Node * begin = new Node(std::move(dat));
        begin->next = head;
        head = begin;
        if(tail==nullptr){
            tail=head;
        }
        ++size;
    }

    //Specific member functions (List) (inherited from ClearableContainer)
    template<typename Data>
    void List<Data>::Clear(){
        delete head;
        head = tail = nullptr;
        size = 0;
    }
    
    template<typename Data>
    bool List<Data>::Insert(const Data & dat){
        for(Node * cur = head; cur != nullptr; cur = cur->next){
            if(cur->element == dat){
                return false;
            }
        }
        InsertAtBack(dat);
        
        return true;
    }

    template<typename Data>
    bool List<Data>::Insert(Data && dat){
        for(Node * cur = head; cur != nullptr; cur = cur->next){
            if(cur->element == dat){
                return false;
            }
        }
        InsertAtBack(std::move(dat));
        
        return true;
    }

   template <typename Data>
   Data & List<Data>::operator[](const ulong index){
    if(index < size){
        Node * cur = head;
        for(ulong idx = 0; idx<index ; ++idx, cur = cur->next){}
        return cur->element;
    }else{
        throw std::out_of_range("Access at index"+std::to_string(index));
    }
   }

    template<typename Data>
    bool List<Data>::Remove(const Data & dat){
        Node * last = nullptr;
        for (Node **cur = &head; *cur != nullptr; last = *cur, cur = &((*cur)->next)){
            if((*cur)->element == dat){
                Node * node = *cur;
                *cur = node->next;
                node->next = nullptr;
                delete node;
                size --;
                if(tail == node){
                    tail = last;
                }
                return true;
            }
        }
        return false;    }

   template<typename Data>
   const Data & List<Data>::operator[](const ulong index) const {
    if(index < size){
        Node * cur = head;
        for(ulong idx = 0; idx < index ; ++idx, cur = cur->next){}
        return cur->element;
    }else{
         throw std::out_of_range("Access at index"+std::to_string(index));
    }
   }



   template<typename Data>
   const Data & List<Data>::Front() const{
    if(head != nullptr){
        return head->element;
    }else{
        throw std::length_error("accesso a lista vuota");
    }
   }

   template<typename Data>
    Data & List<Data>::Front() {
    if(head != nullptr){
        return head->element;
    }else{
        throw std::length_error("accesso a lista vuota");
    }
   }

   template<typename Data>
    Data & List<Data>::Back() {
    if(tail != nullptr){
        return tail->element;
    }else{
        throw std::length_error("accesso a lista vuota");
    }
   }
   template<typename Data>
    const Data & List<Data>::Back() const{
    if(tail != nullptr){
        return tail->element;
    }else{
        throw std::length_error("accesso a lista vuota");
    }
   }

   //Specific member functions (List) (inherited from TraversableContainer)
   template<typename Data>
   inline void List<Data>::Traverse(TraverseFun fun) const {
    PreOrderTraverse(fun, head);
   }

    template<typename Data>
    void List<Data>::RemoveFromFront(){
        if(head!=nullptr){
            Node * front = head;
            if(tail == head){
                head = tail = nullptr;
            }else{
                head = head->next;
            }
            --size;
            front->next = nullptr;
            delete front;
        }else{
            throw std::length_error("accesso a lista vuota");
        }

    }



template<typename Data>
   Data List<Data>::FrontNRemove(){
        if(head != nullptr){
            Node * front = head;
            if(tail == head){
                head = tail = nullptr;
            }else{
                head = head->next;
            }
            --size;
            front->next = nullptr;
            Data dat(std::move(front->element));
            delete front;
            return dat;
        }else{
            throw std::length_error("aaccess to an empty list");
        }
   }
   
   template<typename Data>
   void List<Data>::InsertAtBack(const Data & dat){
        Node * end = new Node(dat);
        if(tail == nullptr){
            head = end;
        }else{
            tail->next = end;
        }
        tail = end;
        ++size;
   }

   template<typename Data>
void List<Data>::InsertAtBack(Data && dat) {
    Node * end = new Node(std::move(dat)); 

    if (tail == nullptr) {
        head = end;
    } else {
        tail->next = end;
    }

    tail = end;
    ++size;
}




template <typename Data>
    void List<Data>::PreOrderTraverse(TraverseFun fun) const{
        PreOrderTraverse(fun, head);
    }

template <typename Data>
    void List<Data>::PostOrderTraverse(TraverseFun fun, const Node * cur)const{
if(cur!=nullptr){
    PostOrderTraverse(fun,cur->next);
    fun(cur->element);
}
    }

    template <typename Data>
    void List<Data>::PreOrderTraverse(TraverseFun fun,const Node * cur) const{
        for(;cur!=nullptr;cur=cur->next){
        fun(cur->element);
        }
    }

    //Auxiliary member functions (List) (for MappableContainer)
    template <typename Data>
    void List<Data>::PreOrderMap(MapFun fun, Node * cur){
        for(; cur!=nullptr ; cur = cur->next){
            fun(cur->element);
        }
    }

    template <typename Data>
    void List<Data>::PostOrderMap(MapFun fun,Node * cur){
        if(cur!=nullptr){
            PostOrderMap(fun,cur->next);
            fun(cur->element);

        }
        
    }




    ///dubbi
    template<typename Data>
void List<Data>::Map(MapFun fun) {
    PreOrderMap(fun, head);
}

template<typename Data>
void List<Data>::PreOrderMap(MapFun fun) {
    PreOrderMap(fun, head);
}



template<typename Data>
void List<Data>::PostOrderMap(MapFun fun) {
    PostOrderMap(fun, head);
}


template<typename Data>
void List<Data>::PostOrderTraverse(TraverseFun fun) const {
    PostOrderTraverse(fun, head);
}



};
