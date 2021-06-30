/************************************************************************
* file name: 704.c
* author: lalala
* mail: 
* array 二分法
* created time: 2021年06月29日 星期二 09时16分04秒
*************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../include/print.h"
#include "../../include/public.h"


int search(int* nums, int numsSize, int target)
{
	int mark = -1;
	int minM, maxM;
	int i = 0;
	minM = 0;
	maxM = numsSize - 1;
	while(nums[(minM + maxM)/2] != target && i <= (numsSize/2 + 1))//!!!! 边界
	{
		if(target > nums[(minM + maxM)/2])
		{
			if((minM + maxM)%2 == 0)
				minM = (minM + maxM)/2;
			else
				minM = (minM + maxM)/2 + 1;
		}
		else
		{
			if((minM + maxM)%2 == 0)
				maxM = (minM + maxM)/2;
			else
				maxM = (minM + maxM)/2 + 1;
		}
		i++;
		printf("minM : %d maxM : %d\n", minM, maxM);
	}
	if(i <= (numsSize/2 + 1))mark = (minM + maxM)/2;
	printf("mark: %d\n", mark);
	return mark;
}

int main(int argc, char *argv[])
{
	int nums[3] = {-1,0,5};
	int target = 5;
	int numsSize = sizeof(nums)/sizeof(nums[0]);
	printf("size:%d\n", numsSize);
	search(nums, numsSize, target);

    return 0;
}
