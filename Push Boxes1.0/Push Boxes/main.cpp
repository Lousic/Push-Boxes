#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int n = 0;//n�ǹؿ���

int map[3][9][11] =//9�ǵ�ͼ���¸߶�,11�ǵ�ͼ���ҿ��,map�ǵ�ͼ����
{
	{
		{ 0,0,0,1,1,1,1,1,0,0,0 },//0����յ�
		{ 0,0,0,1,0,0,0,1,0,0,0 },//1����ǽ
		{ 0,0,0,1,0,0,0,1,0,0,0 },//3����Ŀ�ĵ�
		{ 1,1,1,1,0,0,0,1,1,1,1 },//4��������
		{ 1,0,3,0,4,5,0,0,0,0,1 },//5������
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
//���Ƶ�ͼ	//��ά����+switch()
void DrawMap()
{

	//������ά����,���Ƶ�ͼ
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 11; j++)
		{
			//if else switch
			switch (map[n][i][j])
			{
			case 0:
				printf("  ");//�յ�
				break;
			case 1:
				printf("��");//ǽ��
				break;
			case 3:
				printf("��");//Ŀ�ĵ�
				break;
			case 4:
				printf("��");//����
				break;
			case 5:
				printf("��");//��
				break;
			case 7:	//4+3	������Ŀ�ĵ���
				printf("��");
				break;
			case 8:
				printf("��");//5+3	����Ŀ�ĵ���
				break;
			}
		}
		printf("\n");
	}
}

void PlayGame()//�����ӵĶ����߼��ж�
{
	int r, c;//�˵��±�
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 11; j++)
		{
			if (map[n][i][j] == 5 || map[n][i][j] == 8)	//i 	j	�˵��±�
			{
				r = i;
				c = j;
			}
		}
	}

	char ch;		//�ַ�����
	ch = getch();		//���̵����뱣�浽�ַ���
	switch (ch)
	{
	case 'W':	//W A S D����	72 80 75 77 �����ֵ ascii windowsVK_UP VK_TAB VK_RETUNE
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

	case'S':	//enter����������
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
		n--;//��һ��
		break;
	case  'E':
	case 'e':
		n++;//��һ��
		break;
	}
}
int Gameover()//�ж����ӽ���Ŀ�ĵص�����
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
		printf("��  %d  ��\nQ q,��һ��,E e,��һ��\n", n + 1);
		DrawMap();
		PlayGame();
		Gameover();
		while (Gameover() == 3)//�ж����ӽ���Ŀ�ĵص������Ƿ�Ϊ3��,������һ��
		{
			printf("��ϲ����!��Enter������һ��");
			getchar();
			n++;
			while (n == 3)//�ж��Ѿ�ͨ���Ĺؿ��Ƿ�Ϊ3��,������Ϸ
			{
				printf("��ϲͨ��!!");
				getchar();
				return 0;
			}
		}
	}
}