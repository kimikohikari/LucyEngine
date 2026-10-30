#include "VulkanContext.h"

#include <iostream>
#include <vector>

bool VulkanContext::Initialize()
{
    VkApplicationInfo appInfo{};
    appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;

    appInfo.pApplicationName = "Lucy Engine";
    appInfo.applicationVersion = VK_MAKE_VERSION(0, 0, 1);

    appInfo.pEngineName = "Lucy Engine";
    appInfo.engineVersion = VK_MAKE_VERSION(0, 0, 1);

    appInfo.apiVersion = VK_API_VERSION_1_0;

    VkInstanceCreateInfo createInfo{};
    createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    createInfo.pApplicationInfo = &appInfo;

    VkResult result = vkCreateInstance(
        &createInfo,
        nullptr,
        &m_Instance
    );

    if(result != VK_SUCCESS)
    {
        std::cerr << "Failed to create Vulkan Instance. Error code: "
                  << result << "\n";
        
        return false;
    }

    std::cout << "Vulkan Instance created successfully.\n";

    return true;
}

bool VulkanContext::SelectPhysicalDevice()
{
    uint32_t deviceCount = 0;

    vkEnumeratePhysicalDevices(
        m_Instance,
        &deviceCount,
        nullptr
    );

    if (deviceCount == 0)
    {
        std::cerr << "No Vulkan-compatible GPUs found.\n";
        return false;
    }

    std::vector<VkPhysicalDevice> devices(deviceCount);

    vkEnumeratePhysicalDevices(
        m_Instance,
        &deviceCount,
        devices.data()
    );

    m_PhysicalDevice = devices[0];

    VkPhysicalDeviceProperties deviceProperties{};
    vkGetPhysicalDeviceProperties(
        m_PhysicalDevice,
        &deviceProperties
    );
    
    std::cout << "Selected GPU:" 
              << deviceProperties.deviceName 
              << "\n";
    
    return true;
}

void VulkanContext::Shutdown()
{
    if (m_Instance != VK_NULL_HANDLE)
    {
        vkDestroyInstance(m_Instance, nullptr);

        m_Instance = VK_NULL_HANDLE;
    }
}