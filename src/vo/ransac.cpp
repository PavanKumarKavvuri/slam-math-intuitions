/* Copyright [2025] Pavan Kumar Kavvuri */


#include "vo/ransac.hpp"

#include "iostream"

namespace ransac_ns
{
Eigen::Vector2d ransac_math::difference(Eigen::Vector2d a, Eigen::Vector2d b)
{
  return a - b;
}
}  // namespace ransac_ns
