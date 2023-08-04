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
void gotoxy(int x, int y);
void initSnake(Snake& snake);
bool checkCOOR_Fr_Sn(Snake snake, Coordinates fruit);
void initFruit(Coordinates& fruit);
void Map(int score);
bool checkLose(Snake snake);
void Move(Snake& snake, Coordinates& fruit, int& score);
void PlayGame();