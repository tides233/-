#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"/*��stdio.h��stdlib.h��time.h����ͷ�ļ����ã�Ȼ�����ڴ˴�����ͷ�ļ����Ϳ��Լ��ٴ�������ͬʱ��Ҳ������Դ���ģ�*/
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
	init(board, ROW, COL);/*��ʼ�����飬ʹÿ�ν�����Ϸʱ�������Ϊ������*/
	display(board,ROW, COL);/*ʹ���������*/
	while (1)/*��Һ͵�����Ҫ�����£��ʲ���ѭ��*/
	{
		player(board, ROW, COL);/*�����*/
		display(board, ROW, COL);
		ret=whoiswin(board, ROW, COL);/*�ж�ʤ��*/
		if (ret!='C')
		{
			break;
		}
		computer(board, ROW, COL);/*������*/
		display(board, ROW, COL);
		ret = whoiswin(board, ROW, COL);/*�ж�ʤ��*/
		if (ret != 'C')
		{
			break;
		}


	}
	win(ret);/*������*/
}
int main()
{
	int input;
	menu();
	do
	{
		printf("��������Ϸ��������1��0\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;

		default:
			printf("�������������1��0\n");
			break;
		}
	} while (input);

	return 0;
}