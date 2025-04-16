# this is the makefile I made to compile my program
# makes both versions of the program using one make

CC = gcc
CXX = g++

# Flags
CFLAGS = -std=c99 -Wall
CXXFLAGS = -std=c++11 -Wall


all: matrix_cppver matrix_cver

# cpp version
matrix_cppver: main_cpp.o Matrix_cppversion.o
	$(CXX) $(CXXFLAGS) -o matrix_cppver main_cpp.o Matrix_cppversion.o

main_cpp.o: main.cpp Matrix.h
	$(CXX) $(CXXFLAGS) -c main.cpp -o main_cpp.o

Matrix_cppversion.o: Matrix_cppversion.cpp Matrix.h
	$(CXX) $(CXXFLAGS) -c Matrix_cppversion.cpp -o Matrix_cppversion.o

# c version
matrix_cver: main_c.o matrix_cversion.o
	$(CC) $(CFLAGS) -o matrix_cver main_c.o matrix_cversion.o

main_c.o: main.c matrix_cversion.h
	$(CC) $(CFLAGS) -c main.c -o main_c.o

matrix_cversion.o: matrix_cversion.c matrix_cversion.h
	$(CC) $(CFLAGS) -c matrix_cversion.c -o matrix_cversion.o

# to clean files
clean:
	rm -f *.o matrix_cppver matrix_cver
