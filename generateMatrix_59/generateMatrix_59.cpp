// generateMatrix_59.cpp : 定义控制台应用程序的入口点。
//
/*
给定一个正整数 n，生成一个包含 1 到 n2 所有元素，且元素按顺时针顺序螺旋排列的正方形矩阵。

示例:

输入: 3
输出:
[
[ 1, 2, 3 ],
[ 8, 9, 4 ],
[ 7, 6, 5 ]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/spiral-matrix-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include "stdafx.h"
#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> generateMatrix(int n) {
	if (n == 0)return{};
	vector<vector<int>> matrix(n, vector<int>(n, 0));
	int minR, maxR, minC, maxC;
	minR = 0;
	minC = 0;
	maxR = n;
	maxC = n;
	int m = 1;
	while (1)
	{
		//left->right
		for (int i = minC; i < maxC; i++)
		{
			matrix[minR][i] = m++;
		}
		minR++;
		if (minR == maxR)return matrix;
		//up->down
		for (int i = minR; i < maxR; i++)
		{
			matrix[i][maxC - 1] = m++;
		}
		maxC--;
		if (minC == maxC)return matrix;
		//right->left
		for (int i = maxC - 1; i >= minC; i--)
		{
			matrix[maxR - 1][i] = m++;
		}
		maxR--;
		if (minR == maxR)return matrix;
		//down->up
		for (int i = maxR - 1; i >= minR; i--)
		{
			matrix[i][minC] = m++;
		}
		minC++;
		if (minC == maxC)return matrix;
	}

}

int main()
{
	vector<vector<int>> matrix = generateMatrix(4);
	for each (auto var in matrix)
	{
		for each (auto it in var)
		{
			cout << it << " ";
		}
		cout << endl;
	}
    return 0;
}

