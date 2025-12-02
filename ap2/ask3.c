#include <stdio.h>
#define NUM 10
int main()
{
	const int a = 2 * NUM;
	int b,c;
	b = NUM * NUM / 4;
	c = NUM / 4 * NUM;

	printf("%d\n", b - c);

	return 0;
}
