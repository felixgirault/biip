#include <fstream>
#include <stdexcept>

#include "score.h"



/**
 *
 */

Score::Score( const std::string& fileName ) {

	_load( fileName );
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



/**
 *	UGLY
 */

void Score::_load( std::string fileName ) {

	std::ifstream file( fileName.c_str( ));

	if ( !file ) {
		throw new std::runtime_error( "Unable to read the tab." );
	}

	int unit;
	std::string noteName;
	std::string line;
	std::vector< std::string > notesName;

	file >> unit;

	do {
		file >> noteName;
		file >> line;

		if ( notesName.empty( )) {
			notesName.resize( line.length( ), "S" );
		}

		for ( unsigned int i = 0; i < line.length( ); ++i ) {
			if ( line[ i ] == 'o' ) {
				notesName[ i ] = noteName;
			}
		}
	} while ( !file.eof( ));

	std::string previousNoteName = notesName.front( );
	Note note( previousNoteName, 0 );

	for ( unsigned int i = 1; i < notesName.size( ); ++i ) {
		noteName = notesName.at( i );
		note.duration += unit;

		if ( noteName != previousNoteName ) {
			_notes.push_back( note );

			note.name = noteName;
			note.duration = 0;
		}

		previousNoteName = noteName;
	}

	if ( noteName != previousNoteName ) {
		_notes.push_back( note );

		note.name = noteName;
		note.duration = 0;
	}

	note.duration += unit;
	_notes.push_back( note );
}
