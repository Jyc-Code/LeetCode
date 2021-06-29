/************************************************************************
* file name: 27.c
* author: lalala
* mail: 
* created time: 2021年06月29日 星期二 13时07分45秒
*************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../include/print.h"

/*
 * int removeElement(int* nums, int numsSize, int val)
 * {
 * 	int num = 0,count = 0;
 * 	int *fast = nums;
 * 	int *slow = nums;
 * 
 * 	for(int i = 0;i < numsSize;i++)
 * 	{
 * 		if(*slow == val)
 * 		{
 * 			while(*fast == val)
 * 			{
 * 				if((num + count) < numsSize - 1)
 * 					fast++;
 * 				count++;
 * 				if((num + count) >= numsSize)break;
 * 			}
 *             printf("1 %d count:%d %d\n",num,count, *fast);
 * 		}
 * 
 * 		while(*fast == val)
 * 		{
 * 			if((num + count) < numsSize - 1)
 * 				fast++;
 * 			count++;
 * 			if((num + count) >= numsSize)break;
 *             printf("2 %d count:%d %d\n",num,count, *fast);
 * 		}            
 *  		
 *         *slow = *fast;
 * 		if((num + count) >= numsSize)break;
 *         num++;
 * 
 * 		slow++;
 * 		if((num + count) < numsSize)
 * 			fast++;
 * 	}
 * 
 * 	return num;
 * }
 */
int removeElement(int* nums, int numsSize, int val)
{
    int fast=0;
    int slow=0;
    while(fast<numsSize)
    {
        if(nums[fast++]!=val)
        {
            nums[slow++]=nums[fast-1];
        }
		printf("fast:%d,slow:%d\n",fast,slow);
    }
    return slow;

}

int main(int argc, char *argv[])
{
	int nums[8] = {0, 1, 2, 2, 3, 0, 4, 2};
	int numsSize = sizeof(nums)/sizeof(nums[0]);
	int val = 0;
	int num;

	num = removeElement(nums, numsSize, val);
	printf("num:%d\n",num);
	for(int i = 0;i < num;i++)
		printf("%d ",nums[i]);
	printf("\n");

    return 0;
}
