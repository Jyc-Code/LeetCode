/************************************************************************
* file name: 977.c
* author: lalala
* mail: 
* 升序 进行平方后按非降序排列
* created time: 2021年06月29日 星期二 16时09分49秒
*************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../include/print.h"

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortedSquares(int* nums, int numsSize, int* returnSize)
{
	int *ret = malloc(sizeof(nums));
	int k = numsSize - 1;
	for(int i = 0,j = numsSize - 1;i <= j;)
	{
		if(nums[i]*nums[i] > nums[j]*nums[j])
		{
			ret[k--] = nums[i]*nums[i];
			i++;
		}
		else
		{
			ret[k--] = nums[j]*nums[j];
			j--;
		}
	}

	return ret;
}

int main(int argc, char *argv[])
{
	int nums[5] = {-7,-3,2,3,11};
	int numsSize = sizeof(nums)/sizeof(nums[0]);
	int *a;
	int *b;
	b = sortedSquares(nums, numsSize,a);
	for(int i = 0;i < numsSize;i++)
		printf("%d ",b[i]);
	printf("\n");
    return 0;
}
