#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 1000

int main()
{
	FILE *fp;
	int x[N];
	srand(time(NULL));

	for(int i = 0; i < N; i++)
	{
        	x[i] = rand()%11;
        }

	fp = fopen("test.txt","wb");

	if(fp==NULL)
	{
		fprintf(stderr,"Error\n");
		exit(-1);
	}

	fwrite(x,sizeof(int),N,fp);

	fclose(fp);

	return 0;
}
