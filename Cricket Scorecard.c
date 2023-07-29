#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>


struct batting
{
    char name[50];
    int runs,balls;
    float strikerate;
};

struct bowling
{
    char name[50];
    float overs,economy;
    int wickets,runs;
};

struct scoresheet
{
    int innings,extras,runs,wickets;
    char battingteam[50], bowlingteam[50];
    struct batting bat[11];
    struct bowling bowl[11];
};

struct scorecard
{
    char matchname[50],competition[4],venue[50],team1[50],team2[50],toss[6],tosswinner[50],tossoutcome[8],date[11],result[100];
    struct scoresheet *q,score[2];
};


void scoresheetinput(struct scoresheet *q,int j)
{
    int notout,bow,out,chk;
    char chk1;
    
    (q+j)->innings=j+1;
    
    do{
        notout=0;
        printf("\n---BATSMAN DETAILS---");
        printf("\nEnter the Name of the Batting Team: ");
        scanf(" ");
        fgets((q+j)->battingteam,50,stdin);
        for(int k=0;k<11;k++)
        {
            printf("\nEnter the Name of the Batsman: ");
            scanf(" ");
            fgets((q+j)->bat[k].name,50,stdin);
            do
            {
                printf("\nEnter the Number of Runs scored: ");
                scanf(" ");
                scanf("%d",&(q+j)->bat[k].runs);
            }while((q+j)->bat[k].runs<0);

            do
            {
                printf("\nEnter the Number of Balls faced: ");
                scanf(" ");
                scanf("%d",&(q+j)->bat[k].balls);
            }
            while((q+j)->bat[k].balls<0);
            float runs=(q+j)->bat[k].runs,balls=(q+j)->bat[k].balls;
            (q+j)->bat[k].strikerate=runs/balls*100;
            printf("\nIs the Batsman out?(1 for Yes /0 for No): ");
            scanf("%d",&chk);
            if(chk==0)
            {
                notout=notout+1;
            }
            out++;
            if(notout>1)
                break;
        }
        for(int k=out;k<11;k++)
        {
            strcpy((q+j)->bat[k].name,"");
            (q+j)->bat[k].balls=0;
            (q+j)->bat[k].strikerate=0;
            (q+j)->bat[k].runs=0;

        }
        printf("\nDo you want to edit the batsman details(Enter 'e' for edit or press any key to continue)");
        scanf(" ");
        scanf(" %c",&chk1);
    }while(chk1=='e');
    
    do
    {
        printf("\n\n---BOWLER DETAILS---");
        printf("\nEnter the number of bowlers: ");
        scanf(" ");
        scanf("%d",&bow);
        printf("\nEnter the Name of the Bowling Team: ");
        scanf(" ");
        fgets((q+j)->bowlingteam,50,stdin);
        for(int k=0;k<bow;k++)
        {   
            printf("\nEnter the Name of the Bowler: ");
            scanf(" ");
            fgets((q+j)->bowl[k].name,50,stdin);
            do
            {
                printf("\nEnter of Overs Bowled: ");
                scanf(" ");
                scanf("%f",&(q+j)->bowl[k].overs);
            }while((q+j)->bowl[k].overs<0);

            do
            {
                printf("\nEnter the Number of Runs Given: ");
                scanf(" ");
                scanf("%d",&(q+j)->bowl[k].runs);
            }while((q+j)->bowl[k].runs<0);

            do
            {
                printf("\nEnter the Number of Wickets Taken: ");
                scanf(" ");
                scanf("%d",&(q+j)->bowl[k].wickets);
            }while((q+j)->bowl[k].wickets<0);

            (q+j)->bowl[k].economy=(q+j)->bowl[k].runs/(floor((q+j)->bowl[k].overs)+( ((q+j)->bowl[k].overs -floor((q+j)->bowl[k].overs))*10/6));

        }
        for(int k=bow;k<11;k++)
        {
            strcpy((q+j)->bowl[k].name,"");
            (q+j)->bowl[k].overs=0;
            (q+j)->bowl[k].economy=0;
            (q+j)->bowl[k].wickets=0;
            (q+j)->bowl[k].runs=0;

        }
        printf("\nDo you want to edit the bowler details(Enter 'e' for edit or press any key to continue)");
        scanf(" ");
        scanf(" %c",&chk1);
   }while(chk1=='e');
    
    do
    {
        printf("\nEnter the number of Extras: ");
        scanf(" ");
        scanf("%d",&q[j].extras);
    }while((q+j)->extras<0);

    do
    {
        printf("\nEnter the number of Runs scored: ");
        scanf(" ");
        scanf("%d",&q[j].runs);
    }while((q+j)->runs<0);

    do{ 
        printf("\nEnter the number of Wickets Fallen: ");
        scanf(" ");
        scanf("%d",&q[j].wickets);
    }while((q+j)->wickets<0);

}

