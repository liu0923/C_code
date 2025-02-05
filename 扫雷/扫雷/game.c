#include"game.h"
void InitBoard(char board[ROWS][COLS], int rows, int cols,char set)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			board[i][j] = set;//'0';//'*'
			
		}
	}

}
void DisplayBoard(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	//打印列号
	for (i = 0;i<=row;i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);
		for (j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}

}
void SetMine(char board[ROWS][COLS], int row, int col)
{
	int count = EASY_COUNT;
	while (count)
	{
		int x = rand() % row + 1;//产生1到9的随机数，随机布置雷；
		int y = rand() % col + 1;
		if (board[x][y] == '0')
		{
			board[x][y] == '1';
			count--;//排查之后逐渐递减
		}
	}

}
int get_mine_count(char mine[ROWS][COLS], int x, int y)
{
	mine[x - 1][y] +
		mine[x - 1][y - 1] +
		mine[x][y - 1] +
		mine[x + 1][y - 1] +
		mine[x + 1][y] +
		mine[x + 1][y - 1] +
		mine[x][y + 1] +
		mine[x - 1][y + 1] - 8 * '0';
	//计算x,y旁边几个雷；
	//'1'-'0'=1这是计算方法；即每个坐标藏的是字符再减去字符0就是数字；



}
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0; 
	int y = 0;
	int win = 0;
	while (win<row*col-EASY_COUNT)
	{
		printf("请输入排查雷的坐标：");
		scanf_s("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			//坐标合法
			//1.踩雷
			if (mine[x][y] == '1')
			{
				printf("很遗憾，你被炸死了\n");
				DisplayBoard(mine, row, col);
				break;
			}
			else//不是雷

			{
				//计算x,y的周围有几个雷
				int count = get_mine_count(mine, x, y);
				show[x][y] = count + '0';
				DisplayBoard(show, row, col);
				win++;

			}
		}
		
		else
		{
			printf("输入坐标非法，请重新输入");
		}
	}
		if (win == row * col - EASY_COUNT)
		{
			printf("恭喜你，排雷成功");
		}

}