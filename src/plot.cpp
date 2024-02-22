#include "../include/plot.hpp"

namespace tlib 
{
	Plot::Plot(void) 
	{
		plot_pipe = nullptr;
		_init();
	}

	Plot::Plot(const char *filename, int height, int width) 
	{
		plot_pipe = nullptr;
		_init();

		cmd("set terminal png size %d,%d\n", height, width);
		cmd("set output '%s'\n", filename);
	}

	void Plot::_init(void)
	{
		plot_pipe = popen("gnuplot -persistent", "w");
	
		if(!plot_pipe) {
			perror("popen");
			exit(EXIT_FAILURE);
		}
	}

	void Plot::cmd(const char *fmt, ...) 
	{
		va_list args;

		va_start(args, fmt);
		vfprintf(plot_pipe, fmt, args);
		va_end(args);
	}

	Plot::~Plot(void) 
	{
		cmd("e");
		fflush(plot_pipe);
		pclose(plot_pipe);
	}
}
