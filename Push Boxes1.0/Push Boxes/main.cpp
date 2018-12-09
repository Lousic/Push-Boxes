#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int n = 0;//n是关卡数

int map[3][9][11] =//9是地图上下高度,11是地图左右宽度,map是地图数据
{
	{
		{ 0,0,0,1,1,1,1,1,0,0,0 },//0代表空地
		{ 0,0,0,1,0,0,0,1,0,0,0 },//1代表墙
		{ 0,0,0,1,0,0,0,1,0,0,0 },//3代表目的地
		{ 1,1,1,1,0,0,0,1,1,1,1 },//4代表箱子
		{ 1,0,3,0,4,5,0,0,0,0,1 },//5代表人
		{ 1,0,0,0,4,4,0,0,3,0,1 },
		{ 1,1,1,1,0,0,0,1,1,1,1 },
		{ 0,0,0,1,0,0,3,1,0,0,0 },
		{ 0,0,0,1,1,1,1,1,0,0,0 }
	},
	{
		{0,0,0,1,1,1,1,1,0,0,0},
		{0,0,0,1,0,0,0,1,0,0,0},
		{0,0,0,1,0,0,0,1,0,0,0},
		{1,1,1,1,4,0,0,1,1,1,1},
		{1,3,0,0,0,5,0,0,0,0,1},
		{1,0,0,0,0,4,0,0,0,3,1},
		{1,1,1,1,4,0,0,1,1,1,1},
		{0,0,0,1,0,0,3,1,0,0,0},
		{0,0,0,1,1,1,1,1,0,0,0}
	},
	{
		{0,0,0,1,1,1,1,1,1,0,0},
		{0,1,1,0,0,4,0,3,1,1,1},
		{1,0,3,0,0,4,0,0,0,0,1},
		{1,1,1,1,1,0,0,1,1,1,1},
		{1,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,5,1,1,0,0,1},
		{1,1,0,0,4,0,0,0,0,0,1},
		{0,1,0,0,0,1,0,0,3,0,1},
		{0,1,1,1,1,1,1,1,1,1,1}
	}
};
//绘制地图	//二维数组+switch()
void DrawMap()
{

	//遍历二维数组,绘制地图
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 11; j++)
		{
			//if else switch
			switch (map[n][i][j])
			{
			case 0:
				printf("  ");//空地
				break;
			case 1:
				printf("■");//墙壁
				break;
			case 3:
				printf("☆");//目的地
				break;
			case 4:
				printf("□");//箱子
				break;
			case 5:
				printf("♀");//人
				break;
			case 7:	//4+3	箱子在目的地中
				printf("★");
				break;
			case 8:
				printf("♂");//5+3	人在目的地中
				break;
			}
		}
		printf("\n");
	}
}

void PlayGame()//推箱子的动作逻辑判断
{
	int r, c;//人的下标
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 11; j++)
		{
			if (map[n][i][j] == 5 || map[n][i][j] == 8)	//i 	j	人的下标
			{
				r = i;
				c = j;
			}
		}
	}

	char ch;		//字符变量
	ch = getch();		//键盘的输入保存到字符中
	switch (ch)
	{
	case 'W':	//W A S D方向	72 80 75 77 虚拟键值 ascii windowsVK_UP VK_TAB VK_RETUNE
	case 'w':
	case 72:
		if (map[n][r - 1][c] == 0 || map[n][r - 1][c] == 3)
		{
			map[n][r - 1][c] += 5;
			map[n][r][c] -= 5;
		}
		else if (map[n][r - 1][c] == 4 || map[n][r - 1][c] == 7)
		{
			if (map[n][r - 2][c] == 0 || map[n][r - 2][c] == 3)
			{
				map[n][r - 2][c] += 4;
				map[n][r - 1][c] += 1;
				map[n][r][c] -= 5;
			}
		}
		break;

	case'S':	//enter按键的作用
	case's':
	case 80:
		if (map[n][r + 1][c] == 0 || map[n][r + 1][c] == 3)
		{
			map[n][r + 1][c] += 5;
			map[n][r][c] -= 5;
		}
		else if (map[n][r + 1][c] == 4 || map[n][r + 1][c] == 7)
		{
			if (map[n][r + 2][c] == 0 || map[n][r + 2][c] == 3)
			{
				map[n][r + 2][c] += 4;
				map[n][r + 1][c] += 1;
				map[n][r][c] -= 5;
			}
		}
		break;

	case'A':
	case'a':
	case 75:
		if (map[n][r][c - 1] == 0 || map[n][r][c - 1] == 3)
		{
			map[n][r][c - 1] += 5;
			map[n][r][c] -= 5;
		}
		else if (map[n][r][c - 1] == 4 || map[n][r][c - 1 == 7])
		{
			if (map[n][r][c - 2] == 0 || map[n][r][c - 2] == 3)
			{
				map[n][r][c - 2] += 4;
				map[n][r][c - 1] += 1;
				map[n][r][c] -= 5;
			}
		}
		break;

	case 'D':
	case 'd':
	case 77:
		if (map[n][r][c + 1] == 0 || map[n][r][c + 1] == 3)
		{
			map[n][r][c + 1] += 5;
			map[n][r][c] -= 5;
		}
		else if (map[n][r][c + 1] == 4 || map[n][r][c + 1] == 7)
		{
			if (map[n][r][c + 2] == 0 || map[n][r][c + 2] == 3)
			{
				map[n][r][c + 2] += 4;
				map[n][r][c + 1] += 1;
				map[n][r][c] -= 5;
			}
		}
		break;

	case 'Q':
	case 'q':
		n--;//上一关
		break;
	case  'E':
	case 'e':
		n++;//下一关
		break;
	}
}
int Gameover()//判断箱子进入目的地的数量
{
	int count = 0;
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 11; j++)
		{
			if (map[n][i][j] == 7)
				count++;
		}
	}
	return count;
}

int main()
{
	while (1)
	{
		system("cls");
		printf("第  %d  关\nQ q,上一关,E e,下一关\n", n + 1);
		DrawMap();
		PlayGame();
		Gameover();
		while (Gameover() == 3)//判断箱子进入目的地的数量是否为3个,进入下一关
		{
			printf("恭喜过关!按Enter进入下一关");
			getchar();
			n++;
			while (n == 3)//判断已经通过的关卡是否为3关,结束游戏
			{
				printf("恭喜通关!!");
				getchar();
				return 0;
			}
		}
	}
}