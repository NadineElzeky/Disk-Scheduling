#include "LRU.h"
#include <stdio.h>

void LRU(int * page, int n, int *frame, int nf, char * type)
{
	printf("Replacement Policy = %s\n", type);
	printf("-------------------------------------\n");
	printf("Page   Content of Frames\n");
	printf("----   -----------------\n");
	int i, j, k, p, available, fCount = 0, flag = 0, temp[nf], flag2 = 0, min, counter = 0, fault = 0;
	for (i = 0; i < nf; i++)
		frame[i] = -1;
	for (i = 0; i < n; i++)
	{ 
		for (j = 0; j < nf; j++)
		{ 
			if (frame[j] == page[i])  //check if page in frame
			{
				counter++; 
				temp[j] = counter; //Put last count of the page

				flag = flag2 = 1;
			}
		}
		if (flag == 0)  //page is not in frame
		{ 
			for (k = 0; k < nf; k++)
			{
			
				if (frame[k] == -1)
				{
					counter++;
					frame[k] = page[i];
					temp[k] = counter;
					flag2 = 1;
					break;
				}
			}
		}
		if (flag2 == 0) //page doesn't exist in frame and replacement will take place
		{ 
			min = temp[0];
			p = 0;
			for (j = 1; j < nf; j++)   //check which has the least counter and will replace it
			{
				if (temp[j] < min)
				{
					min = temp[j];
					p = j;
				}
			}
			counter++;
			frame[p] = page[i];
			fCount++;
			fault = 1;
			temp[p] = counter;
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
		flag = flag2 = fault = 0;
		printf("\n");
	} 
	printf("-------------------------------------\n");
	printf("Number of page faults = %d\n", fCount);
}