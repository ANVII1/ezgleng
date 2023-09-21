#include <GLFW/glfw3.h>

namespace CORE
{
    class Window {
    private:
        GLFWwindow* window;
    public:
        Window(int width, int height, const char* title);
        ~Window();

        GLFWwindow* getWindow();
        void pollEvents();
        bool isShouldClose();
        void setShouldClose(bool flag);
        void swapBuffers();
    };
}
