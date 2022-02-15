cmake_minimum_required(VERSION 3.5)
project(concordo VERSION 0.1 LANGUAGES CXX)

include_directories(include)

add_executable(dnaprofiler
               source/database.cpp
               source/dna.cpp
               source/io.cpp
               source/main.cpp
               source/profile.cpp)
