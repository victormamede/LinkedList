#pragma once

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

  Node<T> *getNodeAtPosition(int position);

public:
  LinkedList() : firstItem(nullptr) {}

  void push(T *value);
  T *get(int position);
  void insertAtPosition(int position, T *value);

  ~LinkedList();
};