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
	/*board[0][0] = 2;
	board[1][0] = 2;
	board[2][0] = 2;
	board[3][0] = 2;*/

	bool flag = false;

	while (!flag)
	{
		int n = rand() % 4;
		int m = rand() % 4;

		if (board[n][m] == 0)
		{
			board[n][m] = 2;
			flag = true;
		}
	}
	
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
							//???????
							
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
							
							

							//BREAK????????

							/*else if (board[i][itL] == board[i][itR] && count != 1)
							{
								if (board[i][j] == 0 && itL < j)
								{
									board[i][j] = board[i][itL] * 2;
									board[i][itR] = 0;
									board[i][itL] = 0;
									break;
								}
								else
								{
									board[i][itL] *= 2;
									board[i][itR] = 0;
									break;
								}
							}
							else if (board[i][itL] != board[i][itR] && count != 1 && board[i][j] == 0)
							{
								board[i][j] = board[i][itR];
								board[i][itR] = 0;
								break;
							}*/
						}
					}
					
				}
				endWhile = true;
			}
		}
	}
}


			
		

	

void MoveRight() {}
void MoveDown() {}
void MoveUp() {}

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
			MoveLeft();
		}
		
		
		
		
	}
		
}

//void MoveLeftZero(int _itL, int _itR)
//{
//	for (int i = 0; i < 4; ++i)
//	{
//		for (int j = 0; j < 4; j++)
//		{
//			int count = 0;
//			for (int k = 0; k < 4; k++)
//			{
//				if (board[i][k] != 0)
//				{
//					++count;
//				}
//			}
//
//			bool endWhile = false;
//			int itL = _itL;
//			int itR = _itR;
//
//			while (!endWhile)
//			{
//
//				bool rFlag = false;
//				bool lFlag = false;
//
//				while (!rFlag)
//				{
//					if (board[i][itR] != 0)
//					{
//						rFlag = true;
//						break;
//					}
//					--itR;
//					if (itR < 1)
//					{
//						rFlag = true;
//					}
//				}
//				while (!lFlag)
//				{
//
//					if (board[i][itL] != 0)
//					{
//						lFlag = true;
//						break;
//					}
//					++itL;
//					if (itL > 3)
//					{
//						lFlag = true;
//					}
//				}
//
//				if (count == 1 && itR == itL && board[i][0] == 0)
//				{
//					board[i][0] = board[i][itR];
//					board[i][itR] = 0;
//					break;
//				}
//				/*if (board[i][itL] == board[i][itR])
//				{
//					board[i][itL] *= 2;
//					board[i][itR] = 0;
//					break;
//				}*/
//
//
//
//				endWhile = true;
//			}
//		}
//
//	}
//}
//
//void MoveLeft()
//{
//	int itR = BOARD_SIZE - 1;
//
//	int itL = 1;
//
//	for (int i = 0; i < 4; i++)
//	{
//		MoveLeftZero(i, itR);
//	}
//
//
//
//
//
//}

//for (int i = 0; i < 4; i++)
	//{
	//	bool zeroFlag = false;

	//	bool endWhile = false;
	//	int itL = 0;
	//	int itR = 3;

	//	while (!endWhile)
	//	{
	//		int count = 0;
	//		for (int q = 0; q < 4; q++)
	//		{
	//			if (board[i][q] != 0)
	//			{
	//				count++;
	//			}
	//		}

	//		bool rFlag = false;
	//		bool lFlag = false;

	//		while (!rFlag)
	//		{
	//			if (board[i][itR] != 0)
	//			{
	//				rFlag = true;
	//				break;
	//			}
	//			--itR;
	//			if (itR < 1)
	//			{
	//				rFlag = true;
	//			}
	//		}

	//		while (!lFlag && !(board[i][itL] == board[i][itR]))
	//		{
	//			if (board[i][itL] != 0)
	//			{
	//				lFlag = true;
	//				break;
	//			}
	//			++itL;
	//			if (itL > 3)
	//			{
	//				lFlag = true;
	//			}
	//		}

	//		
	//		for (int j = 0; j < 4; j++)
	//		{
	//			if (count == 1 && board[i][j] == 0 && itR>j)
	//			{
	//				board[i][j] = board[i][itR];
	//				board[i][itR] = 0;
	//				break;

	//			}
	//			else if (board[i][itL] == board[i][itR] && count != 1)
	//				{
	//					if (board[i][j] == 0 && itL < j)
	//					{
	//						board[i][j] = board[i][itL] * 2;
	//						board[i][itR] = 0;
	//						board[i][itL] = 0;
	//					}
	//					else {
	//						board[i][itL] *= 2;
	//						board[i][itR] = 0;
	//					}
	//				}
	//			else
	//			{
	//				if (board[i][j] == 0 && count != 1 && itR < j)
	//				{
	//					board[i][j] = board[i][itR];
	//					board[i][itR] = 0;
	//					
	//				}
	//			}
	//			else
	//			{
	//				if (board[i][j] == 0 && lflag)
	//				{

	//					break;
	//				}
	//			}
	//			
	//				
	//			
	//		}
	//					
	//		/*if (board[i][itL] == board[i][itR])
	//		{
	//			board[i][itL] *= 2;
	//			board[i][itR] = 0;
	//			break;
	//		}*/
	//		
	//		endWhile = true;
	//	}
	//}
