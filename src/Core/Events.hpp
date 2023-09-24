#include <GLFW/glfw3.h>


namespace CORE
{
    class Events
    {
        public:
            static int initialize(GLFWwindow *window);
            static void pullEvents();

            static bool pressed(int keycode);
            static bool jpressed(int keycode);

            static bool clicked(int button);
            static bool jclicked(int button);

    };

    void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);
    void mouse_button_callback(GLFWwindow* window, int button, int action, int mode);
    void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);
    void window_size_callback(GLFWwindow* window, int width, int height);
}
