/* MIT License
 *
 * Copyright (c) 2024 Alexander (@alkuzin)
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE. */

#include <torus/statistics.hpp>
#include <iostream>

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
			median = ((data.at((size >> 1) - 1) + data.at(size >> 1))) / 2;
		else
			median = data.at(size >> 1);
			
		return median;
	}
	
	double mode(const std::vector<double> &data)
	{
		if (data.empty())
        	throw std::invalid_argument("data is empty");
		
		std::map<double, int> frequency_map;
    	int    max_frequency;
		double mode;

    	for (const auto& value : data) {
        	frequency_map[value]++;
		}
    	
		mode          = data.at(0);
		max_frequency = 0;
    	
		for (const auto& pair : frequency_map) {
        	if (pair.second > max_frequency) {
            	max_frequency = pair.second;
            	mode          = pair.first;
        	}
   		}

    	return mode;
	}
	
	double dispersion(const std::vector<double> &data)
	{
		if (data.empty())
        	throw std::invalid_argument("data is empty");

		double mean, sum;

		mean = tlib::mean(data);
		sum  = 0;

    	for (const auto& value : data)
			sum += std::pow(value - mean, 2);

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
	
		double lower_pos, upper_pos, lower_val, upper_val, pos, q;

    	std::sort(data.begin(), data.end());

    	pos       = quantile * (data.size() - 1);
    	lower_pos = (int)pos;
    	upper_pos = lower_pos + 1;
    	lower_val = data[lower_pos];
    	upper_val = data[upper_pos];
    	q         = lower_val + (pos - lower_pos) * (upper_val - lower_val);

    	return q;
	}
	
	double interquantile_range(std::vector<double> &data) 
	{
		if (data.empty())
        	throw std::invalid_argument("data is empty");
		
		double quantile_1, quantile_3;

		quantile_1 = tlib::quantile(data, 0.25);
		quantile_3 = tlib::quantile(data, 0.75);
		
		return (quantile_3 - quantile_1);
	}
	
	double skewness(std::vector<double> &data)
	{
		double std, sum, size, mean;
		
		if (data.empty())
        	throw std::invalid_argument("data is empty");

		sum  = 0;
		size = data.size();
		std  = tlib::std_deviation(data);
		mean = tlib::mean(data);

    	for (const auto& value : data)
			sum += std::pow(value - mean, 3);	

		return ((1/(size * std::pow(std, 3))) * sum);
	}
	
	double normal(double x, double mean, double std) 
	{
		double exponent, denominator;

		exponent    = -0.5 * std::pow((x - mean) / std, 2);
		denominator = std::sqrt(2 * M_PI) * std;

		return (1/denominator) * std::exp(exponent);
	}

    double sem(const std::vector<double> &data)
    {
        double std, n;

        std = tlib::std_deviation(data);
        n   = data.size();

        return (std / std::sqrt(n - 1));
    }

    double t_distribution(double t, double v)
    {
        double numerator, denominator;

        numerator   = std::tgamma(0.5 * (v + 1));
        denominator = std::sqrt(v * M_PI) * std::tgamma(0.5 * v);

        return ((numerator / denominator) * std::pow(1 + ((t * t) / v), -(0.5 * (v + 1))));
    }
}