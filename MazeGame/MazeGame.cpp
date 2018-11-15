//Maze Game
//Rhyder Quinlan
//C00223030

#include "pch.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <SFML/Graphics.hpp>
using namespace std;



void print_array(int **grid, int rows, int columns) {
	for (int row = 0; row < rows; row++)
	{
		for (int column = 0; column < columns; column++)
		{
			cout << grid[row][column];
		}
		cout << endl;
	}
}

int main()
{
	//create array
	int rows = 20;
	int columns = 20;
	int **grid = new int*[rows];

	for (int row = 0; row < rows; row++)
	{
		grid[row] = new int[columns];
	}

	//read grid.txt
	ifstream gridfile("grid/grid.txt");
	string readline;
	int i = 0;
	if (gridfile.is_open())
	{
		while (getline(gridfile, readline))
		{
			for (int row = 0; row < rows; row++)
			{
				for (int column = 0; column < columns; column++)
				{
					grid[row][column] = readline.at(int(i));
					i++;
				}
			}
			cout << endl;
		}
		gridfile.close();
		print_array(grid, rows, columns);
	}
	else
	{
		cout << "Unable to open file";
	}
	i = 0;
	return 0;
}