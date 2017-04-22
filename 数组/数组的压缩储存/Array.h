#pragma once
#include <iostream>
using namespace std;
#define MAXSIZE 100

//三元组中的元素结构
typedef struct Triple{
	int x, y;//元素的横纵位置
	int values;//该元素的值
}Triple;

//三元组的结构
typedef struct TSMatrix {
	Triple data[MAXSIZE + 1];//三元组中元素的个数
	int rows, cols, nonZeroNumber;//三元组的行数、列数、非零元素个数
}TSMatrix;

//创建三元组函数
int CreateTSMatrix(TSMatrix &M) {
	int row, col, elem;
	printf("输入行= ");
	scanf_s("%d", &M.rows);
	printf("输入列= ");
	scanf_s("%d", &M.cols);
	printf("输入非零元素的个数= ");
	scanf_s("%d", &M.nonZeroNumber);

	if (M.nonZeroNumber > MAXSIZE)
	{
		printf("非零元素的个数超过了设置\a\n");
		return 0;
	}
	else {
		printf("行	列	数据\n");
		for (int i = 1; i <= M.nonZeroNumber; i++) {
			scanf_s("%d%d%d", &row, &col, &elem);
			M.data[i].x = row;
			M.data[i].y = col;
			M.data[i].values = elem;
		}
		return 1;
	}
}

//三元表打印函数
void PrintTSMatrix(TSMatrix M)
{
	for (int i = 1; i <= M.nonZeroNumber; i++)
	{
		printf("%d\t%d\t%d\n", M.data[i].x, M.data[i].y, M.data[i].values);
	}
}

//两个矩阵相加运算
int AddTSMatrix(TSMatrix M, TSMatrix N, TSMatrix &Q)
{
	if (M.rows != N.rows || M.cols != N.cols)
	{
		printf("两个矩阵无法进行相加运算!\a\n");
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
			//1.相同位置上有元素
			//因为M和N矩阵的x是相同的，即是同行比较的，所以只需再比较列
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


