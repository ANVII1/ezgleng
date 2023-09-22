#include <vector>
#include "Entity.hpp"

namespace CORE 
{
    class World
    {
    private:
        GLFWwindow* window;
        std::vector<CORE::Entity*> entities;

    private:
        void CreateRect(CORE::Color color, CORE::Cord cord);
        void CreateFloor();
        void render_sqd();

    public:
        World(GLFWwindow* window);
        ~World();
        void update();
        
    };
}
