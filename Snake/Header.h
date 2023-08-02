#pragma once
#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
struct Coordinates {
	int x, y;
};
int Random(int min, int max);
void Map();
void PlayGame();