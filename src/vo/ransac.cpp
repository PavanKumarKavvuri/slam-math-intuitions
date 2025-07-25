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

auto RansacMath::computeBestFitLine(std::vector<Eigen::Vector2d> & input_vector) ->
LineParameters
{
  for (const auto & point : input_vector) {
    std::cout << "Point is " << "(" << point.x() << ", " << point.y() << ")," << std::endl;
  }

  return LineParameters{
    .slope = 10.0,
    .intercept = 67.9
  };
}

auto computeLineParameters(
  const Eigen::Vector2d & point_1,
  const Eigen::Vector2d & point_2) -> LineParameters
{
  double dx = point_2.x() - point_1.x();

  if (std::abs(dx) < K_EPS) {
    return LineParameters{
      .slope = std::nullopt,
      .intercept = std::nullopt,
      .vertical_line = true,
      .x_cons = point_2.x()
    };
  }

  double gradient = (point_2.y() - point_1.y()) / dx;
  double intercept = point_1.y() - gradient * point_1.x();

  return LineParameters{
    .slope = gradient,
    .intercept = intercept,
    .vertical_line = false,
    .x_cons = std::nullopt,
  };
}

auto computeNormalDistance(
  const Eigen::Vector2d & point_normal,
  const LineParameters & line_params) -> double
{
  std::cout << "Inside computing Normal distance" << std::endl;

  if (line_params.vertical_line) {
    return std::abs(point_normal.x() - line_params.x_cons.value());
  }

  double a = line_params.slope.value();
  double b = -1.0;
  double c = line_params.intercept.value();

  double residual = a * point_normal.x() + b * point_normal.y() + c;
  double normalisation_factor = std::sqrt(a * a + b * b);

  return std::abs(residual) / normalisation_factor;
}
}  // namespace ransac_ns
