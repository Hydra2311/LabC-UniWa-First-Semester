#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define YES 1
#define NO 0
#define MAX 5

int main()
{
	int ran, tries, numg= -1, found, cont;
	srand(time(NULL));
	do
	{
		ran = rand()%101;
		for(tries = 0,found = NO; (tries < 5 && found == NO); tries++)
		{
			printf("Guess a number from 0 to 100: ");
			scanf("%d", &numg);

			if (numg == ran)
				found = YES;
			else if (numg > ran)
				printf("Lower\n");
			else if (numg < ran)
				printf("Higher\n");
		}
		if (found)
			printf("You won!,found in %d guesses\n", tries);
		else	
			printf("You lost :(\n");

		printf("Do you want to play again?(1 for YES/0 for NO) ");
		scanf(" %d", &cont);
	}
	while (cont == YES);
	return 0;
}	
