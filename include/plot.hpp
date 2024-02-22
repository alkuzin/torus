#ifndef TORUS_PLOT_HPP
#define TORUS_PLOT_HPP

#include <iostream>
#include <cstdarg>

namespace tlib
{
	class Plot
	{
		FILE *plot_pipe;

		public:
			Plot(void);
			Plot(const char *filename, int height, int width); // save as png 
			~Plot();

			void cmd(const char *fmt, ...);	

		private:
			void _init(void);
	};
}

#endif // TORUS_PLOT_HPP
