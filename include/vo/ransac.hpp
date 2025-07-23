/**
 * @file simple_math.hpp
 * @author Pavan Kavvuri
 * @brief Basic math utilities for SLAM math intuitions
 *
 * @copyright Copyright (c) 2025
 * @license GNU General Public License v3.0 or later
 */


#pragma once

#include <Eigen/Dense>
#include <vector>

namespace ransac_ns
{
class ransac_math
{
public:
  bool show_plots{false};

  Eigen::Vector2d difference(Eigen::Vector2d a, Eigen::Vector2d b);
  void print_input_vector_array();
};
}  // namespace ransac_ns
