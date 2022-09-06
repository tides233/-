#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"/*把stdio.h、stdlib.h、time.h等在头文件引用，然后再在此处引用头文件，就可以减少代码量的同时，也减少资源消耗；*/
void menu()
{
	printf("++++++++++++++++++++++++++++\n");
	printf("++++  1.play    0.exit  ++++\n");
	printf("++++++++++++++++++++++++++++\n");

}
void game()
{
	char ret;
	char board[ROW][COL] = { 0 };
	init(board, ROW, COL);/*初始化数组，使每次进行游戏时，数组均为空数组*/
	display(board,ROW, COL);/*使井字棋可视*/
	while (1)/*玩家和电脑需要轮流下，故不断循环*/
	{
		player(board, ROW, COL);/*玩家下*/
		display(board, ROW, COL);
		ret=whoiswin(board, ROW, COL);/*判断胜负*/
		if (ret!='C')
		{
			break;
		}
		computer(board, ROW, COL);/*电脑下*/
		display(board, ROW, COL);
		ret = whoiswin(board, ROW, COL);/*判断胜负*/
		if (ret != 'C')
		{
			break;
		}


	}
	win(ret);/*输出结果*/
}
int main()
{
	int input;
	menu();
	do
	{
		printf("三子棋游戏，请输入1或0\n");
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
			printf("输入错误，请输入1或0\n");
			break;
		}
	} while (input);

	return 0;
}