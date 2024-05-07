# Torus
Torus - math statistics library for own projects

<img src="res/torus.png">

## Dependencies
* [gnuplot](http://www.gnuplot.info/) (software for generation plots of functions, data, and data fits)

Installation of gnuplot in Debian, Ubuntu and etc.
```c
sudo apt install gnuplot
```

## Installation
First clone this repository:
```console
git clone https://github.com/alkuzin/torus-lib.git
```

Then move to library directory and build library:
```cpp
cd torus-lib/ && make all
```

Then include the __`torus.hpp`__ header file in your project.
```c
#include <torus/torus.hpp>
// project code here
```
Finaly compile and run your project, including __`libtorus.a`__ file:

```console
g++ -I include/ main.cpp libtorus.a -o main && ./main
```

To return everything to original state:
```console
make fclean
```