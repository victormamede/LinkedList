#include <iostream>
#include <stdexcept>
#include "scheduler.h"

void Scheduler::createPriorityQueue()
{
  queues->push_back(new ProcessList);
}

void Scheduler::removePriorityQueue()
{
  auto popped = queues->back();

  queues->pop_back();

  delete popped;
}

void Scheduler::addProcess(Process *process, ulong priority)
{
  if (priority >= queues->size())
  {
    throw std::invalid_argument("priority list doesn't exist");
  }

  queues->at(priority)->push(process);
}

void Scheduler::executeProcess()
{
  for (int i = queues->size() - 1; i >= 0; i--)
  {
    auto currentQueue = queues->at(i);

    if (currentQueue->size() == 0)
      continue;

    auto currentProcess = currentQueue->shift();
    addProcess(currentProcess, (i > 0) ? (i - 1) : 0);

    return;
  }
}

ulong *Scheduler::getProcessPosition(uint pid)
{
  for (ulong i = 0; i < queues->size(); i++)
  {
    auto currentQueue = queues->at(i);
    for (ulong j = 0; j < currentQueue->size(); j++)
    {
      if (currentQueue->get(j)->pid == pid)
      {
        auto returnValue = new ulong[2]{i, j};
        return returnValue;
      }
    }
  }

  return nullptr;
}

void Scheduler::moveProcess(uint pid, ulong priority)
{
  auto processPosition = getProcessPosition(pid);
  if (processPosition == nullptr)
  {
    throw std::invalid_argument("process not found");
  }

  auto removed = queues->at(processPosition[0])->removeAt(processPosition[1]);
  addProcess(removed, priority);

  delete processPosition;
};
void Scheduler::endProcess()
{
  for (int i = queues->size() - 1; i >= 0; i--)
  {
    auto currentQueue = queues->at(i);

    if (currentQueue->size() == 0)
      continue;

    auto currentProcess = currentQueue->shift();
    delete currentProcess;

    return;
  }
};
void Scheduler::endProcess(uint pid)
{
  auto processPosition = getProcessPosition(pid);
  delete queues->at(processPosition[0])->removeAt(processPosition[1]);
  delete processPosition;
};

void Scheduler::print()
{
  for (ulong i = 0; i < queues->size(); i++)
  {
    auto currentQueue = queues->at(i);
    std::cout
        << "Lista " << i << " [ \n";
    for (ulong j = 0; j < currentQueue->size(); j++)
    {
      currentQueue->get(j)->print();
    }
    std::cout << "] \n";
  }
}