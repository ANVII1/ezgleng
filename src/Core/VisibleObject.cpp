
#include "VisibleObject.hpp"
/// VISIBLE OBJ ///////////////////////////////////////////////
// construct on Coordinates with axis
CORE::VisibleObject::VisibleObject(GLFWwindow *window, CORE::Color color, CORE::Axis axis, CORE::Cord cord, float verteces[], unsigned int verArrLenght) : CORE::Entity(window, cord, axis)
{
    this->verArrLenght =  verArrLenght;
    this->color = color;
    this->verteces = new float [verArrLenght];
    for (int i = 0; i < verArrLenght; ++i)
        this->verteces[i] = verteces[i];
    
};

CORE::VisibleObject::~VisibleObject()
{
    delete[] verteces;
};

void CORE::VisibleObject::rotate() 
{
    
}

void CORE::VisibleObject::render()
{
    glLineWidth(10);
    glColor3f(color.R,color.G,color.B);
    glVertexPointer(3,GL_FLOAT,0,this->verteces);
    glEnableClientState(GL_VERTEX_ARRAY);
        glDrawArrays(GL_TRIANGLE_FAN,0,4);
    glDisableClientState(GL_VERTEX_ARRAY);
}