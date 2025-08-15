#pragma once
#include "obse64_common/obse64_version.h" // OBSE
#include "obse64_common/Log.h" // Needed for OBSE64
#include "obse64_common/Errors.h" // Needed for OBSE64
#include "IVersionCheck.h" // Common plugin version check, found in \common\common_plugins\
// #include "../plugin_common/common.h" // EG: Common plugin functions for this sdk if needed

// ================================
// Plugin Information
// ================================

// Plugin info
#define PLUGIN_AUTHOR				"Ez0n3"					// Author of the plugin

#define PLUGIN_NAME_SHORT			"ez_obse64_plugin_example"	// Plugin name without spaces
#define PLUGIN_NAME_LONG			"Ez OBSE64 Plugin Example"	// Plugin name with spaces

// Plugin version, Major, Minor, Build. EG: (1.0.0) equals (Major.Minor.Build)
#define PLUGIN_VERSION_MAJOR		1
#define PLUGIN_VERSION_MINOR		0
#define PLUGIN_VERSION_BUILD		0

// ================================
// Nothing below this needs changing between plugins except maybe MINIMUM_RUNTIME_VERSION and/or SUPPORTED_RUNTIME_VERSION_STRICT
// ================================

// Plugin log file
#define PLUGIN_LOG_FILE				"\\My Games\\" GAME_SAVE_FOLDER_NAME("Oblivion Remastered") "\\OBSE\\" PLUGIN_LOG_FILE_NAME(PLUGIN_NAME_SHORT) // plugin log file location

// Common definitions
#define SDK_VERSION_STRING			VERSION_TO_STRING(OBSE_VERSION_INTEGER, OBSE_VERSION_INTEGER_MINOR, OBSE_VERSION_INTEGER_BETA)
#define PLUGIN_VERSION_STRING		VERSION_TO_STRING(PLUGIN_VERSION_MAJOR, PLUGIN_VERSION_MINOR, PLUGIN_VERSION_BUILD)

#define PLUGIN_VERSION_DLL			MAKE_EXE_VERSION(PLUGIN_VERSION_MAJOR, PLUGIN_VERSION_MINOR, PLUGIN_VERSION_BUILD)
#define PLUGIN_VERSION_INFO			PLUGIN_NAME_SHORT " v%s (0x%08X) (SDK v%s)", PLUGIN_VERSION_STRING, PLUGIN_VERSION_DLL, SDK_VERSION_STRING

// ================================
// Plugin Version Information
// ================================

// The minimum runtime version allowed by the plugin. EG: I need function X, which was added in runtime Y, therefore Y is the minimum runtime version
#define MINIMUM_RUNTIME_VERSION				RUNTIME_VERSION_0_411_140	// The lowest version

// The runtime version the plugin was designed for
// #define SUPPORTED_RUNTIME_VERSION		CURRENT_RELEASE_RUNTIME
#define SUPPORTED_RUNTIME_VERSION			RUNTIME_VERSION // Set in /config/_Plugins.props, controls core and plugin versions - normally latest

// Strict runtime version. If strict=true, runtime and supported versions must match. If strict=false, runtime version must be above the minimum
#define SUPPORTED_RUNTIME_VERSION_STRICT	false

// The compatible runtime version - set automatically
#define COMPATIBLE(runtimeVersion)			(runtimeVersion == SUPPORTED_RUNTIME_VERSION)

// ================================

/*
// From obse64_version.h

#define RUNTIME_VERSION_0_411_140	MAKE_EXE_VERSION(0, 411, 140)	// 0x019B08C0	initial release
#define RUNTIME_VERSION_0_411_141	MAKE_EXE_VERSION(0, 411, 141)	// 0x019B08D0	ms store only update
#define RUNTIME_VERSION_0_411_142	MAKE_EXE_VERSION(0, 411, 142)	// 0x019B08E0	ms store only update
#define RUNTIME_VERSION_1_511_102	MAKE_EXE_VERSION(1, 511, 102)	// 0x11FF0660	beta patch released to public
#define RUNTIME_VERSION_1_512_105	MAKE_EXE_VERSION(1, 512, 102)	// 0x12000690	beta patch released to public
*/

