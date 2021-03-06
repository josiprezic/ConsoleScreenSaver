#include "stdafx.h"
#include <iostream>
#include <fstream>
#include<conio.h>
#include <ctime>
#include<random>
#include<windows.h>
using namespace std;

int numberOfRows = 20;
int numberOfColumns = 100;

void allocation(char **&matrix)
{
	matrix = new char *[numberOfRows];
	for (int i = 0; i < numberOfRows; i++)
	{
		matrix[i] = new char[numberOfColumns];
	}
}

void deallocation(char **&matrix)
{
	for (int i = 0; i < numberOfRows; i++)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
	matrix = nullptr;
}

void show(char **matrix)
{
	system("cls");
	cout << endl << "+";
	for (int i = 0; i < numberOfColumns; i++)
	{
		cout << "-";
	}
	cout << "+" << endl;
	for (int i = 0; i < numberOfRows; i++)
	{
		cout << "|";
		for (int j = 0; j < numberOfColumns; j++)
		{
			cout << matrix[i][j];
		}
		cout << "|";
		cout << endl;
	}
	cout << "+";
	for (int i = 0; i < numberOfColumns; i++)
	{
		cout << "-";
	}
	cout << "+";
	cout << endl;
}

void clean(char **matrix)
{
	for (int i = 0; i < numberOfRows; i++)
	{
		for (int j = 0; j < numberOfColumns; j++)
		{
			matrix[i][j] = ' ';
		}
	}
}

bool fellOnTheGround(char **matrix, int row, int column)
{
	if (row == numberOfRows - 1)
	{
		return true;
	}
	if (matrix[row + 1][column] == '*');
	{
		return false;
	}
	return false;
}

void createSnowflake(char **matrix, int location)
{
	matrix[0][location] = '*';
}

void dropSnowflakes(char **matrix)
{
	bool isFellOnTheGraund;
	for (int i = 0; i < numberOfRows; i++)
	{
		for (int j = 0; j < numberOfColumns; j++)
		{
			isFellOnTheGraund = fellOnTheGround(matrix, i, j);  
			if (matrix[i][j] == '*' && i != numberOfRows - 1 && matrix[i + 1][j] == ' ')
			{
				matrix[i][j] = ' ';
				if (i != numberOfRows - 1)
					matrix[i + 1][j] = '?';
			}
		}
	}
	for (int i = 0; i < numberOfRows; i++)
	{
		for (int j = 0; j < numberOfColumns; j++)
		{
			if (matrix[i][j] == '?')
			{
				matrix[i][j] = '*';
			}
		}
	}
}

bool willTheSnowflakeFall()
{
	int myRandom = rand();
	if (myRandom % 15 == 0)
	{
		return true;
	}
	return false;
}

void tooMuchSnow(char **matrix)
{
	int counter = 0;
	for (int i = 0; i < numberOfRows; i++)
	{
		for (int j = 0; j < numberOfColumns; j++)
		{
			if (matrix[i][j] == ' ')
			{
				counter++;
			}
		}
	}
	if (counter<350)
	{
		clean(matrix);
	}
}

void buildTheHouse(char **matrix)
{
	for (int i = numberOfRows / 2 + 5; i < numberOfRows; i++)
	{
		for (int j = numberOfColumns / 2 + 20; j < numberOfColumns / 2 + 10 + 20; j++)
		{
			if (i == numberOfRows / 2 + 5 || i == numberOfRows - 1 || j == numberOfColumns / 2 + 20 || j == numberOfColumns / 2 + 9 + 20)
			{
				matrix[i][j] = '#';
			}
			else
				matrix[i][j] = ' ';
		}
	}
	matrix[numberOfRows / 2 + 4][numberOfColumns / 2 + 21] = '#';
	matrix[numberOfRows / 2 + 4][numberOfColumns / 2 + 28] = '#';
	matrix[numberOfRows / 2 + 3][numberOfColumns / 2 + 22] = '#';
	matrix[numberOfRows / 2 + 3][numberOfColumns / 2 + 27] = '#';
	matrix[numberOfRows / 2 + 2][numberOfColumns / 2 + 23] = '#';
	matrix[numberOfRows / 2 + 2][numberOfColumns / 2 + 26] = '#';
	matrix[numberOfRows / 2 + 1][numberOfColumns / 2 + 25] = '#';
	matrix[numberOfRows / 2 + 1][numberOfColumns / 2 + 24] = '#';
	matrix[numberOfRows / 2 + 8][numberOfColumns / 2 + 24] = '#';
	matrix[numberOfRows / 2 + 7][numberOfColumns / 2 + 24] = '#';
	matrix[numberOfRows / 2 + 7][numberOfColumns / 2 + 23] = '#';
	matrix[numberOfRows / 2 + 8][numberOfColumns / 2 + 23] = '#';

}

