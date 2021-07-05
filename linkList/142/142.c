/************************************************************************
* file name: 142.c
* author: lalala
* mail: 
* introduction: 环形链表2 返回入环的第一个节点  hash
* created time: 2021年07月05日 星期一 11时26分42秒
*************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../include/lalinklist.h"
#include "../../include/uthash/uthash.h"

typedef struct hashtable{
	MyLinkedList *key;
	UT_hash_handle hh;
}HT;

HT *head = NULL;

HT* UT_HT_Search(MyLinkedList* Key)
{
	HT* tmp;
	HASH_FIND_PTR(head, &Key, tmp);	
	return tmp;
}

void UT_HT_Insert(MyLinkedList* iKey)
{
	HT* it = UT_HT_Search(iKey);
	if(it == NULL)
	{
		HT * tmp = malloc(sizeof(HT));
		tmp->key = iKey;
		HASH_ADD_PTR(head, key, tmp);
	}
}

MyLinkedList *detectCycle(MyLinkedList *head)
{
	MyLinkedList *cur = head;

	while(cur != NULL)
	{
		if(UT_HT_Search(cur) != NULL)
			break;

		UT_HT_Insert(cur);
		cur = cur->next;
	}

	return cur;
}

int main(int argc, char *argv[])
{

    return 0;
}
