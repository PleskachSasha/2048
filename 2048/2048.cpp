#include <iostream>
#include <conio.h>
#include <string>

using namespace std;

const int BOARD_SIZE = 4;
int board[BOARD_SIZE][BOARD_SIZE]{};

void ShowBoard()
{
	for (size_t i = 0; i < BOARD_SIZE; ++i)
	{
		for (size_t j = 0; j < BOARD_SIZE; ++j)
		{
			cout << board[i][j] << "\t";
		}
		cout << endl;
	}
}
void NewNumber()
{
	board[3][0] = 2;
	board[3][1] = 2;
	board[3][2] = 2;
	board[3][3] = 2;

	bool flag = false;

	/*while (!flag)
	{
		int n = rand() % 4;
		int m = rand() % 4;

		if (board[n][m] == 0)
		{
			board[n][m] = 2;
			flag = true;
		}
	}*/
	
}

void MoveLeft() 
{
	for (int i = 0; i < 4; i++)
	{
		for (int next = 0; next < 3; next++)
		{
			bool zeroFlag = false;
			bool endWhile = false;

			while (!endWhile)
			{
				int itL = next;
				int itR = -1;

				int count = 0;

				for (int q = 0; q < 4; q++)
				{
					if (board[i][q] != 0)
					{
						count++;
					}
				}
				if (count == 0)
				{
					endWhile = true;
				}

				if (!endWhile)
				{

					bool rFlag = false;
					bool lFlag = false;

					while (!lFlag)
					{
						
						if (board[i][itL] != 0 || itL > 3)
						{
							lFlag = true;
							break;
						}
						++itL;
					}


					if (count > 1)
					{
						while (!rFlag)
						{
							if (itL == itR)
							{
								++itR;

							}
							if (itR > 3)
							{
								itR = 0;
								break;
							}
							if (board[i][itR] != 0 && itL < itR)
							{
								rFlag = true;
								break;
							}
							++itR;							
						}
					}

					if (itL < 4 && itR < 4)
					{
						for (int j = 0; j < 4; j++)
						{

							if (board[i][itL] == board[i][itR] && board[i][j] == 0 && j < itL)
							{
								board[i][j] = board[i][itL] * 2;
								board[i][itR] = 0;
								board[i][itL] = 0;
								j--;
								break;
								
							}
							else if (board[i][itL] == board[i][itR] && j > itL)
							{
								board[i][itL] *= 2;
								board[i][itR] = 0;
								j--;
								break;
							}
							else if (board[i][itL] != board[i][itR] && count > 1 && itL < j && itR > j && board[i][j] == 0)
							{
								board[i][j] = board[i][itR];
								board[i][itR] = 0;
								break;
							}
							else if (board[i][itL] != board[i][itR] && count > 1 && itL > j && itR > j && board[i][j] == 0)
							{
								board[i][j] = board[i][itL];
								board[i][itL] = board[i][itR];
								board[i][itR] = 0;
								break;
							}
							else if (board[i][j] == 0 && itL != 0 && j < itL)
							{
								board[i][j] = board[i][itL];
								board[i][itL] = 0;
								next = 4;
								break;
							}
						}
					}
					
				}
				endWhile = true;
			}
		}
	}
}

