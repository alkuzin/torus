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

#include <torus/statistics.hpp>
#include <stdexcept>

#include <gtest/gtest.h>


// ::::::::::: TEST torus::mean() :::::::::::
// TEST DOUBLE

TEST(torus_mean_test0, empty_vector)
{
    std::vector<double> v = {};
    EXPECT_THROW(torus::mean(v), std::invalid_argument);
}

TEST(torus_mean_test1, positive_double_numbers)
{
    std::vector<double> v = {3.03132, 44.783, 63.6364, 27.6086, 84.2041,
                             69.7047, 6.45622, 30.5468, 0.27492, 77.9748};
    double mean = torus::mean(v);    
    EXPECT_EQ(40.822086, mean);
}

TEST(torus_mean_test2, negative_double_numbers)
{
    std::vector<double> v = {-85.3249, -0.210539, -22.6952, -32.4681, -46.285,
                             -11.0477, -14.1495, -30.9248, -63.9782, -74.0521};
    double mean = torus::mean(v);
    EXPECT_EQ(-38.1136039, mean);
}

TEST(torus_mean_test3, single_positive_double_number)
{
    std::vector<double> v = {3.03132};
    double mean = torus::mean(v);    
    EXPECT_EQ(3.03132, mean);
}

TEST(torus_mean_test4, single_negative_double_number)
{
    std::vector<double> v = {-13.0213};
    double mean = torus::mean(v);    
    EXPECT_EQ(-13.0213, mean);
}

// TEST INT

TEST(torus_mean_test5, positive_int_numbers)
{
    std::vector<int> v = {57, 76, 56, 37, 6, 68, 79, 53, 9, 75};
    double mean           = torus::mean(v);
    EXPECT_EQ(51.6, mean);
}

TEST(torus_mean_test6, negative_int_numbers)
{
    std::vector<int> v = {-55, -51, -81, -93, -87, -19, -7, -99, -87, -78};
    double mean        = torus::mean(v);    
    EXPECT_EQ(-65.7, mean);
}

TEST(torus_mean_test7, single_positive_int_number)
{
    std::vector<int> v = {10};
    double mean        = torus::mean(v);    
    EXPECT_EQ(10.0, mean);
}

TEST(torus_mean_test8, single_negative_int_number)
{
    std::vector<int> v = {-13};
    double mean        = torus::mean(v);    
    EXPECT_EQ(-13, mean);
}

// TEST UNSIGNED INT

TEST(torus_mean_test9, uint_numbers)
{
    std::vector<unsigned int> v = {189352, 906582, 921527, 461192, 466356,
                                   969165, 305375, 210987, 329145, 896144};
    double mean = torus::mean(v);
    EXPECT_EQ(565582.5, mean);
}

TEST(torus_mean_test10, single_uint_number)
{
    std::vector<unsigned int> v = {1234567890};
    double mean                 = torus::mean(v);    
    EXPECT_EQ(1234567890, mean);
}