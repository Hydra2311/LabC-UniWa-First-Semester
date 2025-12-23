#include <stdio.h>
#include <stdlib.h>
#define N 1000

int main()
{
	FILE *fp;
	int *x,i;

	fp = fopen("test.txt","rb");

	if(fp == NULL)
	{
		fprintf(stderr,"Error!");
		exit(-1);
	}

	x = (int *)malloc(sizeof(int) * N);
	if(x == NULL)
	{
		fprintf(stderr,"Memory allocation failed\n");
		exit(-1);
	}

	fread(x,sizeof(int),N,fp);

	fclose(fp);

	for(i=0;i<N;i++)
	{
		printf("%d\n",x[i]);
	}

	free(x);
	return 0;
}
