#ifndef __PLATFORM_H__
#define __PLATFORM_H__



/**
 *
 */

#if defined( unix ) || defined( __unix__ ) || defined( __unix )
	#define PLATFORM_UNIX
#elif defined( _WIN32 ) || defined( _WIN64 )
	#define PLATFORM_WINDOWS
#endif

#endif
