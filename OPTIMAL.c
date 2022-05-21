#include "OPTIMAL.h"
#include <stdio.h>

void optimal(int * page, int n,int *frame,int nf,char * type)
{
	printf("Replacement Policy = %s\n", type);
	printf("-------------------------------------\n");
	printf("Page   Content of Frames\n");
	printf("----   -----------------\n");
	int i, j, k, p, available, fCount = 0, fault = 0, flag = 0, temp[nf], flag2 = 0, max;
	for (i = 0; i < nf; i++) 
		frame[i] = -1;

	for (i = 0; i < n; i++)
	{ 
		available = 0;
	
		for (k = 0; k < nf; k++)
		{
			if (frame[k] == page[i])
				available = 1;
		}

		if (available == 0)
		{	
			for (k = 0; k < nf; k++)
			{
				if (frame[k] == -1)   //if there is place
				{
					frame[k] = page[i];   // then put it in frame
					flag = 1;   //page is added
					break;
				}
			}

			if (flag == 0)   //means no place in frame
			{
				flag2 = 0;

				for (j = 0; j < nf; j++)
				{
					temp[j] = -1;
					for (k = i + 1; k < n - 1; k++) // check if pages in frames will apear in future or will not
					{ 
						if (frame[j] == page[k])
						{
							temp[j] = k;    // and if it will appear put page index in temp
							break;
						}
					}
				}
				for (j = 0; j < nf; j++)
				{
					if (temp[j] == -1)  //if page will not appear in the future so we will replace it
					{
						p = j;
						flag2 = 1;  //when there is a page that will not appear in future
						break;
					}
				}
				if (flag2 == 0)   //when all of them appear we will replace with the last one appeared in future
				{
					max = temp[0];
					p = 0;
					for (j = 1; j < nf; j++)
					{
						if (temp[j] > max)
						{
							max = temp[j];
							p = j;
						}
					}
				}
				frame[p] = page[i];
				fCount++;
				fault = 1; 
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
		printf("\n");
		available = flag = flag2 = fault = 0;
	}
	printf("-------------------------------------\n");
	printf("Number of page faults = %d\n", fCount);
}