/* main.c
 *
 * Copyright 2023 Anvie
 *
 */

// TODO:
/*
    1. Новая перспектива через glPerspectiv а не Frustrum
    2. нормальная ходьба
*/

#include <GLFW/glfw3.h>

#include "Core/World.hpp"
#include "Core/Window.hpp"

const unsigned int windowHeight = 700;
const unsigned int windowWidth = 900;

using namespace std;

int main()
{
    CORE::Window::init(windowWidth,windowHeight,"TRIPLE AAA GAME");
    CORE::World *world = new CORE::World(CORE::Window::window);
    while (!CORE::Window::isShouldClose())
    {
        CORE::Window::pollEvents();
        world->update();
        CORE::Window::swapBuffers();
    }
    delete world;
    return 0;
}