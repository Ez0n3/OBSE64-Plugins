#include "GameData.h"

RelocPtr <TESDataHandler *> g_dataHandler(0x09480018);

TESDataHandler * TESDataHandler::GetSingleton()
{
	return *g_dataHandler;
}
