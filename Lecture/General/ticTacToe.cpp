#include <stdio.h>

int main()
{
	char board[5][5];
	int turn = 0;
	int x, y;
	
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			board[i][j] = ' ';
		}
	}
	
	for(int i = 0; i < 9; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			for(int k = 0; k < 3; k++)
			{
				printf("%c", board[j][k]);
			}
			printf("\n");
		}
		scanf("%d %d", &x, &y);
		
		if(board[y-1][x-1] == ' ')
		{
			if(turn == 0)
			{
				board[y-1][x-1] = 'O';
			}
			else
			{
				board[y-1][x-1] = 'X';
			}
			turn = (turn + 1) %2;	
		}
		else
		{
			i--;
		}
//		if(board[0][0] == board[0][1] && board[0][1] == board[0][2])
		
		
	}
	
	return 0;
}
