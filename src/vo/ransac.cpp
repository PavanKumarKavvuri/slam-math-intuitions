/**
 * @file simple_math.hpp
 * @author Pavan Kavvuri
 * @brief Basic math utilities for SLAM math intuitions
 *
 * @copyright Copyright (c) 2025
 * @license GNU General Public License v3.0 or later
 */


// Third-party headers
#include "vo/ransac.hpp"

namespace ransac_ns
{

auto RansacMath::pickTwoRandomPoints(std::vector<Eigen::Vector2d> & input_vector) ->
std::vector<Eigen::Vector2d>
{
  // std::cout<<"Inside picking random points"<<std::endl;

  size_t index_1, index_2;
  do{
    index_1 = RansacMath::dis(RansacMath::gen);
    index_2 = RansacMath::dis(RansacMath::gen);
  }while(index_1 == index_2);

  // std::cout<<"Index 1 ->"<< index_1 << " Index 2 ->"<< index_2 << std::endl;

  auto point_1 = input_vector[index_1];
  auto point_2 = input_vector[index_2];

  // std::cout<< point_1 << std::endl;
  // std::cout<< point_2 << std::endl;

  return std::vector<Eigen::Vector2d>{point_1, point_2};
}

auto RansacMath::computeBestFitLine(std::vector<Eigen::Vector2d> & input_vector) ->
LineParameters
{
  auto prev_inliers_count = 0;
  LineParameters best_fit_line;

  RansacMath::dis = std::uniform_int_distribution<size_t>(0, input_vector.size() - 1);

  for (int i = 0; i < max_iterations; ++i) {
    int inliers_count = 0;

    auto random_points = RansacMath::pickTwoRandomPoints(input_vector);
    auto line_parameters = RansacMath::computeLineParameters(random_points[0], random_points[1]);
    // std::cout<<line_parameters.slope<<std::endl;
    double normal_length = 0.0;
    for (const auto & point : input_vector) {
      normal_length = RansacMath::computeNormalDistance(point, line_parameters);
      // std::cout<<"Normal Length : "<< normal_length <<std::endl;
      if (normal_length < threshold) {
        inliers_count++;
      }
    }

    if (inliers_count >= prev_inliers_count) {
      prev_inliers_count = inliers_count;
      best_fit_line = line_parameters;
      std::cout << "\n Best Inliers Count in Iteration " << i << ": " << inliers_count << std::endl;
      std::cout << "Best Fit Line Parameters: Slope -> " << best_fit_line.slope.value()
                << " Intercept -> " << best_fit_line.intercept.value() << std::endl;
    }
  }


  return LineParameters{
    .slope = 10.0,
    .intercept = 67.9
  };
}

auto RansacMath::computeLineParameters(
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

  // std::cout<<"\nGradient: ->"<<gradient<< " Intercept: ->"<<intercept<< std::endl;

  return LineParameters{
    .slope = gradient,
    .intercept = intercept,
    .vertical_line = false,
    .x_cons = std::nullopt,
  };
}

auto RansacMath::computeNormalDistance(
  const Eigen::Vector2d & point_normal,
  const LineParameters & line_params) -> double
{
  // std::cout << "Inside computing Normal distance" << std::endl;


  if (line_params.vertical_line) {
    return std::abs(point_normal.x() - line_params.x_cons.value());
  }

  double a = line_params.slope.value();
  double b = -1.0;
  double c = line_params.intercept.value();

  double residual = (a * point_normal.x()) + (b * point_normal.y()) + c;
  double normalisation_factor = std::sqrt(a * a + b * b);

  // std::cout<< "a: " << a << " b: " << b << " c: " << c << std::endl;
  // std::cout << "Point Normal: " << point_normal.transpose() << std::endl;
  // std::cout << "Residual: " << residual << std::endl;
  // std::cout << "Normalisation Factor: " << normalisation_factor << std::endl;

  return std::abs(residual) / normalisation_factor;
}
}  // namespace ransac_ns
