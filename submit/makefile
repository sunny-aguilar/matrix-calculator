# File: 	makefile
# Author: 	Sandro Aguilar
# Date: 	January 2019
# Description:	Makefile for Lab 1 Matrix Calculator

# Variables to control Makefile operation

CXX = g++
CXXFLAGS = -Wall
CXXFLAGS += -g
CXXFLAGS += -std=c++0x
OBJECTS = main.o readMatrix.o determinant.o

# Targets needed to bring the executable up to date

calc: $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o calc main.o readMatrix.o determinant.o

main.o: main.cpp readMatrix.hpp determinant.hpp
	$(CXX) $(CXXFLAGS) -c main.cpp

readMatrix.o: readMatrix.hpp

determinant.o: determinant.hpp

# Clean up operations
clean:
	rm calc *.o

debug:
	valgrind -v --leak-check=full --show-leak-kinds=all --track-origins=yes ./Ant

zip :
	zip -D matrix-calculator.zip $(CPPs) $(HPPs) $(TXTS) makefile *.txt *.pdf