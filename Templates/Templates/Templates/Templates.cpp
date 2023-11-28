#include <iostream>
#include "Queue.h"
#include <vector>
#include "Utility.h"

int main()
{
	std::vector<std::string> stringVector{ "b", "woudhawd", "iuug", "iuhwuiagugdwa", "a" };
	std::vector<float> floatVector{ 1, 890, 2, 3987341, 98721, 2 };

	Custom::Utility<float>::Sort(floatVector);
	Custom::Utility<float>::PrintContents(floatVector);

	Custom::Utility<std::string>::Sort(stringVector);
	Custom::Utility<std::string>::PrintContents(stringVector);

	Custom::Queue<std::string> stringQueue;
	stringQueue.Put("First Element.");
	stringQueue.Put("Last Element.");
	std::cout << stringQueue.Get() << std::endl;
	std::cout << stringQueue.Size() << std::endl;
}