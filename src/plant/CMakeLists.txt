cmake_minimum_required(VERSION 3.16)

add_library(
  plant
  STATIC
  plant.hpp
  plant.cpp
)

target_link_libraries(
  plant
  GameObject
  GameWorld
)

target_include_directories(
  plant
  PUBLIC 
  ${CMAKE_SOURCE_DIR}/src/GameObject/
  ${CMAKE_SOURCE_DIR}/src/GameWorld/
  ${CMAKE_SOURCE_DIR}/src/plant/
)
