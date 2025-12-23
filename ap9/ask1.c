#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void sort_list(char **p,int num);

int main()
{
	int i,num, length;
	char **p,**ar;

	printf("Dwse ari8mo n: ");
	scanf("%d",&num);

	printf("Dwse mege8os: ");
	scanf("%d",&length);

	while (getchar() != '\n');

	p = (char **)malloc(num * sizeof(char *));
	ar = (char **)malloc(num *sizeof(char *));

	for (i=0;i<num;i++)
	{
		p[i] = (char *)malloc((length+1) * sizeof(char));
		ar[i] = (char *)malloc((length+1) * sizeof(char));
		printf("Dwse lejh: ");
		fgets(p[i],length+1,stdin);
		p[i][strcspn(p[i],"\n")] = 0;
	}

	sort_list(p,num);

	for (i=0;i<num;i++)
		printf("%s\n",(p[i]));

	for(i=0; i<num; i++) free(p[i]);
    	free(p);


	return 0;
}

void sort_list(char **ar,int num)
{
	int i,j;
	char *temp;

	for(i=0;i<num-1;i++)
		for(j=num-1;j>i;j--)
			if (strcmp(ar[j-1],ar[j]) > 0)
			{
				temp = ar[j-1];
				ar[j-1] = ar[j];
				ar[j] = temp;
			}
}
