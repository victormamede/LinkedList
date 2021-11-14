#include <iostream>
#include "process.h"

void Process::print()
{
  std::cout << "[" << pid << "] " << name << "\n";
}