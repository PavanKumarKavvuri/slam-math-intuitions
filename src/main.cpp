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

auto main() -> int
{
  // std::cout << "Hello Pavan, this is our very first step towards VO development pipeline"
  //           << std::endl;
  // std::cout << "We will be using C++ and Linear Algebra for this project" << std::endl;
  // std::cout << "Let's get started!" << std::endl;

  Eigen::Vector2d a_val = {10.0, 20.0};
  Eigen::Vector2d b_val = {11.8, 23.9};

  ransac_ns::ransac_math math_int;
  math_ns::MathClass simple_math;

  Eigen::Vector2d result = math_int.difference(a_val, b_val);

  std::cout << "Difference result : " << result << std::endl;

  Eigen::Vector2d simple_result = simple_math.computeVectorSum(a_val, b_val);
  std::cout << "Sum result" << simple_result << std::endl;


  return 0;
}
