#include <GLFW/glfw3.h>
#include "Window.hpp"


GLFWwindow* CORE::Window::window;
unsigned int CORE::Window::height;
unsigned int CORE::Window::width;


int CORE::Window::init(unsigned int width, unsigned int height, const char* title) { 
    
    CORE::Window::width = width;
    CORE::Window::height = height;

    if (!glfwInit())
        return -1;

    window = glfwCreateWindow(CORE::Window::width , CORE::Window::height, title, NULL, NULL);

    if (!window)
        glfwTerminate();
    
    glfwMakeContextCurrent(window);
    glScalef((float)height/(float)width,1,1);
    glFrustum(-1,1,-1,1 ,2,100);
    glEnable(GL_DEPTH_TEST);
}   

int CORE::Window::final() {
    glfwTerminate();
}

bool CORE::Window::isShouldClose() {
    return glfwWindowShouldClose(window);
}

void CORE::Window::pollEvents() {
    glfwPollEvents();
}

void CORE::Window::setShouldClose(bool flag) {
    glfwSetWindowShouldClose(window, flag);
}

void CORE::Window::swapBuffers() {
    glfwSwapBuffers(window);
}
