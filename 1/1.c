/************************************************************************
* file name: 1.c
* author: lalala
* mail: 
* created time: 2021年05月11日 星期二 15时23分51秒
*************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../print.h"

typedef struct node{
	int key;
	int value;
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

void HT_Insert(HASHTABLE *ht, int iKey, int iValue)
{
	HTNODE * tmp = malloc(sizeof(HTNODE));
	tmp->key = iKey;
	tmp->value = iValue;
	ht->next[iKey] = tmp;
	ht->count++;
}

HTNODE* HT_Search(HASHTABLE *ht, int Key)
{
	if(ht->next[Key] != NULL)
		return ht->next[Key];
	else return NULL;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
	HASHTABLE *ht;
	HTNODE *hn;
	
	ht = malloc(sizeof(HASHTABLE));
	ht->count = 0;
	ht->size = target;
	ht->next = calloc(target, sizeof(HTNODE));
	
	for(int i = 0; i < numsSize; i++)
	{
		if(target > nums[i])
			hn = HT_Search(ht, abs(target - nums[i]));
		else
			hn = HT_Search(ht, abs(nums[i] - target));

		if(hn != NULL)
		{
			int *ret = malloc(sizeof(int)*2);
			ret[0] = hn->value;
			ret[1] = i;
			fprintf(stdout, "ret0:%d\nret1:%d\n",ret[0], ret[1]);
			*returnSize = 2;
			return ret;
		}
		HT_Insert(ht, abs(nums[i]), i);
	}
	*returnSize = 0;
	return 0;
}

int main(int argc, char *argv[])
{
	int nums[3]={0,2,0};
	int target = 0;
	int numsSize;
	int *returnSize = malloc(sizeof(int));
	int *ret=malloc(sizeof(int)*2);
	numsSize = (int)(sizeof(nums)/sizeof(nums[0]));
	ret = twoSum(nums, numsSize, target, returnSize);
    return 0;
}
