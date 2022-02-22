#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <vector>
#include <iostream>
#include "Triangle.hpp"
#include <cmath>


using namespace sf;
using namespace std;

void fTree(float x, float y, float l, vector<Triangle>& v, int n)
{
			
	if(n > 0)
	{
		sf::VertexArray triangle(sf::LineStrip, 4);
		float height = sqrt(3.0)/2.0 * l;
		
	 	// define the position of the triangle's points
        	triangle[0].position = sf::Vector2f(x - (l/2.0), y - (height/3.0));
        	triangle[1].position = sf::Vector2f(x + (l/2.0) , y - (height/3.0));
        	triangle[2].position = sf::Vector2f(x, y + ((2.0/3.0) * height) );
        	triangle[3].position = triangle[0].position;
    
        	// define the color of the triangle's points
        	triangle[0].color = sf::Color::Red;
        	triangle[1].color = sf::Color::Blue;
        	triangle[2].color = sf::Color::Green;
        	triangle[3].color = sf::Color::Red;

 
		Triangle t;
		t.tri = triangle;
		v.push_back(t);
                
                double oax = x - (l/2.0);
                double oay = y - (2.0/3.0) * height;
                
		double obx = x + (3.0/4.0)*l;
		double oby = y - (1.0/6.0) * height;
		
		double ocx = x - (1.0/4.0) * l;
		double ocy = y + (5.0/6.0) * height;
		
		// recursive function calls
		fTree(oax, oay, l/2.0, v, n-1);
		fTree(obx, oby, l/2.0, v, n-1);
		fTree(ocx, ocy, l/2.0, v, n-1);
	}
	
		return;
}
