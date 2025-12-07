#include <stdio.h>
#define SIZE 10

int * find(int arr[]);

int main()
{
	int arr[SIZE],i,*ptr;

	for (i=0;i<SIZE;i++)
	{
		printf("Dwse akeraio: ");
		scanf("%d",&arr[i]);
	}

	ptr = find(arr);

	if (ptr == NULL)
		printf("No duplicated value was found\n");
	else
		printf("The most duplicated value was %d\n",*ptr);

	return 0;
}

int * find(int arr[])
{
	int i,j,max=0,*maxptr,pb;

	maxptr = NULL;

	for (i=0;i<SIZE-1;i++)
	{
		pb = 0;
		for (j=i+1;j<SIZE;j++)
		{
			if (arr[i]==arr[j])
				pb += 1;
		}
		if (pb > max)
		{
			max = pb;
			maxptr = &arr[i];
		}
	}

	return maxptr;
}



