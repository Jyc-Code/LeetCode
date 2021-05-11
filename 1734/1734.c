/************************************************************************
* file name: 1734.c
* author: lalala
* mail: 
* created time: 2021年05月11日 星期二 09时42分30秒
*************************************************************************/
#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../print.h"
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* decode(int* encoded, int encodedSize, int* returnSize)
{
	int *perm = malloc(sizeof(int)*(encodedSize + 1));
	int allXOR = 0;
	int temp = 0;
	memset(perm, 0, sizeof(int)*(encodedSize + 1));
	if(encodedSize%2 || encodedSize == 0)
		return 0;
	*returnSize = encodedSize + 1;
	
	for(int i = 1;i <= (encodedSize + 1);i++)
		temp ^= i;

	for(int i = 1;i < encodedSize;i += 2)
		*perm ^= *(encoded+i);
	*perm ^= temp;
	
	for(int i = 0;i < encodedSize;i++)
	{
		allXOR ^= *(encoded + i); 
		*(perm + i + 1) = *perm ^ allXOR; 
	}
	return perm;
}

int main(int argc, char *argv[])
{
	int permSize = 0;
	int encoded[2]={1,3};
	int *perm = (int *)malloc(sizeof(int) * 3);
	perm = decode(encoded, 2, &permSize);
	
	for(int i=0; i < permSize;i++)
		DEBUG("%d\n", *(perm++));
	
	/* free(perm); */
    return 0;
}

