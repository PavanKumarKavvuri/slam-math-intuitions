/**
 * @file simple_math.hpp
 * @author Pavan Kavvuri
 * @brief Basic math utilities for SLAM math intuitions
 *
 * @copyright Copyright (c) 2025
 * @license GNU General Public License v3.0 or later
 */


#pragma once

// Headers placement order: Local headers -> C headers -> C++ headers

// Third-party headers
#include <Eigen/Dense>

// C++ system headers
#include <vector>
#include <random>
#include <iostream>
#include <optional>


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
  std::random_device rd;
  std::mt19937 gen;
  std::uniform_int_distribution<size_t> dis;

  auto computeNormalDistance(
    const Eigen::Vector2d & point_normal,
    const LineParameters & line_params) -> double;
  auto computeLineParameters(
    const Eigen::Vector2d & point_1,
    const Eigen::Vector2d & point_2) -> LineParameters;
  auto pickTwoRandomPoints(
    std::vector<Eigen::Vector2d> & input_vector) -> std::vector<Eigen::Vector2d>;

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
