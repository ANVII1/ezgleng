#include "Entity.hpp"

namespace CORE 
{
    class Player : public CORE::Entity
    {
    private:
        float braking;
        void rotateCamera();
    public:
        Player(GLFWwindow *window);
        virtual void update() override;
        virtual void render() override;
    };
}
