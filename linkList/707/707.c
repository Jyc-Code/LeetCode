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
	if(obj->next == NULL)
		return -1;
	else
		obj = obj->next;
	for(int i = 0;i < index;i++)
	{
		if(obj->next == NULL)return -1;
		obj = obj->next;
	}

	return obj->val;
}

/** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
	MyLinkedList *addNode = malloc(sizeof(MyLinkedList));
	addNode->pre = obj;
	addNode->val = val;
	
	if(obj->next == NULL)
	{
		addNode->next = NULL;
		obj->next = addNode;
	}
	else
	{
		addNode->next = obj->next;
		obj->next->pre = addNode;//原头节点前指针，容易忘记
		obj->next = addNode;
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
	int count = 0;

	if(obj->next == NULL || index <= 0)
	{
		if(index <= 0)
		{
			myLinkedListAddAtHead(obj, val);
			return;
		}
		else
			return;
	}

	obj = obj->next;
	while(obj->next != NULL && count < index)
	{
		count++;
		obj = obj->next;
	}

	if(obj->next != NULL || count == index)
	{
		MyLinkedList *addNode = malloc(sizeof(MyLinkedList));
		addNode->val = val;
		addNode->next = obj;
		addNode->pre = obj->pre;
		
		obj->pre->next = addNode;
		obj->pre = addNode;
	}
	else
	{
		count++;//链表总长度(包括虚拟头节点)
		if(count == index)
		{
			MyLinkedList *addNode = malloc(sizeof(MyLinkedList));
			addNode->val = val;
			addNode->next = NULL;
			addNode->pre = obj;

			obj->next = addNode;
		}
	}
}

/** Delete the index-th node in the linked list, if the index is valid. */
void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
	int count = 0;

	if(obj->next == NULL || index < 0)
		return;
	else
		obj = obj->next;
	
	while(obj->next != NULL && count < index)
	{
		count++;
		obj = obj->next;
	}
	
	if(obj->next != NULL)
	{
		obj->pre->next = obj->next;
		obj->next->pre = obj->pre;
		free(obj);
	}
	else
	{
		if(count == index)
		{
			obj->pre->next = NULL;
			free(obj);
		}
	}
}

void myLinkedListFree(MyLinkedList* obj) {
	if(obj->next == NULL)
		return;
	else
		obj = obj->next;
	while(obj->next != NULL)
	{
		obj = obj->next;
		MyLinkedList *delNode = obj->pre;
		free(delNode);
	}
	free(obj);
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
	myLinkedListAddAtHead(head, 7);
	myLinkedListAddAtHead(head, 2);
	myLinkedListAddAtHead(head, 1);
	myLinkedListAddAtIndex(head, 3, 0);
	myLinkedListDeleteAtIndex(head, 2);
	myLinkedListAddAtHead(head, 6);
	myLinkedListAddAtTail(head, 4);
	/* printf("get:%d\n", myLinkedListGet(head, 1)); */
	MyLinkedList *tmp = head->next;
	while(tmp->next != NULL)
	{
		printf("%d  ",tmp->val);
		tmp = tmp->next;
	}
	printf("%d \n",tmp->val);
    return 0;
}
