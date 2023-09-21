#include "Player.hpp"
#include <iostream>

/// PLAYER ///////////////////////////////////////////////
CORE::Player::Player(GLFWwindow *window):Entity(window){}; //bagos

void CORE::Player::rotateCamera()
{
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    static int basex = 900 / 2, basey =  700 / 2; // Вернуть нормальный размер окна через const unsigned int а не 900 на 700
    double xpos,ypos;
    float sensitivity = 0.05f;

    glfwGetCursorPos(window,&xpos,&ypos);
    axis.X += (xpos-basex)* sensitivity;
    axis.Y += (basey-ypos) * sensitivity;

    if (axis.X > 360) axis.X -= 360;
    if (axis.X < 0) axis.X += 360;
    
    if (axis.Y > 90) axis.Y = 90;
    if (axis.Y < -90) axis.Y = -90;

    std::cout << "Axis X" << axis.X << std::endl << "Axis Y" << axis.Y << std::endl << std::endl;
    glfwSetCursorPos(window,basex,basey);
}

void CORE::Player::update()
{
    rotateCamera();
    if (glfwGetKey(window,GLFW_KEY_W) == GLFW_PRESS) cord.Z += 0.1f;
    if (glfwGetKey(window,GLFW_KEY_A) == GLFW_PRESS) cord.X += 0.1f;
    if (glfwGetKey(window,GLFW_KEY_S) == GLFW_PRESS) cord.Z -= 0.1f;
    if (glfwGetKey(window,GLFW_KEY_D) == GLFW_PRESS) cord.X -= 0.1f;
    if (glfwGetKey(window,GLFW_KEY_SPACE) == GLFW_PRESS) cord.Y -= 0.1f;
    if (glfwGetKey(window,GLFW_KEY_LEFT_CONTROL) == GLFW_PRESS) cord.Y += 0.1f;
}

void CORE::Player::render()
{
    glRotatef(-(axis.Y),1,0,0);
    glRotatef(axis.X,0,1,0);
    glTranslatef(cord.X,cord.Y,cord.Z);
}