#include <stdio.h>
#include <math.h>

int primenumber(int x);

int main()
{
	int i,n1,n2;

	printf("Δώσε δύο ακέραιους: ");
	scanf("%d%d", &n1,&n2);

	for(i = n1+1; i < n2; i++)
		if (primenumber(i))
		{
			printf("%d\n", i);
		}

	return 0;
}

int primenumber(int x)
{
	int i=2, flag=1;

	while(i <= sqrt(x) && flag)
	{
		if (x % i == 0)
		{
			flag=0;
		}
		i++;
	}

	return flag;
}
