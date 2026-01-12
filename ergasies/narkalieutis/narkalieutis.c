#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define INF 90000

int ** fillnark(int **,int , int, int );
int ** filldist(int **,int , int, int );

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr,"Exe data files needed\n");
		exit(-3);
	}

	int m,n,k,**box,i,j;
	char c,res;
	FILE *fp;
	srand(time(NULL));

	fprintf(stdout,"Give size M and N: ");
	scanf("%d%d",&m,&n);
	while((c = getchar()) != '\n');
        fprintf(stdout,"Give amount of narks: ");
        scanf("%d",&k);
	while((c = getchar()) != '\n');
	while(k>(m * n))
	{
	        fprintf(stdout,"Amount of narks must be less than size: ");
        	scanf("%d",&k);
        	while((c = getchar()) != '\n');
	}

	box = (int **)malloc(sizeof(int *) * m);
	if (box == NULL)
	{
		fprintf(stderr,"Couldn't allocate memory\n");
		exit(-1);
	}
	for (i=0;i<m;i++)
	{
		box[i] = (int *)malloc(sizeof(int) * n);
		if (box[i] == NULL)
		{
			fprintf(stderr,"Couldn't allocate memory\n");
			exit(-2);
		}
		for(j=0;j<n;j++)
		{
			box[i][j] = INF;
		}
	}

	box = fillnark(box,m,n,k);
	box = filldist(box,m,n,k);

        for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			if(box[i][j] == 0)
				fprintf(stdout,"|*|");
			else
				fprintf(stdout,"|%d|",box[i][j]);
		}
		fprintf(stdout,"\n");
	}

	fprintf(stdout,"Would you like for this board to be saved? [Y/n]\n");
	scanf("%c",&res);
	while((c = getchar()) != '\n');
	if (res == 'Y')
	{
		fp = fopen(argv[1],"w");
		if (fp == NULL)
		{
			fprintf(stderr,"Couldn't open file");
			exit (-5);
		}
	        for(i=0;i<m;i++)
        	{
                	for(j=0;j<n;j++)
                	{
                        	if(box[i][j] == 0)
                                	fprintf(fp,"|*|");
                        	else
                                	fprintf(fp,"|%d|",box[i][j]);
                	}
                	fprintf(fp,"\n");
        	}
		fclose(fp);
	}
	else
	{
		fprintf(stdout,"Thank you for using our app\n");
		for(i=0;i<m;i++)
			free(box[i]);
		free(box);
		exit(1);
	}
        for(i=0;i<m;i++)
        	free(box[i]);
        free(box);
        exit(1);

	return 0;
}

int ** fillnark(int **nark,int m,int n,int k)
{
	int i,j,flag=TRUE,x,y;

	while(k>0)
	{
		while(flag)
		{
			x = rand()%(m);
			y = rand()%(n);

			if(nark[x][y] != 0)
			{
				nark[x][y] = 0;
				flag = FALSE;
			}
		}
		flag = TRUE;
		k = k - 1;
	}

	return nark;
}

int ** filldist(int **dist,int m,int n,int k)
{
	int i,j,l,z;
	int row_dist,col_dist,cur_dist;

	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			if(dist[i][j] == 0)
			{
				for(l=0;l<m;l++)
				{
					for(z=0;z<n;z++)
					{
						row_dist = abs(i-l);
						col_dist = abs(j-z);

						if (row_dist > col_dist)
							cur_dist = row_dist;
						else
							cur_dist = col_dist;

						if (cur_dist < dist[l][z])
							dist[l][z] = cur_dist;
					}
				}
			}
		}
	}

	return dist;
}
