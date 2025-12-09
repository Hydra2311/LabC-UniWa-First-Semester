#include <stdio.h>
#include <string.h>

char * strcatt(char *, char *);

int main()
{
	char str1[40],str2[40];

	printf("Give me a word: ");
	fgets(str1,40,stdin);

	str1[strcspn(str1, "\n")] = '\0';

	printf("Give me another word: ");
        fgets(str2,40,stdin);

	str2[strcspn(str2, "\n")] = '\0';

	printf("The new word is %s\n", strcatt(str1,str2));

	return 0;
}

char * strcatt(char *x, char *y)
{
	int i=0;
	int start_len = strlen(x);
        int y_len = strlen(y);

	for(i=0;i<y_len;i++)
	{
		x[start_len+i] = y[i];
	}

	x[start_len + i] = '\0';

	return x;
}
