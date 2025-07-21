# Specify the minimum required CMake version
cmake_minimum_required(VERSION 3.10...4.0)

# Define the project name, version, description, and languages
project(
  MathIntuitionsProject # Project name
  VERSION 1.0 # Optional version info
  DESCRIPTION
    "A project to explore mathematical intuitions of SLAM Algorithms" # Optional
                                                                      # description
  LANGUAGES CXX # Use only C++
)

# Use modern C++17 standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Enable compiler warnings for better code hygiene
add_compile_options(-Wall -Wextra -Wpedantic)

# ------------------------------------------------------------------------------
# Source Files
# ------------------------------------------------------------------------------

# Recursively gather all .cpp files inside the src/ directory
file(GLOB_RECURSE SRC_FILES src/*.cpp)

# Define the main executable target using the collected source files
add_executable(MathIntuitions ${SRC_FILES})

# ------------------------------------------------------------------------------
# Dependencies
# ------------------------------------------------------------------------------

# Locate the Eigen3 package if installed system-wide This provides the imported
# target Eigen3::Eigen with correct include paths
find_package(Eigen3 REQUIRED)

# Link Eigen to our target — though Eigen is header-only, this ensures correct
# include paths are set in a portable and modern way
target_link_libraries(MathIntuitions PRIVATE Eigen3::Eigen)

# ------------------------------------------------------------------------------
# Include Directories
# ------------------------------------------------------------------------------

# Add local project headers (e.g., include/*.hpp) and third-party headers (e.g.,
# third_party/mathplot/mathplot.h) to the include path
target_include_directories(
  MathIntuitions
  PRIVATE ${PROJECT_SOURCE_DIR}/include # Your own reusable headers
          ${PROJECT_SOURCE_DIR}/third_party/mathplot # Header-only plotting
                                                     # library
)

# ------------------------------------------------------------------------------
# Optional: Add other third-party or module folders below if needed
# ------------------------------------------------------------------------------

# For example: target_include_directories(MathIntuitions PRIVATE
# ${PROJECT_SOURCE_DIR}/external/ceres/include)
