/*
 Name:		Debounce.cpp
 Created:	3/10/2019 1:34:58 PM
 Author:	thanh
 Editor:	http://www.visualmicro.com
*/

#include "Debounce.h"

CDebouncer::CDebouncer(unsigned char debouncerTimeInMs)
	: state(IN_RELEASED),
	m_debouncerTime(debouncerTimeInMs),
	m_initTime(0)
{
}

unsigned long CDebouncer::getCurrentTime()
{
	return millis();
}

void CDebouncer::Handle(EVENT event)
{
	switch (state)
	{
	case IN_RELEASED:
		if (event == PRESSED)
		{
			if (getCurrentTime() - m_initTime > m_debouncerTime)
			{
				m_initTime = getCurrentTime();
				state = IN_PRESSED;
				m_ptrPressCallBack;
			}

		}
		break;
	case IN_PRESSED:
		if (event == RELEASED)
		{
			if (getCurrentTime() - m_initTime > m_debouncerTime)
			{
				m_initTime = getCurrentTime();
				state = IN_RELEASED;
				m_ptrReleaseCallBack;
			}
		}
		break;
	}
}

void CDebouncer::RegisterActionWhenPressed(void(*ptrPressed)())
{
	m_ptrPressCallBack = ptrPressed;
}

void CDebouncer::RegisterActionWhenReleased(void(*ptrRelease)())
{
	m_ptrReleaseCallBack = ptrRelease;
}
