#include"game.h"
void init(char board[ROW][COL], int row, int col)
{

	int i, j = 0;
	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COL; j++)
		{
			board[i][j] = ' ';/*此处初始化字符类型的数组用单引号，不能用双引号*/
		}
	}
}
void display(char board[ROW][COL], int row, int col)
{
	int i, j = 0;
	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COL; j++)/*此循环打印的是"井"字的第一行上面那些东西，为三个空格加一个竖杠循环组成*/
		{
			printf("   ");
			if (j < col - 1)/*井字最后不需要"|"，故只需要打印两个"|", 因而只循环两次,下同;*/
			{
				printf("|");
			}
			
		}
		if (i<row-1)/*此处亦只是打印两行内容，因而只循环两次*/
		{
			printf("\n");
			for (j = 0; j < COL; j++)/*此循环打印的是"井"字的第一行，为三个减号加一个竖杠组成*/
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
	printf("\n");
}
