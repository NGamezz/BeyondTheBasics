#pragma once

#include <iostream>
#include <vector>
#include <ranges>
#include <algorithm>

namespace Custom
{
	template<typename T>
	class Utility
	{
	public:
		static void Sort(std::vector<T>& collection);
		static void PrintContents(std::vector<T> collection);
	};

	template<typename T>
	void Utility<T>::PrintContents(std::vector<T> collection)
	{
		for (auto x : collection)
		{
			std::cout << x << std::endl;
		}
	};

	template<typename T>
	void Utility<T>::Sort(std::vector<T>& collection)
	{
		std::sort(collection.begin(), collection.end());

	};
}