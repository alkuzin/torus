#ifndef TORUS_LIB_HPP
#define TORUS_LIB_HPP

#include "statistics.hpp"
#include "plot.hpp"

#include <vector>

namespace tlib 
{
	void save(std::vector<double> &data, const char *filename);
}

#endif  // TORUS_LIB_HPP

