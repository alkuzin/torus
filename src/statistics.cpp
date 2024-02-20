#include <iostream>
#include "../include/statistics.hpp"

namespace tlib 
{
	double mean(const std::vector<double> &data)
	{
		if (data.empty())
        	throw std::invalid_argument("data is empty");

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
	
	double mode(const std::vector<double> &data)
	{
		if (data.empty())
        	throw std::invalid_argument("data is empty");
		
		std::map<double, int> frequency_map;
		double mode;
    	int max_frequency;

    	for (const auto& value : data) {
        	frequency_map[value]++;
		}
    	
		mode = data.at(0);
		max_frequency = 0;
    	
		for (const auto& pair : frequency_map) {
        	if (pair.second > max_frequency) {
            	max_frequency = pair.second;
            	mode = pair.first;
        	}
   		}

    	return mode;
	}
}
