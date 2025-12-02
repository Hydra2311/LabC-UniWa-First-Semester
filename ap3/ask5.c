#include <stdio.h>
#include <math.h>

int main()
{
	float a,b,c,x1,x2,D,x;

	printf("Give numbers: ");
	scanf("%f%f%f", &a, &b, &c);

	D = b*b - 4 * a * c;

	if (D>0)
	{
		x1 = (-b + sqrt(D)) / (2*a);
		x2 = (-b - sqrt(D)) / (2*a);
		printf("Two real roots x1 = %.2f x2 = %.2f\n", x1,x2);
	}
	else if (D==0)
	{		
       		x = (-b)/(2*a);
		printf("Double real roots x1 = x2 = %.2f\n", x);
	}
	else
	{
		printf("No real roots\n");
	}

	return 0;
}

