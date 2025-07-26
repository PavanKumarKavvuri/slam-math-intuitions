/**
 * @file simple_math.hpp
 * @author Pavan Kavvuri
 * @brief Basic math utilities for SLAM math intuitions
 *
 * @copyright Copyright (c) 2025
 * @license GNU General Public License v3.0 or later
 */

#include "Eigen/Dense"
#include "iostream"
#include "math/simple_math.hpp"
#include "vo/ransac.hpp"
#include "vector"

auto main() -> int
{
  // std::cout << "Hello Pavan, this is our very first step towards VO development pipeline"
  //           << std::endl;
  // std::cout << "We will be using C++ and Linear Algebra for this project" << std::endl;
  // std::cout << "Let's get started!" << std::endl;

  std::vector<Eigen::Vector2d> sample_input_vector = {
    {1.0, 1.5},
    {2.1, 3.5},
    {3.2, 4.8},
    {4.3, 6.7},
    {5.4, 5.9},
    {6.5, 8.5},
    {7.6, 4.4},
    {8.7, 6.3},
    {9.8, 2.2},
    {10.9, 16.1}
  };

  ransac_ns::RansacMath math_int(25, true, 0.005);
  math_int.computeBestFitLine(sample_input_vector);


  // math_ns::MathClass simple_math;

  // Eigen::Vector2d result = math_int.difference(a_val, b_val);
  // std::cout << "Difference result : " << result << std::endl;

  // Eigen::Vector2d simple_result = simple_math.computeVectorSum(a_val, b_val);
  // std::cout << "Sum result" << simple_result << std::endl;


  return 0;
}
