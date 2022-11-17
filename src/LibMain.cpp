#include "LibMain.h"
//#include <cstdint>

using GPUtils = gigperformer::sdk::GPUtils;

// Define an XML string describing your product
const std::string XMLProductDescription =
    // Replace with your information
    "<Library>"
    "  <Product"
    "    Name=\"Plugin Sync\""
    "    Version=\"1.0\""
    "    BuildDate=\"17/11/2022\">"
    "  </Product> "
    "  <Description>Update a global rackspace plugin from a local rackspace plugin</Description>"
    "  <ImagePath></ImagePath>"
    "</Library>";

 std::string localHandlePrefix = "LOCAL_";
const std::string globalHandlePrefix = "GLOBAL_";

void LibMain::Initialization()
{
    registerCallback("OnRackspaceActivated");
}

void LibMain::SyncPlugins()
{
    std::vector<std::string> localPlugins;
    std::vector<std::string> globalPlugins;
    getPluginList(localPlugins, false);
    getPluginList(globalPlugins, true);
    for (int i = 0; i < localPlugins.size(); i++) {
        std::string plugin = localPlugins[i];
        if (plugin.find(localHandlePrefix) != std::string::npos) { // Widget handle matches the defined format
            std::string localHandleSuffix = plugin.substr(plugin.find("_") + 1, plugin.length()); // Extract the handle suffix - this is what we will match to a global plugin
            if (pluginExists(globalHandlePrefix + localHandleSuffix, true)) { // Attempt to locate a global plugin with the same handle suffix as the local plugin
                // Match found - sync the parameters
                std::string globalPlugin = globalHandlePrefix + localHandleSuffix;
                int localPluginParameterCount = getPluginParameterCount(plugin, false);
                int globalPluginParameterCount = getPluginParameterCount(globalPlugin, true);
                for (int j = 0; j < localPluginParameterCount; j++) {
                    if (j < globalPluginParameterCount) { // Check in case the plugins aren't the same and have different parameter counts
                        setPluginParameter(globalPlugin, j, getPluginParameter(plugin, j, false), true);
                    }
                }
            }
        }
    }
    
}
void LibMain::OnRackspaceActivated() 
{
    SyncPlugins();
}

std::string LibMain::GetProductDescription()
{
    return XMLProductDescription;
}

namespace gigperformer
{
namespace sdk
{

GigPerformerAPI *CreateGPExtension(LibraryHandle handle)
{
    return new LibMain(handle);
}

} // namespace sdk
} // namespace gigperformer
