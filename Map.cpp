#include "Map.h"

Map::Map()
{
};
Map::Map(char **reg , int _length, int _wide)
{
	length = _length;
	wide = _wide;
	totalmap = new char*[length];
	displaymap = new bool*[length];
	for (int count = 0; count < length; count++)
	{
		totalmap[count] = new char[wide];
		displaymap[count] = new bool[wide];
		for (int index = 0; index < wide; index++)
		{
			totalmap[count][index] = reg[count][index];
			displaymap[count][index] = false;
		}
	}

};

void Map::Printmap()
{
	for (int count = 0; count < length; count++)
	{
		for (int index = 0; index < wide; index++)
		{
			if (displaymap[count][index] == true)
			{
				std::cout << totalmap[count][index];
			}
			else
			{
				std::cout << ' ';
			}
		}
		std::cout << '\n';
	}


};

void Map::dealmap(int x, int y)
{

	if (totalmap[y][x] != '0' && displaymap[y][x] == false )
	{
		if (x > display_max_x)
			display_max_x = x;
		if (x < display_min_x)
			display_min_x = x;
		if (y > display_max_y)
			display_max_x = y;
		if (y < display_min_y)
			display_min_y = y;
		displaymap[y][x] = true ;
	}
	else
	{
		return;
	}

	if (y + 1 < length && totalmap[y][x] != '3' )
	{
		dealmap(x, y + 1);
	}

	if (y - 1 >= 0 && totalmap[y][x] != '3')
	{
		dealmap(x, y - 1);
	}

	if (x + 1 < wide && totalmap[y][x] != '3')
	{
		dealmap(x + 1, y);
	}

	if (x - 1 >= 0 && totalmap[y][x] != '3')
	{
		dealmap(x - 1, y);
	}

	return;
};
void Map::check_initial()
{

	initial_x = display_min_x;
	initial_y = display_min_y;
	for (int i = initial_y; i < length; i++)
	{
		for (int j = initial_x; j < wide; j++)
		{
			if ( totalmap[i][j] == '_' || totalmap[i][j] == '*')
			{
				totalmap[i][j] = '*';
				initial_x = j;
				initial_y = i;
				return;
			}
		}
	}

};

void Map::clearinitial()
{

	initial_x = display_min_x;
	initial_y = display_min_y;
	for (int i = initial_y; i < length; i++)
	{
		for (int j = initial_x; j < wide; j++)
		{
			if (totalmap[i][j] == '_' || totalmap[i][j] == '*')
			{
				totalmap[i][j] = '1';
			}
		}
	}
	return;
};

void Map::InitialMove( int x , int y , string str, PlayCharacter& reg)
{
	for (int count = 0; count < (int)str.length() ; count++ )
	{
		switch (str[count])
		{
			case 'w':
			{
				if (y - 1 >= 0 && ( totalmap[y-1][x] == '_' || totalmap[y - 1][x] == '*') )
				{
					y = y - 1;
				}
				break;
			}
			case 'a':
			{
				if (x - 1 >= 0 && (totalmap[y][x - 1] == '_' || totalmap[y][x - 1] == '*'))
				{
					x = x - 1;
				}
				break;
			}
			case 's':
			{
				if (y + 1 < length && (totalmap[y + 1][x] == '_' || totalmap[y + 1][x] == '*') )
				{
					y = y + 1;
				}
				break;
			}
			case 'd':
			{
				if (x + 1 < wide && (totalmap[y][x + 1] == '_' || totalmap[y][x + 1] == '*') )
				{
					x = x + 1;
				}
				break;
			}
			case 'e':
			{
				break;
			}
		}
	}
	reg.location.x = x;
	reg.location.y = y;
	return;
};
