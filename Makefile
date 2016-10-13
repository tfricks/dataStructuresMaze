# Makefile for Bag program driver - Jeff Braun

#Macros to specify compiler, compiler/linking flags, target file
DIR = `basename pwd`
C++  = g++
CFLAGS = -std=c++11 -Wall -Werror
LD = g++
LDFLAGS = 
LIBS = 
OBJS = MazeDriver.o Maze.o Creature.o
EXEC = Driver

#Rules to create target file Driver
# If any files on line with colon are modified, then recompile the object file
all:		$(EXEC)

$(EXEC):	$(OBJS)
		$(LD) $(LDFLAGS) -o $(EXEC) $(OBJS) $(LIBS)

Maze.o: Maze.cpp Maze.h
		$(C++) $(CFLAGS) -c Maze.cpp
    
Creature.o: Creature.cpp Creature.h
		$(C++) $(CFLAGS) -c Creature.cpp

MazeDriver.o:	MazeDriver.cpp Creature.cpp Maze.cpp Creature.h Maze.h 
		$(C++) $(CFLAGS) -c MazeDriver.cpp

clean:
		rm -f $(OBJS) $(EXEC) 

submit:
		rm -f $(OBJS) $(EXEC) 
		tar cvzf ../`whoami`5.tgz ../$(shell basename $(CURDIR))/*
		mail -a ../`whoami`5.tgz -s Program5 jbraun@mtech.edu < /dev/null
