#include "FIFO.h"
#include <stdio.h>
void FIFO(int *page, int n, int *frame, int nf , char *type)
{
	printf("Replacement Policy = %s\n", type);
	printf("-------------------------------------\n");
	printf("Page   Content of Frames\n");
	printf("----   -----------------\n");
	int i, j = 0, k, available, fCount = 0, fault = 0, flag = 0;
	for (i = 0; i < nf; i++) //initialize frame
		frame[i] = -1;
	for (i = 0; i < n; i++)
	{
		available = 0;
		for (k = 0; k < nf; k++)  //check if page in frame
		{ 
			if (frame[k] == page[i])
				available = 1;
		}
		if (available == 0) //if not in frame(memory)
		{
			if (frame[j] == -1) //Check Empty Places
				flag = 1;  
    
			frame[j] = page[i]; // put page in frame		 	
			j = (j + 1) % nf; // circular
			if (flag == 0)  //Check Fault 
			{				  
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
		flag = 0; 
		fault = 0;
	}
	printf("-------------------------------------\n");
	printf("Number of page faults = %d\n", fCount);
}