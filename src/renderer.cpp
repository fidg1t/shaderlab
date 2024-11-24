//-----------------------------------------------------------------------------
// Filename: renderer.cpp
// Purpose:  Template file
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------

#include "renderer.hpp"
#include "window.hpp"
#include <iostream>

//-----------------------------------------------------------------------------
// Defines
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Functions
//-----------------------------------------------------------------------------

Renderer::Renderer() : m_window(nullptr)
{

}

Renderer::~Renderer()
{
  
}

void Renderer::Init()
{
  // Setup GLFW
  glfwInit();

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  
  m_window = new Window("Shaderlab");

  // Setup GLAD
  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
  {
    std::cerr << "Failed to initialize GLAD" << std::endl;
    return;
  }

  glViewport(0, 0, 800, 600);
}

void Renderer::Update(double dt)
{
  m_window->Update(dt);
}

void Renderer::Render()
{

}

void Renderer::Exit()
{
  delete m_window;
}

bool Renderer::ShouldExit() const
{
  return m_window->ShouldClose();
}