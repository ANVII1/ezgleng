#include "Entity.hpp"

/// VISIBLE OBJ ///////////////////////////////////////////////
namespace CORE 
{
    class VisibleObject : public CORE::Entity
    {
    private:
        float *verteces;
        unsigned int verArrLenght;
        CORE::Color color;
        void rotate();

    public:
        VisibleObject(GLFWwindow *window, CORE::Color color, CORE::Axis axis, CORE::Cord cord, float verteces[], unsigned int verArrLenght); // MB BUG
        ~VisibleObject();

        virtual void render() override;
    };
}
