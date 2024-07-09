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

/**
 * @file  statistics.h
 * @brief Contains math statistics functions.
 * 
 * @author Alexander Kuzin (<a href="https://github.com/alkuzin">alkuzin</a>)
 * @date   07.07.2024
 */

#ifndef _TORUS_STATISTICS_HPP_
#define _TORUS_STATISTICS_HPP_

#include <stdexcept>
#include <cstdint>
#include <vector>
#include <cmath>


namespace torus
{
	/**
	 * @brief Calculate mean value of given data.
	 * 
	 * @param [in] data - given data.
	 * @return mean value of @a data.
	 */
	template <typename T>
	double mean(const std::vector<T> &data);

	/**
	 * @brief Calculate median of given data.
	 * 
	 * @param [in] data - given data.
	 * @return middle value separating the greater and lesser halves of a data set.
	 */
	template <typename T>
	double median(const std::vector<T> &data);

	/**
	 * @brief Calculate most frequent value in a data set.
	 * 
	 * @param [in] data - given data.
	 * @return mode of given @a data.
	 */
	template <typename T>
	double mode(const std::vector<T> &data);

	/**
	 * @brief Calculate measure of spread of given data.
	 * 
	 * @param [in] data - given data.
	 * @return variance of @a data.
	 */
	template <typename T>
	double variance(const std::vector<T> &data);

	/**
	 * @brief Calculate measure of the amount of variation of a
	 * random variable expected about its mean.
	 * 
	 * @param [in] data - given data.
	 * @return standard deviation of @a data.
	 */
	template <typename T>
	double std(const std::vector<T> &data);

	/**
	 * @brief Calculate value that cut points dividing the range of
	 * a probability distribution into continuous intervals with equal probabilities.
	 * 
	 * @param [in] data - given data.
	 * @param [in] quantile - given quantile. 
	 * @return quantile value.
	 */
	template <typename T>
	double quantile(const std::vector<T> &data, const double quantile);
	
	/**
	 * @brief Calculate interquantile range.
	 * 
	 * @param [in] data - given data.
	 * @return interquantile range of @a data.
	 */
	template <typename T>
	double iqr(const std::vector<T> &data);
	
	/**
	 * @brief Calculate skewness of given data.
	 * 
	 * @param [in] data - given data.
	 * @return positive number - tail on the right side of the distribution is longer
	 * @return negative number - tail on the left side of the distribution is longer
	 * @return 0 - in case of normally distributed data.
	 */
	template <typename T>
	double skew(const std::vector<T> &data);
	
	/**
	 * @brief Calculate standart error of the mean.
	 * 
	 * @param [in] data - given data.
	 * @return standart error of the mean of @a data.
	 */
	template <typename T>
    double sem(const std::vector<T> &data);
}

#endif  // _TORUS_STATISTICS_HPP_