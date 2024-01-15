//
//  DoublyLinkedList.cpp
//  List
//  A doubly-liked list implementation for class project CSci 235 Software Design and Analysis II
//
//  Created by Tiziana Ligorio


//

#include "DoublyLinkedList.hpp"

// constructor
template <class T>
DoublyLinkedList<T>::DoublyLinkedList() : item_count_(0), first_(nullptr), last_(nullptr) {}

//copy constructor
template <class T>
DoublyLinkedList<T>::DoublyLinkedList(const DoublyLinkedList<T> &a_list)
{
  item_count_ = a_list.item_count_;
  Node<T> *orig_chain_ptr = a_list.first_; // Points to nodes in original chain

  if (orig_chain_ptr == nullptr)
  { // Original chain is empty
    first_ = nullptr;
    last_ = nullptr;
  }
  else
  {
    // Copy first node
    first_ = new Node<T>();
    first_->setPrevious(nullptr);
    first_->setItem(orig_chain_ptr->getItem());

    // Copy remaining nodes
    Node<T> *new_chain_ptr = first_;            // Points to last node in new chain
    orig_chain_ptr = orig_chain_ptr->getNext(); // Advance original-chain pointer

    while (orig_chain_ptr != nullptr)
    {
      // Get next item from original chain
      T next_item = orig_chain_ptr->getItem();

      // Create a new node containing the next item
      Node<T> *new_node_ptr = new Node<T>(next_item);

      // Link new node to end of new chain
      new_chain_ptr->setNext(new_node_ptr);
      new_node_ptr->setPrevious(new_chain_ptr);

      // Advance pointer to new last node
      new_chain_ptr = new_chain_ptr->getNext();

      // Advance original-chain pointer
      orig_chain_ptr = orig_chain_ptr->getNext();
    } // end while

    // Flag end of chain
    new_chain_ptr->setNext(nullptr);
    last_ = new_chain_ptr;
  } // end if
} // copy constructor

// destructor
template <class T>
DoublyLinkedList<T>::~DoublyLinkedList() { clear(); }

/**@return true if list is empty - item_count_ == 0 */
template <class T>
bool DoublyLinkedList<T>::isEmpty() const { return (item_count_ == 0); }

/**@return the number of items in the list - item_count_ */
template <class T>
size_t DoublyLinkedList<T>::getLength() const { return item_count_; }

/**
 @param position indicating point of insertion
 @param new_element to be inserted in list
 @post new_element is added at position in list (the node previously at that position is now at position+1)
 @return true always - it always inserts, if position > item_count_ it inserts at end of list */
template <class T>
bool DoublyLinkedList<T>::insert(size_t position, const T &new_element)
{
  // Create a new node containing the new entry and get a pointer to position
  Node<T> *new_node_ptr = new Node<T>(new_element);
  Node<T> *pos_ptr = getPointerTo(position);

  // Attach new node to chain
  if (first_ == nullptr)
  {
    //Chain is empty -  Insert first node
    new_node_ptr->setNext(nullptr);
    new_node_ptr->setPrevious(nullptr);
    first_ = new_node_ptr;
    last_ = new_node_ptr;
  }
  else if (pos_ptr == first_)
  {
    // Insert new node at beginning of list
    new_node_ptr->setNext(first_);
    new_node_ptr->setPrevious(nullptr);
    first_->setPrevious(new_node_ptr);
    first_ = new_node_ptr;
  }
  else if (pos_ptr == nullptr)
  {
    //insert at end of list
    new_node_ptr->setNext(nullptr);
    new_node_ptr->setPrevious(last_);
    last_->setNext(new_node_ptr);
    last_ = new_node_ptr;
  }
  else
  {
    // Insert new node before node to which pos_ptr points
    new_node_ptr->setNext(pos_ptr);
    new_node_ptr->setPrevious(pos_ptr->getPrevious());
    pos_ptr->getPrevious()->setNext(new_node_ptr);
    pos_ptr->setPrevious(new_node_ptr);

  } // end if

  item_count_++; // Increase count of entries
  return true;   //It will always insert, if pos_ptr is nullptr it will insert at end
} //end insert

/**
 @param position indicating point of deletion
 @post node at position is deleted, if any. List order is retains
 @return true if ther eis a node at position to be deleted, false otherwise */
