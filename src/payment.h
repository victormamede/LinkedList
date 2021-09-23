#pragma once
#include <ctime>

class Payment
{
public:
  time_t expiration;
  double value;
  bool status;

  void print();
};
