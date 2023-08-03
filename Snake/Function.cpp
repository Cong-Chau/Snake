#include"Header.h"


//Toa do dau ran
Snake snake;
//Toa do trai cay
Coordinates fruit;

int Random(int min, int max) {
	srand(time(NULL));
	int r = rand();
	int ran = min + r % max;
	return ran;
}
void gotoxy(int x, int y)//Ham toa do
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD a = { x, y };    SetConsoleCursorPosition(h, a);
}

//Khoi tao vi tri dau ran
void initSnake() {
	snake.length = 3;
	int x = 5, y = 4;
	for (int i = 0; i < snake.length; i++,x--) {
		snake.point[i].x = x;
		snake.point[i].y = y;
		gotoxy(x, y);
		cout << "x";
	}
}

bool checkCOOR_Fr_Sn() {
	for (int i = 0; i < snake.length; i++) {
		if (fruit.x == snake.point[i].x && fruit.y == snake.point[i].y) {
			return false;
		}
	}
	return true;
}
void initFruit() {
	fruit.x = Random(1, 18);
	fruit.y = Random(1, 8);
	while (!checkCOOR_Fr_Sn) {
		fruit.x = Random(1, 18);
		fruit.y = Random(1, 8);
	}
	gotoxy(fruit.x, fruit.y);
	cout << "o";
}

void Map() {
	system("cls");
	//Hien thi
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 10; j++) {
			if (i == 0 || i == 19) {
				gotoxy(i, j);
				cout << "#";
				continue;
			}
			if (j == 0 || j == 9) {
				gotoxy(i, j);
				cout << "#";
				continue;
			}
		}
	}
	cout << endl;
	cout << " Score: ";
	
}



void PlayGame() {
	// Tao khung tro choi
	Map();
	initSnake();
	initFruit();

	gotoxy(0, 15);
}