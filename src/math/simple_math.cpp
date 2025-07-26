/* Copyright [2025] Pavan Kumar Kavvuri */

#include "Eigen/Dense"  // include Dense folder consisting of multiple imports
#include "math/simple_math.hpp"

namespace math_ns
{
auto MathClass::computeVectorSum(
  const Eigen::Vector2d & a_val,
  const Eigen::Vector2d & b_val) -> Eigen::Vector2d
{
  return a_val + b_val;
}
}
