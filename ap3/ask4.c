#include <stdio.h>

int main()
{
	int a,b,c,cnt;

	printf("Δώσε τρεις ακεραίους: ");
	scanf("%d%d%d", &a, &b, &c);

	if ((a+b == c) || (a+c == b) || (c+b == a))
	{
	        if (a>=0 && a<=10)
	      		printf("Ειναι αναμεσα 0,10 : %d\n", a);
		if (b>=0 && b<=10)
                        printf("Ειναι αναμεσα 0,10 : %d\n", b);
		if (c>=0 && c<=10)
        		printf("Ειναι αναμεσα 0,10 : %d\n", c);
	}
	else
	{
		printf("Δώσε άλλους τρεις ακεραίους: ");
        	scanf("%d%d%d", &a, &b, &c);
		cnt = 0;

		if (a%6 == 0 || a != 20)
			cnt++;
		if (b%6 == 0 || b != 20)
                        cnt++;	
		if (c%6 == 0 || c != 20)
                        cnt++;
		
		printf("Τόσοι : %d\n", cnt);
	}
	return 0;	
}
