#include "..\..\Includes\Geometry\IndexBuffer.h"


Geometry::IndexBuffer::IndexBuffer(GLushort * data, GLuint count):
m_IndexCount(count)
{
    glGenBuffers(1, &m_BufferID);
    Bind();
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, m_IndexCount * sizeof(GLushort), data, GL_DYNAMIC_DRAW);
    Unbind();
}

Geometry::IndexBuffer::IndexBuffer(GLuint * data, GLuint count)
{
    glGenBuffers(1, &m_BufferID);
    Bind();
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, m_IndexCount * sizeof(GLint), data, GL_DYNAMIC_DRAW);
    Unbind();
}

Geometry::IndexBuffer::~IndexBuffer()
{
    glDeleteBuffers(1, &m_BufferID);
}

void Geometry::IndexBuffer::Bind() const
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_BufferID);
}

void Geometry::IndexBuffer::Unbind() const
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}
