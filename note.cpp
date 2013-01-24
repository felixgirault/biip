#include "note.h"



/**
 *
 */

Note::Note( ) :
	name( ),
	duration( 0 )
{ }



/**
 *
 */

Note::Note( const std::string& name, int duration ) :
	name( name ),
	duration( duration )
{ }



/**
 *
 */

std::ifstream& operator>>( std::ifstream &stream, Note &note ) {

	stream >> note.name;
	stream >> note.duration;

	return stream;
}
