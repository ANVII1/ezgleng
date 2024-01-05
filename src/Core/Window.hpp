#include <GLFW/glfw3.h>
#include <iostream>

namespace CORE
{
    class Window {
    public:
        static unsigned int width;
        static unsigned int height;
        static GLFWwindow* window;
        static int init(unsigned int width, unsigned int height, const char* title);
        static int final();

        static void pollEvents();
        static bool isShouldClose();
        static void setShouldClose(bool flag);
        static void swapBuffers();
    };
}
