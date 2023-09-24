#include <GLFW/glfw3.h>
#include <iostream>

namespace CORE
{
    class Window {
    public:
        static GLFWwindow* window;
        static int init(int width, int height, const char* title);
        static int final();

        static void pollEvents();
        static bool isShouldClose();
        static void setShouldClose(bool flag);
        static void swapBuffers();
    };
}
