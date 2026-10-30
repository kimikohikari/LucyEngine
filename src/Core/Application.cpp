#include "Application.h"
#include <GLFW/glfw3.h>
#include <iostream>

void Application::Run()
{
    if (!glfwInit())
    {
        std::cerr << "Failed to initialize GLFW\n";
        return;
    }
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    GLFWwindow* window = glfwCreateWindow(
        1280,
        720,
        "Lucy Engine",
        nullptr,
        nullptr
    );

    if(!window)
    {
        std::cerr << "Failed to create GLFW window\n";
        glfwTerminate();
        return;
    }

    std::cout << "Lucy Engine window created\n";

    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
}