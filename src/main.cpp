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
    CORE::Window *window = new CORE::Window(windowWidth,windowHeight,"TRIPLE AAA GAME");
    CORE::World *world = new CORE::World(window->getWindow() );
    while (!window->isShouldClose())
    {
        window->pollEvents();
        world->update();
        window->swapBuffers();
    }
    delete window, world;
    return 0;
}