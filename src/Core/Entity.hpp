#pragma once

#include <GLFW/glfw3.h>

namespace CORE
{
    struct Cord
    {
        float X, Y, Z;
    };
    struct Axis
    {
        float X, Y, Z;
    };
    struct Color
    {
        float R,G,B,A;
    };
    struct Speed
    {
        float X, Y, Z;
        float maxX, maxY, maxZ;
    };

    class Entity 
    {
    protected:
        CORE::Cord cord;
        CORE::Axis axis;
        GLFWwindow *window;
    public:
        Entity(GLFWwindow *window,Cord cord, Axis axis);
        Entity(GLFWwindow *window,Cord cord);
        Entity(GLFWwindow *window);
        virtual void update();
        virtual void render();
    };
}