void destroyTheHouse(char **matrix)
{
	for (int i = numberOfRows / 2 + 5; i < numberOfRows; i++)
	{
		for (int j = numberOfColumns / 2 + 20; j < numberOfColumns / 2 + 10 + 20; j++)
		{
			if (i == numberOfRows / 2 + 5 || i == numberOfRows - 1 || j == numberOfColumns / 2 + 20 || j == numberOfColumns / 2 + 9 + 20)
			{
				matrix[i][j] = ' ';
			}
			else
				matrix[i][j] = ' ';
		}
	}
	matrix[numberOfRows / 2 + 4][numberOfColumns / 2 + 21] = ' ';
	matrix[numberOfRows / 2 + 4][numberOfColumns / 2 + 28] = ' ';
	matrix[numberOfRows / 2 + 3][numberOfColumns / 2 + 22] = ' ';
	matrix[numberOfRows / 2 + 3][numberOfColumns / 2 + 27] = ' ';
	matrix[numberOfRows / 2 + 2][numberOfColumns / 2 + 23] = ' ';
	matrix[numberOfRows / 2 + 2][numberOfColumns / 2 + 26] = ' ';
	matrix[numberOfRows / 2 + 1][numberOfColumns / 2 + 25] = ' ';
	matrix[numberOfRows / 2 + 1][numberOfColumns / 2 + 24] = ' ';
	matrix[numberOfRows / 2 + 8][numberOfColumns / 2 + 24] = ' ';
	matrix[numberOfRows / 2 + 7][numberOfColumns / 2 + 24] = ' ';
	matrix[numberOfRows / 2 + 7][numberOfColumns / 2 + 23] = ' ';
	matrix[numberOfRows / 2 + 8][numberOfColumns / 2 + 23] = ' ';

}

void changeTemperature(char **matrix, int temperature)
{
	int destroy;
	int number = 1001 - temperature;
	for (int i = 0; i < numberOfRows; i++)
	{
		for (int j = 0; j < numberOfColumns; j++)
		{
			if (matrix[i][j] != ' ' && matrix[i][j] != '#')
			{
				destroy = rand() % number;
				if (destroy == 0)
				{
					matrix[i][j] = ' ';
				}
			}
		}
	}
}

void printTime()
{
	time_t timeSec = time(0);
	long hour, min;
	timeSec = timeSec % 86400;
	hour = timeSec / 3600;
	timeSec = timeSec % 3600;
	min = timeSec / 60;
	timeSec = timeSec % 60;
	cout << endl << endl << "\t\t\t\t\tCURRENT TIME: " << hour + 2 << " : " << min << " : " << timeSec << endl;
}

void changeSnowflakesToLetters(char **matrix)
{
	int random;
	char letter;
	for (int i = 0; i < numberOfRows; i++)
	{
		for (int j = 0; j < numberOfColumns; j++)
		{
			if (matrix[i][j] == '*')
			{
				random = rand() % 25 + 65;
				letter = char(random);
				matrix[i][j] = letter;
			}
		}
	}
}

void main() {
	bool house = true;
	bool magic = false;
	int temperature = 0;
	char command;

	srand(time(NULL));
	int randomNumber;
	char **matrix;
	allocation(matrix);
	clean(matrix);
	show(matrix);
	buildTheHouse(matrix);
	temperature = 750;
	do
	{
		if (house)
			buildTheHouse(matrix);
		for (int i = 0; i < numberOfColumns; i++)
		{
			if (willTheSnowflakeFall())
			{
				randomNumber = rand() % numberOfColumns;
				createSnowflake(matrix, randomNumber);
			}
		}
		dropSnowflakes(matrix);
		show(matrix);
		time_t vrijeme;
		time(&vrijeme);
		tooMuchSnow(matrix);

		if (_kbhit())
		{
			command = _getch();
			if (command == '2')
				temperature += 10;
			if (command == '1')
				temperature -= 10;
			if (temperature>998)
				temperature = 998;
			if (temperature<0)
				temperature = 0;
			if (command == '3')
			{
				if (house)
				{
					house = false;
					destroyTheHouse(matrix);
				}
				else
				{
					house = true;
					buildTheHouse(matrix);
				}
			}
			if (command == '4')
			{
				clean(matrix);
			}
			else if (command == '5')

			{
				if (!magic)
				{
					magic = true;
					changeSnowflakesToLetters(matrix);
				}
				else if (magic)
				{
					magic = false;
				}
			}
		}
		changeTemperature(matrix, temperature);
		cout << "TEMPERATURE(1,2): " << ((float)temperature / 100) - 9 << " C" << "  BUILD/DESTROY HOUSE(3)   CLEAN THE SNOW(4)   CHANGE SNOWFLAKES TO LETTERS(5)";
		printTime();
		Sleep(30);


	} while (1);


	deallocation(matrix);
	system("pause>0");
}