void input(struct scorecard *p,int i)
{
    char chk;
    do
    {
    printf("\nEnter the Match Name: ");
    scanf(" ");
    fgets((p+i)->matchname,50,stdin);
    printf("\nEnter the Competition(ODI/T20): ");
    scanf(" ");
    fgets((p+i)->competition,4,stdin);
    printf("\nEnter the Venue: ");
    scanf(" ");
    fgets((p+i)->venue,50,stdin);
    printf("\nEnter the name of the First Team: ");
    scanf(" ");
    fgets((p+i)->team1,50,stdin);
    printf("\nEnter the name of the Second Team: ");
    scanf(" ");
    fgets((p+i)->team2,50,stdin);
    printf("\nEnter the Toss turned out(Heads/Tails): ");
    scanf(" ");
    fgets((p+i)->toss,6,stdin);
    printf("\nEnter the Toss Winning Team: ");
    scanf(" ");
    fgets((p+i)->tosswinner,50,stdin);
    printf("\nEnter the Toss Outcome(Batting/Bowling): ");
    scanf(" ");
    fgets((p+i)->tossoutcome,8,stdin);
    printf("\nEnter the Date: ");
    scanf(" ");
    fgets((p+i)->date,11,stdin);
    printf("\nDo you want to edit (Enter 'e' to edit or press any key to continue)");
    scanf(" ");
    scanf(" %c",&chk);
    }while(chk=='e');
    struct scoresheet *q=((p+i)->score);
    do{
        printf("\n\n---First Innings---");
        scoresheetinput(q,0);
        printf("Do you want to edit(Enter 'e' for edit or press any key to continue)");
        scanf(" ");
        scanf(" %c",&chk);
        }while(chk=='e');
    do{
        printf("\n\n---Second Innings---");
        scoresheetinput(q,1);
        printf("\nDo you want to edit(Enter 'e' for edit or press any key to continue)");
        scanf(" ");
        scanf(" %c",&chk);
        }while(chk=='e');
    if( ( (p+i)->score->runs) > ((p+i)->score[1].runs))
    {
        strcpy((p+i)->result,(p+i)->score->battingteam );
    }
    else if(( (p+i)->score->runs) == ((p+i)->score[1].runs))
    {
        strcpy((p+i)->result,"Match Tied");
    }
    else
    {
         strcpy((p+i)->result,(p+i)->score[1].battingteam );       
    }
    printf("\n\nDETAILS ENTERED SUCCESSFULLY");
    
}

