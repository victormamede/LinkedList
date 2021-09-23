#include <iostream>
#include "payment.h"
#include "linked_list.h"

Payment *createRandomPayment();
int randomCount = 0;

double doubleRand()
{
  std::srand(std::time(0) + randomCount);
  randomCount++;
  return double(rand()) / (double(RAND_MAX) + 1.0);
}

int main()
{
  LinkedList<Payment> list;

  Payment *thirdPosition = createRandomPayment();

  list.push(createRandomPayment());
  list.push(thirdPosition);
  list.push(createRandomPayment());
  list.push(createRandomPayment());
  list.push(createRandomPayment());

  std::cout << "Segunda posição: \n";
  thirdPosition->print();
  std::cout << "Segunda posição get: \n";
  list.get(1)->print();

  Payment *toInsert = createRandomPayment();

  std::cout << "Terceira posição antes do insert: \n";
  list.get(2)->print();
  std::cout << "Quarta posição antes do insert: \n";
  list.get(3)->print();

  list.insertAtPosition(3, toInsert);

  std::cout << "Terceira posição depois do insert: \n";
  list.get(2)->print();
  std::cout << "Quinta posição depois do insert: \n";
  list.get(4)->print();

  std::cout
      << "Para inserir na quarta posição: \n";
  toInsert->print();
  std::cout << "Inserido na quarta posição: \n";
  list.get(3)->print();

  std::cout << "Segunda posição antes do remove: \n";
  list.get(1)->print();
  std::cout << "Terceira posição antes do remove: \n";
  list.get(2)->print();
  std::cout << "Quarta posição antes do remove: \n";
  list.get(3)->print();

  Payment *removed = list.removeAt(2);

  std::cout << "Segunda posição após o remove: \n";
  list.get(1)->print();
  std::cout << "Terceira posição após o remove: \n";
  list.get(2)->print();
  std::cout << "Item removido: \n";
  removed->print();

  delete removed;

  std::cout << "Última posição antes do pop: \n";
  list.last()->print();
  std::cout << "Item removido: \n";
  Payment *popped = list.pop();
  popped->print();
  delete popped;
  std::cout << "Última posição após o pop: \n";
  list.last()->print();

  return 0;
}

Payment *createRandomPayment()
{
  Payment *payment = new Payment();
  payment->value = doubleRand() * 1000;
  payment->expiration = doubleRand() * 1000;
  payment->status = doubleRand() > 0.5;

  return payment;
}