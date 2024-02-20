#include <iostream>
#include "../include/statistics.hpp"

namespace tlib 
{
	double mean(const std::vector<double> &data)
	{
		if (data.empty())
        	throw std::invalid_argument("vector is empty");

		return (std::accumulate(data.begin(), data.end(), 0.0) / data.size());
	}
}
