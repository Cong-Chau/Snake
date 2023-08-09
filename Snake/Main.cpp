#pragma once
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<Windows.h>
#include<conio.h>
#define TIMEOUT 1
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


int wight = 40;
int heigth = 20;
int speed = 100;

int Random(int min, int max) {
	srand(time(NULL));
	int r = rand();
	int ran = min + r % max;
	return ran;
}
void gotoxy(int x, int y) {
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD a = { x, y };    SetConsoleCursorPosition(h, a);
}

//Khoi tao vi tri dau ran
void initSnake(Snake& snake) {
	snake.length = 1;
	int x = 4, y = (heigth / 2) - 1;
	for (int i = 0; i < snake.length; i++, x--) {
		snake.point[i].x = x;
		snake.point[i].y = y;
		gotoxy(x, y);
		cout << "x";
	}
}

bool checkCOOR_Fr_Sn(Snake snake, Coordinates fruit) {
	for (int i = 0; i < snake.length; i++) {
		if (fruit.x == snake.point[i].x && fruit.y == snake.point[i].y) {
			return false;
		}
	}
	return true;
}
void initFruit(Snake snake, Coordinates& fruit) {
	fruit.x = Random(1, 18);
	fruit.y = Random(1, 8);
	while (!checkCOOR_Fr_Sn(snake, fruit)) {
		fruit.x = Random(1, 18);
		fruit.y = Random(1, 8);
	}
}

void Map(int score) {
	system("cls");
	//Hien thi
	for (int i = 0; i < wight; i++) {
		for (int j = 0; j < heigth; j++) {
			if (i == 0 || i == wight - 1) {
				gotoxy(i, j);
				cout << "#";
				continue;
			}
			if (j == 0 || j == heigth - 1) {
				gotoxy(i, j);
				cout << "#";
				continue;
			}
		}
	}
	cout << "\nSCORE: " << score << endl;
}

bool checkLose(Snake snake) {
	if (snake.point[0].x == 0 || snake.point[0].x == wight - 1)
		return true;
	if (snake.point[0].y == 0 || snake.point[0].y == heigth - 1)
		return true;
	//Chua the text
	for (int i = 1; i < snake.length; i++) {
		if (snake.point[0].x == snake.point[i].x && snake.point[0].y == snake.point[i].y)
			return true;
	}
	//--------------
	return false;
}

int checkTime() {
	clock_t tstart = clock();
	int v1 = ' ';                   // default key press
	while ((clock() - tstart) / /**/ CLOCKS_PER_SEC < TIMEOUT) {/**/  //chinh lai minisecond
		if (_kbhit()) {
			v1 = _getch();
			break;
		}
	}
	return v1;
}

void Move(Snake& snake, Coordinates& fruit, int& score) {
	Coordinates speeds;
	speeds.x = 1;
	speeds.y = 0;
	while (1) {
		if (checkLose(snake)) {
			system("cls");
			gotoxy((wight / 2) - 7, heigth / 2);
			cout << " GAME OVER!!!\n";
			gotoxy((wight / 2) - 4, heigth / 2 + 1);
			cout << "Score: " << score;
			return;
		}

		system("cls");
		Map(score);
		gotoxy(fruit.x, fruit.y);
		cout << "o";
		for (int i = 0; i < snake.length; i++) {
			gotoxy(snake.point[i].x, snake.point[i].y);
			cout << "x";
		}

		Coordinates vector;
		vector.x = snake.point[0].x;
		vector.y = snake.point[0].y;

		int v1 = checkTime();
		if (v1 == 'w') {
			speeds.x = 0;
			speeds.y = -1;
		}

		if (v1 == 's') {
			speeds.x = 0;
			speeds.y = 1;
		}

		if (v1 == 'd') {
			speeds.x = 1;
			speeds.y = 0;
		}

		if (v1 == 'a') {
			speeds.x = -1;
			speeds.y = 0;
		}

		for (int i = snake.length; i > 0; i--) {
			snake.point[i].x = snake.point[i - 1].x;
			snake.point[i].y = snake.point[i - 1].y;
		}

		snake.point[0].x = vector.x + speeds.x;
		snake.point[0].y = vector.y + speeds.y;

		gotoxy(0, 0);
		if (snake.point[0].x == fruit.x && snake.point[0].y == fruit.y) {
			snake.length++;
			initFruit(snake, fruit);
			score++;
		}
	}
}


void PlayGame() {
	//Toa do dau ran
	Snake snake;
	//Toa do trai cay
	Coordinates fruit;
	//Diem
	int score = 0;
	// Tao khung tro choi
	Map(score);
	initSnake(snake);
	initFruit(snake, fruit);
	gotoxy(fruit.x, fruit.y);
	cout << "o";

	Move(snake, fruit, score);

	gotoxy(0, heigth + 5);
}

int main() {
	PlayGame();
	gotoxy(0, heigth + 5);
	return 0;
}