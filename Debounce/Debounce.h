/*
 Name:		Debounce.h
 Created:	3/10/2019 1:34:58 PM
 Author:	thanh
 Editor:	http://www.visualmicro.com
*/

#ifndef _Debounce_h
#define _Debounce_h

#define ARDUINO 100

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

class CDebouncer
{
private:
	typedef enum
	{
		IN_PRESSED,
		IN_RELEASED,
	} STATE;

	typedef enum
	{
		PRESSED,
		RELEASED,
	} EVENT;

	STATE state;

	unsigned char m_debouncerTime;
	unsigned long m_initTime;
	unsigned long getCurrentTime();
	void(*m_ptrPressCallBack)(void);
	void(*m_ptrReleaseCallBack)(void);

public:
	void Handle(EVENT event);
	CDebouncer(unsigned char debouncerTimeInMs);
	void RegisterActionWhenPressed(void(*ptrPressed)());
	void RegisterActionWhenReleased(void(*ptrRelease)());
};

#endif

