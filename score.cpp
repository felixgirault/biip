#include <fstream>
#include <stdexcept>

#include "score.h"



/**
 *
 */

Score::Score( const std::string& fileName ) {

	std::ifstream file( fileName.c_str( ));

	if ( !file ) {
		throw new std::runtime_error( "Unable to read the score." );
	}

	while ( !file.eof( )) {
		Note note;
		file >> note;

		_notes.push_back( note );
	}
}



/**
 *
 */

int Score::noteCount( ) const {

	return _notes.size( );
}



/**
 *
 */

const Note& Score::note( int index ) const {

	return _notes.at( index );
}
