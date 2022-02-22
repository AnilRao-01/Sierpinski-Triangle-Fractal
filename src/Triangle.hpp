#ifndef Recursive_Tree
#define Recursive_Tree

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <vector>
#include <iostream>

using namespace sf;
using namespace std;

class Triangle 
{
public:
	sf::VertexArray tri;
};

void fTree(float x, float y, float l, vector<Triangle>& v, int n);

#endif
