#include "Semaphore.h"



Semaphore::Semaphore(int count)
{
	this->count = count;
}

void Semaphore::Lock_Semaphore(Semaphore sem, int count)
{
	while (sem.count < count)
	{
		Sleep(10);
	}
	sem.count -= count;
}

void Semaphore::Unlock_Semaphore(Semaphore sem, int count)
{
	sem.count += count;
}

Semaphore::~Semaphore()
{
}
