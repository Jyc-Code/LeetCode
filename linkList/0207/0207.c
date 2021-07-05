/************************************************************************
* file name: 0207.c
* author: lalala
* mail: 
* introduction: 
* created time: 2021年07月05日 星期一 10时47分49秒
*************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../include/lalinklist.h"
#include "../../include/public.h"

MyLinkedList *getIntersectionNode(MyLinkedList *headA, MyLinkedList *headB)
{
	MyLinkedList *curA = headA;
	MyLinkedList *curB = headB;
	int countA = 0,countB = 0;
	
	if(headA->next == NULL || headB->next == NULL)return NULL;//需要考虑是否存在虚拟头节点

	while(curA != NULL)
	{
		countA++;
		curA = curA->next;
	}
	
	while(curB != NULL)
	{
		countB++;
		curB = curB->next;
	}
	curA = headA;
	curB = headB;
	
	for(int i = 0;i < abs(countA - countB);i++)
	{
		if(countA > countB)
			curA = curA->next;
		else
			curB = curB->next;
	}
	
	while(curA != NULL) // curA->next 将无法对链表尾进行判断
	{
		if(curA == curB)
			break;
		curA = curA->next;
		curB = curB->next;
	}

	return curA;
}


int main(int argc, char *argv[])
{

    return 0;
}