template <class T>
bool DoublyLinkedList<T>::remove(size_t position)
{
  //get pointer to position
  Node<T> *pos_ptr = getPointerTo(position);

  if (pos_ptr == nullptr)
    return false;
  else
  {
    // Remove node from chain

    if (first_ == last_)
    {
      // single node in list 
      first_ = nullptr;
      last_ = nullptr;

      // Return node to the system
      pos_ptr->setNext(nullptr);
      delete pos_ptr;
      pos_ptr = nullptr;
    }
    else if (pos_ptr == first_)
    {
      // Remove first node
      first_ = pos_ptr->getNext();
      first_->setPrevious(nullptr);

      // Return node to the system
      pos_ptr->setNext(nullptr);
      delete pos_ptr;
      pos_ptr = nullptr;
    }
    else if (pos_ptr == last_)
    {
      //remove last node
      last_ = pos_ptr->getPrevious();
      last_->setNext(nullptr);

      // Return node to the system
      pos_ptr->setPrevious(nullptr);
      delete pos_ptr;
      pos_ptr = nullptr;
    }
    else
    {
      //Remove from the middle
      pos_ptr->getPrevious()->setNext(pos_ptr->getNext());
      pos_ptr->getNext()->setPrevious(pos_ptr->getPrevious());

      // Return node to the system
      pos_ptr->setNext(nullptr);
      pos_ptr->setPrevious(nullptr);
      delete pos_ptr;
      pos_ptr = nullptr;
    }

    item_count_--; // decrease count of entries
    return true;
  }

} //end remove

/**
 @pre 0 <= position < item_count_
 @param position of item to be retrieved
 @return the item at position in list if there is one, otherwise it throws exception: PrecondViolatedExcep */

template <class T>
T DoublyLinkedList<T>::getItem(size_t position) const
{

  Node<T> *pos_ptr = getPointerTo(position);

  // Enforce precondition
  if (pos_ptr != nullptr)
    return pos_ptr->getItem();
  return nullptr;
}

/**@post the list is empty and item_count_ == 0*/
template <class T>
void DoublyLinkedList<T>::clear()
{
  Node<T> *node_to_delete = first_;
  while (first_ != nullptr)
  {
    first_ = first_->getNext();

    // Return node to the system
    node_to_delete->setNext(nullptr);
    node_to_delete->setPrevious(nullptr);
    delete node_to_delete;

    node_to_delete = first_;
  } // end while
  // head_ptr_ is nullptr; node_to_delete is nullptr
  last_ = nullptr;
  item_count_ = 0;
} //end clear

//position follows classic indexing from 0 to item_count_-1
//if position > item_count it returns nullptr
template <class T>
Node<T> *DoublyLinkedList<T>::getPointerTo(size_t position) const
{

  Node<T> *find = nullptr;
  if (position < item_count_)
  {
    find = first_;
    for (size_t i = 0; i < position; ++i)
    {
      find = find->getNext();
    }
  }

  return find;
} //end getPointerTo

//return head node
template <class T>
Node<T> *DoublyLinkedList<T>::getHeadNode() const
{
  return first_;
}

template <class T>
void DoublyLinkedList<T>::display()
{
  if (getLength() == 0)
  {
    return;
  }
  Node<T> *iterator = first_;
  while (iterator != nullptr)
  {
    if (iterator->getNext() == nullptr)
    {
      std::cout << iterator->getItem() << std::endl;
      return;
    }
    else
    {
      std::cout << iterator->getItem() << " ";
    }
    iterator = iterator->getNext();
  }
  return;
  std::cout << std::endl;
}

