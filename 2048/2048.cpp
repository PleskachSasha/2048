#include <iostream>
#include <conio.h>
#include <string>


const int BOARD_SIZE = 4;
int board[BOARD_SIZE][BOARD_SIZE]{};
int prevBoard[BOARD_SIZE][BOARD_SIZE]{};

int score = 0;

enum EnumChoise
{
	choice_A = 97,
	choice_W = 119,
	choice_D = 100,
	choice_S = 115,
	choice_E = 101
};

void ScoreIncrease(int value)
{
	score += value;
}

void ShowScore()
{
	std::cout << "SCORE: " << score << std::endl;
}

void FillPrevBoard()
{
	for (int i = 0; i < BOARD_SIZE; ++i)
	{
		for (int j = 0; j < BOARD_SIZE; ++j)
		{
			prevBoard[i][j] = board[i][j];
		}
	}
}

bool CompareBoard()
{
	bool compare = true;

	for (int i = 0; i < BOARD_SIZE; ++i)
	{
		for (int j = 0; j < BOARD_SIZE; ++j)
		{
			if (prevBoard[i][j] != board[i][j])
			{
				compare = false;
			}
		}
	}

	return compare;
}

void ShowBoard()
{
	for (int i = 0; i < BOARD_SIZE; ++i)
	{
		for (int j = 0; j < BOARD_SIZE; ++j)
		{
			std::cout << board[i][j] << "\t";
		}
		std::cout << std::endl << std::endl;
	}
}
void NewNumber()
{
	

	bool flag = false;
	while (!flag)
	{
		int twoOrFour = rand() % 10;

		int n = rand() % 4;
		int m = rand() % 4;

		if (board[n][m] == 0)
		{
			if (score > 100 && twoOrFour > 8)
			{
				board[n][m] = 2;
			}
			else
			{
				board[n][m] = 2;
			}
			flag = true;
		}
	}
}

void CountZero(bool& zero, int count)
{
	if (count == 0)
	{
		zero = true;
	}
}

