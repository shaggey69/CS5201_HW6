# Makefile that will prdouce the executable for the forth Prgram!
# By: Ari Sherman
# Class: CS5201 HW #5
# Date: 4.4.18

CXX = /usr/bin/g++
CXXFLAGS = -g -Wpedantic -Wall -Wextra -Wfloat-conversion -Werror -std=c++11

OBJECTS =  main.o


.SUFFIXES: .cpp

.cpp.o: $<
	${CXX} -c ${CXXFLAGS} $< -o $@

default: all

all: driver

driver: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o $@

clean:
	-@rm -f core > /dev/null 2>&1
	-@rm -f driver > /dev/null 2>&1
	-@rm -f ${OBJECTS} > /dev/null 2>&1

# The Dependency lists!
main.o:	bandedMatrix.h matrix.h myArray.h deepdec.h diagMatrix.h symMatrix.h
