#pragma once 

#include <vulkan/vulkan.h>

class VulkanContext
{
public:
    bool Initialize();
    void Shutdown();

private:
    VkInstance m_Instance = VK_NULL_HANDLE;
};