void display(struct scorecard *p, int i)
{
    char name[100];
	printf("\n\t\t\t\t        SCORE SHEET DISPLAY\n\t\t\t\t-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-\n\n");
    for(int j=0;j<i;j++)
    {
        printf("%d. %s",j+1,(p+j)->matchname);
    }
	printf("\n\t\t\tEnter the MATCH Name to Display the ScoreSheet :\n\t\t\t\t\t\t ");
	scanf(" ");
    fgets(name,100,stdin);
    for(int j=0;j<=i;j++)
    {
		if(strncmp(name, (p+j)->matchname,strlen(name)-1)==0)                    
		{
			printf("\n______________________________________________________________________________________________________");
			printf("\nMatch Info\n");
			printf("______________________________________________________________________________________________________");
			printf("\nMatch         : %s",(p+j)->matchname);
			printf("Competition   : %s",(p+j)->competition); 
            printf("\nMatch between :\nTeam 1        : %sTeam 2        : %s",(p+j)->team1,(p+j)->team2);       
			printf("Date          : %s",(p+j)->date);
            printf("Venue         : %s",(p+j)->venue);
            printf("Toss          : %s",(p+j)->toss);
            printf("\nToss Winner   : %s",(p+j)->tosswinner);
            printf("\nChosen        : %s\n",(p+j)->tossoutcome);
			printf("______________________________________________________________________________________________________");
			printf("\nInnings       : 1 ");
            printf("\nBatting       : %s",(p+j)->score[0].battingteam);
			printf("Score         : %d-%d\n",(p+j)->score[0].runs,(p+j)->score[0].wickets);
			printf("\n______________________________________________________________________________________________________");
			printf("\nBatsman                                                                        R\tB\tSR\n");
			printf(". . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .");
			for(int i=0;i<11;i++)
			{   
                if((p+j)->score[0].bat[i].balls!=0)
                {
                    printf("\n%s",(p+j)->score[0].bat[i].name);
                    for(int k=0;k<79;k++)
                        printf(" ");
                    printf("%d\t%d\t%.3f\n",(p+j)->score[0].bat[i].runs,(p+j)->score[0].bat[i].balls,(p+j)->score[0].bat[i].strikerate);
                }
                else
                {
                    break;
                }  
			}
			
			printf(". . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .");
			printf("\nBowler                                                                O\t\tW\tR\tECO\n");
			printf(". . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .");
			for(int i=0;i<11;i++)
			{   
                if((p+j)->score[0].bowl[i].overs!=0)
                {
                    printf("\n%s",(p+j)->score[0].bowl[i].name);
                    for(int k=0;k<71;k++)
                        printf(" ");
                    printf("%.1f\t%d\t%d\t%.2f\n",(p+j)->score[0].bowl[i].overs,(p+j)->score[0].bowl[i].wickets,(p+j)->score[0].bowl[i].runs,(p+j)->score[0].bowl[i].economy);
                }

			}
            printf("\nExtras: %d",(p+j)->score[0].extras);


			printf("\n______________________________________________________________________________________________________");
			printf("\nInnings       : 2 ");
            printf("\nBatting       : %s",(p+j)->score[1].battingteam);
			printf("Score         : %d-%d\n",(p+j)->score[1].runs,(p+j)->score[1].wickets);
			printf("\n______________________________________________________________________________________________________");
			printf("\nBatsman                                                                        R\tB\tSR\n");
			printf(". . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .");
			for(int i=0;i<11;i++)
			{   
                if((p+j)->score[1].bat[i].balls!=0)
                {
                    printf("\n%s",(p+j)->score[1].bat[i].name);
                    for(int k=0;k<79;k++)
                        printf(" ");
                    printf("%d\t%d\t%.3f\n",(p+j)->score[1].bat[i].runs,(p+j)->score[1].bat[i].balls,(p+j)->score[1].bat[i].strikerate);
                }
                else
                {
                    break;
                }
                
			}
			
			printf(". . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .");
			printf("\nBowler                                                                O\t\tW\tR\tECO\n");
			printf(". . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .");
			for(int i=0;i<11;i++)
			{   
                if((p+j)->score[1].bowl[i].overs!=0)
                {
				printf("\n%s",(p+j)->score[1].bowl[i].name);
				for(int k=0;k<71;k++)
				    printf(" ");
				printf("%.1f\t%d\t%d\t%.2f\n",(p+j)->score[1].bowl[i].overs,(p+j)->score[1].bowl[i].wickets,(p+j)->score[1].bowl[i].runs,(p+j)->score[1].bowl[i].economy);
                }

			}
            printf("\nExtras: %d",(p+j)->score[1].extras);
            printf("\n______________________________________________________________________________________________________");
            printf("\n\nTHE WINNER IS %s",(p+j)->result);
            printf("________________________________________________________________________________________________________");
            return;			
		}
        printf("\nThe scorecard is not found");

    }

}


int main()
{
    int ch,i=0;
    char chk;
    struct scorecard *p;
    do
    {
        printf("\n1 for Input\n2 for Display\n3 for exit\nEnter the choice: ");
        scanf(" ");
        scanf("%d",&ch);
        if(ch==1)
        {
            do{
                input(p,i);
                printf("\nDo you want to edit the whole scorecard?(Enter 'e' for edit or press any key to continue)");
                scanf(" ");
                scanf(" %c",&chk);
               }while(chk=='e');
            i++;
            
        }
        if(ch==2)
        {
            display(p,i);

        }
    }while(ch!=3);

return 0;    
}