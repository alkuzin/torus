#ifndef TORUS_STATISTICS_H
#define TORUS_STATISTICS_H

#include <algorithm>
#include <numeric>
#include <vector>
#include <map>

namespace tlib
{
	double mean(const std::vector<double> &data);	

	double median(const std::vector<double> &data);	

	double mode(const std::vector<double> &data);	
}

#endif  // TORUS_STATISTICS_H
