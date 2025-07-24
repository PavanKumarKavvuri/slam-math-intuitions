/**
 * @file simple_math.hpp
 * @author Pavan Kavvuri
 * @brief Basic math utilities for SLAM math intuitions
 *
 * @copyright Copyright (c) 2025
 * @license GNU General Public License v3.0 or later
 */


#pragma once

#include "Eigen/Dense"  // include Dense folder consisting of multiple imports
#include "iostream"

namespace math_ns
{
class MathClass
{
public:
  static constexpr int K_DEFAULT_SCALAR_VALUE = 67;
  int scalar_member{K_DEFAULT_SCALAR_VALUE};
  auto computeVectorSum(
    const Eigen::Vector2d & a_val,
    const Eigen::Vector2d & b_val) -> Eigen::Vector2d;
  bool show_plots{false};
};

}  // namespace math_ns
