#include <stdio.h>

#define N 10
 
int CA[N][N], MA[N][N], AVAIL[N],REQUEST[N][N];
int ALLOC[N] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int TOTAL[N], RUN[N], safe = 0;
int count = 0, i, j, FATAL, resources, processes, k = 1;
int sum,l;
 
int main()
{
	
printf("<< SYNOLO DIERGASIWN >>: ");
	scanf("%d",&processes);
	printf("\n------------------------------------------");
 
    	for (i = 0; i < processes; i++) 
	{
        	RUN[i] = 1;
        	count++;
    	}
	printf("\n<<    SYNOLO PORWN   >>: ");
	scanf("%d",&resources);
	printf("\n------------------------------------------\n");
 
	for (i=0; i<resources; i++)
	{
		printf("MEGETHOS STIGMIOTYPOY %dou POROU : ",i+1);
		scanf("%d",&TOTAL[i]);
	}
	printf("\n------------------------------------------\n");
 
printf("\nCURRENT ALLOCATION\n");
	printf("--------------------\n");
	for (i=0; i<processes; i++)
	{
		for(j=0; j<resources; j++)
		{
			printf("CURRENT ALLOCATION P%d :",i+1);
			scanf("%d",&CA[i][j]);	
		}
		printf("\n");
	}
 
printf("\nMAX ALLOCATION\n");
	printf("------------------\n");
	for (i=0; i<processes; i++)
	{
		for(j=0; j<resources; j++)
		{
			printf("MAX ALLOCATION P%d :",i+1);
			scanf("%d",&MA[i][j]);
		}
		printf("\n");
	}
	//PRINT ARRAYS
	printf("\n\n    CURRENT ALLOCATION          MAX ALLOCATION                REQUEST\n");
	printf("  ----------------------    ----------------------     ----------------------\n");
	for (i=0; i<processes; i++)
	{
		printf("    P%d |",i);
		
		//CURENT ALLOCATION
		int g;
		g=resources;
		for(j=0; j<resources; j++)
		{
			printf(" %d |",CA[i][j]);
		}
		while(g<=4)
			{
				printf("    ");
				g++;	
			}
			
		
		//MAX ALLOCATION
		g=resources;
		for(j=0; j<resources; j++)
		{
			printf("| %d ",MA[i][j]);		
		}
		printf("|");
		while(g<=5)
			{
				printf("     ");	
				g++;
			}
		
		//REQUEST
		g=resources;
		printf("|");
		for(j=0; j<resources; j++)
		{
			l= MA[i][j]-CA[i][j];
			REQUEST[i][j]=l;
			printf(" %d |",REQUEST[i][j]);	
			l=0;
		}
		printf("\n");
		printf("  ----------------------    ----------------------     ----------------------\n");	
		
	}
 		//DESMEYMENOI POROI
		for (i = 0; i < processes; i++) 
		{
        	for (j = 0; j < resources; j++) 
			{
            		ALLOC[j] += CA[i][j];
        	}
    	}
		//EKTYPWSH PORWN
		//DESMEYMENOI POROI
		printf("\nCOMMITED SOURCES     : ");
		for(i=0; i<resources; i++)
		{
			printf("%d, ",ALLOC[i]);
		}
		//SYNOLIKOI POROI
		printf("\nTOTAL SOURCES        : ");
		for(i=0; i<resources; i++)
		{
			printf("%d, ",TOTAL[i]);
		}
		//DIATHESIMOI POROI
    	printf("\nAVAILABLES RESOURCES : ");
    	for (i = 0; i < resources; i++) 
    	{
            AVAIL[i] = TOTAL[i] - ALLOC[i];
    	}
		for(i=0; i<resources; i++)
		{
			printf("%d, ",AVAIL[i]);
		}
 
 
	//ALGORITHMOS TOY TRAPEZITI
	printf("\n\nTHE SEQUENCE IS ["); 
	printf("AVAILABLES: ");
        for (i = 0; i < resources; i++) 
    	{
            printf("%d ", AVAIL[i]);
        }
        printf("] + ");
	  while (count != 0) 
    {
        safe = 0;
        for (i = 0; i < processes; i++) 
        {
            if (RUN[i]) 
            {
                FATAL = 1;
                for (j = 0; j < resources; j++) 
                {
                    if (MA[i][j] - CA[i][j] > AVAIL[j]) 
                    {
                        FATAL = 0;
                        break;
                    }
                }
                if (FATAL) 
                {
                    printf(" P%d", i );//POROS X
                    RUN[i] = 0;
                    count--;
                    safe = 1;

                    for (j = 0; j < resources; j++) 
                    {
                        AVAIL[j] += CA[i][j];
                    }
                    break;
            	}
            }
        }
    	
	
	//EKTYPWSH APOTELESMATWN
    	if (!safe) 
		{
        		printf("\nWARNING!!!....UNSAFE STATE!!!.\n");
        		break;
    	} 
		else 
		{
            		
    		printf("(");

    		for (i = 0; i < resources; i++) 
			{
        		printf("%d ", AVAIL[i]);
    		}
			printf(")--->");
        }
	}
		printf(" THE TOTAL WAS :[");
        for(i=0; i<resources; i++)
				{
					printf("%d ",TOTAL[i]);
				}	
				printf("]");
    	return 0;
}









