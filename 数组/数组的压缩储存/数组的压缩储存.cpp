// �����ѹ������.cpp : �������̨Ӧ�ó������ڵ㡣
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
	printf("�������֮��Ϊ��\n");
	AddTSMatrix(M, N, Q);
	PrintTSMatrix(Q);

	system("pause");
    return 0;
}

