#include <iostream>
#include "Inventory.h"
#include <thread>
#include "Utility.h"

Inventory<int> inventory{};
std::vector<std::thread> threads;

void AddToInventory()
{
	for (int i = 0; i < 10; i++)
	{
		inventory.Put(i);
	}
}

int main()
{
	for (int i = 0; i <= 5; i++)
	{
		threads.push_back(std::thread(AddToInventory));
	}

	for (auto& thread : threads)
	{
		thread.join();
	}

	Custom::Utility::PrintContents(inventory.GetContents());
}