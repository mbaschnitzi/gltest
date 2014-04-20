project(gltest)

cmake_minimum_required(VERSION 2.8)

set(gltest_VERSION_MAJOR "0")
set(gltest_VERSION_MINOR "1")
set(gltest_VERSION_PATCH "0")
set(gltest_VERSION_EXTRA "")
set(gltest_VERSION "${GLFW_VERSION_MAJOR}.${GLFW_VERSION_MINOR}")
set(gltest_VERSION_FULL "${GLFW_VERSION}.${GLFW_VERSION_PATCH}${GLFW_VERSION_EXTRA}")

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_FLAGS "-std=c++11")

add_executable(gltest src/main.cpp)

### glew
#add_subdirectory(libs/glew)
include_directories(libs/glew/include)
add_library(glew STATIC IMPORTED)
set_target_properties(glew PROPERTIES IMPORTED_LOCATION ${CMAKE_BINARY_DIR}/libs/glew/lib/libGLEW.a)
### glfw
add_subdirectory(libs/glfw)
include_directories(libs/glfw/include)
# glm
include_directories(libs/glm)



target_link_libraries(gltest glfw glew ${GLFW_LIBRARIES})

### ### sdfsd
