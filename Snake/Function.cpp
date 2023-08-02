#include"Header.h"
int height = 10;
int width = 20;
int length = 2;
//Toa do dau ran
Coordinates snake;
//Toa do trai cay
Coordinates fruit;

int Random(int min, int max) {
	srand(time(NULL));
	int r = rand();
	int ran = min + r % max;
	return ran;
}

//Khoi tao vi tri dau ran
void initFirstLocal() {
	snake.x = Random(1, 8);
	snake.y = Random(1, 18);
}
//Khoi tao vi tri cua trai cay
void initFruit() {
	fruit.x = Random(1, 8);
	while (fruit.x == snake.x) {
		fruit.x = Random(1, 8);
	}
	fruit.y = Random(1, 18);
	while (fruit.y == snake.y) {
		fruit.y = Random(1, 18);
	}
}


void Map() {
	system("cls");
	//Hien thi
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 20; j++) {
			if (i == 0 || i == 9) {
				cout << "#";
				continue;
			}
			if (j == 0 || j == 19) {
				cout << "#";
				continue;
			}
			if (0 < i && i < 10) {
				if (0 < j && j < 20) {		
					//
					if (i == snake.x && j == snake.y) {
						cout << "X";
					}					
					//
					if (i == fruit.x && j == fruit.y) {
						cout << "o";
					}
					if ((i != snake.x && j != snake.y) || (i != fruit.x  && j != fruit.y)) {
						cout << " ";
					}
				}
				continue;
			}
		}
		cout << endl;
	}
	cout << " Score: ";
	int a; cin >> a;
	initFruit();
}

void PlayGame() {
	initFirstLocal();
	initFruit();
	for (int i = 0; i < 3; i++) {
		Map();
	}
}