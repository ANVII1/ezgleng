/* main.c
 *
 * Copyright 2023 Anvie
 *
 */

// TODO:
/*
    1. Вращение мышкой
    2. разнесение по файлам
    3. Новая перспектива через glPerspectiv а не Frustrum
    4. нормальная ходьба
*/

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <GLFW/glfw3.h>
#include <unistd.h>
#include <math.h>
#include <vector>

const unsigned int windowHeight = 700;
const unsigned int windowWidth = 900;

using namespace std;

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

/// ENTITY ///////////////////////////////////////////////
class Entity 
{
protected:
    Cord cord;
    Axis axis;
    GLFWwindow *window;
public:
    // Constructor ALL ON CLUSIVE
    Entity(GLFWwindow *window,Cord cord, Axis axis)
    {
        this->cord = cord;
        this->axis = axis;
        this->window = window;

    }
    // CONSTRUCTOR BUISNESS CLASS
    Entity(GLFWwindow *window,Cord cord)
    {
        this->cord = cord;
        this->axis = {0,0,0}; 
        this->window = window;
    }

    // CONSTRUCTOR ECONOM
    Entity(GLFWwindow *window)
    {   
        this->cord = {0,0,0}; 
        this->axis = {0,0,0};
        this->window = window;
    }
    
    virtual void update(){}
    virtual void render(){}
};

/// PLAYER ///////////////////////////////////////////////
class Player : public Entity
{
private:
    void rotateCamera()
    {
        glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
        /*
        if (glfwGetInputMode(window,GLFW_CURSOR) != GLFW_CURSOR_DISABLED)
            return;
        */
        static int basex = windowWidth / 2, basey =  windowHeight / 2;
        double xpos,ypos;
        float sensitivity = 0.05f;

        glfwGetCursorPos(window,&xpos,&ypos);
        axis.X += (xpos-basex)* sensitivity;
        axis.Y += (basey-ypos) * sensitivity;

        if (axis.X > 360) axis.X -= 360;
        if (axis.X < 0) axis.X += 360;
        
        if (axis.Y > 90) axis.Y = 90;
        if (axis.Y < -90) axis.Y = -90;

        cout << "Axis X" << axis.X << endl << "Axis Y" << axis.Y << endl << endl;
        glfwSetCursorPos(window,basex,basey);
    }
public:
    Player(GLFWwindow *window):Entity(window)
    {

    };

    virtual void update() override
    {
        rotateCamera();
        if (glfwGetKey(window,GLFW_KEY_W) == GLFW_PRESS) cord.Z += 0.1f;
        if (glfwGetKey(window,GLFW_KEY_A) == GLFW_PRESS) cord.X += 0.1f;
        if (glfwGetKey(window,GLFW_KEY_S) == GLFW_PRESS) cord.Z -= 0.1f;
        if (glfwGetKey(window,GLFW_KEY_D) == GLFW_PRESS) cord.X -= 0.1f;
        if (glfwGetKey(window,GLFW_KEY_SPACE) == GLFW_PRESS) cord.Y -= 0.1f;
        if (glfwGetKey(window,GLFW_KEY_LEFT_CONTROL) == GLFW_PRESS) cord.Y += 0.1f;

    }
    virtual void render() override
    {
        glRotatef(-(axis.Y),1,0,0);
        glRotatef(axis.X,0,1,0);
        glTranslatef(cord.X,cord.Y,cord.Z);
    }
};

/// VISIBLE OBJ ///////////////////////////////////////////////
class VisibleObject : public Entity
{
private:
    float *verteces;
    unsigned int verArrLenght;
    Color color;

public:
    // construct on Coordinates with axis
    VisibleObject(GLFWwindow *window, Color color, Axis axis, Cord cord, float verteces[], unsigned int verArrLenght) : Entity(window, cord, axis)
    {
        this->verArrLenght =  verArrLenght;
        this->color = color;
        this->verteces = new float [verArrLenght];
        for (int i = 0; i < verArrLenght; ++i)
            this->verteces[i] = verteces[i];
        
    };

    ~VisibleObject()
    {
        delete[] verteces;
    };

    virtual void render() override
    {
        glLineWidth(10);
        glColor3f(color.R,color.G,color.B);
        glVertexPointer(3,GL_FLOAT,0,this->verteces);
        glEnableClientState(GL_VERTEX_ARRAY);
            glDrawArrays(GL_TRIANGLE_FAN,0,4);
        glDisableClientState(GL_VERTEX_ARRAY);
    }
};

class World
{
private:
    GLFWwindow* window;
    vector<Entity*> entities;

    void CreateRect(Color color, Cord cord)
    {
        float verteces[] = {
            -0.5f + cord.X, 0.0f + cord.Y, -0.5f + cord.Z,
             0.5f + cord.X, 0.0f + cord.Y, -0.5f + cord.Z,
             0.5f + cord.X, 0.0f + cord.Y,  0.5f + cord.Z,
            -0.5f + cord.X, 0.0f + cord.Y,  0.5f + cord.Z
        };
        unsigned int verArrSize = 12;
        Axis axis {0,0,0};
        entities.push_back(new VisibleObject(window, color, axis, cord, verteces,verArrSize));
    }

    void CreateFloor()
    {   
        for (int i = 0; i < 15;i++)
        {
            for (int j = 0; j < 15;j++)
            {        
                Color color;
                Cord cord {-i,-1,-j}; // MB bug
                if ((j+i)%2==0) 
                    {color = {1,1,1,1};}
                else 
                    {color = {0,0,0,1};}
                CreateRect(color, cord);
            }
        }
    }

public:
    World(GLFWwindow* window)
    {
        this->window = window;
        entities.push_back(new Player(this->window));
        CreateFloor();
    }

    void update()
    {
        for (size_t i = 0; i < entities.size();++i)
        {
            entities[i]->update();
            entities[i]->render();
        }
    }
};

int main(void)
{
    GLFWwindow* window;
    if (!glfwInit())
        return -1;

    window = glfwCreateWindow(windowWidth, windowHeight, "Tripe AAA Game", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    // Создаём контест кокна
    glfwMakeContextCurrent(window);
    // Скейлим изображение окна под разрешение
    glScalef((float)windowHeight/(float)windowWidth,1,1);
    glFrustum(-1,1,-1,1 ,2,100);

    glEnable(GL_DEPTH_TEST);

    World *world = new World(window);

    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();
        glClearColor(0.85f, 1, 1,1);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

            glPushMatrix();
            world->update();
            glPopMatrix();
        
        glfwSwapBuffers(window);

    }
    
    glfwTerminate();
    return 0;
}