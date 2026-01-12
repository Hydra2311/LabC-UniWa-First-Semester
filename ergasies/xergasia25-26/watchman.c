#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define TRUE 1
#define FALSE 0

typedef enum{Movie, Series} Typelist;
typedef enum{Planned, Watching, Completed, Dropped} Statuslist;

typedef struct{
	int id;
	char title[50];
	Typelist type;
	char platform[10];
	Statuslist status;
	float rating;
	char note[200];
} Movielist;

void menu();

int main(int argc,char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr,"Error, filename argument must be given after the exe\n");
		exit(-9);
	}
	int ans,i,j,reslen,newnlen,resi,resi2,pl=0,wa=0,com=0,dr=0,net=0,dis=0,pri=0,platlen;
	int count=0,capacity=0;
	float sum=0;
	char c,*stacmp,res[200],*newn,buf[300],*token;
	const char * Types[] = {"Movie","Series"};
	const char * Statuss[] = {"Planned","Watching","Completed","Dropped"};
	FILE *fp;
	Movielist *movie = NULL;
	while (TRUE)
	{
		menu();
		scanf("%d", &ans);
		while((c=getchar()) != '\n');
		while(ans<0 || ans>10)
		{
			fprintf(stdout,"Input must be between 1 and 10");
			scanf("%d", &ans);
			while((c=getchar()) != '\n');
		}
		switch (ans)
		{
			case 1:
			{
				if (capacity == 0)
               	{
                    capacity = 5;
                    movie = (Movielist *)malloc(capacity * sizeof(Movielist));
                }
            	else if (count >= capacity)
				{
					capacity *= 2;
					movie = (Movielist *)realloc(movie,capacity * sizeof(Movielist));
				}
				if (movie == NULL)
				{
					fprintf(stderr,"Couldnt allocate memory");
					exit(-1);
				}
				Movielist newmovie;
				newmovie.id = count + 1;
				fprintf(stdout,"Title: ");
				fgets(newmovie.title,50,stdin);
				newmovie.title[strcspn(newmovie.title,"\n")] = '\0';
				fprintf(stdout,"Type(0.Movie 1.Series): ");
                scanf("%d",&resi);
				newmovie.type = (Typelist) resi;
                while((c = getchar()) != '\n');
				fprintf(stdout,"Platform: ");
                fgets(newmovie.platform,10,stdin);
				newmovie.platform[strcspn(newmovie.platform,"\n")] = '\0';
				fprintf(stdout,"Status(0.Planned,1.Watching,2.Completed,3.Dropped): ");
                scanf("%d",&resi);
				newmovie.status = (Statuslist) resi;
				while((c = getchar()) != '\n');
				fprintf(stdout,"Rating: ");
				scanf("%f", &newmovie.rating);
				while((c = getchar()) != '\n');
				fprintf(stdout,"Note: ");
                fgets(newmovie.note,200,stdin);
                newmovie.note[strcspn(newmovie.note,"\n")] = '\0';
				movie[count] = newmovie;
				count ++;
				fprintf(stdout,"Επιτυχής προσθήκη\n");
				break;
			}
			case 2:
			{
				for(i=0;i<count;i++)
				{
					fprintf(stdout,"id: %d\n",movie[i].id);
					fprintf(stdout,"Title: %s\n",movie[i].title);
					fprintf(stdout,"Type: %s\n",Types[movie[i].type]);
					fprintf(stdout,"Platform: %s\n",movie[i].platform);
					fprintf(stdout,"Status: %s\n",Statuss[movie[i].status]);
					fprintf(stdout,"Rating: %.2f\n",movie[i].rating);
					fprintf(stdout,"Note: %s\n",movie[i].note);
				}
				break;
			}
			case 3:
			{
				for(i=0;i<count;i++)
				{
					if (movie[i].status == Completed)
						fprintf(stdout,"Completed: %s\n",movie[i].title);
                    if (movie[i].status == Planned)
                        fprintf(stdout,"Planned: %s\n",movie[i].title);
                    if (movie[i].status == Watching)
                        fprintf(stdout,"Watching: %s\n",movie[i].title);
                    if (movie[i].status == Dropped)
                        fprintf(stdout,"Dropped: %s\n",movie[i].title);
				}
				break;
			}
			case 4:
			{
                fprintf(stdout,"Search: ");
                fgets(res,200,stdin);
                res[strcspn(res, "\n")] = '\0';
                reslen = strlen(res);
                for(i=0;i<reslen;i++)
                {
                    res[i] = toupper((unsigned char)res[i]);
                }
                for(j=0;j<count;j++)
                {
                    newn = (char *)malloc(strlen(movie[j].title) * sizeof(char)+1);
                    if (newn == NULL)
					{
						fprintf(stderr,"Couldn't allocate memory\n");
						exit(-1);
					}
                    strcpy(newn,movie[j].title);
                    newnlen = strlen(newn);
                    for(i=0;i<newnlen;i++)
                    {
                        newn[i] = toupper((unsigned char)newn[i]);
                    }
                    if (strstr(newn,res) != NULL)
                    {
                        fprintf(stdout,"This the movie/series: %s\n", movie[j].title);
                    }
					free(newn);
				}
				break;
			}
			case 5:
			{
                fprintf(stdout,"Give id: ");
                scanf("%d", &resi);
                while ((c = getchar()) != '\n');
                for(i=0;i<count;i++)
                {
                    if(i+1 == resi)
                    {
                        fprintf(stdout,"1.Status, 2.Rating, 3.Note\n");
                        scanf("%d", &resi2);
                        while ((c = getchar()) != '\n');
                        switch (resi2)
                        {
                            case 1:
                                fprintf(stdout,"New status(0.Planned,1.Watching,2.Completed,3.Dropped): ");
                                scanf("%d", &resi2);
								movie[i].status = (Statuslist) resi2;
                                while((c = getchar()) != '\n');
                                break;
                            case 2:
                                fprintf(stdout,"New rating: ");
                                scanf("%f",&movie[i].rating);
								while ((c = getchar()) != '\n');
                                break;
                            case 3:
                                fprintf(stdout,"New note: ");
                                fgets(movie[i].note,200,stdin);
                                movie[i].note[strcspn(movie[i].note,"\n")] = '\0';
                                break;
                            default:
                            	fprintf(stdout,"Invalid input\n");
                                break;
						}
					}
				}
				break;
			}
			case 6:
			{
                fprintf(stdout,"1.Πλήθος ανα stat, 2.Πλήθος ανα plat, 3.Μέσος όρος completed\n");
                scanf("%d",&resi);
				while ((c = getchar()) != '\n');
                if (resi == 1)
                {
                	for(j=0;j<count;j++)
                    {
                        if(movie[j].status == Planned)
                            pl++;
                        else if(movie[j].status == Watching)
                            wa++;
                        else if(movie[j].status == Completed)
                            com++;
                    	else if(movie[j].status == Dropped)
                            dr++;
                    }
                    fprintf(stdout,"Planned: %d\nWatched: %d\nCompleted: %d\nDropped: %d\n",pl,wa,com,dr);
					pl = 0;
					wa = 0;
					com = 0;
					dr = 0;
                }
                else if(resi == 2)
                {
                	for(i=0;i<count;i++)
                	{
                        platlen=strlen(movie[i].platform);
                        newn = (char *)malloc(platlen+1);
                        if(newn == NULL)
						{
							fprintf(stderr,"Couldn't allocate memory");
							exit(-2);
						}
                        strcpy(newn,movie[i].platform);
                        for(j=0;j<platlen;j++)
                        {
                            newn[j] = toupper((unsigned char)(newn[j]));
                        }
                    	if(strcmp(newn,"NETFLIX") == 0)
                            net++;
                        else if(strcmp(newn,"DISNEY") == 0)
                            dis++;
                        else if(strcmp(newn,"PRIME") == 0)
                            pri++;
                        else
                            fprintf(stdout,"Not known platform\n");
						free(newn);
                    }
                    fprintf(stdout,"Netflix: %d\nDisney: %d\nPrime: %d\n",net,dis,pri);
					net = 0;
					dis = 0;
					pri = 0;
                }
                else
                {
					if(count==0)
					{
						fprintf(stderr,"Can't divide with 0");
						exit(-3);
					}
					else
					{
                        for(j=0;j<count;j++)
                        {
							if(movie[j].status == Completed)
                            	sum += movie[j].rating;
                        }
                    	fprintf(stdout,"The average is: %.2f\n", (float)sum/count);
					}
                }
				break;
			}
			case 7:
			{
				fprintf(stdout,"1.Ανά τίτλο,2.Κατά βαθμολογία\n");
				scanf("%d",&resi);
				while ((c=getchar()) != '\n');
                Movielist *tempmovie = (Movielist *)malloc(sizeof(Movielist)*count);
            	if(tempmovie == NULL)
                {
                    fprintf(stderr,"Couldn't allocate memory");
                    exit(-4);
                }
                for(i=0;i<count;i++)
                {
                    tempmovie[i] = movie[i];
                }
                Movielist temptemp;
				switch (resi)
				{
					case 1:
					{
						for(i=0; i < count - 1;i++)
						{
							for(j=0; j < count - i - 1;j++)
							{
								if(strcmp(tempmovie[j].title,tempmovie[j+1].title) < 0)
								{
									temptemp = tempmovie[j];
									tempmovie[j] = tempmovie[j+1];
									tempmovie[j+1] = temptemp;
								}
							}
						}
						for(i=0;i<count;i++)
						{
							fprintf(stdout,"id: %d\n",tempmovie[i].id);
                        	fprintf(stdout,"Title: %s\n",tempmovie[i].title);
                            fprintf(stdout,"Type: %s\n",Types[tempmovie[i].type]);
                            fprintf(stdout,"Platform: %s\n",tempmovie[i].platform);
                            fprintf(stdout,"Status: %s\n",Statuss[tempmovie[i].status]);
                            fprintf(stdout,"Rating: %.2f\n",tempmovie[i].rating);
                            fprintf(stdout,"Note: %s\n",tempmovie[i].note);
						}
						free(tempmovie);
						break;
					}
					case 2:
					{
                        for(i=0; i < count - 1;i++)
                        {
                            for(j=0; j < count - i - 1;j++)
                            {
                                if(tempmovie[j].rating < tempmovie[j+1].rating)
                                {
                                    temptemp = tempmovie[j];
                                    tempmovie[j] = tempmovie[j+1];
                                    tempmovie[j+1] = temptemp;
                                }
                            }
                        }
                        for(i=0;i<count;i++)
                        {
                            fprintf(stdout,"id: %d\n",tempmovie[i].id);
                            fprintf(stdout,"Title: %s\n",tempmovie[i].title);
                            fprintf(stdout,"Type: %s\n",Types[tempmovie[i].type]);
                            fprintf(stdout,"Platform: %s\n",tempmovie[i].platform);
                            fprintf(stdout,"Status: %s\n",Statuss[tempmovie[i].status]);
                            fprintf(stdout,"Rating: %.2f\n",tempmovie[i].rating);
                            fprintf(stdout,"Note: %s\n",tempmovie[i].note);
                        }
                        free(tempmovie);
						break;
                    }
					default: free(tempmovie); break;
				break;
				}
			}
			case 8:
			{
				fp = fopen(argv[1],"w");
				if (fp == NULL)
				{
					fprintf(stderr,"Couldn't open file");
					exit(-6);
				}
				for(i=0;i<count;i++)
				{
                	fprintf(fp,"%d;",movie[i].id);
                    fprintf(fp,"%s;",movie[i].title);
                    fprintf(fp,"%d;",movie[i].type);
                    fprintf(fp,"%s;",movie[i].platform);
                    fprintf(fp,"%d;",movie[i].status);
                    fprintf(fp,"%.1f;",movie[i].rating);
                    fprintf(fp,"%s;\n",movie[i].note);
				}
				fclose(fp);
				break;
			}
			case 9:
			{
				fp = fopen(argv[1],"r");
				if (fp == NULL)
				{
					fprintf(stderr,"Couldn't open file");
					exit(-7);
				}
				while(fgets(buf,300,fp) != NULL)
				{
					buf[strcspn(buf,"\n")] = '\0';

					if (count >= capacity)
					{
						if (capacity == 0)
						{
							capacity = 5;
						}
						else
						{
							capacity *= 2;
						}
                        Movielist *mmovie = (Movielist *)realloc(movie,sizeof(Movielist) * capacity);
                        if (mmovie == NULL)
                        {
                            fprintf(stderr,"Couldn't allocate memory\n");
                            exit(-8);
                        }
                        movie = mmovie;
					}

					token = strtok(buf,";");
					if (token != NULL) movie[count].id = atoi(token);
					token = strtok(NULL, ";");
        			if (token != NULL) strcpy(movie[count].title, token);
                	token = strtok(NULL, ";");
                    if (token != NULL) movie[count].type = atoi(token);
                    token = strtok(NULL, ";");
                    if (token != NULL) strcpy(movie[count].platform, token);
                    token = strtok(NULL, ";");
                    if (token != NULL) movie[count].status = atoi(token);
                    token = strtok(NULL,";");
                    if (token != NULL) movie[count].rating = atof(token);
                    token = strtok(NULL, ";");
                    if (token != NULL) strcpy(movie[count].note, token);

					count++;
				}
				fclose(fp);
				break;
			}
			case 10:
			{
				fprintf(stdout,"Thank you for using our app\n");
				if (movie != NULL)
					free(movie);
				exit(1);
				break;
			}
		}
	}
	return 0;
}

void menu()
{
        printf("1. Προσθήκη τίτλου\n2. Εμφάνιση όλων\n3. Φιλτράρισμα ανά κατάσταση\n");
        printf("4. Αναζήτηση με λέξη στον τίτλο\n5. Ενημέρωση εγγραφής\n");
        printf("6. Στατιστικά\n7. Ταξινόμηση\n8. Αποθήκευση σε αρχείο\n");
        printf("9. Φόρτωση από αρχείο\n10. Έξοδος\n");
}
