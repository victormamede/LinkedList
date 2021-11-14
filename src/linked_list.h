#pragma once
#include <iostream>

template <class T>
class Node
{
public:
  Node(T *_value) : value(_value), nextNode(nullptr) {}
  T *value;
  Node<T> *nextNode;
};

template <class T>
class LinkedList
{
  Node<T> *firstItem;

  Node<T> *getNodeAtPosition(ulong position);

public:
  LinkedList() : firstItem(nullptr) {}

  void unshift(T *value);
  void insertAtPosition(ulong position, T *value);
  void push(T *value);

  T *shift();
  T *removeAt(ulong position);
  T *pop();

  T *get(ulong position);
  size_t size();
  T *last();

  ~LinkedList();
};