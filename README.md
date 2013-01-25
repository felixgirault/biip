Biip
====

Usage
-----

```
make

./biip FILE [repetitions]

./biip scores/win.txt
./biip scores/all.txt
./biip scores/tron.txt 4
```

### Linux

You should edit the modprobe blacklist (/etc/modprobe.d/blacklist.conf) in order to have your motherboard speaker working.
Just comment out this line: `blacklist pcspkr`.

Then, run biip as root.

### Windows

Not tested yet, but should work !

Scores
------

A biip score looks like that:

```
100

C4	1
C#4	1
D4	1
D#4	1
E4	1
F4	1
F#4	1
G4	1
G#4	1
A4	1
A#4	1
B4	1
C5	4
```

The first line sets the base unit of time in milliseconds.
Then, each line represents a single note, identified by it's name and duration (multiple of base time unit).

In the above example, biip would play each note of the 4th octave for 100ms, and a C of the 5th octave for 400ms.

### Notes

A note is identified by it's name and octave.
You can use any of these standard notes : `A`, `A#`/`Bb`, `B`, `C`, `C#`/`Db`, `D`, `D#`/`Eb`, `E`, `F`, `F#`/`Gb`, `G` and `G#`/`Ab`.
The available octaves go from 2 to 6.

There is also a `S` note (without octave), which is basically a silence.
