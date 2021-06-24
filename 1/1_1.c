/************************************************************************
* file name: 1.c
* author: lalala
* mail: 
* created time: 2021年05月11日 星期二 15时23分51秒
*************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/print.h"
#include "../include/uthash/uthash.h"

#define MAX(x,y) (((x) > (y))?(x):(y))
#define MIN(x,y) (((x) < (y))?(x):(y))

typedef struct htnode{
	int key;
	int value;
	UT_hash_handle hh;
}HTTABLE;

void UT_HT_Insert(int iKey, int iValue);
HTTABLE* UT_HT_Search(int Key);
int* twoSum(int* nums, int numsSize, int target, int* returnSize);

HTTABLE * head = NULL;

int main(int argc, char *argv[])
{
	int nums[5]={3,2,95,4,-3};
	int target = 92;
	int numsSize;
	int *returnSize = malloc(sizeof(int));
	int *ret=malloc(sizeof(int)*2);
	numsSize = (int)(sizeof(nums)/sizeof(nums[0]));
	ret = twoSum(nums, numsSize, target, returnSize);
	printf("ret[0]:%d,ret[1]:%d\n", ret[0], ret[1]);
    return 0;
}
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
	HTTABLE* ht;
	for(int i = 0;i <numsSize;i++)
	{
		ht = UT_HT_Search(target - nums[i]);
		if(ht != NULL)
		{
			int *ret = malloc(sizeof(int) * 2);
			ret[0] = ht->value;
			ret[1] = i;
			*returnSize = 2;
			return ret;
		}
		UT_HT_Insert(nums[i], i);
	}

	*returnSize = 0;
	return 0;
}

void UT_HT_Insert(int iKey, int iValue)
{
	HTTABLE* it = UT_HT_Search(iKey);
	if(it == NULL)
	{
		HTTABLE * tmp = malloc(sizeof(HTTABLE));
		tmp->key = iKey;
		tmp->value = iValue;
		HASH_ADD_INT(head, key, tmp);
	}
	else
		it->value = iValue;
}

HTTABLE* UT_HT_Search(int Key)
{
	HTTABLE* tmp;
	HASH_FIND_INT(head, &Key, tmp);
	return tmp;
}
