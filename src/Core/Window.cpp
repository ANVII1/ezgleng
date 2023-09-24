#include <GLFW/glfw3.h>
#include "Window.hpp"


GLFWwindow* CORE::Window::window;

int CORE::Window::init(int width, int height, const char* title) {   
    if (!glfwInit())
        return -1;

    window = glfwCreateWindow(width, height, title, NULL, NULL);

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
