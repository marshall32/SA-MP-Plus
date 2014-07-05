#pragma once

#include <stdafx.h>

class CLocalPlayer
{
public:
	enum ePlayerAction : unsigned char
	{
		ALL,
		SPRINT,
		ENTER_CAR,
		CROUCH,
		FIRE_WEAPON,
		UNKNOWN,
		SWITCH_WEAPON,
		JUMP,
		COUNT
	};

	static void SetActionEnabled(unsigned char action, bool bEnabled);
	static void OnDriveByShot();

private:
	static DWORD m_actionMemory[ePlayerAction::COUNT-1];

};