#include <stdio.h>

int main()
{
	int a,b,c;
	printf("Dwse enan ari8mo a: ");
	scanf("%d", &a);

	do
	{
		printf("Dwse enan ari8mo b mikrotero tou a: ");
		scanf("%d", &b);
	}
	while(b >= a);

	do
        {
                printf("Dwse enan ari8mo c mikrotero tou b: ");
                scanf("%d", &c);
	}
        while(c >= b);

	printf("Oi telikoi ari8moi einai %d > %d > %d\n", a, b ,c);
}

	
