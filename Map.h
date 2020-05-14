#pragma once
#include<iostream>
#include<string>
#include"PlayCharacter.h"

using namespace std;

class Map
{
public:
	Map();
	Map( char** , int , int );
	char** totalmap;
	bool** displaymap;
	int wide;
	int length;
	//displayrange
	int display_min_x;
	int display_max_x;
	int display_min_y;
	int display_max_y;
	//displayrange
	//character
	int initial_x = 0 ;
	int initial_y = 0;
	//character
	void Printmap( );
	void dealmap(int x, int y);
	void check_initial();
	void clearinitial();
	bool Move(int x, int y, string str,PlayCharacter& reg);
	void InitialMove(int x, int y, string str, PlayCharacter& reg);
};