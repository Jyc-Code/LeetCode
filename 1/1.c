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

typedef struct node{
	int key;
	int value;
	char keyFlag;
}NODE;

typedef struct htnode{
	int key;
	int value;
	char keyFlag;
	NODE * next;
}HTNODE;

typedef struct hashTable{
	int count;
	int size;
	HTNODE ** next;
}HASHTABLE;

void HT_INIT(HASHTABLE *ht, int size)
{
	ht = malloc(sizeof(HASHTABLE));
	ht->size = size;
	ht->count = 0;
	ht->next = calloc(size, sizeof(HTNODE));
}

int HT_Search(HASHTABLE *ht, int Key)
{
	char kFlag;
	int absK = abs(Key);
	kFlag = Key < 0?1 : 0;
	if(ht->next[absK] != NULL)
	{	
		if(ht->next[absK]->next == NULL)
		{
			if(ht->next[absK]->keyFlag == kFlag)
				return ht->next[absK]->value;
			else 
				return -2;
		}
		if(ht->next[absK]->next != NULL)
		{
			if(ht->next[absK]->keyFlag == kFlag)
				return ht->next[absK]->value;
			else if(ht->next[absK]->next->keyFlag == kFlag)
				return ht->next[absK]->next->value;
			else 
				return -3;
		}
	}
	else return -1;
}

void HT_Insert(HASHTABLE *ht, int iKey, int iValue)
{
	char kFlag;
	int absK = abs(iKey);
	kFlag = iKey < 0?1 : 0;
	if(HT_Search(ht, iKey) == -1)
	{
		HTNODE * tmp = malloc(sizeof(HTNODE));
		tmp->next = NULL;
		tmp->keyFlag = kFlag;
		tmp->key = absK;
		tmp->value = iValue;
		ht->next[absK] = tmp;
		ht->count++;
	}
	else 
	{
		NODE * tmp = malloc(sizeof(NODE));
		tmp->keyFlag = kFlag;
		tmp->key = absK;
		tmp->value = iValue;
		ht->next[absK]->next = tmp;
	}
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
	HASHTABLE *ht;
	int hn;

	int numsMax,numsMin;
	numsMax = nums[0];
	numsMin = nums[0];
	for(int i = 1;i < numsSize;i++)
	{
		numsMax = MAX(numsMax, nums[i]);
		numsMin = MIN(numsMin, nums[i]);
	}

	numsMax = MAX(numsMax, target) - MIN(numsMin, target);

	printf("MAX:%d\n", numsMax);

	ht = malloc(sizeof(HASHTABLE));
	ht->count = 0;
	ht->size = numsMax + 1;
	ht->next = calloc(numsMax + 1, sizeof(HTNODE));
	
	for(int i = 0; i < numsSize; i++)
	{
		hn = HT_Search(ht, target - nums[i]);
		if(hn >= 0)
		{
			int *ret = malloc(sizeof(int)*2);
			ret[0] = hn;
			ret[1] = i;
			fprintf(stdout, "ret0:%d\nret1:%d\n",ret[0], ret[1]);
			free(ht->next);
			free(ht);
			*returnSize = 2;
			return ret;
		}
		HT_Insert(ht, nums[i], i);
	}
	*returnSize = 0;
	return 0;
}

int main(int argc, char *argv[])
{
	int nums[5]={3,2,95,4,-3};
	int target = 92;
	int numsSize;
	int *returnSize = malloc(sizeof(int));
	int *ret=malloc(sizeof(int)*2);
	numsSize = (int)(sizeof(nums)/sizeof(nums[0]));
	ret = twoSum(nums, numsSize, target, returnSize);
    return 0;
}
