#include <stdio.h>

int main(int argc, char *argv[])
{
	int i;

	fprintf(stdout,"The number of arguements is %d\n", argc);
	for(i=0;i<argc;i++)
	{
		fprintf(stdout,"This is the arguement %d: %s\n",i,argv[i]);
	}

	return 0;
}
