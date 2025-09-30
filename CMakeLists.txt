cmake_minimum_required(VERSION 3.22...4.1)
project(boost-fetchcontent-example)

include(FetchContent)
FetchContent_Declare(
    boost
    URL https://github.com/boostorg/boost/releases/download/boost-1.89.0/boost-1.89.0-cmake.zip
    URL_HASH MD5=2b36c6002d2a35eac3e6cb07c0097f77
)
FetchContent_MakeAvailable(boost)

add_executable(boost_example boost_example.cc)
target_compile_features(boost_example PRIVATE cxx_std_17)
target_link_libraries(boost_example PRIVATE Boost::serialization Boost::pfr Boost::filesystem)