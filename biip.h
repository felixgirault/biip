#ifndef __BIIP_H__
#define __BIIP_H__

#include <map>
#include <string>

#include "note.h"
#include "score.h"



/**
 *
 */

class Biip {

	public:

		Biip( );
		~Biip( );

		void playNote( const Note& note );
		void playScore( const Score& score );

	private:

		void _loadFrequencies( );

	private:

#ifdef __linux__
		int _tty;
#endif
		std::map< std::string, float > _frequencies;

};

#endif
