#makefile for CMD1

all: fandango

CXX = g++
CXXFLAGS = -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g

OBJS = fandango.o rooms.o player.o item.o interface.o
SRCS = fandango.cpp rooms.cpp player.cpp item.cpp interface.cpp
HEADERS = rooms.hpp player.hpp interface.hpp

fandango: ${OBJS} ${HEADERS}
	${CXX} ${CXXFLAGS} ${OBJS} -o fandango

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

