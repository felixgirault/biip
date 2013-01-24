#include <stdexcept>
#ifdef __linux__
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/kd.h>
#elif defined _WIN32 || defined _WIN64
#include <windows.h>
#endif

#include "biip.h"



/**
 *
 */

Biip::Biip( ) {

	_loadFrequencies( );

#ifdef __linux__
	_tty = open( "/dev/tty10", O_WRONLY );

	if ( _tty == -1 ) {
		throw new std::runtime_error( "Unable to use the beeper." );
	}
#endif
}



/**
 *
 */

Biip::~Biip( ) {

#ifdef __linux__
	close( _tty );
#endif
}



/**
 *
 */

void Biip::playNote( const Note& note ) {

	if ( note.name == "S" ) {
		usleep( 1000 * note.duration );
	} else {
		float frequency = _frequencies[ note.name ];

#ifdef __linux__
		ioctl( _tty, KIOCSOUND, ( int )( 1193180 / frequency ));
		usleep( 1000 * note.duration );
		ioctl( _tty, KIOCSOUND, 0 );
#elif defined _WIN32 || defined _WIN64
		Beep( frequency, note.duration );
#endif
	}
}



/**
 *
 */

void Biip::playScore( const Score& score, int repeat ) {

	for ( int r = 0; r < repeat; ++r ) {
		for ( int i = 0; i < score.noteCount( ); ++i ) {
			playNote( score.note( i ));
		}
	}
}



/**
 *
 */

void Biip::_loadFrequencies( ) {

	_frequencies["S"] = 0;	// silence

	_frequencies["C2"] = 65.4064;
	_frequencies["C#2"] = 69.2957;
	_frequencies["Db2"] = _frequencies["C#2"];
	_frequencies["D2"] = 73.4162;
	_frequencies["D#2"] = 77.7817;
	_frequencies["Eb2"] = _frequencies["D#2"];
	_frequencies["E2"] = 82.4069;	// guitar low E
	_frequencies["F2"] = 87.3071;
	_frequencies["F#2"] = 92.4986;
	_frequencies["Gb2"] = _frequencies["F#2"];
	_frequencies["G2"] = 97.9989;
	_frequencies["G#2"] = 103.826;
	_frequencies["Ab2"] = _frequencies["G#2"];
	_frequencies["A2"] = 110.000;	// guitar A
	_frequencies["A#2"] = 116.541;
	_frequencies["Bb2"] = _frequencies["A#2"];
	_frequencies["B2"] = 123.471;

	_frequencies["C3"] = 130.813;
	_frequencies["C#3"] = 138.591;
	_frequencies["Db3"] = _frequencies["C#3"];
	_frequencies["D3"] = 146.832;	// guitar D
	_frequencies["D#3"] = 155.563;
	_frequencies["Eb3"] = _frequencies["D#3"];
	_frequencies["E3"] = 164.814;
	_frequencies["F3"] = 174.614;
	_frequencies["F#3"] = 184.997;
	_frequencies["Gb3"] = _frequencies["F#3"];
	_frequencies["G3"] = 195.998;	// guitar G
	_frequencies["G#3"] = 207.652;
	_frequencies["Ab3"] = _frequencies["G#3"];
	_frequencies["A3"] = 220.000;
	_frequencies["A#3"] = 233.082;
	_frequencies["Bb3"] = _frequencies["A#3"];
	_frequencies["B3"] = 246.942;	// guitar B

	_frequencies["C4"] = 261.626;
	_frequencies["C#4"] = 277.183;
	_frequencies["Db4"] = _frequencies["C#4"];
	_frequencies["D4"] = 293.665;
	_frequencies["D#4"] = 311.127;
	_frequencies["Eb4"] = _frequencies["D#4"];
	_frequencies["E4"] = 329.628;	// guitar high E
	_frequencies["F4"] = 349.228;
	_frequencies["F#4"] = 369.994;
	_frequencies["Gb4"] = _frequencies["F#4"];
	_frequencies["G4"] = 391.995;
	_frequencies["G#4"] = 415.305;
	_frequencies["Ab4"] = _frequencies["G#4"];
	_frequencies["A4"] = 440.000;
	_frequencies["A#4"] = 466.164;
	_frequencies["Bb4"] = _frequencies["A#4"];
	_frequencies["B4"] = 493.883;

	_frequencies["C5"] = 523.251;
	_frequencies["C#5"] = 554.365;
	_frequencies["Db5"] = _frequencies["C#5"];
	_frequencies["D5"] = 587.330;
	_frequencies["D#5"] = 622.254;
	_frequencies["Eb5"] = _frequencies["D#5"];
	_frequencies["E5"] = 659.255;
	_frequencies["F5"] = 698.456;
	_frequencies["F#5"] = 739.989;
	_frequencies["Gb5"] = _frequencies["F#5"];
	_frequencies["G5"] = 783.991;
	_frequencies["G#5"] = 830.609;
	_frequencies["Ab5"] = _frequencies["G#5"];
	_frequencies["A5"] = 880.000;
	_frequencies["A#5"] = 932.328;
	_frequencies["Bb5"] = _frequencies["A#5"];
	_frequencies["B5"] = 987.767;

	_frequencies["C6"] = 1046.50;
	_frequencies["C#6"] = 1108.73;
	_frequencies["Db6"] = _frequencies["C#6"];
	_frequencies["D6"] = 1174.66;
	_frequencies["D#6"] = 1244.51;
	_frequencies["Eb6"] = _frequencies["D#6"];
	_frequencies["E6"] = 1318.51;
	_frequencies["F6"] = 1396.91;
	_frequencies["F#6"] = 1479.98;
	_frequencies["Gb6"] = _frequencies["F#6"];
	_frequencies["G6"] = 1567.98;
	_frequencies["G#6"] = 1661.22;
	_frequencies["Ab6"] = _frequencies["G#6"];
	_frequencies["A6"] = 1760.00;
	_frequencies["A#6"] = 1864.66;
	_frequencies["Bb6"] = _frequencies["Bb6"];
	_frequencies["B6"] = 1975.53;
}
