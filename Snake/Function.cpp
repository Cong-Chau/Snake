#include"Header.h"
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
	snake.length = 3;
	int x = 4, y = (heigth / 2) - 1;
	for (int i = 0; i < snake.length; i++,x--) {
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

void Right(Snake& snake, Coordinates& fruit, int& score) {
	while (1) {
		for (int x = snake.point[0].x; x < wight; x++) {
			if (checkLose(snake)) {
				gotoxy((wight / 2) - 7, heigth + 3);
				cout << " GAME OVER!!!\n";
				return;
			}
			gotoxy(x, snake.point[0].y);
			for (int i = 0; i < snake.length; i++) {
				cout << "x";
				gotoxy(snake.point[i + 1].x, snake.point[i + 1].y);
			}
			for (int i = snake.length;i>0; i--) {
				snake.point[i].x = snake.point[i - 1].x;
				snake.point[i].y = snake.point[i - 1].y;
			}
			snake.point[0].x = x + 1;
			gotoxy(0, 0);
			if (snake.point[0].x == fruit.x && snake.point[0].y == fruit.y) {
				snake.length++;
				initFruit(snake, fruit);
			}
			Sleep(speed);
			system("cls");
			Map(score);
			gotoxy(fruit.x, fruit.y);
			cout << "o";

			
		}
		char _input;
		int move;
		while (1) {
			_input = _getch();
			move = _input;
			if (move == 119 || move == 87) {
				Up(snake, fruit, score);
			}
			if (move == 115 || move == 83) {
				Down(snake, fruit, score);
			}
			/*if (move == 100 || move == 68) {
				Right(snake, fruit, score);
			}*/
			if (move == 97 || move == 65) {
				Left(snake, fruit, score);
			}
		}
	}
}

void Left(Snake& snake, Coordinates& fruit, int& score) {
	while (1) {
		for (int x = snake.point[0].x; x >= 0; x--) {
			if (checkLose(snake)) {
				gotoxy((wight / 2) - 7, heigth + 3);
				cout << " GAME OVER!!!\n";
				return;
			}
			gotoxy(x, snake.point[0].y);
			for (int i = 0; i < snake.length; i++) {
				cout << "x";
				gotoxy(snake.point[i + 1].x, snake.point[i + 1].y);
			}
			for (int i = snake.length; i > 0; i--) {
				snake.point[i].x = snake.point[i - 1].x;
				snake.point[i].y = snake.point[i - 1].y;
			}
			snake.point[0].x = x - 1;
			gotoxy(0, 0);
			if (snake.point[0].x == fruit.x && snake.point[0].y == fruit.y) {
				snake.length++;
				initFruit(snake, fruit);
			}
			Sleep(speed);
			system("cls");
			Map(score);
			gotoxy(fruit.x, fruit.y);
			cout << "o";

			
		}
		char _input;
		int move;
		while (1) {
			_input = _getch();
			move = _input;
			if (move == 119 || move == 87) {
				Up(snake, fruit, score);
			}
			if (move == 115 || move == 83) {
				Down(snake, fruit, score);
			}
			if (move == 100 || move == 68) {
				Right(snake, fruit, score);
			}
			/*if (move == 97 || move == 65) {
				Left(snake, fruit, score);
			}*/
		}
	}
}

void Down(Snake& snake, Coordinates& fruit, int& score) {
	while (1) {
		for (int y = snake.point[0].y; y < heigth; y++) {
			if (checkLose(snake)) {
				gotoxy((wight / 2) - 7, heigth + 3);
				cout << " GAME OVER!!!\n";
				return;
			}
			gotoxy(snake.point[0].x, y);
			for (int i = 0; i < snake.length; i++) {
				cout << "x";
				gotoxy(snake.point[i + 1].x, snake.point[i + 1].y);
			}
			for (int i = snake.length; i > 0; i--) {
				snake.point[i].x = snake.point[i - 1].x;
				snake.point[i].y = snake.point[i - 1].y;
			}
			snake.point[0].y = y + 1;
			gotoxy(0, 0);
			if (snake.point[0].x == fruit.x && snake.point[0].y == fruit.y) {
				snake.length++;
				initFruit(snake, fruit);
			}
			Sleep(speed * 2);
			system("cls");
			Map(score);
			gotoxy(fruit.x, fruit.y);
			cout << "o";

			
		}
		char _input;
		int move;
		while (1) {
			_input = _getch();
			move = _input;
			if (move == 119 || move == 87) {
				Up(snake, fruit, score);
			}
			/*if (move == 115 || move == 83) {
				Down(snake, fruit, score);
			}*/
			if (move == 100 || move == 68) {
				Right(snake, fruit, score);
			}
			if (move == 97 || move == 65) {
				Left(snake, fruit, score);
			}
		}
	}
}

void Up(Snake& snake, Coordinates& fruit, int& score) {
	while (1) {
		for (int y = snake.point[0].y; y >= 0; y--) {
			if (checkLose(snake)) {
				gotoxy((wight / 2) - 7, heigth + 3);
				cout << " GAME OVER!!!\n";
				return;
			}
			gotoxy(snake.point[0].x, y);
			for (int i = 0; i < snake.length; i++) {
				cout << "x";
				gotoxy(snake.point[i + 1].x, snake.point[i + 1].y);
			}
			for (int i = snake.length; i > 0; i--) {
				snake.point[i].x = snake.point[i - 1].x;
				snake.point[i].y = snake.point[i - 1].y;
			}
			snake.point[0].y = y - 1;
			gotoxy(0, 0);
			if (snake.point[0].x == fruit.x && snake.point[0].y == fruit.y) {
				snake.length++;
				initFruit(snake, fruit);
			}
			Sleep(speed * 2);
			system("cls");
			Map(score);
			gotoxy(fruit.x, fruit.y);
			cout << "o";

			
		}
		char _input;
		int move;
		while (1) {
			_input = _getch();
			move = _input;
			/*if (move == 119 || move == 87) {
				Up(snake, fruit, score);
			}*/
			if (move == 115 || move == 83) {
				Down(snake, fruit, score);
			}
			if (move == 100 || move == 68) {
				Right(snake, fruit, score);
			}
			if (move == 97 || move == 65) {
				Left(snake, fruit, score);
			}
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

//	Right(snake, fruit, score);
	char _input;
	int move;
	while (1) {
		_input = _getch();
		move = _input;
		if (move == 119 || move == 87) {
			Up(snake, fruit, score);
		}
		if (move == 115 || move == 83) {
			Down(snake, fruit, score);
		}
		if (move == 100 || move == 68) {
			Right(snake, fruit, score);
		}
		if (move == 97 || move == 65) {
			Left(snake, fruit, score);
		}
	}
	
	gotoxy(0, heigth + 5);
}