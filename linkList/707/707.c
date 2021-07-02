/************************************************************************
* file name: 707.c
* author: lalala
* mail: 
* introduction: 
* created time: 2021年06月30日 星期三 14时43分39秒
*************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../include/public.h"

typedef struct MyLinkedList_t{
	int val;
	struct MyLinkedList_t *next;
	struct MyLinkedList_t *pre;
} MyLinkedList;

/** Initialize your data structure here. */

MyLinkedList* myLinkedListCreate(void) {
	MyLinkedList * l = malloc(sizeof(MyLinkedList));
	l->next = NULL;
	l->pre = NULL;
	l->val = 0;

	return l;
}

/** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
int myLinkedListGet(MyLinkedList* obj, int index) {
	MyLinkedList *tmp = obj;
	for(int i = 0;i < index;i++)
	{
		if(tmp->next == NULL)return -1;
		tmp = (MyLinkedList*)tmp->next;
	}

	return tmp->val;
}

/** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
	MyLinkedList *tmp = malloc(sizeof(MyLinkedList));
	tmp->pre = NULL;
	tmp->val = val;
	
	if(obj->next == NULL)
	{
		tmp->next = NULL;
		obj->next = tmp;
	}
	else
	{
		tmp->next = obj->next;
		obj->next = tmp;
	}
}

/** Append a node of value val to the last element of the linked list. */
void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
	MyLinkedList *addNode = malloc(sizeof(MyLinkedList));
	addNode->next = NULL;
	addNode->val = val;

	if(obj->next == NULL)
	{
		addNode->pre = obj;
		obj->next = addNode;
		return;
	}
	else
	{
		obj = obj->next;
		while(obj->next != NULL)
			obj = obj->next;

		addNode->pre = obj;
		obj->next = addNode;
	}
}

/** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
	MyLinkedList *tmp = obj;
	int count = 0;
	
	while(tmp->next != NULL && count < index)
	{
		count++;
		tmp = (MyLinkedList*)tmp->next;
	}

	if(tmp->next != NULL || index <= 0)
	{
		MyLinkedList *addNode = malloc(sizeof(MyLinkedList));
		addNode->val = val;
		addNode->next = tmp;
		addNode->pre = tmp->pre;
		
		tmp->pre->next = addNode;
		tmp->pre = addNode;
		
		if(index <= 0)
			obj = addNode;
	}
	else
	{
		if(count < index)
			return;
		else if (count == index)
		{
			MyLinkedList *addNode = malloc(sizeof(MyLinkedList));
			addNode->pre = tmp;
			addNode->val = val;
			addNode->next = NULL;
			
			tmp->next = addNode;
		}
	}
}

/** Delete the index-th node in the linked list, if the index is valid. */
void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
	MyLinkedList *tmp = obj;
	int count = 0;

	while(tmp->next != NULL && count < index)
	{
		count++;
		tmp = tmp->next;
	}
	
	if(tmp->next != NULL)
	{
		if(index > 0)
		{
			tmp->pre->next = tmp->next;
			tmp->next->pre = tmp->pre;
			free(tmp);
		}
		else
		{
			obj->next->pre = NULL;
			obj = obj->next;
			free(tmp);
		}
	}
	else
	{
		if(count == index)
		{
			tmp->pre->next = NULL;
			free(tmp);
		}
	}
}

void myLinkedListFree(MyLinkedList* obj) {
	while(obj->next != NULL)
	{
		obj = obj->next;
		MyLinkedList *tmp = obj->pre;
		free(tmp);
	}
}

/**
 * Your MyLinkedList struct will be instantiated and called as such:
 * MyLinkedList* obj = myLinkedListCreate();
 * int param_1 = myLinkedListGet(obj, index);
 
 * myLinkedListAddAtHead(obj, val);
 
 * myLinkedListAddAtTail(obj, val);
 
 * myLinkedListAddAtIndex(obj, index, val);
 
 * myLinkedListDeleteAtIndex(obj, index);
 
 * myLinkedListFree(obj);
*/
int main(int argc, char *argv[])
{
	MyLinkedList *head = myLinkedListCreate();
	
	myLinkedListAddAtHead(head, 1);
	myLinkedListAddAtTail(head, 3);



	MyLinkedList *tmp = head->next;
	while(tmp != NULL)
	{
		printf("%d  ",tmp->val);
		tmp = tmp->next;
	}
	printf("\n");
    return 0;
}
