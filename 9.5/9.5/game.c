#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
void init(char board[ROW][COL], int row, int col)
{
	int i, j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';/*此处必须用单引号！！！*/
		}
	}
}
void display(char board[ROW][COL], int row, int col)
{
	int i, j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);/*前边的打印为"空格%c空格"*//*此处打印的是“井”字第一行的上面那部分*/
			if (j < col - 1)/*由于上面部分只有两条杠，故只循环两次*/
			{
				printf("|");
			}
		}
		if (i<row-1)/*此处打印的是“井”字的第一行，由于只有两行，故只循环两次*/
		{
			printf("\n");
			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j<col-1)
				{
					printf("|");
				}
			}
			printf("\n");
		}
	}
	printf("\n");/*循环结束后，打印完了完整的表格，最后记得再换行，避免后面打印出问题*/
	
}
void player(char board[ROW][COL], int row, int col)
{
	int x, y = 0;
	while (1)
	{
		printf("玩家下:>\n");
		scanf("%d%d", &x, &y);
		if (x<=3&&x>=1&&y<=3&&y>=1)/*此处设置为大于等于1，小于等于3，是出于对玩家优先的考虑，毕竟并不是所有玩游戏的都是程序员，
			不知道第一行第一列为0 0*/
		{
			if (board[x-1][y-1]==' ')/*仅满足大于等于1小于等于3还不能确定这个位置是否被下过，因而需要进行判断*/
			{
				board[x - 1][y - 1] = '*'; /*由于实际上计算机识别的还是012，故再减去1，即可为计算机识别*/
				break;
			}
		}
		else
		{
			printf("参数非法\n");
		}
	}
}

void computer(char board[ROW][COL], int row, int col)
{
	int x, y = 0;
	while (1)
	{
		printf("电脑下:>\n");
		x = rand() % ROW;/*此处使用了随机数函数，需要再使用srand函数*/
		/*而且一个数模上3只有0、1、2三种情况，完美符合下棋的需要，故此处不需要再进行判断是否参数合理*/
		y = rand() % COL;
		if (board[x][y]==' ')
		{
			board[x][y] = '#';
			break;
		}
	}
}

int isfull(char board[ROW][COL], int row, int col)/*判断棋盘是否下满*/
{
	int i, j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')/*只要判断出空格就没满，比判断全都不是空格要更简便*/
			{
				return 0;
			}
		}
	}return 1;
}

char whoiswin(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < ROW; i++)
	{
		if (board[0][i] == board[1][i] && board[2][i] == board[1][i] && board[1][i] != ' ') /*判断竖向有没有成直线*/
		{
			return board[1][i];/*用"board[1][i代替字符*与#更简便，下同*/
		}
		if(board[i][0]==board[i][1]&&board[i][2]==board[i][1]&&board[i][1]!=' ')/*判断横向有没有成直线*/
		{
			return board[i][1];
		}
		if (board[0][0]==board[1][1]&&board[1][1]==board[2][2]&&board[1][1]!=' ')/*判断斜线有没有成直线*/
		{
			return board[1][1];
		}
		if (board[0][2]==board[1][1]&&board[1][1]==board[2][0]&&board[1][1]!=' ')/*判断另外一个斜线有没有成直线*/
		{
			return board[1][1];
		}
	}
	if (1==isfull(board,ROW,COL))/*判断是否平局或没下完棋*/
	{
		return 'Q';
	}
	else
	{
		return 'C';
	}

}
void win(char ret)
{
	if (ret=='*')
	{
		printf("玩家获胜\n");
	}
	if (ret=='#')
	{
		printf("电脑获胜\n");
	}
	if (ret=='Q')
	{
		printf("平局\n");
	}
	
}
