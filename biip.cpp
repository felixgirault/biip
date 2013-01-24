#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>

#ifdef __linux__
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/kd.h>
#elif defined _WIN32 || defined _WIN64
#include <windows.h>
#endif



/**
 *
 */

struct Note {
	
	Note( float frequency, int duration ) :
		frequency( frequency ),
		duration( duration )
	{ }

	float frequency;
	int duration;
};



/**
 *
 */

int main( int argc, char* argv[ ]) {

	if ( argc < 2 ) {
		std::cerr << "You must pass a melody file." << std::endl;
		return 1;
	}

	std::map< std::string, float > frequencies;

	frequencies["S"] = 0;

	frequencies["C2"] = 65.4064;
	frequencies["C#2"] = 69.2957;
	frequencies["Db2"] = 69.2957;
	frequencies["D2"] = 73.4162;
	frequencies["D#2"] = 77.7817;
	frequencies["Eb2"] = 77.7817;
	frequencies["E2"] = 82.4069;	// guitar low E
	frequencies["F2"] = 87.3071;
	frequencies["F#2"] = 92.4986;
	frequencies["Gb2"] = 92.4986;
	frequencies["G2"] = 97.9989;
	frequencies["G#2"] = 103.826;
	frequencies["Ab2"] = 103.826;
	frequencies["A2"] = 110.000;	// guitar A
	frequencies["A#2"] = 116.541;
	frequencies["Bb2"] = 116.541;
	frequencies["B2"] = 123.471;

	frequencies["C3"] = 130.813;
	frequencies["C#3"] = 138.591;
	frequencies["Db3"] = 138.591;
	frequencies["D3"] = 146.832;	// guitar D
	frequencies["D#3"] = 155.563;
	frequencies["Eb3"] = 155.563;
	frequencies["E3"] = 164.814;
	frequencies["F3"] = 174.614;
	frequencies["F#3"] = 184.997;
	frequencies["Gb3"] = 184.997;
	frequencies["G3"] = 195.998;	// guitar G
	frequencies["G#3"] = 207.652;
	frequencies["Ab3"] = 207.652;
	frequencies["A3"] = 220.000;
	frequencies["A#3"] = 233.082;
	frequencies["Bb3"] = 233.082;
	frequencies["B3"] = 246.942;	// guitar B

	frequencies["C4"] = 261.626;
	frequencies["C#4"] = 277.183;
	frequencies["Db4"] = 277.183;
	frequencies["D4"] = 293.665;
	frequencies["D#4"] = 311.127;
	frequencies["Eb4"] = 311.127;
	frequencies["E4"] = 329.628;	// guitar high E
	frequencies["F4"] = 349.228;
	frequencies["F#4"] = 369.994;
	frequencies["Gb4"] = 369.994;
	frequencies["G4"] = 391.995;
	frequencies["G#4"] = 415.305;
	frequencies["Ab4"] = 415.305;
	frequencies["A4"] = 440.000;
	frequencies["A#4"] = 466.164;
	frequencies["Bb4"] = 466.164;
	frequencies["B4"] = 493.883;

	frequencies["C5"] = 523.251;
	frequencies["C#5"] = 554.365;
	frequencies["Db5"] = 554.365;
	frequencies["D5"] = 587.330;
	frequencies["D#5"] = 622.254;
	frequencies["Eb5"] = 622.254;
	frequencies["E5"] = 659.255;
	frequencies["F5"] = 698.456;
	frequencies["F#5"] = 739.989;
	frequencies["Gb5"] = 739.989;
	frequencies["G5"] = 783.991;
	frequencies["G#5"] = 830.609;
	frequencies["Ab5"] = 830.609;
	frequencies["A5"] = 880.000;
	frequencies["A#5"] = 932.328;
	frequencies["Bb5"] = 932.328;
	frequencies["B5"] = 987.767;

	frequencies["C6"] = 1046.50;
	frequencies["C#6"] = 1108.73;
	frequencies["Db6"] = 1108.73;
	frequencies["D6"] = 1174.66;
	frequencies["D#6"] = 1244.51;
	frequencies["Eb6"] = 1244.51;
	frequencies["E6"] = 1318.51;
	frequencies["F6"] = 1396.91;
	frequencies["F#6"] = 1479.98;
	frequencies["Gb6"] = 1479.98;
	frequencies["G6"] = 1567.98;
	frequencies["G#6"] = 1661.22;
	frequencies["Ab6"] = 1661.22;
	frequencies["A6"] = 1760.00;
	frequencies["A#6"] = 1864.66;
	frequencies["Bb6"] = 1864.66;
	frequencies["B6"] = 1975.53;

	std::ifstream melody( argv[ 1 ]);

	if ( !melody ) {
		std::cerr << "Unable to open the melody file." << std::endl;
		return 1;
	}

	std::vector< Note > notes;
	std::string name;
	int duration;

	while ( !melody.eof( )) {
		melody >> name;
		melody >> duration;

		notes.push_back( Note( frequencies[ name ], duration ));
	}

#ifdef __linux__
	int tty = open( "/dev/tty10", O_WRONLY );

	if ( tty == -1 ) {
		std::cerr << "Unable to use the beeper." << std::endl;
		return 1;
	}
#endif

	for ( int i = 0; i < notes.size( ); ++i ) {
		Note note = notes.at( i );

		if ( note.frequency < 1 ) {
			usleep( 1000 * note.duration );
		} else {
#ifdef __linux__
			//std::cout << frequency << ' ' << duration << std::endl;
			ioctl( tty, KIOCSOUND, ( int )( 1193180 / note.frequency ));
			usleep( 1000 * note.duration );
			ioctl( tty, KIOCSOUND, 0 );
#elif defined _WIN32 || defined _WIN64
			Beep( Note.frequency, note.duration );
#endif
		}
		
		std::cout << note.frequency << ' ' << note.duration << std::endl;
	}

#ifdef __linux__
	close( tty );
#endif

	return 0;
}

