#include "GameObjects.h"
#include "obse64_common/Relocation.h"

RelocAddr <PlayerCharacter *> PlayerCharacterSingleton(0x0941F708);

PlayerCharacter * PlayerCharacter::Get()
{
	return PlayerCharacterSingleton;
}
