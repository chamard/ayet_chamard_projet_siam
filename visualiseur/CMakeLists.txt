
cmake_minimum_required(VERSION 2.6)

project(visualiseur)


file(
GLOB
source_files
*.cpp
*.c
*.h
)

SET(CMAKE_BUILD_TYPE Debug)
SET(CMAKE_C_FLAGS "-Wall -Wextra -Wno-unused-parameter -D_REENTRANT -fPIC -std=c99" )


add_executable(	
   visualiseur
   ${source_files}
   )	

target_link_libraries(visualiseur "-lm -lGL -lGLU -lglut")


