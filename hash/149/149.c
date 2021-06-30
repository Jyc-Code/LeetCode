/************************************************************************
* file name: 149.c
* author: lalala
* mail: 
* 同一直线上的点
* created time: 2021年06月24日 星期四 13时25分35秒
*************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "../../include/uthash/uthash.h"
#include "../../include/print.h"

#define MAX(x,y) (((x) > (y))?(x):(y))
#define MIN(x,y) (((x) < (y))?(x):(y))

typedef struct hashtable{
	int N;
	int key; // K
	long long int value; // num
	UT_hash_handle hh;
}HT;

long long int la_pow(long long int a, int b);
int maxPoints(int** points, int pointsSize, int* pointsColSize);

long long int max(HT *tmp, int i);
void UT_HT_Insert(int iKey, int iValue, int i);
HT* UT_HT_Search(int Key, int i);

HT* head = NULL;
int wNum = 1;
int main(int argc, char *argv[])
{
	int a;
	int p_tmp[93][2] = {{7,3},{19,19},{-16,3},{13,17},{-18,1},{-18,-17},{13,-3},{3,7},{-11,12},{7,19},{19,-12},{20,-18},{-16,-15},{-10,-15},{-16,-18},{-14,-1},{18,10},{-13,8},{7,-5},{-4,-9},{-11,2},{-9,-9},{-5,-16},{10,14},{-3,4},{1,-20},{2,16},{0,14},{-14,5},{15,-11},{3,11},{11,-10},{-1,-7},{16,7},{1,-11},{-8,-3},{1,-6},{19,7},{3,6},{-1,-2},{7,-3},{-6,-8},{7,1},{-15,12},{-17,9},{19,-9},{1,0},{9,-10},{6,20},{-12,-4},{-16,-17},{14,3},{0,-1},{-18,9},{-15,15},{-3,-15},{-5,20},{15,-14},{9,-17},{10,-14},{-7,-11},{14,9},{1,-1},{15,12},{-5,-1},{-17,-5},{15,-2},{-12,11},{19,-18},{8,7},{-5,-3},{-17,-1},{-18,13},{15,-3},{4,18},{-14,-15},{15,8},{-18,-12},{-15,19},{-9,16},{-9,14},{-12,-14},{-2,-20},{-3,-13},{10,-7},{-2,-10},{9,10},{-1,7},{-17,-6},{-15,20},{5,-17},{6,-6},{-11,-8}};
	int *p[93] = {p_tmp[0],p_tmp[1],p_tmp[2],p_tmp[3],p_tmp[4],p_tmp[5],p_tmp[6],p_tmp[7],p_tmp[8],p_tmp[9],p_tmp[10],p_tmp[11],p_tmp[12],p_tmp[13],p_tmp[14],p_tmp[15],p_tmp[16],p_tmp[17],p_tmp[18],p_tmp[19],p_tmp[20],p_tmp[21],p_tmp[22],p_tmp[23],p_tmp[24],p_tmp[25],p_tmp[26],p_tmp[27],p_tmp[28],p_tmp[29],p_tmp[30],p_tmp[31],p_tmp[32],p_tmp[33],p_tmp[34],p_tmp[35],p_tmp[36],p_tmp[37],p_tmp[38],p_tmp[39],p_tmp[40],p_tmp[41],p_tmp[42],p_tmp[43],p_tmp[44],p_tmp[45],p_tmp[46],p_tmp[47],p_tmp[48],p_tmp[49],p_tmp[50],p_tmp[51],p_tmp[52],p_tmp[53],p_tmp[54],p_tmp[55],p_tmp[56],p_tmp[57],p_tmp[58],p_tmp[59],p_tmp[60],p_tmp[61],p_tmp[62],p_tmp[63],p_tmp[64],p_tmp[65],p_tmp[66],p_tmp[67],p_tmp[68],p_tmp[69],p_tmp[70],p_tmp[71],p_tmp[72],p_tmp[73],p_tmp[74],p_tmp[75],p_tmp[76],p_tmp[77],p_tmp[78],p_tmp[79],p_tmp[80],p_tmp[81],p_tmp[82],p_tmp[83],p_tmp[84],p_tmp[85],p_tmp[86],p_tmp[87],p_tmp[88],p_tmp[89],p_tmp[90],p_tmp[91],p_tmp[92]};
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
	int tmp,count = 0;

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
				wNum *= 1;
			else
				wNum *= 10;
			tmp /= 10;
		}while(tmp);
		for(int j = i + 1;j < pointsSize;j++)//pointsSize
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
			UT_HT_Search(K*10000, i);//K的精度
			
			UT_HT_Insert(K*10000, wNum, i);
			ht = UT_HT_Search(K*10000, i);
			ret = MAX(ht->value/wNum, ret);
			printf("%d  %d %d ret : %d\n", i, j,(int)(K*10000), ret);
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

void UT_HT_Insert(int iKey, int iValue, int i)
{
	/* printf("K:%d,V:%d\n", iKey, iValue); */
	HT* it = UT_HT_Search(iKey, -1);
	if(it == NULL)
	{
		/* printf("NULL\n"); */
		HT * tmp = malloc(sizeof(HT));
		tmp->key = iKey;
		tmp->value = 2 * iValue;
		tmp->N = i;
		HASH_ADD_INT(head, key, tmp);
	}
	else
	{	
		if((it->value/iValue) == 0)
			it->value += 2 * iValue;
		else
			it->value += iValue;
		it->N = i;
	}
}

HT* UT_HT_Search(int Key, int i)
{
	/* printf("P:%d K:%d V:%d \n",perF,Key,i); */
	HT* tmp;
	HASH_FIND_INT(head, &Key, tmp);	
	if(tmp != NULL && tmp->N != i && i != -1)
		tmp->value = MAX(tmp->value/wNum,tmp->value%wNum );
	
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


