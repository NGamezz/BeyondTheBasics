#pragma once

#include <vector>
#include <ranges>
#include <algorithm>

namespace Custom
{
	template<typename T>
	class Utility
	{
	public:
		T Sort(std::vector<T>& collection);
	};

	template<typename T>
	inline T Utility<T>::Sort(std::vector<T>& collection)
	{
		collection = std::sort(collection.begin(), collection.end());
	}
}