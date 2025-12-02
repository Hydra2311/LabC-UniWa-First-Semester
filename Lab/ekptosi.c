#include <stdio.h>

int main()
{	
	float ekptosi, amount, posoek;
	printf("Δώσε ποσό: ");\
	scanf("%f", &amount);

	if (amount>0 && amount < 100)
	{
		ekptosi = 0;
		posoek = 0;
	}
	else if (amount>=100 && amount<200)
	{
		ekptosi = 5;
		posoek = amount * ekptosi / 100;
	}
	else if (amount>=200 && amount<300)
        {
                ekptosi = 10;
                posoek = amount * ekptosi / 100;
        }
	else if (amount>=300 && amount<400)
        {
                ekptosi = 15;
                posoek = amount * ekptosi / 100;
        }
	else if (amount>=400 && amount<=500)
        {
                ekptosi = 20;
                posoek = amount * ekptosi / 100;
        }

	printf("Έκανε %.2f ευρώ και είχες εκπτωση %.2f%%, το ποσο εκπτωσης ήταν %.2f και πλήρωσες %.2f\n", amount, ekptosi, posoek, amount - posoek); 

	return 0;
}