template <class T>
void DoublyLinkedList<T>::swapNode(int i, int j)
{
  if (i == j || i < 0 || j > getLength() - 1)
  {
    return;
  }
  if (i > j)
  {
    int temp = i;
    i = j;
    j = temp;
  }

  Node<T> *ptr_i = getPointerTo(i);
  Node<T> *ptr_i_next = ptr_i->getNext();
  Node<T> *ptr_i_prev = ptr_i->getPrevious();
  Node<T> *ptr_j = getPointerTo(j);
  Node<T> *ptr_j_next = ptr_j->getNext();
  Node<T> *ptr_j_prev = ptr_j->getPrevious();

  if (i == 0) //cases of 1st element involved in swapping
  {
    if (j == getLength() - 1) //case: swap first and last node
    {
      if (getLength() == 2) //there are only 2 nodes
      {
        ptr_j->setNext(ptr_i);
        ptr_j->setPrevious(nullptr);
        ptr_i->setNext(nullptr);
        ptr_i->setPrevious(ptr_j);

        first_ = ptr_j;
        last_ = ptr_i;
      }
      else if (getLength() > 2) //j is last item but more than 2 nodes
      {
        ptr_j->setNext(ptr_i_next);
        ptr_j->setPrevious(nullptr);
        ptr_i_next->setPrevious(ptr_j);

        ptr_i->setNext(nullptr);
        ptr_i->setPrevious(ptr_j_prev);
        ptr_j_prev->setNext(ptr_i);

        first_ = ptr_j;
        last_ = ptr_i;
      }
    }
    else if (getLength() > 2 && j == 1) //if j is the 2nd item but more than 2 nodes
    {
      ptr_i->setNext(ptr_j_next);
      ptr_i->setPrevious(ptr_j);
      ptr_j->setNext(ptr_i);
      ptr_j->setPrevious(nullptr);
      ptr_j_next->setPrevious(ptr_i);

      first_ = ptr_j;
    }
    else //any other case that's a node in the middle of the list
    {
      ptr_i->setNext(ptr_j_next);
      ptr_j_next->setPrevious(ptr_i);
      ptr_i->setPrevious(ptr_j_prev);
      ptr_j_prev->setNext(ptr_i);
      ptr_i_next->setPrevious(ptr_j);
      ptr_j->setNext(ptr_i_next);
      ptr_j->setPrevious(nullptr);

      first_ = ptr_j;
    }
  }
  else if (i > 0 && j != getLength() - 1) //cases of middle elements swap
  {
    if (j - i == 1) //case where swap successive middle elements
    {
      ptr_i->setNext(ptr_j_next);
      ptr_i->setPrevious(ptr_j);

      ptr_j->setNext(ptr_i);
      ptr_j->setPrevious(ptr_i_prev);

      ptr_i_prev->setNext(ptr_j);
      ptr_j_next->setPrevious(ptr_i);
    }

    else //case where we swap middle elements that are not successive
    {
      ptr_i->setNext(ptr_j_next);
      ptr_i->setPrevious(ptr_j_prev);

      ptr_j->setNext(ptr_i_next);
      ptr_j->setPrevious(ptr_i_prev);

      ptr_i_prev->setNext(ptr_j);
      ptr_j_prev->setNext(ptr_i);

      ptr_j_next->setPrevious(ptr_i);
      ptr_i_next->setPrevious(ptr_j);
    }
  }
  else if (i > 0 && j == getLength() - 1) //cases where we swap with the last element but first element isn't involved
  {
    if (j - 1 == i) //case where we swap last element with 2nd-to-last element
    {
      ptr_i->setNext(nullptr);
      ptr_i->setPrevious(ptr_j);

      ptr_j->setNext(ptr_i);
      ptr_j->setPrevious(ptr_i_prev);

      ptr_i_prev->setNext(ptr_j);
      last_ = ptr_i;
    }

    else //other case where its last element with some middle element that isnt 2nd-to-last
    {
      ptr_i->setNext(ptr_j_next);
      ptr_i->setPrevious(ptr_j_prev);

      ptr_j->setNext(ptr_i_next);
      ptr_j->setPrevious(ptr_i_prev);

      ptr_j_prev->setNext(ptr_i);

      ptr_i_prev->setNext(ptr_j);
      ptr_i_next->setPrevious(ptr_j);
      last_ = ptr_i;
    }
  }
}


template <class T>
void DoublyLinkedList<T>::swap(int i, int j)
{

  Node<T>* ptr_i = getPointerTo(i);
  Node<T>* ptr_j = getPointerTo(j);

  // indices out of bounds
  if (ptr_i == nullptr || ptr_j == nullptr)
  {
    return;
  }
  else //swap
  {
    T temp = ptr_i->getItem();
    ptr_i->setItem(ptr_j->getItem());
    ptr_j->setItem(temp);
  }
  
}