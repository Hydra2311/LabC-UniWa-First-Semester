#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	FILE *fp;
	char x;
	int counter=0,acounter=0;

	if (argc != 2)
	{
		fprintf(stderr,"Usage: %s file\n", argv[0]);
		exit(-1);
	}

	fp = fopen(argv[1],"r");
	if (fp == NULL)
	{
		fprintf(stderr,"Read emr: %s\n",argv[1]);
		exit(-2);
	}

	while ((x = fgetc(fp)) != EOF)
	{
		putchar(x);
		counter++;
		if(x == 'a')
		{
			acounter++;
		}
	}

	fclose(fp);
	fprintf(stdout,"Total size: %d\n", counter);
	fprintf(stdout,"Total letters: %d\n",counter-1);
	fprintf(stdout,"a: %d\n",acounter);

	return 0;
}
