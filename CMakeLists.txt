cmake_minimum_required(VERSION 3.16)
project(p1_cg CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/Ds/include 
    ${CMAKE_CURRENT_SOURCE_DIR}/Ds/externals/include    
)

add_executable(p1_cg
    src/Main.cpp
    src/MainWindow.cpp
)

find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)

target_link_libraries(p1_cg PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/lib/libcg.a
  ${CMAKE_CURRENT_SOURCE_DIR}/lib/libgl3w.a
  glfw
  OpenGL::GL
)

