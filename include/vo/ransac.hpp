/**
 * @file simple_math.hpp
 * @author Pavan Kavvuri
 * @brief Basic math utilities for SLAM math intuitions
 *
 * @copyright Copyright (c) 2025
 * @license GNU General Public License v3.0 or later
 */


#pragma once

#include "Eigen/Dense"
#include "vector"
#include "iostream"
#include "optional"

namespace ransac_ns
{

struct LineParameters
{
  std::optional<double> slope{};
  std::optional<double> intercept{};
  bool vertical_line{false};
  std::optional<double> x_cons{};
};

static constexpr double K_EPS = 1e-12;


class RansacMath
{
private:
  bool show_plots;
  int max_iterations;
  double threshold;

  auto computeNormalDistance(
    const Eigen::Vector2d & point_normal,
    const LineParameters & line_params) -> double;
  auto computeLineParameters(
    const Eigen::Vector2d & point_1,
    const Eigen::Vector2d & point_2) -> LineParameters;

public:
  explicit RansacMath(int iterations = 10, bool plots = false, double thresh = 10.0)
  : show_plots(plots),
    max_iterations(iterations),
    threshold(thresh)
  {
    std::cout << "Ransac Math Class Initiated" << std::endl;
  }


  auto computeBestFitLine(std::vector<Eigen::Vector2d> & input_vector) -> LineParameters;
};
}  // namespace ransac_ns
