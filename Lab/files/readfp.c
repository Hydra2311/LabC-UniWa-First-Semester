#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *fp;
	char **str,buf[300];
	int count=0,i=0;

	fp = fopen("test.txt","r");

	if (fp == NULL)
	{
		fprintf(stderr,"Error\n");
		exit(2);
	}

	while(fgets(buf,sizeof(buf),fp) != NULL)
	{
		count++;
	}

	rewind(fp);

	str = (char **)malloc(sizeof(char *) * count);
	if(str == NULL)
	{
		fprintf(stderr,"Memory allocation failed\n");
		exit(-1);
	}

	for(i=0;i<count;i++)
                str[i] = (char *)malloc(sizeof(char) * 300);
		if (str[i] == NULL) {
            		fprintf(stderr, "Memory allocation failed\n");
            		exit(-1);
		}
	i=0;
	while(i < count && fgets(str[i],300,fp) != NULL)
		{
			i++;
		}

	fclose(fp);
	for(i=0;i<count;i++)
		printf("%s",str[i]);

	for(i=0;i<count;i++)
                free(str[i]);
	free(str);

	return 0;
}
