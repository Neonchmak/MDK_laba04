//Игра крестики-нолики
#include <iostream>
#include <vector>
//Тут был андрюша
using namespace std;

void Play(char M[3][3], char c)
{
	int x, y = 0;
	cout << c;

	cout << " Input cell: ";
	cin >> x;
	while (x > 3)
	{
		x -= 3;
		y++;
	}
	x--;

	M[y][x] = c;
}

//Вывод поля
void Field(char M[3][3])
{
	system("cls");

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << M[i][j] << " ";
		}
		cout << "\n";
	}
}

//Проверка
bool WinCheck(char M[3][3])
{
	int check[3][3];
	int res = 0;

	//ROWS
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (M[i][j] == 'X')
				res += 1;
			else if (M[i][j] == 'O')
				res -= 1;
			else
				break;
		}

		if (res == 3 || res == -3)
			return true;
		else
			res = 0;
	}

	//COLUMS
	for (int j = 0; j < 3; j++)
	{
		for (int i = 0; i < 3; i++)
		{
			if (M[i][j] == 'X')
				res += 1;
			else if (M[i][j] == 'O')
				res -= 1;
			else
				break;
		}

		if (res == 3 || res == -3)
			return true;
		else
			res = 0;
	}

	//DIAGONAL
	for (int j = 0; j < 3; j++)
	{
		if (M[j][j] == 'X')
			res += 1;
		else if (M[j][j] == 'O')
			res -= 1;
		else
			break;
	}

	if (res == 3 || res == -3)
		return true;
	else
		res = 0;
	//REV DIAGONAL
	for (int j = 3; j >= 0; j--)
	{
		if (M[j][j] == 'X')
			res += 1;
		else if (M[j][j] == 'O')
			res -= 1;
		else
			break;
	}

	if (res == 3 || res == -3)
		return true;
	else
		res = 0;

	return false;
}

int main()
{
	char matrix[3][3] = { {'1','2','3'},
						  {'4','5','6'},
						  {'7','8','9'} };
	bool win = false;

	Field(matrix);
	while (!win)
	{
		Play(matrix, 'X');//X
		Field(matrix);

		win = WinCheck(matrix);//CHECK
		if (win) break;

		Play(matrix, 'O');//O
		Field(matrix);

		win = WinCheck(matrix);//CHECK
	}

	return 0;
}
//Конец кода