int CountNumberLeftRight(int line)
{
	int count = 0;
	for (int q = 0; q < 4; ++q)
	{
		if (board[line][q] != 0)
		{
			++count;
		}
	}
	return count;
}
void MoveLeft() 
{
	for (int i = 0; i < 4; ++i)
	{
		for (int next = 0; next < 3; ++next)
		{
			bool zeroFlag = false;
			bool endWhile = false;

			while (!endWhile)
			{
				int itL = next;
				int itR = -1;
					int count = CountNumberLeftRight(i);

				CountZero(endWhile, count);
				

				if (!endWhile)
				{
					while (true)
					{
						if (board[i][itL] != 0 || itL > 3)
						{
							break;
						}
						++itL;
					}

					if (count > 1)
					{
						while (true)
						{
							if (itL == itR)
							{
								++itR;

							}
							if (itR > 3)
							{
								itR = -1;
								break;
							}
							if (board[i][itR] != 0 && itL < itR)
							{
								break;
							}
							++itR;							
						}
					}

					if (itL < 4 && itR < 4)
					{
						for (int j = 0; j < 4; ++j)
						{
							if (board[i][itL] == board[i][itR] && board[i][j] == 0 && j < itL)
							{
								board[i][j] = board[i][itL] * 2;
								board[i][itR] = 0;
								board[i][itL] = 0;
								--j;
								ScoreIncrease(board[i][j]);
								break;
							}
							else if (board[i][itL] == board[i][itR] && j > itL)
							{
								board[i][itL] *= 2;
								board[i][itR] = 0;
								--j;
								ScoreIncrease(board[i][itL]);
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
				int count = CountNumberLeftRight(i);

				CountZero(endWhile, count);

				if (!endWhile)
				{
					while (true)
					{
						if (board[i][itR] != 0 || itR < 0)
						{
							break;
						}
						--itR;
					}

					if (count > 1)
					{
						itL = 3;
						while (true)
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
								ScoreIncrease(board[i][j]);
								break;
							}
							else if (board[i][itL] == board[i][itR] && j < itR)
							{
								board[i][itR] *= 2;
								board[i][itL] = 0;
								++j;
								ScoreIncrease(board[i][itR]);
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

int CountNumberUpDown(int line)
{
	int count = 0;
	for (int q = 0; q < 4; ++q)
	{
		if (board[q][line] != 0)
		{
			++count;
		}
	}

	return count;
}
void MoveUp()
{
	for (int i = 0; i < 4; ++i)
	{
		for (int next = 0; next < 3; ++next)
		{
			bool zeroFlag = false;
			bool endWhile = false;

			while (!endWhile)
			{
				int itL = next;
				int itR = -1;
				int count = CountNumberUpDown(i);

				CountZero(endWhile, count);

				if (!endWhile)
				{
					while (true)
					{

						if (board[itL][i] != 0 || itL > 3)
						{
							break;
						}
						++itL;
					}

					if (count > 1)
					{
						while (true)
						{
							if (itL == itR)
							{
								++itR;

							}
							if (itR > 3)
							{	
								itR = -1;
								break;
							}
							if (board[itR][i] != 0 && itL < itR)
							{
								break;
							}
							++itR;
						}
					}

					if (itL < 4 && itR < 4)
					{
						for (int j = 0; j < 4; ++j)
						{

							if (board[itR][i] == board[itL][i] && board[j][i] == 0 && j < itL)
							{
								board[j][i] = board[itL][i] * 2;
								board[itR][i] = 0;
								board[itL][i] = 0;
								--j;
								ScoreIncrease(board[j][i]);
								break;
							}
							else if (board[itR][i] == board[itL][i] && j > itL)
							{
								board[itL][i] *= 2;
								board[itR][i] = 0;
								--j;
								ScoreIncrease(board[itL][i]);
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
void MoveDown() 
{
	for (int i = 3; i >= 0; --i)
	{
		for (int next = 3; next > 0; --next)
		{
			bool zeroFlag = false;
			bool endWhile = false;

			while (!endWhile)
			{
				int itL = -1;
				int itR = next;

				int count = CountNumberUpDown(i);

				CountZero(endWhile, count);

				if (!endWhile)
				{
					while (true)
					{
						if (board[itR][i] != 0 || itR < 0)
						{
							break;
						}
						--itR;
					}

					if (count > 1)
					{
						itL = next - 1;
						while (true)
						{
							if (itL == itR)
							{
								--itL;
							}
							if (itL < 0)
							{
								itL = -1;
								break;
							}
							if (board[itL][i] != 0 || itL > 3)
							{
								break;
							}
							--itL;
						}					
					}

					if (itR > -1)
					{
						for (int j = 3; j >= 0; --j)
						{

							if (board[itR][i] == board[itL][i] && board[j][i] == 0 && j > itR)
							{
								board[j][i] = board[itR][i] * 2;
								board[itR][i] = 0;
								board[itL][i] = 0;
								++j;
								ScoreIncrease(board[j][i]);
								break;
							}
							else if (board[itR][i] == board[itL][i] && j < itR)
							{
								board[itR][i] *= 2;
								board[itL][i] = 0;
								++j;
								ScoreIncrease(board[itR][i]);
								break;
							}
							else if (board[itR][i] != board[itL][i] && count > 1 && itL < j && itR > j && board[j][i] == 0)
							{
								board[j][i] = board[itL][i];
								board[itL][i] = 0;
								break;
							}
							else if (board[itR][i] != board[itL][i] && count > 1 && itL < j && itR < j && board[j][i] == 0)
							{
								board[j][i] = board[itR][i];
								board[itR][i] = board[itL][i];
								board[itL][i] = 0;
								break;
							}
							else if (board[j][i] == 0 && itR != 3 && j > itR)
							{
								board[j][i] = board[itR][i];
								board[itR][i] = 0;
								next = 0;
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

bool CanMove() 
{
	bool canMove = false;

	for (int i = 0; i < BOARD_SIZE; ++i)
	{
		for (int j = 0; j < BOARD_SIZE; ++j)
		{
			if (board[i][j] == 0)
			{
				canMove = true;
			}
		}
	}
	if (!canMove)
	{
		for (int i = 0; i < BOARD_SIZE - 1; ++i)
		{
			for (int j = 0; j < BOARD_SIZE - 1; ++j)
			{
				if (board[i][j] == board[i][j + 1] || board[j][i] == board[j + 1][i])
				{
					canMove = true;
				}
			}
		}
	}
	
	return canMove;
}
void End2048(bool& flag)
{
	for (int i = 0; i < BOARD_SIZE; ++i)
	{
		for (int j = 0; j < BOARD_SIZE; ++j)
		{
			if (board[i][j] == 2048)
			{
				ShowBoard();
				ShowScore();
				std::cout << "Do you want to continue playing \n1.Yes \n2.No" << std::endl;
				int end;
				std::cin >> end;
				if (end == 2)
				{
					flag = true;
				}
			}
		}
	}
}
	
int PlayerChoice()
{
	std::cout << "a:left\t w:up\t d:right\t s:down\t e:EndGame" << std::endl;

	char choice;
	std::cin >> choice;
	
	return choice;
}
void Menu()
{
	bool flag = false;
	bool end2048 = false;

	NewNumber();

	while (!flag)
	{
		FillPrevBoard();
		ShowBoard();
		ShowScore();
		
		if (CanMove())
		{
			int choice = PlayerChoice();

			switch (choice)
			{
			case choice_A:
				MoveLeft();
				break;
			case choice_W:
				MoveUp();
				break;
			case choice_D:
				MoveRight();
				break;
			case choice_S:
				MoveDown();
				break;
			case choice_E:
				std::cout << "End game" << std::endl;
				flag = true;
				break;
			default:
				std::cout << "You entered an invalid letter" << std::endl;
				break;
			}
			if (!end2048)
			{
				End2048(flag);
				end2048 = true;
			}
			

			if (!CompareBoard())
			{
				NewNumber();
			}
		}
		else
		{
			flag = true;
			std::cout << "GAME OVER" << std::endl;
		}
	}
}



int main()
{
	srand(time(NULL));
	Menu();
	
}

