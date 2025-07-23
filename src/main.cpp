/* Copyright [2025] Pavan Kumar Kavvuri */


#include "Eigen/Dense"
#include "iostream"
#include "math/simple_math.hpp"
#include "vo/ransac.hpp"

int main()
{
  // std::cout << "Hello Pavan, this is our very first step towards VO development pipeline"
  //           << std::endl;
  // std::cout << "We will be using C++ and Linear Algebra for this project" << std::endl;
  // std::cout << "Let's get started!" << std::endl;

  Eigen::Vector2d a = {10.0, 20.0};
  Eigen::Vector2d b = {11.8, 23.9};

  ransac_ns::ransac_math math_int;

  Eigen::Vector2d result = math_int.difference(a, b);

  std::cout << "Difference result : " << result << std::endl;

  return 0;
}
