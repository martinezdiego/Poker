# La ruta de tu instalación de clang o g++
CXX = clang++ -std=c++14

FLAGS = -g -O2 -Wall

INCLUDE = -I.

default: main

main: 
	$(CXX) $(FLAGS) $(INCLUDE) $@.cpp -o $@  

clean:
	$(RM) *~ *.o main 
