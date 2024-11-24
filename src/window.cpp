//-----------------------------------------------------------------------------
// Filename: window.cpp
// Purpose:  Window handling
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------

#include "window.hpp"
#include <iostream>

//-----------------------------------------------------------------------------
// Defines
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Functions
//-----------------------------------------------------------------------------

Window::Window(const char* name)
{
  m_glfwWindow = glfwCreateWindow(800, 600, name, NULL, NULL);

  if (!m_glfwWindow)
  {
    std::cerr << "Failed to create window" << std::endl;
    glfwTerminate(); // maybe move this
  }
  
  glfwMakeContextCurrent(m_glfwWindow);
}

Window::~Window()
{

}

GLFWwindow* Window::GetGLFWWindow() const
{
  return m_glfwWindow;
}

bool Window::ShouldClose() const
{
  return glfwWindowShouldClose(m_glfwWindow);
}