// 数组的压缩储存.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include "Array.h"
using namespace std;

int main()
{
	TSMatrix M;
	int tag;
	tag = CreateTSMatrix(M);
	if (tag == 1) PrintTSMatrix(M);
	else printf("Error!\n");
	printf("\n");

	TSMatrix N;
	tag = CreateTSMatrix(N);
	if (tag == 1) PrintTSMatrix(N);
	else printf("Error!\n");
	printf("\n");

	TSMatrix Q;
	AddTSMatrix(M, N, Q);
	PrintTSMatrix(Q);

	system("pause");
    return 0;
}

