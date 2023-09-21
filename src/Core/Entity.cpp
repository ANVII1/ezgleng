#include <GLFW/glfw3.h>

#include "Entity.hpp"


/// ENTITY ///////////////////////////////////////////////
CORE::Cord cord;
CORE::Axis axis;
GLFWwindow *window;

// CONSTRUCTOR ALL ON CLUSIVE
CORE::Entity::Entity(GLFWwindow *window,Cord cord, Axis axis)
{
    this->cord = cord;
    this->axis = axis;
    this->window = window;

}
// CONSTRUCTOR BUISNESS CLASS
CORE::Entity::Entity(GLFWwindow *window, CORE::Cord cord)
{
    this->cord = cord;
    this->axis = {0,0,0}; 
    this->window = window;
}

// CONSTRUCTOR ECONOM
CORE::Entity::Entity(GLFWwindow *window)
{   
    this->cord = {0,0,0};
    this->axis = {0,0,0};
    this->window = window;
}

void CORE::Entity::update(){}
void CORE::Entity::render(){}
