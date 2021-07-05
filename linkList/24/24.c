/************************************************************************
* file name: 24.c
* author: lalala
* mail: 
* introduction: 
* created time: 2021年07月03日 星期六 16时59分09秒
*************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../include/lalinklist.h"

MyLinkedList* swapPairs(MyLinkedList* head)
{
	MyLinkedList *per = head;
	MyLinkedList *tmp = head;
	MyLinkedList *link;

	int count = 0;

	if(head == NULL)return head;
	printf("count:%d tmp:%d \n", count, tmp->val);
	while(tmp->next != NULL)
	{
		count++;
		tmp = tmp->next;
		printf("count:%d tmp:%d \n", count, tmp->val);
		if(count%2 == 1)
		{
			per->next = tmp->next;
			tmp->next = per;

			if(count == 1)
				head = tmp;
			else
				link->next = tmp;
			tmp = per;
			printf("head:%d,change:%d\n",head->val,tmp->val);
		}
		else
		{
			link = per;
			per = tmp;
		}
	}
	return head;
}

int main(int argc, char *argv[])
{
	MyLinkedList *head = myLinkedListCreate();
	myLinkedListAddAtHead(head, 1);
	myLinkedListAddAtTail(head, 2);
	myLinkedListAddAtTail(head, 3);
	myLinkedListAddAtTail(head, 4);
	/* printf("get:%d\n", myLinkedListGet(head, 1)); */

	MyLinkedList *tmp = swapPairs(head->next);
	while(tmp->next != NULL)
	{
		printf("%d  ",tmp->val);
		tmp = tmp->next;
	}
	printf("%d \n",tmp->val);

    return 0;
}
