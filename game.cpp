// Первая игра на C++.Игра лабиринт.

#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <conio.h>
using namespace std;

void gameOverManagement()
{
	system("cls");
	cout << "\n\n\n\n\n\n\n\n\t\t\t\t\t GAME OVER!\n\n\n\n\n\n\n";
	/*system("pause");*/
	Sleep(3000);
	exit(1);
}

void gameVictoryManagement()
{
	system("cls");
	cout << "\n\n\n\n\n\n\n\n\t\t\t\t\t VICTORY!\n\n\n\n\n\n\n";
	system("pause");
}

int dataManagement(int management, int stopGame)
{
	if (management == 1){
		gameOverManagement();
		stopGame = 1;
	} else if (management == 3) {
		gameVictoryManagement();
		stopGame = 1;
	}
	management = 2;
	return management, stopGame;
}

int game()
{
	int map[33][20] = { {1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,}, // Инициализация двухмерного массива карыты.
                      {1,0,1,0,0,1,0,1,0,0,0,1,1,1,1,0,0,0,0,1,}, // 1 = стена
                      {1,0,1,1,0,1,0,1,0,1,0,0,0,0,1,0,1,1,0,1,}, // 2 = правильный путь
                      {1,0,0,0,0,0,0,1,0,1,1,1,1,0,1,0,0,1,0,1,}, // 0 = ложный путь
                      {1,1,1,1,1,1,0,1,0,1,0,0,1,0,1,1,0,1,0,1,},
                      {1,0,0,1,0,0,0,0,0,1,1,0,0,0,0,0,0,1,0,1,},
                      {1,0,1,1,0,1,1,1,1,1,0,0,1,0,1,1,1,1,0,1,},
                      {1,0,0,0,0,0,0,0,0,1,1,1,1,0,1,0,0,0,0,1,},
                      {1,1,1,1,1,1,0,1,1,1,0,0,0,0,1,0,1,1,1,1,},
                      {1,1,0,0,0,1,0,0,1,1,0,1,1,1,1,0,0,0,0,1,},
                      {1,0,0,1,0,0,0,0,0,1,0,0,0,0,1,1,1,1,0,1,},
                      {1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,0,0,0,0,1,},
                      {1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,1,1,1,},
                      {1,0,1,1,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,},
                      {1,0,1,0,0,0,1,0,0,0,1,0,0,0,0,0,1,1,0,1,},
                      {1,0,1,1,1,1,1,0,1,0,1,1,1,0,1,0,0,0,0,1,},
                      {1,0,1,0,0,0,1,0,1,0,0,0,1,1,1,1,1,1,1,1,},
                      {1,0,1,0,1,0,1,0,1,0,1,0,0,0,0,0,0,0,0,1,},
                      {1,0,1,0,1,0,1,0,1,0,1,1,1,1,1,1,1,1,0,1,},
                      {1,0,1,0,1,0,1,0,1,0,0,0,0,0,0,0,0,0,0,1,},
                      {1,0,1,0,1,0,0,0,1,0,1,1,1,1,1,1,0,1,0,1,},
                      {1,0,1,0,1,1,1,1,1,0,0,0,1,0,1,0,0,1,0,1,},
                      {1,0,1,0,0,1,0,0,1,1,1,0,0,0,1,0,1,1,0,1,},
                      {1,0,1,1,0,1,1,0,0,0,0,0,1,0,1,0,0,1,0,1,},
                      {1,0,1,1,0,1,0,0,1,1,1,1,1,1,1,1,1,1,0,1,},
                      {1,0,1,1,0,1,1,0,1,0,0,0,0,0,0,0,0,0,0,1,},
                      {1,0,1,1,0,1,0,0,1,0,1,1,1,1,1,1,1,1,1,1,},
                      {1,0,1,1,0,1,0,1,1,0,1,1,1,1,1,1,1,1,0,3,},
                      {1,0,1,1,0,1,0,0,1,0,1,1,0,0,0,0,0,0,0,1,},
                      {1,0,1,1,0,1,0,1,1,0,1,1,0,1,1,1,1,1,1,1,},
                      {1,0,1,1,0,1,0,0,1,0,1,1,0,1,0,0,0,1,0,1,},
                      {1,0,0,0,0,1,0,1,1,0,0,0,0,0,0,1,0,0,0,1,},
                      {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,} };

	unsigned short keysArrow;
	int s1 = 0;
	int s2 = 1;
	int stopGame = 0;
	map[s1][s2] = 2;
	do
	{
		system("cls");
		
		for (int i = 0; i < 33; i ++)
		{
			for (int j = 0; j < 20; j++)
			{
				if (map[i][j] == 1)
				{
					cout << static_cast<char>(176);
					cout << static_cast<char>(176);
				} else if (map[i][j] == 2)
				{
					cout << static_cast<char>(186);
					cout << static_cast<char>(186);
				} else if (map[i][j] == 0 || 3)
				{
					cout << "  ";
				}
			}
			cout << endl;
		}
		
		keysArrow = getch();
		if (keysArrow == 72 || keysArrow == 150 || keysArrow == 230)
		{
			// Вверх
			map[s1][s2] = 0;
			s1--;
			dataManagement(map[s1][s2], stopGame);
			map[s1][s2] = 2;
		} else if (keysArrow == 80 || keysArrow == 155 || keysArrow == 235)
		{
			// Вниз
			map[s1][s2] = 0;
			s1++;
			dataManagement(map[s1][s2], stopGame);
			map[s1][s2] = 2;
		} else if (keysArrow == 77 || keysArrow == 130 || keysArrow == 262)
		{
			// Вправо
			map[s1][s2] = 0;
			s2++;
			dataManagement(map[s1][s2], stopGame);
			map[s1][s2] = 2;
		} else if (keysArrow == 75 || keysArrow == 148 || keysArrow == 235)
		{
			// Влево
			map[s1][s2] = 0;
			s2--;
			dataManagement(map[s1][s2], stopGame);
			map[s1][s2] = 2;
		}
	} while(true);
	
}

int main()
{
	game();
	return 0;
}
