#include <iostream>
#include "Queue.h"
#include <vector>
#include "Utility.h"

int main()
{
	Custom::Utility<std::string> utilityString;
	Custom::Utility<float> utilityFloat;

	std::vector<std::string> stringVector{ "w", "woudhawd", "iuug", " iuhwuiagugdwa", "a" };
	std::vector<float> floatVector{ 1, 890, 2, 3987341, 98721, 2 };

	auto printAllContents = [](std::vector<float> collection) -> void
		{
			for (int i = 0; i < collection.size(); i++)
			{
				std::cout << collection[i] << std::endl;
			}
		};

	printAllContents(floatVector);
	utilityFloat.Sort(floatVector);
	printAllContents(floatVector);

	Custom::Queue<std::string> stringQueue;
	stringQueue.Put("First Element.");
	stringQueue.Put("Last Element.");
	std::cout << stringQueue.Get() << std::endl;
	std::cout << stringQueue.Size() << std::endl;
}