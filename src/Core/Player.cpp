#include "Player.hpp"
#include <iostream>
#include <cmath>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "Window.hpp"

// unsigned int CORE::Window::height;
// unsigned int CORE::Window::width;

/// PLAYER ///////////////////////////////////////////////
CORE::Player::Player(GLFWwindow *window):Entity(window)
{
    cord.X = 5;
    cord.Y = -10;
    cord.Z = 5;
    axis.Y = -90;
}

void CORE::Player::rotateCamera()
{
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    static int basex = CORE::Window::width / 2, basey =  CORE::Window::height / 2;
    double xpos,ypos;
    float sensitivity = 0.05f;

    
    glfwGetCursorPos(window,&xpos,&ypos);
    axis.X += (xpos-basex)* sensitivity;
    axis.Y += (basey-ypos) * sensitivity;

    if (axis.X > 360) axis.X -= 360;
    if (axis.X < 0) axis.X += 360;
    
    if (axis.Y > 90) axis.Y = 90;
    if (axis.Y < -90) axis.Y = -90;

    std::cout << "Axis /////////////////" << std::endl << "Axis X" << axis.X << std::endl << "Axis Y" << axis.Y << std::endl << std::endl;
    glfwSetCursorPos(window,basex,basey);
    
}

void CORE::Player::update()
{
    rotateCamera();

    if (glfwGetKey(window,GLFW_KEY_ESCAPE) == GLFW_PRESS) glfwSetWindowShouldClose(window, true);

    // W_key processing
    if (glfwGetKey(window,GLFW_KEY_W) == GLFW_PRESS) cord.Z += 0.07f; 

    // A_key processing
    if (glfwGetKey(window,GLFW_KEY_A) == GLFW_PRESS) cord.X += 0.07f;

    // S_key processing
    if (glfwGetKey(window,GLFW_KEY_S) == GLFW_PRESS) cord.Z -= 0.07f;

    // D_key processing
    if (glfwGetKey(window,GLFW_KEY_D) == GLFW_PRESS) cord.X -= 0.07f;

    if (glfwGetKey(window,GLFW_KEY_SPACE) == GLFW_PRESS) cord.Y -= 0.1f;
    if (glfwGetKey(window,GLFW_KEY_LEFT_CONTROL) == GLFW_PRESS) cord.Y += 0.1f;

    std::cout << "Cords /////////////////" << std::endl << "Cord X: " << cord.X << std::endl << "Cord Y:" << cord.Y << std::endl << "Cord Z:" << cord.Z << std::endl << std::endl ;
}

void CORE::Player::render()
{
    glm::mat4 view;
    glm::mat4 projection;
    
    view = glm::lookAt(glm::vec3(cord.X, cord.Y, cord.Z), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    projection = glm::perspective(90.0f, (GLfloat)900 / (GLfloat)700, 0.1f, 100.0f);
    //GLint viewLoc = glGetUniformLocation(ourShader.Program, "view");
    //GLint projLoc = glGetUniformLocation(ourShader.Program, "projection");

    //glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
    //glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));

    
    glRotatef(-(axis.Y),1,0,0);
    glRotatef(axis.X,0,1,0);
    glTranslatef(cord.X,cord.Y,cord.Z);
    
}