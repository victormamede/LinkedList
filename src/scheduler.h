#pragma once
#include "linked_list.h"
#include "process.h"
#include <vector>

typedef LinkedList<Process> ProcessList;

class Scheduler
{
  std::vector<ProcessList *> *queues;

  ulong *getProcessPosition(uint pid);

public:
  Scheduler() : queues(new std::vector<ProcessList *>) {}

  void createPriorityQueue();
  void removePriorityQueue();

  void addProcess(Process *process, ulong priority = 0);
  void executeProcess();
  void moveProcess(uint pid, ulong priority);
  void endProcess();
  void endProcess(uint pid);

  void print();
};