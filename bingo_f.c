#include <stdio.h> 
#include <conio.h>
#include <stdlib.h>  
#include <time.h>

void elements(int array[9],char player[20])
{
    printf("%s \n",player);
    printf("Enter a value between 1 to 50 and don't repeat the numbers\n");
     for(int i=0;i<9;i++)
		{
			test:
			printf("Enter element %d for the bingo card:",i+1);
		    scanf("%d",&array[i]);
		    if(array[i]>50||array[i]<0)
		    {
		   	printf("You have entererd a invalid input.\n You are exceeding the values!!!\n");
		   	goto test;
			}
            for(int j=0;j<=i-1;j++)
            {
                if(array[i]==array[j])
                {
                    printf("You have entererd a invalid input.\n You are repeating values!!!\n");
		   	        goto test;
                }
            }
		}

}

void bingocard(int array[9],char player[20])
{
    printf("Bingo card of %s:\n",player);
    int k=0;
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			printf("|%d|\t",array[k]);
			k=k+1;
		}
	
		printf("\n\n");
	}
}

void linear(int array1[9],int array2[15])
{
    for(int k=0;k<15;k++)
	{
	for(int i=0;i<9;i++)
	{
		{
			if(array1[i]==array2[k])
            {
                array1[i]=0;
            }
		}
	}
    }
}


int main()
{
    int a[9];
    int b[9];
    int c[15];
    int i,m;
    int count1=0;
    int count2=0;
    char play1[20],play2[20];

    printf("\n\n");
    printf("Heyyyyyy  Welcomeee!!!!!!!!!!\n");
    printf("       BINGOOOOOOOOO GAME\n");
    printf("Letsss beginnn...........\n\n\n\n\n");

    printf("Enter Player 1 name:");
    scanf("%s",&play1);

    elements(a,play1);

    system("cls");
    
    printf("Enter Player 2 name:");
    scanf("%s",&play2);

    elements(b,play2);

    system("cls");

    bingocard(a,play1);

    bingocard(b,play2);

    for(int m=1;m<5;m++)
    {
        for(int i=0;i<15;i++)
        {
            int high=50;
            int low=1;
            c[i] = (rand() % (high + 1 - low)) + low;
        }
        printf("Autogenerating random numbers between 1 to 50\n");
        for(int k=0;k<15;k++)
        {
            printf("|%d|\t",c[k]);
        }
        printf("\n\n\n\n");
        
        linear(a,c);
        
        bingocard(a,play1);
        
        linear(b,c);
        
        bingocard(b,play2);
    }
    
    for(int i=0;i<9;i++)
	{
		if(a[i]==0)
		count1=count1+1;
    }
    
    for(int i=0;i<9;i++)
	{
		if(b[i]==0)
		count2=count2+1;
	}
    
    if(count1>count2)
    {
        printf("Woo Hoo! Good for you! Congrats %s you have won. Congratulationsssss!!!!",play1);
    }
    
    else if(count2>count1)
    {
        printf("Woo Hoo! Good for you! Congrats %s you have won. Congratulationsssss!!!!",play2);
    }
    
    else 
    {
        printf("Oppps its a Draw Match!! Better luck next time.");
    }
    


}