#include<cstdio>

bool checkBlackPawn(int CoordX, int CoordY, char ChessBoard[][8]);
bool checkWhitePawn(int CoordX, int CoordY, char ChessBoard[][8]);

int main() {

	char chessboard[8][8];
	int WhiteKing_x  = -2;
	int WhiteKing_y ;
	int BlackKing_x ;
	int BlackKing_y ;
	bool ans_b;
	bool ans_w;
	while (WhiteKing_x != -1)
	{
		 WhiteKing_x = -1;
		 WhiteKing_y = -1;
		 BlackKing_x = -1;
		 BlackKing_y = -1;

		for (int i = 0; i < 8; i++) 
		{
			for (int j = 0; j < 8; j++) 
			{
				scanf(" %c", &chessboard[i][j]);
				if (chessboard[i][j] == 'k') 
				{
					BlackKing_x = i;
					BlackKing_y = j;
				}
				if (chessboard[i][j] == 'K') 
				{
					WhiteKing_x = i;
					WhiteKing_y = j;
				}
			}
		}

		ans_b = checkBlackPawn(BlackKing_x, BlackKing_y, chessboard);
		ans_w = checkWhitePawn(WhiteKing_x, WhiteKing_y, chessboard);
		printf("%d %d %d\n",ans_w, WhiteKing_x, WhiteKing_y);
		printf("%d %d %d\n",ans_b, BlackKing_x, BlackKing_y);

	}
}

bool checkBlackPawn(int CoordX, int CoordY, char ChessBoard[][8]) 
{
	int i = CoordX + 1;
	int j = CoordY - 1;
	if (i > 0 && i <= 8 && j > 0 && j <= 8) 
	{
		if (ChessBoard[i][j] == 'P') 
		{
			return true;
		}
	}

	j = CoordY + 1;

	if (i > 0 && i <= 8 && j > 0 && j <= 8)
	{
		if (ChessBoard[i][j] == 'P')
		{
			return true;
		}
	}
return false;
}

bool checkWhitePawn(int CoordX, int CoordY, char ChessBoard[][8])
{
	int i = CoordX - 1;
	int j = CoordY - 1;
	if (i > 0 && i < 8 && j > 0 && j < 8)
	{
		if (ChessBoard[i][j] == 'p')
		{
			return true;
		}
	}

	j = CoordY + 1;

	if (i > 0 && i < 8 && j > 0 && j < 8)
	{
		if (ChessBoard[i][j] == 'p')
		{
			return true;
		}
	}
	return false;
}

bool checkKnight(int CoordX, int CoordY, char ChessBoard[][8],char &king)
{
	int i = CoordX ;
	int j = CoordY - 1;
	if (i > 0 && i < 8 && j > 0 && j < 8)
	{
		if (ChessBoard[i][j] == '')
		{
			return true;
		}
	}

	j = CoordY + 1;

	if (i > 0 && i < 8 && j > 0 && j < 8)
	{
		if (ChessBoard[i][j] == 'p')
		{
			return true;
		}
	}
	return false;
}