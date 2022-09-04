#include"game.h"
void menu()
{
	printf("********************************\n");
	printf("*****   1.play    0.exit   *****\n");
	printf("********************************\n");

}
void game()
{
	char board[ROW][COL] = { 0 };
	
	init(board, ROW, COL);/*数组的初始化，使数组3*3均为"空格"*/
	display(board, ROW, COL);/*"井"字的展示*/
}
int main()
{
	int input = 0;
	menu();
	printf("请输入1或0\n");
	do
	{
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
				printf("退出游戏\n");
				break;

		default:
			printf("输入错误\n");
			break;
		}
	} while (input);
	return 0;
}
