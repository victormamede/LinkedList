#include "linked_list.h"
#include "payment.h"

template <class T>
void LinkedList<T>::unshift(T *value)
{
  insertAtPosition(0, value);
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
int LinkedList<T>::size()
{
  if (!firstItem)
  {
    return 0;
  }

  int count = 1;
  Node<T> *currentItem = firstItem;
  while (currentItem->nextNode)
  {
    count++;
    currentItem = currentItem->nextNode;
  }

  return count;
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
T *LinkedList<T>::shift()
{
  Node<T> *toRemove = firstItem;
  firstItem = toRemove->nextNode;

  T *value = toRemove->value;
  delete toRemove;

  return value;
}
template <class T>
T *LinkedList<T>::removeAt(int position)
{
  if (position == 0)
  {
    Node<T> *toRemove = firstItem;
    firstItem = toRemove->nextNode;

    return toRemove->value;
  }

  Node<T> *node = getNodeAtPosition(position - 1);

  Node<T> *toRemove = node->nextNode;
  node->nextNode = toRemove->nextNode;

  T *value = toRemove->value;
  delete toRemove;

  return value;
}
template <class T>
T *LinkedList<T>::pop()
{
  if (!firstItem)
  {
    return nullptr;
  }
  if (!firstItem->nextNode)
  {
    T *value = firstItem->value;
    delete firstItem;
    firstItem = nullptr;
    return value;
  }

  Node<T> *lastItem = firstItem->nextNode;
  Node<T> *secondToLastItem = firstItem;
  while (lastItem->nextNode)
  {
    secondToLastItem = lastItem;
    lastItem = lastItem->nextNode;
  }

  T *value = lastItem->value;
  delete lastItem;
  secondToLastItem->nextNode = nullptr;
  return value;
}

template <class T>
T *LinkedList<T>::last()
{
  if (!firstItem)
  {
    return nullptr;
  }

  Node<T> *lastItem = firstItem;
  while (lastItem->nextNode)
  {
    lastItem = lastItem->nextNode;
  }

  return lastItem->value;
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