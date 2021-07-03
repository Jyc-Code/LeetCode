#ifndef _LALINKLIST_H_
#define _LALINKLIST_H_

typedef struct MyLinkedList_t{
	int val;
	struct MyLinkedList_t *next;
	struct MyLinkedList_t *pre;
} MyLinkedList;

/** Initialize your data structure here. */

MyLinkedList* myLinkedListCreate(void);
int myLinkedListGet(MyLinkedList* obj, int index);
void myLinkedListAddAtHead(MyLinkedList* obj, int val);
void myLinkedListAddAtTail(MyLinkedList* obj, int val);
void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val);
void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index);
void myLinkedListFree(MyLinkedList* obj);

#endif
