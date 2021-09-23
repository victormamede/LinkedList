#include "linked_list.h"
#include "payment.h"

template <class T>
void LinkedList<T>::push(T *value)
{
  Node<T> *newNode = new Node(value);

  if (!firstItem)
  {
    firstItem = newNode;
    return;
  }

  Node<T> *currentItem = firstItem;
  while (currentItem->nextNode)
  {
    currentItem = currentItem->nextNode;
  }

  currentItem->nextNode = newNode;
}

template <class T>
Node<T> *LinkedList<T>::getNodeAtPosition(int position)
{
  if (position == 0)
  {
    return firstItem;
  }

  Node<T> *currentItem = firstItem;
  for (int i = 0; i < position; i++)
  {
    currentItem = currentItem->nextNode;
  }

  return currentItem;
}

template <class T>
T *LinkedList<T>::get(int position)
{
  return getNodeAtPosition(position)->value;
}

template <class T>
void LinkedList<T>::insertAtPosition(int position, T *value)
{
  Node<T> *newNode = new Node(value);
  if (position == 0)
  {
    newNode->nextNode = firstItem;
    firstItem = newNode;
    return;
  }

  Node<T> *node = getNodeAtPosition(position - 1);

  newNode->nextNode = node->nextNode;
  node->nextNode = newNode;
}

template <class T>
void freeNode(Node<T> *node)
{
  if (node->nextNode)
  {
    freeNode(node->nextNode);
  }

  delete node->value;
  delete node;
}

template <class T>
LinkedList<T>::~LinkedList()
{
  freeNode(firstItem);
}

template class LinkedList<Payment>;