CC = g++ 
CFLAGS = -std=c++17 -c -g -Og -Wall -pedantic
OBJ = TFractal.o Triangle.o
DEPS = TFractal.cpp  Triangle.cpp  Triangle.hpp 
LIBS = -lsfml-system -lsfml-audio -lsfml-graphics -lsfml-window  
EXE = Tree

all: $(OBJ)
	$(CC) $(OBJ) -o $(EXE) $(LIBS)

%.o: %.cpp %.hpp
	$(CC) $(CFLAGS) -c $< -o $@

%.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm $(OBJ) $(EXE)

