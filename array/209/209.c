/************************************************************************
* file name: 209.c
* author: lalala
* mail: 
* created time: 2021年06月29日 星期二 17时04分11秒
*************************************************************************/
#include <stdio.h>
#include "../../include/public.h"


int minSubArrayLen(int target, int* nums, int numsSize)
{
	char minF = 0;
	int min = 0;
	int sum = 0;

	for(int i = 0,j = 0;i < numsSize && j < numsSize;)
	{
		if(i == j)sum = nums[j];
		else if(minF == 0)sum += nums[j];

		printf("i:%d j:%d sum:%d\n", i, j,sum);
		if(sum >= target)
		{
			if((j - i) == 0)
			{
				min = 1;
				break;
			}
			
			printf("A%d %d\n",i,j);
			if(min != 0)
				min = MIN(j - i + 1,min);
			else
				min = j - i + 1;

			sum -= nums[i++];
			minF = 1;
			printf("B%d %d min:%d 2sum:%d\n",i,j,min,sum);
		}
		else
		{
			minF = 0;
			j++;
		}
	}
	return min;
}

int main(int argc, char *argv[])
{
	int nums[7] = {1, 1, 1, 1, 1,1 ,1};
	int target = 11;
	int numsSize = sizeof(nums)/sizeof(nums[0]);

	printf("%d\n", minSubArrayLen(target, nums, numsSize));

    return 0;
}
