#include <stdexcept>
#ifdef __linux__
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/kd.h>
#elif defined _WIN32 || defined _WIN64
#include <windows.h>
#endif

#include "speaker.h"

#define TICK 1193180



/**
 *
 */

Speaker::Speaker( ) {

#ifdef PLATFORM_UNIX
	_console = open( "/dev/console", O_WRONLY );

	if ( _console == -1 ) {
		throw new std::runtime_error( "Unable to use the speaker, try to run biip as root." );
	}
#endif
}



/**
 *
 */

Speaker::~Speaker( ) {

#ifdef PLATFORM_UNIX
	close( _console );
#endif
}



/**
 *
 */

void Speaker::beep( float frequency, int duration ) {

#if defined( PLATFORM_UNIX )
	ioctl( _console, KIOCSOUND, ( int )( TICK / frequency ));
	pause( duration );
	ioctl( _console, KIOCSOUND, 0 );
#elif defined( PLATFORM_WINDOWS )
	Beep( frequency, duration );
#endif
}



/**
 *
 */

void Speaker::pause( int duration ) {

	usleep( 1000 * duration );
}
