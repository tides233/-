#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
void init(char board[ROW][COL], int row, int col)
{
	int i, j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';/*�˴������õ����ţ�����*/
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
			printf(" %c ", board[i][j]);/*ǰ�ߵĴ�ӡΪ"�ո�%c�ո�"*//*�˴���ӡ���ǡ������ֵ�һ�е������ǲ���*/
			if (j < col - 1)/*�������沿��ֻ�������ܣ���ֻѭ������*/
			{
				printf("|");
			}
		}
		if (i<row-1)/*�˴���ӡ���ǡ������ֵĵ�һ�У�����ֻ�����У���ֻѭ������*/
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
	printf("\n");/*ѭ�������󣬴�ӡ���������ı�����ǵ��ٻ��У���������ӡ������*/
	
}
void player(char board[ROW][COL], int row, int col)
{
	int x, y = 0;
	while (1)
	{
		printf("�����:>\n");
		scanf("%d%d", &x, &y);
		if (x<=3&&x>=1&&y<=3&&y>=1)/*�˴�����Ϊ���ڵ���1��С�ڵ���3���ǳ��ڶ�������ȵĿ��ǣ��Ͼ���������������Ϸ�Ķ��ǳ���Ա��
			��֪����һ�е�һ��Ϊ0 0*/
		{
			if (board[x-1][y-1]==' ')/*��������ڵ���1С�ڵ���3������ȷ�����λ���Ƿ��¹��������Ҫ�����ж�*/
			{
				board[x - 1][y - 1] = '*'; /*����ʵ���ϼ����ʶ��Ļ���012�����ټ�ȥ1������Ϊ�����ʶ��*/
				break;
			}
		}
		else
		{
			printf("�����Ƿ�\n");
		}
	}
}

void computer(char board[ROW][COL], int row, int col)
{
	int x, y = 0;
	while (1)
	{
		printf("������:>\n");
		x = rand() % ROW;/*�˴�ʹ�����������������Ҫ��ʹ��srand����*/
		/*����һ����ģ��3ֻ��0��1��2������������������������Ҫ���ʴ˴�����Ҫ�ٽ����ж��Ƿ��������*/
		y = rand() % COL;
		if (board[x][y]==' ')
		{
			board[x][y] = '#';
			break;
		}
	}
}

int isfull(char board[ROW][COL], int row, int col)/*�ж������Ƿ�����*/
{
	int i, j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')/*ֻҪ�жϳ��ո��û�������ж�ȫ�����ǿո�Ҫ�����*/
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
		if (board[0][i] == board[1][i] && board[2][i] == board[1][i] && board[1][i] != ' ') /*�ж�������û�г�ֱ��*/
		{
			return board[1][i];/*��"board[1][i�����ַ�*��#����㣬��ͬ*/
		}
		if(board[i][0]==board[i][1]&&board[i][2]==board[i][1]&&board[i][1]!=' ')/*�жϺ�����û�г�ֱ��*/
		{
			return board[i][1];
		}
		if (board[0][0]==board[1][1]&&board[1][1]==board[2][2]&&board[1][1]!=' ')/*�ж�б����û�г�ֱ��*/
		{
			return board[1][1];
		}
		if (board[0][2]==board[1][1]&&board[1][1]==board[2][0]&&board[1][1]!=' ')/*�ж�����һ��б����û�г�ֱ��*/
		{
			return board[1][1];
		}
	}
	if (1==isfull(board,ROW,COL))/*�ж��Ƿ�ƽ�ֻ�û������*/
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
		printf("��һ�ʤ\n");
	}
	if (ret=='#')
	{
		printf("���Ի�ʤ\n");
	}
	if (ret=='Q')
	{
		printf("ƽ��\n");
	}
	
}
