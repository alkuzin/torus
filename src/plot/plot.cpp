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

#include <torus/plot.hpp>


namespace torus
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
		cmd("q");
		fflush(plot_pipe);
		pclose(plot_pipe);
	}
}