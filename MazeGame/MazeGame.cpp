//Maze Game
//Rhyder Quinlan
//C00223030

#include "pch.h"
#include "Player.h"
#include "Grid.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
using namespace std;

#include <SFML/Graphics.hpp>
using namespace sf;

int main()
{
	Player player;
	Grid layout;
	layout.setGrid(20,20);
	int **grid = layout.getGrid();

	//SFML
	Window window(VideoMode(800, 600), "Maze Game");

	while (window.isOpen()) {
		Event event;
		while (window.pollEvent(event))
		{
			switch (event.type) {
				case Event::Closed:
					window.close();
					break;
				case Event::KeyPressed:
					if (event.key.code == Keyboard::Left)
						cout << "Move left" << endl;
						//player.move(-1, 0, grid);
					if (event.key.code == Keyboard::Right)
						cout << "Move right" << endl;
						//player.move(1, 0, grid);
					if (event.key.code == Keyboard::Up)
						cout << "Move up" << endl;
						//player.move(0, -1, grid);
					if (event.key.code == Keyboard::Down)
						cout << "Move down" << endl;
						//player.move(0, 1, grid);
					break;
				default:
					break;
			}
				
		}
	}
	return 0;
}