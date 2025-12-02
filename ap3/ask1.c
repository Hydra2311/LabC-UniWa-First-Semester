#include <stdio.h>

int main()
{
	float a,b,x;

	printf("Δώσε δύο πραγματικούς αριθμούς: ");
	scanf("%f%f", &a,&b);

	if (a == 0.0F)
	{
		printf("a cannot be zero\n");
	}
	else
	{
		x = (-b)/a;
		printf("Το αποτέλεσμα είναι %.2f\n", x);
	}

	return 0;
}

