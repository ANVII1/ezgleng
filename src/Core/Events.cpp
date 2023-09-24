#include "Events.hpp"

int CORE::Events::initialize(GLFWwindow *window)
{
    glfwSetKeyCallback(window, key_callback);
	glfwSetMouseButtonCallback(window, mouse_button_callback);
	glfwSetCursorPosCallback(window, cursor_position_callback);
	glfwSetWindowSizeCallback(window, window_size_callback);
}

void CORE::key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{

}
void CORE::mouse_button_callback(GLFWwindow* window, int button, int action, int mode)
{

}
void CORE::cursor_position_callback(GLFWwindow* window, double xpos, double ypos)
{

}
void CORE::window_size_callback(GLFWwindow* window, int width, int height)
{

}