void MoveRight()
{
	for (int i = 3; i >= 0; --i)
	{
		for (int next = 3; next >= 0; --next)
		{
			bool zeroFlag = false;
			bool endWhile = false;

			while (!endWhile)
			{
				int itL = 4;
				int itR = next;

				int count = 0;

				for (int q = 0; q < 4; q++)
				{
					if (board[i][q] != 0)
					{
						count++;
					}
				}
				if (count == 0)
				{
					endWhile = true;
				}

				if (!endWhile)
				{
					bool rFlag = false;
					bool lFlag = false;

					while (!rFlag)
					{
						if (board[i][itR] != 0 || itR < 0)
						{
							rFlag = true;
							break;
						}
						--itR;
					}

					


					if (count > 1)
					{
						itL = 3;
						while (!lFlag)
						{
							if (itL == itR)
							{
								--itL;
							}
							if (itL < 0)
							{
								itL = 4;
								break;
							}
							if (board[i][itL] != 0 && itL < itR)
							{
								lFlag = true;
								break;
							}
							--itL;
						}
					}

					if (itR >= 0)
					{
						for (int j = 3; j >= 0; --j)
						{

							if (board[i][itL] == board[i][itR] && board[i][j] == 0 && j > itR)
							{
								board[i][j] = board[i][itR] * 2;
								board[i][itR] = 0;
								board[i][itL] = 0;
								++j;
								break;

							}
							else if (board[i][itL] == board[i][itR] && j < itR)
							{
								board[i][itR] *= 2;
								board[i][itL] = 0;
								++j;
								break;
							}
							else if (board[i][itL] != board[i][itR] && count > 1 && itL < j && itR > j && board[i][j] == 0)
							{
								board[i][j] = board[i][itL];
								board[i][itL] = 0;
								break;
							}
							else if (board[i][itL] != board[i][itR] && count > 1 && itL < j && itR < j && board[i][j] == 0)
							{
								board[i][j] = board[i][itR];
								board[i][itR] = board[i][itL];
								board[i][itL] = 0;
								break;
							}
							else if (board[i][j] == 0 && itR != 3 && j > itR)
							{
								board[i][j] = board[i][itR];
								board[i][itR] = 0;
								next = -1;
								break;
							}
						}
					}

				}
				endWhile = true;
			}
		}
	}
}

void MoveUp()
{
	for (int i = 0; i < 4; i++)
	{
		for (int next = 0; next < 3; next++)
		{
			bool zeroFlag = false;
			bool endWhile = false;

			while (!endWhile)
			{
				int itL = next;
				int itR = -1;

				int count = 0;

				for (int q = 0; q < 4; q++)
				{
					if (board[q][i] != 0)
					{
						count++;
					}
				}
				if (count == 0)
				{
					endWhile = true;
				}

				if (!endWhile)
				{

					bool rFlag = false;
					bool lFlag = false;

					while (!lFlag)
					{

						if (board[itL][i] != 0 || itL > 3)
						{
							lFlag = true;
							break;
						}
						++itL;
					}


					if (count > 1)
					{
						while (!rFlag)
						{
							if (itL == itR)
							{
								++itR;

							}
							if (itR > 3)
							{
								itR = 0;
								break;
							}
							if (board[itR][i] != 0 && itL < itR)
							{
								rFlag = true;
								break;
							}
							++itR;
						}
					}

					if (itL < 4 && itR < 4)
					{
						for (int j = 0; j < 4; j++)
						{

							if (board[itR][i] == board[itL][i] && board[j][i] == 0 && j < itL)
							{
								board[j][i] = board[itL][i] * 2;
								board[itR][i] = 0;
								board[itL][i] = 0;
								j--;
								break;

							}
							else if (board[itR][i] == board[itL][i] && j > itL)
							{
								board[itL][i] *= 2;
								board[itR][i] = 0;
								j--;
								break;
							}
							else if (board[itR][i] != board[itL][i] && count > 1 && itL < j && itR > j && board[j][i] == 0)
							{
								board[j][i] = board[itR][i];
								board[itR][i] = 0;
								break;
							}
							else if (board[itR][i] != board[itL][i] && count > 1 && itL > j && itR > j && board[j][i] == 0)
							{
								board[j][i] = board[itL][i];
								board[itL][i] = board[itR][i];
								board[itR][i] = 0;
								break;
							}
							else if (board[j][i] == 0 && itL != 0 && j < itL)
							{
								board[j][i] = board[itL][i];
								board[itL][i] = 0;
								next = 4;
								break;
							}
						}
					}

				}
				endWhile = true;
			}
		}
	}
}
void MoveDown() {}

void GameOver() {}


void Menu()
{
	ShowBoard();
	cout << "a:left\t w:up\t d:right\t s:down\t e:EndGame" << endl;
	
}

void PlayerChoice()
{
	char choice;
	cin >> choice;

	/*switch (choice)
	{
	case 61: 
		cout << "aaaaaaa";
		break;
	default:
		cout << "asdasd";
		break;
	}*/
}

int main()
{
	srand(time(NULL));
	int i = 0;
	while (true)
	{
		NewNumber();
		Menu();
		
		int i;
		cin >> i;
		if (i == 1)
		{
			MoveUp();
		}		
	}
}

