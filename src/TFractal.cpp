#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <cmath>
#include <vector>
#include <iostream>
#include "Triangle.hpp"
#include <thread>


using namespace std;
using namespace sf;
using namespace std::literals::chrono_literals;

int main (int argc, char *argv[])
{
	RenderWindow window(sf::VideoMode(1000,1000), "");
	
	float l = stod(argv[1]);
	
	int z = stoi(argv[2]); //recursion depth
	
	float x = window.getSize().x/2.0;
	float y = window.getSize().y/2.0;
	
	vector<Triangle> shapes;

	int n = 1;
        while (window.isOpen())
        {
		if(n > z)
		{	
			n = 1;
		}
			
		fTree(x,y,l,shapes, n);
		n++;
                sf::Event event;
                while (window.pollEvent(event))
                {
                        if (event.type == sf::Event::Closed)
                                window.close();
                }
  
                window.clear();
       
		for(auto x = shapes.begin(); x != shapes.end(); x++)
		{
			window.draw((*x).tri);
		}

		window.display();
		while(!shapes.empty())
		{
			shapes.pop_back();
		
		}
		std::this_thread::sleep_for(1s); //sleep for 1 second between iterations
        }

	return 0;

}
