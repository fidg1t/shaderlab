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

static void FramebufferSizeCallback(GLFWwindow* window, int width, int height);

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

  glfwSetFramebufferSizeCallback(m_glfwWindow, FramebufferSizeCallback);
}

Window::~Window()
{

}

void Window::Update(double dt)
{
  glfwSwapBuffers(m_glfwWindow);
  glfwPollEvents();
}

GLFWwindow* Window::GetGLFWWindow() const
{
  return m_glfwWindow;
}

bool Window::ShouldClose() const
{
  return glfwWindowShouldClose(m_glfwWindow);
}

static void FramebufferSizeCallback(GLFWwindow* window, int width, int height)
{
  glViewport(0, 0, width, height);
}