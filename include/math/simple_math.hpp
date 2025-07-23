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
class math_class
{
public:
  int scalar_member{67};
  int compute_vector_sum(Eigen::Vector2d a, Eigen::Vector2d b);
};

}  // namespace math_ns
