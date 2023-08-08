#ifndef DOUBLYCIRCULARLINKEDLIST_H
#define DOUBLYCIRCULARLINKEDLIST_H

#include <string>

template <class T>
class DCLListNode
{
public:
  T data;
  DCLListNode<T> *prev;
  DCLListNode<T> *next;
};

template <class T>
class DoublyCircularLinkedList
{
private:
  int size;
  DCLListNode<T> *current;

public:
  DCLListNode<T> *head;
  DCLListNode<T> *tail;

  DoublyCircularLinkedList()
  {
    this->size = 0;
    this->head = nullptr;
    this->tail = nullptr;
    this->current = nullptr;
  };

  ~DoublyCircularLinkedList(){
      // Delete the list
      if (head == nullptr) {
        return;
      }

      DCLListNode<T> *current = head;
      do {
        DCLListNode<T> *nextNode = current->next;
        delete current;
        current = nextNode;
      } while (current != head);

      head = nullptr;
  };

  void insertAtBegin(const T &object)
  {
    DCLListNode<T> *node = new DCLListNode<T>;
    node->data = object;
    node->prev = tail;
    node->next = head;
    head = node;

    if (head == nullptr)
    {
      tail = node;
      head->prev = node;
      head->next = node;
    }
    else
    {
      // Link the new object to the next node's previous pointer
      node->next->prev = node;

      // Link the tail object next pointer to the new object
      tail->next = node;
    }
    size++;
  };

  void insertAtEnd(const T &object)
  {
    DCLListNode<T> *node = new DCLListNode<T>;
    node->data = object;
    node->prev = tail;
    node->next = head;
    tail = node;

    if (head == nullptr)
    {
      head = node;
      head->next = node;
      head->prev = node;
    }
    else
    {
      // Link the new object to the previous node's next pointer
      node->prev->next = node;

      // Link the head object previous pointer to the new object
      head->prev = node;
    }

    size++;
  };

  void insertAtIndex(const T &object, int index)
  {
    DCLListNode<T> *currentNode = head;
    DCLListNode<T> *node = new DCLListNode<T>;
    node->data = object;

    if (index < 0 || index > size)
    {
      cout << "Invalid Index";
    }
    else
    {
      if (index == 0)
      {
        insertAtBegin(object);
      }
      else if (index == size)
      {
        insertAtEnd(object);
      }
      else
      {
        for (int count = 0; count <= index; count++)
        {
          if (count == index)
          {
            node->next = currentNode;
            node->prev = currentNode->prev;
            currentNode->prev->next = node;
            currentNode->prev = node;
            size++;
          }
          
          currentNode = currentNode->next;
        }
      }
    }
  }

  void removeAtBegin() {
    if (size > 0)
    {
      DCLListNode<T> *toBeDeleted = head;
      toBeDeleted->next->prev = toBeDeleted->prev;
      toBeDeleted->prev->next = toBeDeleted->next;
      head = toBeDeleted->next;
      delete toBeDeleted;
      size--;
    }
    else {
      throw std::out_of_range("Index Out of Bound...");
    }
  }

  void removeAtEnd() {
    if (size > 0) {
      DCLListNode<T> *toBeDeleted = tail;
      toBeDeleted->next->prev = toBeDeleted->prev;
      toBeDeleted->prev->next = toBeDeleted->next;
      tail = toBeDeleted->prev;
      delete toBeDeleted;
      size--;
    }
    else {
      throw std::out_of_range("Index Out of Bound...");
    }
  }

  void removeAtIndex(const int index) {
    DCLListNode<T> *currentNode = head;

    if (index < 0 || index > size)
    {
      throw std::out_of_range("Index Out of Bound...");
    }
    else {
      for (int count = 0; count <= index; count++)
      {
        if (count == index)
        {
          currentNode->prev->next = currentNode->next;
          currentNode->next->prev = currentNode->prev;
          delete currentNode;
          size--;
        }

        currentNode = currentNode->next;
      }
    }
  }

  T& removeCurrent() {
    if (size > 0) {
      DCLListNode<T> *toBeDeleted = current;
      toBeDeleted->next->prev = toBeDeleted->prev;
      toBeDeleted->prev->next = toBeDeleted->next;
      current = toBeDeleted->next;
      delete toBeDeleted;
      size--;
      return current->data;
    }
    else {
      throw std::out_of_range("Index Out of Bound...");
    }
  }

  T& getFirst() {
    current = head;
    return current->data;
  }

  T& getLast() {
    current = tail;
    return current->data;
  }

  T& getCurrent() {
    return current->data;
  }

  T& get(int index) {
    DCLListNode<T> *currentNode = head;

    if (index < 0 || index >= size)
    {
      cout << "Item Not Found...";
    }
    else {
      if (index == 0)
      {
        return head->data;
      }
      else if (index == size-1)
      {
        return tail->data;
      }
      else
      {
        for (int count = 0; count <= index; count++)
        {
          if (count == index)
          {
            return currentNode->data;
          }

          currentNode = currentNode->next;
        }
      }
    }
  }

  T& nextItem() {
    current = current->next;
    return current->data;
  }

  T& prevItem() {
    current = current->prev;
    return current->data;
  }

  int getSize()
  {
    return size;
  }

  int getIndex() {
    DCLListNode<T> *currentNode = head;
    int index = -1;

    if (head != nullptr) {
      index++;
    }

    while (currentNode != nullptr && currentNode != current)
    {
      currentNode = currentNode->next;
      index++;
    }

    return index;
  }

  void mergeWith(DoublyCircularLinkedList<T> &secList)
  {
    for (int size = 0; size < secList.getSize(); size++) {
      insertAtEnd(secList.get(size));
    }
  }

  void replace(const T &object, int index) {
    DCLListNode<T> *currentNode = head;

    if (index < 0 || index > size)
    {
      cout << "Invalid Index";
    }
    else {
      if (index == 0)
      {
        head->data = object;
      }
      else if (index == size)
      {
        tail->data = object;
      }
      else
      {
        for (int count = 0; count <= index; count++)
        {
          if (count == index)
          {
            currentNode->data = object;
            break;
          }

          currentNode = currentNode->next;
        }
      }
    }
  }
};

#endif