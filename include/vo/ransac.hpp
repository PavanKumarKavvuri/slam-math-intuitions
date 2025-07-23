/* Copyright [2025] Pavan Kumar Kavvuri */


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
