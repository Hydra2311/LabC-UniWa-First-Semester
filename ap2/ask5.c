#include <stdio.h>
int main()
{
	int num;
	
	printf("Give intenger ");
	scanf("%d", &num);

	printf("%dh %dm %ds\n", num/3600, (num%3600)/60, num%60);

	return 0;
}
