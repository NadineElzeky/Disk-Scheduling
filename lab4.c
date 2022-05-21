#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "HEADERS.h"
#define array_size 10
char type[20];
int *page;
int nf; // =3
int *frame;
int n = 0;


int main()
{
	scanf("%d", &nf);
	scanf("%s", type);
	int i = -1;
	page = (int *)malloc(array_size * sizeof(int));
	int m = array_size - 1; 
	do
	{
		i++;
		if (i > m)
		{
			page = (int *)realloc(page, (m + 1 + array_size) * sizeof(int));
			m += array_size;
		}
		scanf("%d", &page[i]);
	} while (page[i] != -1);
	n = i; 
	frame = (int *)malloc(nf * sizeof(int));
	if (strcmp(type, "FIFO") == 0)
		FIFO(page,n,frame,nf,type);
	else if (strcmp(type, "OPTIMAL") == 0)
		optimal(page,n,frame,nf,type);
	else if (strcmp(type, "LRU") == 0)
		LRU(page,n,frame,nf,type);
	else if (strcmp(type, "CLOCK") == 0)
		clock(page,n,frame,nf,type);
	else
		printf("Unavailable Page Replacement Algorithm");
	free(page);
	return 0;
}
