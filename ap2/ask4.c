#include <stdio.h>

int main()
{
	int succ, fail;
	printf("Success:");
	scanf("%d", &succ);

	printf("Fail:");
        scanf("%d", &fail);

	printf("Succeded : %.2f%%\n", 100.0 * succ / (succ + fail));
	printf("Failed : %.2f%%\n", 100.0 * fail / (succ + fail));

	return 0;
}
