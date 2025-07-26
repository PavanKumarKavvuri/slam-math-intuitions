#!/bin/bash

# Color output helpers
green() { echo -e "\033[0;32m$1\033[0m"; }
red()   { echo -e "\033[0;31m$1\033[0m"; }

# Set build directory
BUILD_DIR="build"

# Create build directory if it doesn't exist
if [ ! -d "$BUILD_DIR" ]; then
    mkdir "$BUILD_DIR"
    green " Created build directory."
fi

# Run CMake and Make
cd "$BUILD_DIR" || exit 1

green "  Running CMake..."
cmake .. || { red " CMake failed"; exit 1; }

green "  Building project..."
make || { red " Build failed"; exit 1; }

# Run the executable if it was built
EXECUTABLE="./MathIntuitions"
if [ -f "$EXECUTABLE" ]; then
    echo ""
    green " Running executable..."
    echo -e "\n==================== Math Intuitions Output ====================\n"
    $EXECUTABLE
else
    red " Executable not found."
    exit 1
fi
