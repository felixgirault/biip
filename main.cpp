#include <iostream>
#include <stdlib.h>

#include "score.h"
#include "biip.h"



/**
 *
 */

int main( int argc, char* argv[ ]) {

	if ( argc < 2 ) {
		std::cerr << "You must pass a score." << std::endl;
		return EXIT_FAILURE;
	}

	int repeat = 1;

	if ( argc > 2 ) {
		repeat = atoi( argv[ 2 ]);
	}

	try {
		Biip biip;
		biip.playScore( Score( argv[ 1 ]), repeat );
	} catch ( std::exception e ) {
		std::cerr << e.what( ) << std::endl;
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}
