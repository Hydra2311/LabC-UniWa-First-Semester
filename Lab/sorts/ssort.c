#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 100

int main()
{
	int i,j,array[N], min,temp;
	clock_t start,end;
	double timee;

	start = clock();
	srand(time(NULL));

	for(i=0;i<N;i++)
		array[i] = rand() % 100;

	for(i=0;i<N-1;i++)
	{
		min = array[i];
		for(j=i+1;j<N;j++)
		{
			if (array[j]<min)
			{
				temp = array[j];
				array[j] = min;
				min = temp;
			}
		}
	}

	for(i=0;i<N;i++)
		printf("%d\n", array[i]);

	end = clock();
	timee = ((double)end - start) / CLOCKS_PER_SEC;
	printf("time taken : %f\n", timee);

	return 0;
}
