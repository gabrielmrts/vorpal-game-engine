//
// Created by lnx on 14/01/24.
//

#define GLFW_INCLUDE_VULKAN

#ifndef GAME_VULCAN_VORPAL_H
#define GAME_VULCAN_VORPAL_H

#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <vector>
#include <cstring>
#include <optional>

#include <GLFW/glfw3.h>

struct QueueFamilyIndices {
    std::optional<uint32_t> graphicsFamily;

    [[nodiscard]] bool isComplete() const {
        return graphicsFamily.has_value();
    }
};

class Vorpal {
    public:
        void run();

    private:
        GLFWwindow* window = nullptr;
        VkInstance instance = nullptr;
        VkPhysicalDevice physicalDevice = VK_NULL_HANDLE;
        VkDevice vkDevice = nullptr;
        VkSurfaceKHR surface = nullptr;

        QueueFamilyIndices findQueueFamilies(VkPhysicalDevice device);

        void createSurface();

        void pickPhysicalDevice();

        void createLogicalDevice();

        bool isDeviceSuitable(VkPhysicalDevice device);

        void createInstance();

        bool checkExtensionIsSupported(const char *glfwExtension);

        void initVulkan();

        void mainLoop();

        void cleanup();

        void initWindow();

        bool checkValidationLayerSupport();

        std::vector<const char*> getRequiredExtensions();

        VKAPI_ATTR VkBool32 VKAPI_CALL debugCallback(
            VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity,
            VkDebugUtilsMessageTypeFlagsEXT messageType,
            const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData,
            void* pUserData
        );
};


#endif //GAME_VULCAN_VORPAL_H
