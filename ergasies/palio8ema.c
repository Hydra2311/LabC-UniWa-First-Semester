#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int * input(int *,int *,int *,int *);
int * doubling(int ,int *);
void print(int *,int);

int main()
{
	int n,a,b;
	int *ptrn,*ptra,*ptrb,*pinakas;
	srand(time(NULL));

	ptrn = &n;
	ptra = &a;
	ptrb = &b;

	pinakas = input(ptrn,ptra,ptrb,pinakas);

	pinakas = doubling(n,pinakas);

	print(pinakas,n);
	free(pinakas);
	return 0;
}

int * input(int *n,int *a,int *b,int *pinakas)
{
	char c;
	int i;

	fprintf(stdout,"Give me limits a,b and the amount n: ");
	scanf("%d%d%d",a,b,n);
	while((c = getchar()) != '\n');

	pinakas = (int *)malloc(*(n) * sizeof(int));
	if (pinakas == NULL)
	{
		fprintf(stderr,"Couldn't allocate memory");
		exit(-1);
	}

	int number = *(n);
	for(i=0;i<number;i++)
	{
		fprintf(stdout,"Give number %d must be between %d and %d: ",(i+1),*(a),*(b));
		scanf("%d",&pinakas[i]);
                while ((pinakas[i] <= *(a)) || (pinakas[i] >= *(b)))
                {
                        fprintf(stdout,"Give number %d must be between %d and %d: ",(i+1),*(a),*(b));
                        scanf("%d",&pinakas[i]);
                }
	}

	return pinakas;
}

int * doubling(int n,int *pinakas)
{
	int amount = (n/2),position,*already,i=0,j=0,is_dupli;

	already = (int *)malloc(amount * (sizeof(int)));
	if (already == NULL)
	{
		fprintf(stderr,"Couldn't allocate memory");
		exit(-3);
	}

while (i < amount)
    {
        do {
            is_dupli = 0;
            position = rand() % n;
            
            for (j = 0; j < i; j++) {
                if (already[j] == position) {
                    is_dupli = 1;
                    break; 
                }
            }
        } while (is_dupli);

        already[i] = position;
        pinakas[position] = pinakas[position] * 2;
        
        i++;
    }

	free(already);
	return pinakas;
}

void print(int *pinakas,int n)
{
	int i,max;
	max = pinakas[0];

	for(i=0;i<n;i++)
	{
		if (pinakas[i] > max)
			max = pinakas[i];
	}


	for(i=0;i<n;i++)
	{
		fprintf(stdout,"Number %d is : %d\n",(i+1),pinakas[i]);
	}
        fprintf(stdout,"The max is: %d\n",max);
}
