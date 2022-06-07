cmake_minimum_required(VERSION 3.21)
project(Lab_08)

set(CMAKE_CXX_STANDARD 14)

include_directories(${PROJECT_SOURCE_DIR}/headers)

file(GLOB headers ${PROJECT_SOURCE_DIR}/headers/*.h)
file(GLOB sources ${PROJECT_SOURCE_DIR}/sources/*.cpp)

add_executable(Lab_08 main.cpp ${headers} ${sources} headers/matrix.h sources/matrix.cpp headers/random_generator.h sources/random_generator.cpp headers/neuron_network.h sources/neuron_network.cpp headers/neural_layer.h sources/neural_layer.cpp)
