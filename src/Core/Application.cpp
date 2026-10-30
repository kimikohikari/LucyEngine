#include "Application.h"
#include <GLFW/glfw3.h>
#include "../Renderer/VulkanContext.h"
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

    VulkanContext vulkanContext;

    if (!vulkanContext.Initialize())
    {
        std::cerr << "Failed to initialize Vulkan.\n";

        glfwDestroyWindow(window);
        glfwTerminate();

        return;
    }

    if (!vulkanContext.SelectPhysicalDevice())
    {
        std::cerr << "Failed to select physical device.\n";
        
        vulkanContext.Shutdown();

        glfwDestroyWindow(window);
        glfwTerminate();

        return;
    }

    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();
    }

    vulkanContext.Shutdown();

    glfwDestroyWindow(window);
    glfwTerminate();
}