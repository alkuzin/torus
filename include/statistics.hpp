/*
MIT License

Copyright (c) 2024 Alexander 

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE. 
*/

#ifndef TORUS_STATISTICS_HPP
#define TORUS_STATISTICS_HPP

#include <algorithm>
#include <numeric>
#include <vector>
#include <cmath>
#include <map>

namespace tlib
{
	// measure of central tendency of a finite set of numbers
	double mean(const std::vector<double> &data);

	// middle value separating the greater and 
	// lesser halves of a data set
	double median(const std::vector<double> &data);

	// most frequent value in a data set
	double mode(const std::vector<double> &data);

	// measure of spread of data
	double dispersion(const std::vector<double> &data);

	// measure of the amount of variation of a 
	// random variable expected about its mean
	double std_deviation(const std::vector<double> &data);

	// cut points dividing the range of a probability distribution into 
	// continuous intervals with equal probabilities
	double quantile(std::vector<double> &data, const double quantile);
	
	// measure of statistical dispersion
	double interquantile_range(std::vector<double> &data);
}

#endif  // TORUS_STATISTICS_HPP
