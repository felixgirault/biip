#ifndef __SCORE_H__
#define __SCORE_H__

#include <string>
#include <vector>

#include "note.h"



/**
 *
 */

class Score {

	public:

		Score( const std::string& file );

		int noteCount( ) const;
		const Note& note( int index ) const;

	private:

		std::vector< Note > _notes;

};

#endif
