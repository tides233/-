#define ROW 3
#define COL 3
#include<stdio.h>
void init(char board[ROW][COL], int row, int col);
void display(char board[ROW][COL], int row, int col);
void player(char board[ROW][COL], int row, int col);
void computer(char board[ROW][COL], int row, int col);
char whoiswin(char board[ROW][COL], int row, int col);
int isfull(char board[ROW][COL], int row, int col);
void win(char ret);
