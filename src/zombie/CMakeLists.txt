cmake_minimum_required(VERSION 3.16)

add_library(
  zombie
  STATIC
  zombie.hpp
  zombie.cpp
)

target_link_libraries(
  zombie
  GameObject
  GameWorld
)

target_include_directories(
  zombie
  PUBLIC 
  ${CMAKE_SOURCE_DIR}/src/GameObject/
  ${CMAKE_SOURCE_DIR}/src/GameWorld/
  ${CMAKE_SOURCE_DIR}/src/zombie/
)
