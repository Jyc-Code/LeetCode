/************************************************************************
* file name: 59.c
* author: lalala
* mail: 
* 循环--模拟
* created time: 2021年06月30日 星期三 10时10分47秒
*************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../include/print.h"

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generateMatrix(int n, int* returnSize, int** returnColumnSizes)
{
	int loop = 0;
	int x = 0,y = 0;
	int count = 1;

	int **ret;
	ret = malloc(sizeof(int*) * n);
	*returnColumnSizes = malloc(sizeof(int) * n);
	for(int i = 0;i < n;i++)
	{
		ret[i] = malloc(sizeof(int) * n);
		(*returnColumnSizes)[i] = n;
	}
	*returnSize = n;

	while(loop < n/2)
	{
		int i,j;
		i = x;
		j = y;

		for(;j < (n - loop - 1);)
		{
			ret[i][j++] = count;
			count++;
		}
		
		for(;i < (n - loop - 1);)
		{
			ret[i++][j] = count;
			count++;
		}

		for(;j > loop;)
		{
			ret[i][j--] = count;
			count++;
		}
		
		for(;i > loop;)
		{
			ret[i--][j] = count;
			count++;
		}
		x++;
		y++;
		loop++;
	}

	if(n%2 == 1)ret[n/2][n/2] = n*n;

	return ret;
}



int main(int argc, char *argv[])
{
	int n = 5;
	int *returnSize;
	int **returnColumnSizes;
	int **ret;
	ret = generateMatrix(n, returnSize, returnColumnSizes);
	
	for(int i = 0;i < n;i++)
	{
		for(int j = 0;j < n;j++)
			printf("%d ",ret[i][j]);
		printf("\n");
	}

	printf("\n");
	return 0;
}
