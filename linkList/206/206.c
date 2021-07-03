/************************************************************************
* file name: 206.c
* author: lalala
* mail: 
* introduction: 
* created time: 2021年07月03日 星期六 11时08分04秒
*************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../include/lalinklist.h"

MyLinkedList* reverseList(MyLinkedList* head){
	static MyLinkedList *pre;
	MyLinkedList *next;
	static int count = 0; 

	if(head == NULL && count == 0)return head;
	if(head->next == NULL)
	{
		count = 0;
		head->next = pre;
		return head;
	}

	if(count == 0)
	{
		pre = head;
		head = head->next;
	}
	
	next = head->next;
	head->next = pre;
	if(count == 0)pre->next = NULL;
	pre = head;

	printf("%d pre:%d head:%d\n",count, pre->next->val, pre->val);
	
	if(next == NULL)return head;
	count++;

	return reverseList(next);
}

int main(int argc, char *argv[])
{
	MyLinkedList *head = myLinkedListCreate();
	
	myLinkedListAddAtHead(head, 1);
	/* myLinkedListAddAtTail(head, 2); */
    /*
	 * myLinkedListAddAtTail(head, 3);
	 * myLinkedListAddAtTail(head, 4);
	 * myLinkedListAddAtTail(head, 5);
     */

	head = reverseList(head->next);
	MyLinkedList *tmp = head;
	while(tmp->next != NULL)
	{
		printf("%d  ",tmp->val);
		tmp = tmp->next;
	}
	printf("%d \n",tmp->val);

    return 0;
}
