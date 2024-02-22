#include <fstream>
#include <string>
#include "../include/torus.hpp"

namespace tlib 
{
	void save(std::vector<double> &data, const char *filename)
	{
		std::ofstream fin;

		fin.open(filename, std::ios::out);

		for(double value : data)
			fin << value << std::endl;

		fin.close();
	}
}
