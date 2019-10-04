cmake_minimum_required(VERSION 3.1 FATAL_ERROR)

# Project name
project(ho5_imc)

# Where to find included source files
include_directories("${PROJECT_SOURCE_DIR}")

# List sources related with CPP IMC bindings
file(GLOB_RECURSE IMC_SOURCES "${PROJECT_SOURCE_DIR}/IMC/*.cpp")
file(GLOB_RECURSE IMC_HEADERS "${PROJECT_SOURCE_DIR}/IMC/*.hpp")

# create a library using all of IMC sources /  headers 
add_library(imc ${IMC_HEADERS} ${IMC_SOURCES})
add_library(say-hello hello.hpp hello.cpp)
add_library(udp UDP/DatagramSocket.h UDP/DatagramSocket.cpp)

# Add program to list
add_executable(HomeworkExercise homeworkExercise.cpp)

target_link_libraries(HomeworkExercise PRIVATE imc udp say-hello ) 
