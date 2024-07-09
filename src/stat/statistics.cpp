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

namespace torus
{
	
	double normal(double x, double mean, double std) 
	{
		double exponent, denominator;

		exponent    = -0.5 * std::pow((x - mean) / std, 2);
		denominator = std::sqrt(2 * M_PI) * std;

		return (1/denominator) * std::exp(exponent);
	}

    double t_distribution(double t, double v)
    {
        double numerator, denominator;

        numerator   = std::tgamma(0.5 * (v + 1));
        denominator = std::sqrt(v * M_PI) * std::tgamma(0.5 * v);

        return ((numerator / denominator) * std::pow(1 + ((t * t) / v), -(0.5 * (v + 1))));
    }
}