#include "pch.h"
#include "Grid.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
using namespace std;

int **grid;
int rows, columns;

void Grid::setGrid(int r, int c) {
	rows = r;
	columns = c;
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

int** Grid::getGrid() {
	print_array();
	return grid;
}

void Grid::print_array() {
	for (int y = 0; y < rows; y++)
	{
		for (int x = 0; x < columns; x++)
		{
			cout << grid[x][y];
		}
		cout << endl;
	}
}

Grid::Grid() {
}
Grid::~Grid()
{
}


