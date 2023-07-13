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

public:
  DCLListNode<T> *head;
  DCLListNode<T> *tail;
  DCLListNode<T> *current;

  DoublyCircularLinkedList()
  {
    this->size = 0;
    this->head = nullptr;
    this->tail = nullptr;
  };

  ~DoublyCircularLinkedList(){
      // Delete the list
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

  T& get(int index) {
    DCLListNode<T> *currentNode = head;

    if (index < 0 || index > size)
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

  }

  T& prevItem() {
    
  }

  void display()
  {
    DCLListNode<T> *currentNode = head;
    DCLListNode<T> *firstItem;
    while (currentNode != nullptr && currentNode != firstItem)
    {
      std::cout << currentNode->data << std::endl;
      currentNode = currentNode->next;
      firstItem = head;
    }
  };

  int getSize()
  {
    return size;
  }
};

#endif