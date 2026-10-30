#pragma once 

#include <vulkan/vulkan.h>

class VulkanContext
{
public:
    bool Initialize();
    bool SelectPhysicalDevice();
    void Shutdown();
    
private:
    VkInstance m_Instance = VK_NULL_HANDLE;
    VkPhysicalDevice m_PhysicalDevice = VK_NULL_HANDLE;
};