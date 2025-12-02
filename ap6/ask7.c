#include <stdio.h>
#define N 3

int magic(int cube[][N]);

int main()
{
	int i, j, sum, ar[N][N];

	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			printf("Give number: ");
			scanf("%d", &ar[i][j]);
		}
	}

	sum = magic(ar);

	if (sum)
		printf("Magic Square and the sum is: %d \n",sum);
	else
		printf("Simple Square\n");

	return 0;
}

int magic(int cube[][N])
{
	int i, j, sum, newsum;

	for(j=0, sum=0; j<3; j++)
		sum += cube[0][j];

	for(i=1;i<N;i++)
        {
                for(j=0,newsum=0;j<N;j++)
                {
                        newsum += cube[i][j];
                }
		if (newsum != sum)
			return 0;
        }

	for(j=0;j<N;j++)
        {
                for(i=0, newsum=0;i<N;i++)
                {
                        newsum += cube[i][j];
                }
		if (newsum != sum)
                        return 0;
        }

	for(i=0,newsum=0;i<N;i++)
	{
		newsum += cube[i][i];
	}

	if (newsum != sum)
        	return 0;

	for(i=0,newsum=0;i<N;i++)
        {
                newsum += cube[i][i];
        }

        if (newsum != sum)
                return 0;

	return sum;
}
