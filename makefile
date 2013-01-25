CC=g++
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=main.cpp note.cpp score.cpp speaker.cpp biip.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=biip

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@
