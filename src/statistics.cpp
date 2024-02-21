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
        	throw std::invalid_argument("data is empty");

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
	
	double dispersion(const std::vector<double> &data)
	{
		if (data.empty())
        	throw std::invalid_argument("data is empty");

		double mean;
		double sum;

		mean = tlib::mean(data);
		sum = 0;

    	for (const auto& value : data) {
			sum += std::pow(value - mean, 2);	
		}

		return (sum / data.size());
	}
	
	double std_deviation(const std::vector<double> &data) 
	{
		if (data.empty())
        	throw std::invalid_argument("data is empty");

		return std::sqrt(tlib::dispersion(data));
	}

	double quantile(std::vector<double> &data, const double quantile)
	{
		if (data.empty() || quantile < 0.0 || quantile > 1.0)
        	throw std::invalid_argument("data is empty or incorrect quantile");
	
		double lower_pos;
		double upper_pos;
		double lower_val;
		double upper_val;
		double pos;
		double q;

    	std::sort(data.begin(), data.end());

    	pos = quantile * (data.size() - 1);
    	lower_pos = (int)pos;
    	upper_pos = lower_pos + 1;
    	lower_val = data[lower_pos];
    	upper_val = data[upper_pos];
    	q = lower_val + (pos - lower_pos) * (upper_val - lower_val);

    	return q;
	}
}
