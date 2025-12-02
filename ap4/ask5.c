#include <stdio.h>
#include <math.h>
#define N 10

int main()
{
	float grade[10],sum=0.0,var=0.0,mo,s;
	int i,A,B,C,F;

	for(i=0 ; i < 10 ; i++)
	{
		printf("Grade of student %d: ", i+1);
		scanf("%f", &grade[i]);
		sum += grade[i];
	}
	mo = sum / N;

	for(i=0, var = 0.0 ; i < 10 ; i++)
        {
                var += (grade[i] - mo) * (grade[i] - mo);
        }
	var = var / N;
	s = sqrt(var);

	for(i=0, A=B=C=F=0 ; i < 10 ; i++)
        {
                if (grade[i] >= 0 && grade[i] < mo - s)
			F++;
		else if (grade[i] < mo)
			C++;
		else if (grade[i] < mo + s)
		 	B++;
		else if (grade[i] <= 10)
			A++;

        }
	
	printf("\n\n");
	printf("Mean is : %.1f and Standard Deviation : %.1f\n", mo, s);
	printf("%d Ma8htes phran F, ara to %.1f%%\n", F, 100.0 * F / N);
	printf("%d Ma8htes phran C, ara to %.1f%%\n", C, 100.0 * C / N);
	printf("%d Ma8htes phran B, ara to %.1f%%\n", B, 100.0 * B / N);
	printf("%d Ma8htes phran A, ara to %.1f%%\n", A, 100.0 * A / N);

	return 0;
}
