#ifndef __SPEAKER_H__
#define __SPEAKER_H__

#include "platform.h"



/**
 *
 */

class Speaker {

	public:

		Speaker( );
		~Speaker( );

		void beep( float freqency, int duration );
		void pause( int duration );

#ifdef PLATFORM_UNIX
	private:

		int _console;
#endif

};

#endif
