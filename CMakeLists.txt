cmake_minimum_required(VERSION 3.22...4.1)
project(boost-fetchcontent-example)

include(FetchContent)
FetchContent_Declare(
    boost
    URL https://github.com/boostorg/boost/releases/download/boost-1.89.0/boost-1.89.0-cmake.zip
    URL_HASH MD5=2b36c6002d2a35eac3e6cb07c0097f77
)

FetchContent_Declare(
    fmt
    GIT_REPOSITORY https://github.com/fmtlib/fmt.git
    GIT_TAG 10.2.1
)

FetchContent_Declare(
    spdlog
    GIT_REPOSITORY https://github.com/gabime/spdlog.git
    GIT_TAG v1.13.0
)
set(SPDLOG_FMT_EXTERNAL ON CACHE INTERNAL "")

FetchContent_Declare(
    range-v3
    GIT_REPOSITORY https://github.com/ericniebler/range-v3.git
    GIT_TAG 0.12.0
)

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