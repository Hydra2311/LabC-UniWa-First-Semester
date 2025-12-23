#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *fp;
	int i;

	fp = fopen("test.txt","w");

	if (fp == NULL)
	{
		fprintf(stderr,"Error\n");
		exit(2);
	}
	for(i=0;i<5;i++)
	{
		fprintf(fp,"Yo\n");
	}

	fclose(fp);


	return 0;
}
