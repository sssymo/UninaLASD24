#include "stacklst.hpp"

namespace lasd {

  // copy assignment
  template <typename Data>
  inline StackLst<Data> & StackLst<Data>::operator=(const StackLst<Data> & stk) {
      List<Data>::operator=(stk);
      return *this;
  }

  // move assignment
  template <typename Data>
  inline StackLst<Data> & StackLst<Data>::operator=(StackLst<Data> && stk) noexcept {
      List<Data>::operator=(std::move(stk));
      return *this;
  }

  // comparison operators
  template <typename Data>
  bool StackLst<Data>::operator==(const StackLst<Data>& stk) const noexcept {
      return List<Data>::operator==(stk);
  }

  template <typename Data>
  bool StackLst<Data>::operator!=(const StackLst<Data>& stk) const noexcept {
      return !(*this == stk);
  }

  // specific member functions from Stack
  template <typename Data>
  const Data& StackLst<Data>::Top() const {
      return List<Data>::Front();
  }
    template <typename Data>
   Data& StackLst<Data>::Top()  {
      return List<Data>::Front();
  }


  template <typename Data>
  void StackLst<Data>::Pop() {
      return List<Data>::RemoveFromFront();
  }

  template <typename Data>
  Data StackLst<Data>::TopNPop() {

      return List<Data>::FrontNRemove();
  }

  template <typename Data>
  void StackLst<Data>::Push(const Data& value) {
      List<Data>::InsertAtFront(value);
  }

  template <typename Data>
  void StackLst<Data>::Push(Data&& value) {
      List<Data>::InsertAtFront(std::move(value));
  }

} ;
