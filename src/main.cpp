#include <iostream>
#include <string>
#include "scheduler.h"
#include "process.h"

Process *createProcess();
ulong promptListIndex();
uint promptPid();

int main()
{
  Scheduler scheduler;
  system("clear");

  while (true)
  {
    scheduler.print();

    std::string input;

    std::cout << "\n";
    std::cout << "Escolha uma opção: \n";
    std::cout << "1: Criar fila de prioridade \n";
    std::cout << "2: Remover fila de prioridade \n";
    std::cout << "3: Adicionar processo \n";
    std::cout << "4: Executar próximo processo \n";
    std::cout << "5: Mover processo \n";
    std::cout << "6: Finalizar processo \n";
    std::cout << "7: Finalizar processo PID \n";
    std::cout << "\n";
    std::cout << "0: Sair\n";

    std::getline(std::cin, input);

    if (input == "1")
    {
      scheduler.createPriorityQueue();
    }
    else if (input == "2")
    {
      scheduler.removePriorityQueue();
    }
    else if (input == "3")
    {
      scheduler.addProcess(createProcess(), promptListIndex());
    }
    else if (input == "4")
    {
      scheduler.executeProcess();
    }
    else if (input == "5")
    {
      try
      {
        scheduler.moveProcess(promptPid(), promptListIndex());
      }
      catch (const std::invalid_argument &e)
      {
        std::cout << "PID não encontrado\n\n";
      }
    }
    else if (input == "6")
    {
      scheduler.endProcess();
    }
    else if (input == "7")
    {
      try
      {
        scheduler.endProcess(promptPid());
      }
      catch (const std::invalid_argument &e)
      {
        std::cout << "PID não encontrado\n\n";
      }
    }

    if (input == "0")
    {
      break;
    }
    system("clear");
  }

  return 0;
}

Process *createProcess()
{
  auto process = new Process;
  std::string input;

  std::cout << "Especifique o PID: \n";
  std::getline(std::cin, input);
  process->pid = std::stoi(input);

  std::cout << "Especifique o nome do processo: \n";
  std::getline(std::cin, input);
  process->name = input;

  return process;
}

ulong promptListIndex()
{
  std::string input;

  std::cout << "Especifique o índice da Lista: \n";
  std::getline(std::cin, input);
  return std::stoul(input);
}

uint promptPid()
{
  std::string input;

  std::cout << "Especifique o PID do processo: \n";
  std::getline(std::cin, input);
  return std::stoul(input);
}