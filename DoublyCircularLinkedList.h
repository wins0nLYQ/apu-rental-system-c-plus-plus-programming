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
public:
  DCLListNode<T> *head;
  DCLListNode<T> *tail;
  int size;

  DoublyCircularLinkedList() {
    this->size = 0;
    this->head = nullptr;
    this->tail = nullptr;
  };
  ~DoublyCircularLinkedList() {
    // Delete the list
  };

  void insert(const T& object) {
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

  void display() {
    DCLListNode<T> *currentNode = head;
    DCLListNode<T> *firstItem;
    while (currentNode != nullptr && currentNode != firstItem) {
      cout << currentNode->data << endl;
      currentNode = currentNode->next;
      firstItem = head;
    }
  };
};

#endif