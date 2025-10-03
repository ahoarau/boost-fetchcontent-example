#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/pfr/core.hpp>

// fmt library
#include <fmt/core.h>
#include <fmt/color.h>

// spdlog library
#include <spdlog/spdlog.h>

// range-v3 library
#include <range/v3/all.hpp>

// Eigen library
#include <Eigen/Dense>

#include <vector>

auto main() -> int {
    // fmt example: formatted printing
    fmt::print("=== fmt Library Example ===\n");
    fmt::print(fmt::fg(fmt::color::green), "Hello from fmt! {}\n", "Formatted string");
    fmt::print("Formatted number: {:.2f}\n\n", 3.14159);

    // spdlog example: logging
    fmt::print("=== spdlog Library Example ===\n");
    spdlog::info("Welcome to spdlog!");
    spdlog::warn("This is a warning message");
    spdlog::error("This is an error message");

    // range-v3 example: ranges and views
    fmt::print("=== range-v3 Library Example ===\n");
    std::vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    // Filter even numbers, square them, and take first 3
    auto range_result = numbers 
        | ranges::views::filter([](int n) { return n % 2 == 0; })
        | ranges::views::transform([](int n) { return n * n; })
        | ranges::views::take(3);
    
    fmt::print("Even numbers squared (first 3): ");
    for (int n : range_result) {
        fmt::print("{} ", n);
    }
    fmt::print("\n\n");

    // Eigen example: linear algebra
    fmt::print("=== Eigen Library Example ===\n");
    Eigen::MatrixXd matrix(2, 2);
    matrix(0, 0) = 3;
    matrix(1, 0) = 2.5;
    matrix(0, 1) = -1;
    matrix(1, 1) = matrix(1, 0) + matrix(0, 1);
    
    fmt::print("Matrix:\n");
    fmt::print("  [{}, {}]\n", matrix(0, 0), matrix(0, 1));
    fmt::print("  [{}, {}]\n", matrix(1, 0), matrix(1, 1));
    fmt::print("Matrix determinant: {:.2f}\n", matrix.determinant());
    
    Eigen::VectorXd vector(2);
    vector(0) = 4;
    vector(1) = 3;
    
    fmt::print("Vector: [{}, {}]\n", vector(0), vector(1));
    Eigen::VectorXd result = matrix * vector;
    fmt::print("Matrix * Vector: [{:.2f}, {:.2f}]\n\n", result(0), result(1));

    fmt::print(fmt::fg(fmt::color::cyan), "=== All libraries integrated successfully! ===\n");
    
    return 0;
}