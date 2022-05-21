#include "CLOCK.h"
#include <stdio.h>
void clock(int * page, int n,int *frame,int nf,char * type)
{
	printf("Replacement Policy = %s\n", type);
	printf("-------------------------------------\n");
	printf("Page   Content of Frames\n");
	printf("----   -----------------\n");
	int i, j = 0, p = 0, fCount = 0, flag = 0, bit[nf], fault = 0, k;
	for (i = 0; i < nf; i++)
	{ 
		frame[i] = -1;
		bit[i] = 0;
	}
	for (i = 0; i < n; i++)
	{ 
		for (j = 0; j < nf; j++)
		{ 
			if (frame[j] == page[i]) //If page in frame 
			{
				flag = 1;
				bit[j] = 1;
			}
		}
		if (flag == 0) //No Page in frame 
		{ 
			while (flag != 1)
			{
				
				if (bit[p] == 0 && frame[p] == -1)
				{
					frame[p] = page[i];
					bit[p] = 1;
					flag = 1;
				}
				else if (bit[p] == 0 && frame[p] != -1)
				{ 
					frame[p] = page[i];
					bit[p] = 1;
					flag = 1;
					fCount++;
					fault = 1;
				}
				else
					bit[p] = 0; 
					
				p = (p + 1) % nf; // Circular
			}
		}
		if (fault == 1)
			printf("%02d F   ", page[i]);
		else
			printf("%02d     ", page[i]);
		for (k = 0; k < nf; k++)
		{
			if (frame[k] != -1)
				printf("%02d ", frame[k]);
		}
		flag = fault = 0; //reset
		printf("\n");
	}
	printf("-------------------------------------\n");
	printf("Number of page faults = %d\n", fCount);
}