// User Defines
#include "config.h"
// OBSE64
#include "obse64/PluginAPI.h"
//#include "skse64/PapyrusNativeFunctions.h" // OBSE does not use Papyrus, what then???
#include "obse64/GameConsole.h" // Print to console
// Windows
#include <shlobj.h>	// CSIDL_MYCODUMENTS

// NOTE: This plugin is currently UNTESTED, but it should work based on similarities with all other SDks
// NOTE: This is a WIP, currently I have not found a way to create a new function that interfaces with game scripts
// NOTE: Although there is not a way to interface with game scripts, the messaging listener and other interfaces should work

// ================================
// Handles
// ================================

// Handle for the plugin
PluginHandle g_pluginHandle = kPluginHandle_Invalid;

// Handle for the papyrus interface
//static OBSEPapyrusInterface* g_papyrus = NULL; // FIXME OBSE does not use Papyrus, what then???

// Handle for other things...

/* // Uncomment to use messaging
// Handle for the messaging interface
static OBSEMessagingInterface* g_messaging = NULL;
*/

// ================================
// User Code
// ================================

// Example namespace and test bool function to print Hello World! to the OBSE plugin log
namespace Plugin_Example_Functions
{
	bool Test() //StaticFunctionTag *base
	{
		_MESSAGE("Hello World!"); // print to the plugin log
		Console_Print("Hello Console!"); // print to the in-game console
		return true;
	}
}

// ================================
// Plugin Listener
// ================================

/* // Uncomment to use messaging
// Listener for the plugin
static void PluginListener(OBSEMessagingInterface::Message* msg) noexcept
{
	switch (msg->type) {
		//case OBSEMessagingInterface::kMessage_PostLoad:
		case OBSEMessagingInterface::kMessage_PostPostLoad: // facilitate the correct dispatching/registering of messages/listeners
		{
			_MESSAGE("PluginListener: kMessage_PostPostLoad");
			break;
		}
		//case OBSEMessagingInterface::kMessage_PostPostDataLoad:
		case OBSEMessagingInterface::kMessage_DataLoaded: // sent after all game data has loaded
		{
			_MESSAGE("PluginListener: kMessage_DataLoaded");
			break;
		}
	}
}
*/

// ================================
// Plugin Compatibility Check
// ================================

// Check that the runtime and plugin versions are compatible
const bool IsCompatible(const OBSEInterface* obse)
{
	// FIXME - need to check for - in editor - like the rest??
	
	// check for compatible version. if strict=true, runtime and supported versions must match. if strict=false, runtime version must be above the minimum
	if (!IVersionCheck::IsCompatibleVersion(obse->runtimeVersion, MINIMUM_RUNTIME_VERSION, SUPPORTED_RUNTIME_VERSION, SUPPORTED_RUNTIME_VERSION_STRICT)) { // not strict
		_MESSAGE("ERROR::IsCompatible: Plugin is not compatible with runtime version, disabling");
		_FATALERROR("ERROR::IsCompatible: Plugin is not compatible with runtime version, disabling");
		
		// not compatible
		return false;
	}
	
	// compatible
	return true;
}

// ================================
// Plugin Export, Query and Load - Start Extern-C
// ================================

extern "C" { // Start: extern "C"

// ================================
// Plugin Version Data - Not Used In All SE SDK's
// ================================

// Export the plugin version data to obse64, without this the plugin will fail to load. See: PluginAPI.h
__declspec(dllexport) OBSEPluginVersionData OBSEPlugin_Version =
{
	OBSEPluginVersionData::kVersion, // obse64 expects plugin version info to follow this structure
	
	PLUGIN_VERSION_DLL,		// set in config.h
	PLUGIN_NAME_LONG, 		// set in config.h
	PLUGIN_AUTHOR, 			// set in config.h

	0,	// not address independent
	0,	// not structure independent
	
	// { RUNTIME_VERSION_0_411_140, 0 },	// compatible with 0.411.140 and that's it
	// { RUNTIME_VERSION_1_512_105, 0 },
	{ SUPPORTED_RUNTIME_VERSION, 0 },		// set in config.h
	
	0,	// works with any version of the script extender. you probably do not need to put anything here
	
	0, 0, 0	// set these reserved fields to 0
};

// ================================
// Plugin Query - Not Used In All SE SDK's
// ================================

/*
// OBSE64 does not use this
bool OBSEPlugin_Query(const OBSEInterface* obse, PluginInfo* info)
{
}
*/

// ================================
// Plugin Preload - Not Used In All SE SDK's
// ================================

/*
// If your plugin needs to make modifications before global initializers, add and export this:
// Note: Game and OBSE functionality may be limited during preload
bool OBSEPlugin_Preload(const OBSEInterface* obse)
{
	_MESSAGE("Plugin_Preload: Preloading");
	
	// User Code
	
	_MESSAGE("Plugin_Preload: Preloaded");
	
	return true;
}
*/

// ================================
// Plugin Load - Used In All SE SDK's
// ================================

// OBSE Plugin Load - Called when the plugin loads everytime
bool OBSEPlugin_Load(const OBSEInterface* obse)
{
	// This is not needed for OBSE64, it handles this internally instead of using common_vc#
	// open the plugin log file
	// gLog.OpenRelative(CSIDL_MYDOCUMENTS, PLUGIN_LOG_FILE);

	_MESSAGE(PLUGIN_VERSION_INFO); // write the plugin version to the log
	_MESSAGE("Plugin_Load: Loading");
	
	// check for compatible versions
	if (!IsCompatible(obse)) {
		_MESSAGE("ERROR::Plugin_Load: Incompatible | Disabling Plugin");
		_FATALERROR("ERROR::Plugin_Load: Incompatible | Disabling Plugin");
		// incompatible
		return false;
	}
	
	// FIXME - this should be in PreLoad instead? Maybe only if PreLoad is needed?
	// store plugin handle for later
	g_pluginHandle = obse->GetPluginHandle();
	
	/* // Uncomment to use messaging
	// register the listener
	g_messaging = (OBSEMessagingInterface*)obse->QueryInterface(kInterface_Messaging);
	if (g_messaging) {
		if (g_messaging->RegisterListener(g_pluginHandle, "OBSE", PluginListener)) {
			_MESSAGE("Plugin_Load: Listener Registered");
		}
	}
	*/
	
	_MESSAGE("Plugin_Load: Loaded Successfully"); // log the successful load

	// initialized
	return true;
}

}; // Stop: extern "C"

// ================================
