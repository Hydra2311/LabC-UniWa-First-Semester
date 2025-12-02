#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define N 100

int main()
{
	int array[N],i,j,temp;
	clock_t start,end;
	double timee;

	start = clock();
	srand(time(NULL));

	for(i=0;i<N;i++)
	{
		array[i] = rand() % 100;
	}

	for(i=1;i<N; i++)
	{
		for(j=N-1; j>=i; j--)
		{
			if (array[j-1] > array[j])
			{
				temp = array[j-1];
				array[j-1] = array[j];
				array[j] = temp;
			}
		}
	}

        for(i=0;i<N;i++)
		printf("%d\n",array[i]);

	end = clock();
	timee = ((double)end - start) / CLOCKS_PER_SEC;
	printf("time taken : %f\n", timee);

	return 0;
}
