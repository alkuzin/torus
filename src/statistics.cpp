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
	
	double median(const std::vector<double> &data)
	{
		if (data.empty())
        	throw std::invalid_argument("vector is empty");

		double median;
		size_t size;

		size = data.size();

		if(size % 2 == 0)
			median = (data.at((size / 2) - 1) + data.at(size / 2)) / 2;
		else
			median = data.at(size / 2);
			
		return median;
	}
}
