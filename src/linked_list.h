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

  void unshift(T *value);
  void insertAtPosition(int position, T *value);
  void push(T *value);

  T *shift();
  T *removeAt(int position);
  T *pop();

  T *get(int position);
  int size();
  T *last();

  ~LinkedList();
};