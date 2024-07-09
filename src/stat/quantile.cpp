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
#include <algorithm>


namespace torus
{
	template <typename T>
	double quantile(const std::vector<T> &data, const T quantile)
	{
		double lower_pos, upper_pos, lower_val, upper_val, pos, q;

		if (data.empty() || quantile < 0.0 || quantile > 1.0)
        	throw std::invalid_argument("data is empty or incorrect quantile");
	
    	std::sort(data.begin(), data.end());

    	pos       = quantile * (data.size() - 1);
    	lower_pos = static_cast<int>(pos);
    	upper_pos = lower_pos + 1;
    	lower_val = data[lower_pos];
    	upper_val = data[upper_pos];
    	q         = lower_val + (pos - lower_pos) * (upper_val - lower_val);

    	return q;
	}
}