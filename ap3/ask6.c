#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n;
	char op;
	float x,y,res = 0.0;

	printf("ΑΡΙΘΜΟΜΗΧΑΝΗ\n");

	printf("Δώσε πρώτο αριθμό: ");
	scanf("%f", &x);

	while (getchar() != '\n');

	printf("Δώσε τον operator: ");
	scanf("%c", &op);

	printf("Δώσε δευτερο αριθμό: ");
        scanf("%f", &y);

	switch (op)
	{
		case '+': res = x + y; break;
		case '-': res = x - y; break;
		case '*': res = x * y; break;
		case '/': if (y != 0.0F) res = x / y; break;
		default : printf("Invalid operator\n"); exit(0);
	}

	if (op == '/' && x==0.0F && y==0.0F)
		printf("Απροσδιόριστη μορφή\n");
	else if (op == '/' && x != 0.0F && y==0.0F)
		printf("Αδύνατη μόρφη\n");
	else
	{
		printf("\n\nΔώσε ακρίβεια δεκαδικών: ");
		scanf("%d", &n);

		printf("\n%.*f %c %.*f = %.*f\n", n, x, op, n, y, n, res);
	}
	
	return 0;
}
