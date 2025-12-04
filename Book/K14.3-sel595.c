#include <stdio.h>
#include <stdlib.h>
#define S 10
#define NS 20

int * expansion(int *,int , int);

int main()
{
	int i,*ptr,*newptr;

	ptr = (int *)malloc(S*sizeof(int));

	if (ptr == NULL)
	{
		printf("Error:Not a available memory");
		exit(2);
	}

	for (i=0;i<10;i++)
	{
		*(ptr+i)=i+100;
	}

	for (i=0;i<S;i++)
	{
		printf("%d\n", *(ptr+i));
	}

	newptr = expansion(ptr, 10, 20);

	for (i=0;i<10;i++)
        {
                *(newptr+10+i)=i+110;
        }

	for (i=0;i<NS;i++)
        {
                printf("%d\n", *(newptr+i));
        }

	free(newptr);

	return 0;
}

int * expansion(int *ptr,int x, int y)
{
	int *newptr,i;

	newptr = (int *)malloc(y*sizeof(int));

	if (ptr == NULL)
        {
                printf("Error:Not a available memory");
                exit(2);
        }

	for (i=0;i<10;i++)
	{
		*(newptr+i) = *(ptr+i);
	}

	free(ptr);

	return newptr;
}
