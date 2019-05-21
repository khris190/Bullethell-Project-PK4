#pragma once
#include <Windows.h>
class Semaphore
{
private:
	int count;
public:
	Semaphore(int count = 0);
	static void Lock_Semaphore(Semaphore sem, int count = 1);
	static void Unlock_Semaphore(Semaphore sem, int count = 1);
	~Semaphore();
};

