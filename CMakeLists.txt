cmake_minimum_required(VERSION 3.22...4.1)
project(boost-fetchcontent-example)

include(FetchContent)
FetchContent_Declare(
    boost
    URL https://github.com/boostorg/boost/releases/download/boost-1.89.0/boost-1.89.0-cmake.zip
    URL_HASH MD5=2b36c6002d2a35eac3e6cb07c0097f77
)

# fmt library - using URL for faster download
FetchContent_Declare(
    fmt
    URL https://github.com/fmtlib/fmt/releases/download/11.0.2/fmt-11.0.2.zip
    URL_HASH SHA256=40fc58bebcf38c759e11a7bd8fdc163507d2423ef5058bba7f26280c5b9c5465
)

# spdlog library - using git with shallow clone
FetchContent_Declare(
    spdlog
    GIT_REPOSITORY https://github.com/gabime/spdlog.git
    GIT_TAG v1.14.1
    GIT_SHALLOW TRUE
)
set(SPDLOG_FMT_EXTERNAL ON CACHE INTERNAL "")

# range-v3 library - using git with shallow clone
FetchContent_Declare(
    range-v3
    GIT_REPOSITORY https://github.com/ericniebler/range-v3.git
    GIT_TAG 0.12.0
    GIT_SHALLOW TRUE
)

# Eigen library - using git with shallow clone (GitHub mirror since GitLab is blocked)
FetchContent_Declare(
    eigen
    GIT_REPOSITORY https://github.com/eigenteam/eigen-git-mirror.git
    GIT_TAG master
    GIT_SHALLOW TRUE
)

FetchContent_MakeAvailable(boost fmt spdlog range-v3 eigen)

add_executable(boost_example boost_example.cc)
target_compile_features(boost_example PRIVATE cxx_std_17)
target_link_libraries(boost_example PRIVATE 
    Boost::serialization 
    Boost::pfr 
    Boost::filesystem
    fmt::fmt
    spdlog::spdlog
    range-v3::range-v3
    Eigen3::Eigen
)