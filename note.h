#ifndef __NOTE_H__
#define __NOTE_H__

#include <string>
#include <fstream>



/**
 *
 */

class Note {

	public:

		Note( );
		Note( const std::string& name, int duration );

	public:

		std::string name;
		int duration;

};



/**
 *
 */

std::ifstream& operator>>( std::ifstream &stream, Note &note );

#endif
