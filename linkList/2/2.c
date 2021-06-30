/************************************************************************
* file name: 2.c
* author: lalala
* mail: 
* 两数相加 链表的形式输入
* 需要考虑进位
* created time: 2021年06月28日 星期一 13时40分16秒
*************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../include/print.h"
#include "../../include/public.h"

struct ListNode {
	int val;
	struct ListNode *next;
	/* struct ListNode *pre; */
};

int getList(struct ListNode* l)
{
	int count = 1;

	while(1)
	{
		if(l->next != NULL)
		{
			l = l->next;
			count++;
		}
		else
			break;
	}
	return count;
}

void upOneOnList(struct ListNode* l)
{
	printf("l->val:%d\n",l->val);
	if(l->next != NULL)
	{
		if(l->next->val + 1 < 10)l->next->val++;
		else
		{
			l->next->val = 0;
			upOneOnList(l->next);
		}
	}
	else
	{
		struct ListNode* tmp = (struct ListNode*)malloc(sizeof(struct ListNode));
		tmp->next = NULL;
		tmp->val = 1;

		l->next = tmp;
		printf("NULL -> val:%d\n", l->next->val);
	}
}

/**
 * Definition for singly-linked list.
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
	char minL = 0,l1F = 0,l2F = 0;
	int count = 0,addF = 0;
	int l1Num,l2Num;
	struct ListNode *Sum;
	struct ListNode *head;

	l1Num = getList(l1);
	l2Num = getList(l2);
	minL = l1Num < l2Num?0 : 1;
	addF = abs(l1Num - l2Num);

	while(1)
	{
		int add;

		if(l1F == 1)l1->val = 0;
		if(l2F == 1)l2->val = 0;
		add = l1->val + l2->val;
			
		printf("%d : %d + %d\n",count, l1->val, l2->val);
		printf("add:%d\n",add);

		if(add < 10)
		{
			struct ListNode *tmp = (struct ListNode*)malloc(sizeof(struct ListNode));
			tmp->next = NULL;
			tmp->val = add;
			if(count == 0)
			{
				Sum = tmp;
				head = Sum;
			}
			else
			{
				Sum->next = tmp;
				Sum = Sum->next;
			}
		}
		else
		{
			struct ListNode *tmp = (struct ListNode*)malloc(sizeof(struct ListNode));
			tmp->next = NULL;
			tmp->val = add%10;
			
			printf("1 count:%d\n",count);
			if(minL == 0)
				upOneOnList(l2);
			else
				upOneOnList(l1);
			printf("2 count:%d\n",count);

			if(count == 0)
			{
				Sum = tmp;
				head = Sum;
			}
			else
			{
				Sum->next = tmp;
				Sum = Sum->next;
			}
			printf("3 count:%d\n\n",count);
		}

		if(l1->next == NULL && l2->next == NULL)break;
		
		if(l1->next != NULL)
		{
			l1F = 0;
			l1 = l1->next;
		}
		else
			l1F = 1;

		if(l2->next != NULL)
		{
			l2F = 0;
			l2 = l2->next;
		}
		else
			l2F = 1;
		count++;
	}
	
	return head;
}


int main(int argc, char *argv[])
{
	struct ListNode* num1 = NULL;
	struct ListNode* num2 = NULL;

	struct ListNode* l1n;
	struct ListNode* l2n;

	struct ListNode* sum;

	int l1[7] = {9,9,9,9,9,9,9};
	int l2[4] = {9,9,9,9};
	for(int i = 0;i < sizeof(l1)/sizeof(l1[0]);i++)
	{
		struct ListNode *tmp = (struct ListNode*)malloc(sizeof(struct ListNode));
		tmp->next = NULL;
		tmp->val = l1[i];
		if(i == 0)
		{
			num1 = tmp;
			l1n = num1;
		}
		else
		{
			num1->next = tmp;
			num1 = num1->next;
		}
	}
	for(int i = 0;i < sizeof(l2)/sizeof(l2[0]);i++)
	{
		struct ListNode *tmp = (struct ListNode*)malloc(sizeof(struct ListNode));
		tmp->next = NULL;
		tmp->val = l2[i];
		if(i == 0)
		{
			num2 = tmp;
			l2n = num2;
		}
		else
		{
			num2->next = tmp;
			num2 = num2->next;
		}
	}

	sum = addTwoNumbers(l1n, l2n);
	do
	{
		printf("%d ",sum->val);
		sum = sum->next;
	}while(sum != NULL);
	printf("\n");
    return 0;
}
