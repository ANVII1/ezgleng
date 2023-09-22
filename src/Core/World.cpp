#include "World.hpp"
#include "VisibleObject.hpp"
#include "Player.hpp"
#include <GLFW/glfw3.h>

void CORE::World::render_sqd()
{
    GLfloat verteces[] = 
    {
        -0.5f, -0.5f, 0.0f,
        0.5f, -0.5f, 0.0f,
        0.5f, 0.5f, 0.0f,
        -0.5f, 0.5f, 0.0f
    };
    
    glColor3f(0,0,0);
    glVertexPointer(3,GL_FLOAT,0,&verteces);
    glEnableClientState(GL_VERTEX_ARRAY);
        glDrawArrays(GL_TRIANGLE_FAN,0,4);
    glDisableClientState(GL_VERTEX_ARRAY);
}

void CORE::World::CreateRect(CORE::Color color, CORE::Cord cord)
{
    float verteces[] = {
        -0.5f + cord.X, 0.0f + cord.Y, -0.5f + cord.Z,
            0.5f + cord.X, 0.0f + cord.Y, -0.5f + cord.Z,
            0.5f + cord.X, 0.0f + cord.Y,  0.5f + cord.Z,
        -0.5f + cord.X, 0.0f + cord.Y,  0.5f + cord.Z
    };
    unsigned int verArrSize = 12;
    CORE::Axis axis {0,0,0};
    entities.push_back(new CORE::VisibleObject(window, color, axis, cord, verteces,verArrSize));
}

void CORE::World::CreateFloor()
{   
    for (int i = 0; i < 15;i++)
    {
        for (int j = 0; j < 15;j++)
        {        
            CORE::Color color;
            CORE::Cord cord {-i,-1,-j}; // MB bug
            if ((j+i)%2==0) 
                {color = {1,1,1,1};}
            else 
                {color = {0,0,0,1};}
            CreateRect(color,cord);
        }
    }
}

CORE::World::World(GLFWwindow* window)
{
    this->window = window;
    entities.push_back(new CORE::Player(this->window));
    CreateFloor();
}

void CORE::World::update()
{
    glClearColor(0.85f, 1, 1,1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glPushMatrix();
    for (size_t i = 0; i < entities.size();++i)
    {
        entities[i]->update();
        entities[i]->render();
    }
    glPopMatrix();
}

CORE::World::~World()
{
    delete window;
    //delete [] entities; Придумать как удалять сущности которые создаются в куче ибо утечка памяти
}