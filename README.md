# Torus
Torus - math library for own projects

<img src="res/torus.png">

## Dependencies
* [gnuplot](http://www.gnuplot.info/) (software for generation plots of functions, data, and data fits)

Installation of gnuplot in Debian, Ubuntu and etc.
```console
sudo apt install gnuplot
```

## Installation
First clone this repository:
```console
git clone https://github.com/alkuzin/torus.git
```

Then move to library directory and build library:
```cpp
cd torus/ && make all
```

Then include the header file in your project (e.g. statistics.hpp):
```cpp
#include <torus/statistics.hpp>
// project code here
```
Finaly compile and run your project, including __`libtorus.a`__ file:

```console
g++ -I include/ <your-source-files> libtorus.a -o <executable-name> && ./<executable-name>
```

To return everything to original state:
```console
make fclean
```

## Tests
* [gtest](https://github.com/google/googletest) (library for writing test programs)
installation:
```console
sudo apt-get install libgtest-dev
```

To run tests use:
```console
make tests
```

To return everything to original state:
```console
make clean_tests
```