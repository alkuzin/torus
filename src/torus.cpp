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

#include <fstream>
#include <string>

#include <torus/torus.hpp>

namespace tlib 
{
	void save(std::vector<double> &data, const char *filename)
	{
		std::ofstream fin;

		fin.open(filename, std::ios::out);
		
		if(!fin.is_open())
			throw std::runtime_error("tlib::save: failed to open file");

		for(double value : data)
			fin << value << std::endl;

		fin.close();
	}
	
	void save_xy(std::vector<double> &x, std::vector<double> &y, const char *filename)
	{
		std::ofstream fin;
		size_t size;

		size = x.size();
		if(size != y.size())
			throw std::runtime_error("tlib::save_xy: different sizes of x & y");

		fin.open(filename, std::ios::out);
		
		if(!fin.is_open())
			throw std::runtime_error("tlib::save_xy: failed to open file");

		for(size_t i = 0; i < size; i++)
			fin << x.at(i) << " " << y.at(i) << std::endl;

		fin.close();
	}
	
	void load(std::vector<double> &data, const char *filename)
	{
		std::ifstream fout;
		std::string   line;

		fout.open(filename, std::ios::in);
		
		if(!fout.is_open())
			throw std::runtime_error("tlib::load: failed to open file");
	
		// skip first line
		std::getline(fout, line);

		while(std::getline(fout, line))
			data.push_back(std::stod(line));	
	
		fout.close();	
	}
}
