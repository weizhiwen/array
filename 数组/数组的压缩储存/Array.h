#pragma once
#include <iostream>
using namespace std;
#define MAXSIZE 100

//��Ԫ���е�Ԫ�ؽṹ
typedef struct Triple{
	int x, y;//Ԫ�صĺ���λ��
	int values;//��Ԫ�ص�ֵ
}Triple;

//��Ԫ��Ľṹ
typedef struct TSMatrix {
	Triple data[MAXSIZE + 1];//��Ԫ����Ԫ�صĸ���
	int rows, cols, nonZeroNumber;//��Ԫ�������������������Ԫ�ظ���
}TSMatrix;

//������Ԫ�麯��
int CreateTSMatrix(TSMatrix &M) {
	int row, col, elem;
	printf("������= ");
	scanf_s("%d", &M.rows);
	printf("������= ");
	scanf_s("%d", &M.cols);
	printf("�������Ԫ�صĸ���= ");
	scanf_s("%d", &M.nonZeroNumber);

	if (M.nonZeroNumber > MAXSIZE)
	{
		printf("����Ԫ�صĸ�������������\a\n");
		return 0;
	}
	else {
		printf("��	��	����\n");
		for (int i = 1; i <= M.nonZeroNumber; i++) {
			scanf_s("%d%d%d", &row, &col, &elem);
			M.data[i].x = row;
			M.data[i].y = col;
			M.data[i].values = elem;
		}
		return 1;
	}
}

//��Ԫ���ӡ����
void PrintTSMatrix(TSMatrix M)
{
	for (int i = 1; i <= M.nonZeroNumber; i++)
	{
		printf("%d\t%d\t%d\n", M.data[i].x, M.data[i].y, M.data[i].values);
	}
}

//���������������
int AddTSMatrix(TSMatrix M, TSMatrix N, TSMatrix &Q)
{
	if (M.rows != N.rows || M.cols != N.cols)
	{
		printf("���������޷������������!\a\n");
		return 0;
	}
	Q.rows = M.rows;
	Q.cols = M.cols;
	Q.nonZeroNumber = 0;
	int n1 = 1, n2 = 1;
	int num = 0;
	int num1 = M.nonZeroNumber;
	int num2 = N.nonZeroNumber;
	int max = num1 + num2;

	for (int row = 1; row <= M.rows && num <= max ; row++)
	{
		for (int col = 1; col <= M.cols && num <= max; col++)
		{
			//1.��ͬλ������Ԫ��
			//��ΪM��N�����x����ͬ�ģ�����ͬ�бȽϵģ�����ֻ���ٱȽ���
			if (M.data[n1].x == row && N.data[n2].x == row && M.data[n1].y == col && col == N.data[n2].y)
			{
					num++;
					Q.data[num].x = M.data[n1].x;
					Q.data[num].y = M.data[n1].y;
					Q.data[num].values = M.data[n1].values + N.data[n2].values;
					Q.nonZeroNumber++;
					n1++;
					n2++;
			}
			else if(M.data[n1].x == row && M.data[n1].y == col)
			{
					num++;
					Q.data[num].x = M.data[n1].x;
					Q.data[num].y = M.data[n1].y;
					Q.data[num].values = M.data[n1].values;
					Q.nonZeroNumber++;
					n1++;
			}
			else if(N.data[n2].x == row && N.data[n2].y == col)
			{
					num++;
					Q.data[num].x = N.data[n2].x;
					Q.data[num].y = N.data[n2].y;
					Q.data[num].values = N.data[n2].values;
					Q.nonZeroNumber++;
					n2++;
			}
		}
	}
	return 1;
}


