cmake_minimum_required(VERSION 3.22...4.1)
project(boost-fetchcontent-example)

include(FetchContent)
FetchContent_Declare(
    boost
    URL https://github.com/boostorg/boost/releases/download/boost-1.87.0/boost-1.87.0-cmake.zip
    URL_HASH MD5=75392f81fbc9acb8634c0bf897fa105a
)

FetchContent_Declare(
    fmt
    URL https://github.com/fmtlib/fmt/releases/download/11.0.2/fmt-11.0.2.zip
    URL_HASH MD5=c622dca45ec3fc95254c48370a9f7a1d
)

FetchContent_Declare(
    spdlog
    URL https://github.com/gabime/spdlog/archive/refs/tags/v1.14.1.zip
    URL_HASH MD5=b87a5b347fbfa46543fb08852759f917
)
set(SPDLOG_FMT_EXTERNAL ON CACHE INTERNAL "")

FetchContent_Declare(
    range-v3
    URL https://github.com/ericniebler/range-v3/archive/refs/tags/0.12.0.zip
    URL_HASH MD5=e220e3f545fdf46241b4f139822d73a1
)

FetchContent_Declare(
    eigen
    URL https://github.com/eigenteam/eigen-git-mirror/archive/refs/tags/3.3.7.zip
    URL_HASH MD5=cd8d0d775b3ebd29895f3a3a8c232cf0
)

FetchContent_MakeAvailable(boost fmt spdlog range-v3 eigen)

# Create Eigen3::Eigen alias for compatibility
if(TARGET eigen AND NOT TARGET Eigen3::Eigen)
    add_library(Eigen3::Eigen ALIAS eigen)
endif()

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