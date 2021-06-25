/************************************************************************
* file name: 149.c
* author: lalala
* mail: 
* created time: 2021年06月24日 星期四 13时25分35秒
*************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "../include/uthash/uthash.h"
#include "../include/print.h"

#define MAX(x,y) (((x) > (y))?(x):(y))
#define MIN(x,y) (((x) < (y))?(x):(y))

typedef struct hashtable{
	int key; // K
	long long int value; // num
	UT_hash_handle hh;
}HT;

long long int la_pow(long long int a, int b);
int maxPoints(int** points, int pointsSize, int* pointsColSize);

long long int max(HT *tmp, int i);
void UT_HT_Insert(int iKey, int iValue);
HT* UT_HT_Search(int Key, int i);

HT* head = NULL;
int wNum = 0;
int main(int argc, char *argv[])
{
	int a;
	int p_tmp[7][2] = {{0,0},{4,5},{7,8},{8,9},{5,6},{3,4},{1,1}};
	int *p[7] = {p_tmp[0], p_tmp[1], p_tmp[2],p_tmp[3],p_tmp[4],p_tmp[5],p_tmp[6]};
    /*
	 * int p_tmp[3][2] = {{0,0},{1,-1},{1,1}};
	 * int *p[3] = {p_tmp[0], p_tmp[1], p_tmp[2]};
     */
	int **points = p;
	int pointsSize = sizeof(p_tmp)/sizeof(p_tmp[0]);
	printf("%d\n", pointsSize);
	a = maxPoints(points, pointsSize, NULL);
	printf("in same line point num : %d\n",a);
    return 0;
}


int maxPoints(int** points, int pointsSize, int* pointsColSize)
{
	int ret = 0,x,y;
	float K;
	int tmp;

	HT* ht = NULL;
	head = NULL;
	
	if(pointsSize <= 2)
		return pointsSize;
	
	for(int i = 0;i < pointsSize;i++)
	{
		tmp = ret;
		wNum = 10;
		do
		{
			if(tmp < 10)
				wNum = 1;
			else
				wNum *= 10;
			tmp /= 10;
		}while(tmp);
		printf("wNum:%d\n", wNum);
		for(int j = i + 1;j < pointsSize;j++)
		{
			x = points[i][0] - points[j][0];
			y = points[i][1] - points[j][1];
			if(x == 0)
				y = 1;
			else if(y == 0)
				x = 1;
			else
			{
				if(y < 0)
				{
					x = -x;
					y = -y;
				}
			}
			K = (float)y/x;
			UT_HT_Insert(K*10, wNum);
			ht = UT_HT_Search(K*10, i);
			ret = MAX(ht->value, ret);
			printf("%d%d ret : %d\n", i, j, ret);
		}
	}
	return ret;
}

long long int la_pow(long long int a, int b)
{
	int tmp = a;
	if(b == 0)
		a = 1;
	else
	{
		for(int i = b;i > 1;i--){
			a *= tmp;
		}
	}
	return a;
}

void UT_HT_Insert(int iKey, int iValue)
{
	/* printf("K:%d,V:%d\n", iKey, iValue); */
	HT* it = UT_HT_Search(iKey, -1);
	if(it == NULL)
	{
		HT * tmp = malloc(sizeof(HT));
		tmp->key = iKey;
		tmp->value = 2 * iValue;
		HASH_ADD_INT(head, key, tmp);
	}
	else
	{
		if((it->value/iValue) == 0)
			it->value += 2 * iValue;
		else
			it->value += iValue;
	}
}

HT* UT_HT_Search(int Key, int i)
{
	static int perF = 0;
	
	HT* tmp;
	HASH_FIND_INT(head, &Key, tmp);	
	
	if(perF != i && i != -1)
		tmp->value = MAX(tmp->value/wNum,tmp->value%wNum );

	perF = i < 0?perF : i;
	return tmp;
}

long long int max(HT *tmp, int i)
{
	static int perF = 0;

	int max = tmp->value;
	
	if(perF != i)
	{
		tmp->value = max;
	}


	perF = i;
	return max;
}


