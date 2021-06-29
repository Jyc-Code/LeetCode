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

	for(int i = 0,j = 0;i < numsSize;)
	{
		if(i == 0)sum = nums[0];
		else sum += nums[j];

		if(sum >= target)
		{
			if((j - i) == 0)
			{
				min = 1;
				break;
			}
			
			printf("A%d %d\n",i,j);
			sum -= nums[i++];
			if(minF)
				min = MIN(j - i + 1,min);
			else
				min = j - i + 1;

			minF = 1;
			printf("B%d %d\n",i,j);
		}
		else
			j++;
	}
	return min;
}


int main(int argc, char *argv[])
{
	int nums[3] = {1, 4, 4};
	int target = 4;
	int numsSize = sizeof(nums)/sizeof(nums[0]);

	printf("%d\n", minSubArrayLen(target, nums, numsSize));

    return 0;
}
