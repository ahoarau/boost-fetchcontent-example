cmake_minimum_required(VERSION 3.22...4.1)
project(boost-fetchcontent-example)

include(FetchContent)
FetchContent_Declare(
    boost
    URL https://github.com/boostorg/boost/releases/download/boost-1.89.0/boost-1.89.0-cmake.zip
    URL_HASH MD5=2b36c6002d2a35eac3e6cb07c0097f77
)
FetchContent_MakeAvailable(boost)

FetchContent_Declare(
    fmt
    URL https://github.com/fmtlib/fmt/releases/download/12.1.0/fmt-12.1.0.zip
    URL_HASH MD5=028c6979cad96a4260154f091885171a
)
FetchContent_MakeAvailable(fmt)

set(SPDLOG_FMT_EXTERNAL ON CACHE BOOL "")
FetchContent_Declare(
    spdlog
    URL https://github.com/gabime/spdlog/archive/refs/tags/v1.16.0.zip
    URL_HASH MD5=9492e71daefbfdfb86727b3628066b5a
)
FetchContent_MakeAvailable(spdlog)

FetchContent_Declare(
    range-v3
    URL https://github.com/ericniebler/range-v3/archive/ca1388fb9da8e69314dda222dc7b139ca84e092f.zip
    URL_HASH MD5=05add5653790ed453d7c4034fe344e01
)
FetchContent_MakeAvailable(range-v3)

FetchContent_Declare(
    eigen
    URL https://gitlab.com/libeigen/eigen/-/archive/5.0.0/eigen-5.0.0.zip
    URL_HASH MD5=3804ac4802bb18a75874d7a165c5c6f3  
)
FetchContent_MakeAvailable(eigen)

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