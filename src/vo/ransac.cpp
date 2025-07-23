/**
 * @file simple_math.hpp
 * @author Pavan Kavvuri
 * @brief Basic math utilities for SLAM math intuitions
 *
 * @copyright Copyright (c) 2025
 * @license GNU General Public License v3.0 or later
 */

#include "vo/ransac.hpp"

#include "iostream"

namespace ransac_ns
{
Eigen::Vector2d ransac_math::difference(Eigen::Vector2d a, Eigen::Vector2d b)
{
  return a - b;
}
}  // namespace ransac_ns
