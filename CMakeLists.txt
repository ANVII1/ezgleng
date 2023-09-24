cmake_minimum_required(VERSION 3.27 FATAL_ERROR)

# set project name and programming language
set(ProjName EZGLENG)

project(${ProjName} CXX)

# set C++ standard
set(CMAKE_CXX_STANDARD 17)

# add executable target
add_executable(${ProjName} 
    ${PROJECT_SOURCE_DIR}/src/main.cpp 
    ${PROJECT_SOURCE_DIR}/src/Core/Window.hpp
    ${PROJECT_SOURCE_DIR}/src/Core/Window.cpp 
    ${PROJECT_SOURCE_DIR}/src/Core/Entity.hpp 
    ${PROJECT_SOURCE_DIR}/src/Core/Entity.cpp 
    ${PROJECT_SOURCE_DIR}/src/Core/Player.hpp 
    ${PROJECT_SOURCE_DIR}/src/Core/Player.cpp 
    ${PROJECT_SOURCE_DIR}/src/Core/VisibleObject.hpp 
    ${PROJECT_SOURCE_DIR}/src/Core/VisibleObject.cpp 
    ${PROJECT_SOURCE_DIR}/src/Core/World.hpp
    ${PROJECT_SOURCE_DIR}/src/Core/World.cpp 
    ${PROJECT_SOURCE_DIR}/src/Core/Events.cpp
    ${PROJECT_SOURCE_DIR}/src/Core/Events.hpp
)

include_directories(
    ${PROJECT_SOURCE_DIR}/src/
    ${PROJECT_SOURCE_DIR}/src/Core/
    )

# include GLFW library
#find_package(glfw3 3.3 REQUIRED)
target_link_libraries(${ProjName} PUBLIC glfw GL)

# include directories
#target_include_directories(${ProjName} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)

