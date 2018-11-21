//Maze Game
//Rhyder Quinlan
//C00223030

#include "pch.h"
#include "Player.h"
#include "Enemy.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <iterator>
#include <fstream>
using namespace std;

#include <SFML/Graphics.hpp>
using namespace sf;

int **grid;
int rows, columns;

void setGrid() {
	rows = 20;
	columns = 20;
	grid = new int*[rows];

	for (int row = 0; row < rows; row++)
	{
		grid[row] = new int[columns];
	}

	ifstream gridfile("grid/grid.txt");
	string readline;

	if (gridfile.is_open())
	{
		int i = 0;
		while (getline(gridfile, readline))
		{

			for (int row = 0; row < rows; row++)
			{
				for (int column = 0; column < columns; column++)
				{
					grid[row][column] = (readline.at(int(i)) - 48);
					i++;
				}
			}
			cout << endl;
		}
		i = 0;
		gridfile.close();
	}
	else
	{
		cout << "Unable to open file";
	}
}

void print_array(int **g) {
	for (int x = 0; x < 20; x++)
	{
		for (int y = 0; y < 20; y++)
		{
			cout << g[x][y];
		}
		cout << endl;
	}
}

class Tilemap : public Drawable, public Transformable
{

public:

	bool generate(const std::string tileset, sf::Vector2u tileSize, int** tiles, unsigned int width, unsigned int height)
	{
		if (!m_tileset.loadFromFile(tileset))
			return false;

		m_vertices.setPrimitiveType(sf::Quads);
		m_vertices.resize(width * height * 4);

		for (unsigned int i = 0; i < width; ++i)
			for (unsigned int j = 0; j < height; ++j)
			{
				int tileNumber = tiles[j][i];

				int tu = tileNumber % (m_tileset.getSize().x / tileSize.x);
				int tv = tileNumber / (m_tileset.getSize().x / tileSize.x);

				sf::Vertex* quad = &m_vertices[(i + j * width) * 4];

				quad[0].position = sf::Vector2f(i * tileSize.x, j * tileSize.y);
				quad[1].position = sf::Vector2f((i + 1) * tileSize.x, j * tileSize.y);
				quad[2].position = sf::Vector2f((i + 1) * tileSize.x, (j + 1) * tileSize.y);
				quad[3].position = sf::Vector2f(i * tileSize.x, (j + 1) * tileSize.y);

				quad[0].texCoords = sf::Vector2f(tu * tileSize.x, tv * tileSize.y);
				quad[1].texCoords = sf::Vector2f((tu + 1) * tileSize.x, tv * tileSize.y);
				quad[2].texCoords = sf::Vector2f((tu + 1) * tileSize.x, (tv + 1) * tileSize.y);
				quad[3].texCoords = sf::Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);
			}

		return true;
	}

private:

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		states.transform *= getTransform();
		states.texture = &m_tileset;
		target.draw(m_vertices, states);
	}

	sf::VertexArray m_vertices;
	sf::Texture m_tileset;
};

int main()
{
	setGrid();
	Player player;
	Enemy enemy;
	Tilemap map;

	grid = player.setPosition(grid);
	grid = enemy.setPosition(grid);

	RenderWindow window(VideoMode(800,700), "Maze Game");
	window.setKeyRepeatEnabled(false);

	Clock gameclock;
	Time looptime = gameclock.getElapsedTime();
	while (window.isOpen()) {
		Event event;
		while (window.pollEvent(event))
		{
			Time elapsed = gameclock.getElapsedTime() - looptime;
			//close command
			if (event.type == Event::Closed)
				window.close();

			//player movement
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			{
				cout << "Move left" << endl;
				grid = player.move(0, -1, grid);
				print_array(grid);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			{
				cout << "Move right" << endl;
				grid = player.move(0, 1, grid);
				print_array(grid);
			} 
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			{
				cout << "Move up" << endl;
				grid = player.move(-1, 0, grid);
				print_array(grid);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			{
				cout << "Move down" << endl;
				grid = player.move(1, 0, grid);
				print_array(grid);
			}
			if (Keyboard::isKeyPressed(Keyboard::T))
			{
				cout << "Time elapsed: " << elapsed.asMicroseconds() << endl;
			}

			//enemy movement
			if (Keyboard::isKeyPressed(Keyboard::E))
			{
				grid = enemy.move(grid);
				print_array(grid);
			}


		}

		if (!map.generate("tileset.png", sf::Vector2u(32, 32), grid, 20, 20))
			return -1;
		window.clear();
		window.draw(map);
		window.display();
	}
	return 0;
}

//