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

#include <torus/utils.hpp>
#include <fstream>


namespace torus 
{
	template <typename T>
	void save(std::vector<T> &data, const std::string& filename)
    {
		std::ofstream fin;

		fin.open(filename, std::ios::out);
		
		if(!fin.is_open())
			throw std::runtime_error("tlib::save: failed to open file");

		for(T value : data)
			fin << value << std::endl;

		fin.close();
    }
	
	template <typename T>
	void save(std::vector<T> &x, std::vector<T> &y, const std::string& filename)
    {
		std::ofstream fin;
		size_t size;

		size = x.size();

		if(size != y.size())
			throw std::runtime_error("torus::save: different sizes of x & y");

		fin.open(filename, std::ios::out);
		
		if(!fin.is_open())
			throw std::runtime_error("torus::save: failed to open file");

		for(size_t i = 0; i < size; i++)
			fin << x.at(i) << " " << y.at(i) << std::endl;

		fin.close();
    }
}