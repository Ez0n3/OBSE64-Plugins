#include "obse64/GameConsole.h"
#include "obse64_common/Relocation.h"

RelocPtr <u8> g_bConsoleMode(0x094800B8);
RelocPtr <std::uintptr_t> _Console_Print(0x0656A7A0);

bool IsConsoleMode()
{
	return *g_bConsoleMode;
}
