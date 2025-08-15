#include "GameScript.h"

RelocAddr <ParseFunction> DefaultParseFunction(0x0694B810);
RelocAddr <_ExtractArgs> ExtractArgs(0x06630750);

// wrap this to give it a static address
bool Cmd_Default_Parse(u32 numParams, const ParamInfo * paramInfo, ScriptLineBuffer * lineBuf, ScriptBuffer * scriptBuf)
{
	return DefaultParseFunction(numParams, paramInfo, lineBuf, scriptBuf);
}

RelocPtr <CommandInfo>	g_firstScriptCommand(0x08FBA4A0);
RelocPtr <CommandInfo>	g_firstConsoleCommand(0x08FC1890);
