#makefile for CMD1

all: fandango

CXX = g++
CXXFLAGS = -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g

<<<<<<< HEAD
OBJS = fandango.o rooms.o player.o item.o interface.o
SRCS = fandango.cpp rooms.cpp player.cpp item.cpp interface.cpp
=======
OBJS = fandango.o rooms.o player.o item.o feature.o
SRCS = fandango.cpp rooms.cpp player.cpp item.cpp feature.cpp
>>>>>>> master
HEADERS = rooms.hpp player.hpp

fandango: ${OBJS} ${HEADERS}
	${CXX} ${CXXFLAGS} ${OBJS} -o fandango -lncurses

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp) -lncurses

