#include <iostream>
#include "payment.h"

void Payment::print()
{
  std::cout << "---------------------------------\n";
  std::cout << "Expiration: " << expiration << "\n";
  std::cout << "Valor: " << value << "\n";
  std::cout << "Status: " << status << "\n";
  std::cout << "---------------------------------\n";
}