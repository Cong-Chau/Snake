#pragma once
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<Windows.h>
using namespace std;

struct Coordinates {
	int x, y;
};

enum {
	RIGHT, LEFT, UP, DOWN
};

struct Snake {
	Coordinates point[100];
	int length;
	//trang thai
};



int Random(int min, int max);
void Map();
void PlayGame();