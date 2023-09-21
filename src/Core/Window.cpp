#include <GLFW/glfw3.h>
#include "Window.hpp"

CORE::Window::Window(int width, int height, const char* title) 
{
    glfwInit();
    window = glfwCreateWindow(width, height, title, NULL, NULL);

    if (!window)
    {
        glfwTerminate();
    }
    // Создаём контест кокна
    glfwMakeContextCurrent(window);
    
    // Скейлим изображение окна под разрешение
    glScalef((float)height/(float)width,1,1);
    glFrustum(-1,1,-1,1 ,2,100);

    glEnable(GL_DEPTH_TEST);
}   

GLFWwindow* CORE::Window::getWindow() 
{
    return window;
}

CORE::Window::~Window()
{
    glfwTerminate();
}

bool CORE::Window::isShouldClose()
{
    return glfwWindowShouldClose(window);
}

void CORE::Window::pollEvents()
{
    glfwPollEvents();
}

void CORE::Window::setShouldClose(bool flag)
{
    glfwSetWindowShouldClose(window, flag);
}

void CORE::Window::swapBuffers()
{
    glfwSwapBuffers(window);
}
