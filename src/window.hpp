//-----------------------------------------------------------------------------
// Filename: window.hpp
// Purpose:  Window handling
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------

#include <glad/glad.h>
#include <GLFW/glfw3.h>

//-----------------------------------------------------------------------------
// Class
//-----------------------------------------------------------------------------

class Window
{
public:
  Window(const char* name);
  ~Window();
private:
  GLFWwindow* m_glfwWindow;
};