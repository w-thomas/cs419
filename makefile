#makefile for CMD1

all: fandango rooms

CXX = g++
CXXFLAGS = -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g

OBJS = fandango.o rooms.o 
SRCS = fandango.cpp rooms.cpp
HEADERS = rooms.hpp  

rooms: ${OBJS} ${HEADERS}
	${CXX} ${CXXFLAGS} ${OBJS} -o rooms

fandango: ${OBJS} ${HEADERS}
	${CXX} ${CXXFLAGS} ${OBJS} -o fandango

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

