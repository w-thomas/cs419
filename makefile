#makefile for CMD1

CXX = g++
CXXFLAGS = -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g

OBJS = fandango.o  
SRCS = fandango.cpp 
#HEADERS = fandango.h  

fandango: ${OBJS} ${HEADERS}
	${CXX} ${CXXFLAGS} ${OBJS} -o fandango

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

