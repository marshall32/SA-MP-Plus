#pragma once

#include <map>
#include "../Shared/RakNet/BitStream.h"

#define RPC_CALLBACK void
#define RPC_ARGS RakNet::BitStream& bsData, int iExtra

typedef RPC_CALLBACK (*RPCFunct_t)(RPC_ARGS);

enum eRPC : unsigned short
{
	// client RPCs
	TOGGLE_HUD_COMPONENT,
	SET_RADIO_STATION,
	SET_WAVE_HEIGHT,
	TOGGLE_PAUSE_MENU,
	SET_HUD_COMPONENT_COLOUR,
	TOGGLE_ACTION,
	/*SET_CHECKPOINT_COLOUR,
	SET_RACE_CHECKPOINT_COLOUR,*/

	// server RPCs
	ON_PAUSE_MENU_TOGGLE,
	ON_PAUSE_MENU_CHANGE,
	ON_DRIVE_BY_SHOT
};

class CRPC
{
public:
	static void Add(unsigned short usRPCId, RPCFunct_t func);
	static void Process(unsigned short usRPCId, RakNet::BitStream& bsData, int iExtra = NULL);

private:
	static std::map<unsigned short, RPCFunct_t> m_functions;

};
