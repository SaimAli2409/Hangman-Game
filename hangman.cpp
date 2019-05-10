/*  Hangman Game  */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<time.h>

void showhangman (int chance);
void CompVsPlayer();
void PlayerVsPlayer();

int main(int argc, char *argv[]) {
	int caseNumber;
	printf("\n-------Welcome to the HANGMAN GAME-------");
	printf("\n\nFor CompVsPlayer press '0' \n\nFor PlayerVsPlayer press '1'");
	printf("\n\nPress the button : ");
	scanf("%d",&caseNumber);
	switch(caseNumber)
	{
		case 0:
			CompVsPlayer();
		case 1:
			PlayerVsPlayer();
	}
	return 0;
}
void CompVsPlayer(){
	char hangmanword[100][100]={"small","psychopath","apple","calculus","computer","beautiful","second","fabricate",
								"oxymoron","static", "collection","artificial","anachronism","chronology","cat","dog",
								"elephant","fish","wrong","jacket","tablet","university","dictionary","hangman",
								"enthusiastic","pessimistic","optimistic"};
	char  guessword[100];
	
	srand(time(NULL));
	int c=rand()%27;
	
	char output[100];
	int wrongtry=6, matchfound=0;
	int counter=0, position=0 , length, i , winner;
	char alphabetfromUser;
	system("cls");

	length=strlen(hangmanword[c]);
	system("cls");
	
	printf("\n\n You will get 5 chances to guess the right word.");
	printf("\n\n  So help the MAN and get....set....GO....!!");
	getchar();
	system("cls");
	
	printf("\n\n   The word has %d alphabets    \n\n",length);
	
	for ( i=0 ; i<length ; i++ )
	{
		output[i]='_';
		output[length]='\0';
		printf(" ");
		printf("%c",output[i]);
	}
	do
	{
		matchfound = 0;
		printf("\n\n\n Enter any alphabet in small case:");
		scanf("%c",&alphabetfromUser);
		if(alphabetfromUser < 'a' || alphabetfromUser > 'z')
		{
			system("cls");
			printf("\n Wrong input TRY AGAIN !!!");
			matchfound = 2;		
		}
		if( matchfound != 2 )
		{
			for( counter=0; counter<length ;counter++)
			{
				if(alphabetfromUser == hangmanword[c][counter])
				{
					matchfound = 1;
				}
			}
		
			if(matchfound == 0)
			{
				printf("\n you have %d tries left ", --wrongtry);
				getchar();
				showhangman(wrongtry);
				getchar();
			}
			else
			{
				for( counter=0 ; counter<length ; counter++)
				{
					matchfound = 0;
					if(alphabetfromUser == hangmanword[c][counter])
					{
						position = counter ;
						matchfound = 1;
					}
					if(matchfound == 1)
					{
						for( i=0 ; i<length ; i++)
						{
							if(i == position)
							{
								output[i] = alphabetfromUser;
							}
							else if (output[i] >= 'a' && output[i] <= 'z')
							{
								continue;
							}
							else
							{
								output[i] = '_';
							}
						}
					
						guessword[position] = alphabetfromUser;
						guessword[length] = '\0';
						winner = strcmp(guessword,hangmanword[c]);
						if(winner == 0)
						{
							printf("\n\n\t CONGRATULATIONS!!!! YOU ARE THE WINNER!!!!!!!");
							printf("\n\n\t The word was %s ", hangmanword[c]);
							printf("\n\n\n\t its EASY HUH....");
							getchar();
							exit(0);
						}
					}	
				}
			}
		}
		printf("\n\n\n");
		for( i=0 ; i<length ; i++)
		{
			printf(" ");
			printf("%c",output[i]);
		}
		getchar();
	}
	while(wrongtry != 0);
	
	if(wrongtry <= 0)
	{
		printf("\n\n\t The word was %s",hangmanword[c]);
		printf("\n\n\t The man is dead you IDIOT!!!!!");
		printf("\n\n\t Better luck next time!!!!");
	}
	getchar();
	
}	

void PlayerVsPlayer(){
	char hangmanword[100], guessword[100];
	char output[100];
	int wrongtry=6, matchfound=0;
	int counter=0, position=0 , length, i , winner;
	char alphabetfromUser;
	system("cls");
	
	printf("\nEnter your word :");	
	scanf("%s",hangmanword);
	printf("\nNow give computer to your friend and see if he/she can CRACK IT !!!");
	getchar();
	length=strlen(hangmanword);
	system("cls");
	
	printf("\n\n You will get 5 chances to guess the right word.");
	printf("\n\n  So help the MAN and get....set....GO....!!");
	getchar();
	system("cls");
	
	printf("\n\n   The word has %d alphabets    \n\n",length);
	
	for ( i=0 ; i<length ; i++ )
	{
		output[i]='_';
		output[length]='\0';
		printf(" ");
		printf("%c",output[i]);
	}

	do
	{
		matchfound = 0;
		printf("\n\n\n Enter any alphabet in small case:");
		scanf("%c",&alphabetfromUser);
		if(alphabetfromUser < 'a' || alphabetfromUser > 'z')
		{
			system("cls");
			printf("\n Wrong input TRY AGAIN !!!");
			matchfound = 2;		
		}
		if( matchfound != 2 )
		{
			for( counter=0; counter<length ;counter++)
			{
				if(alphabetfromUser == hangmanword[counter])
				{
					matchfound = 1;
				}
			}
		
			if(matchfound == 0)
			{
				printf("\n you have %d tries left ", --wrongtry);
				getchar();
				showhangman(wrongtry);
				getchar();
			}
			else
			{
				for( counter=0 ; counter<length ; counter++)
				{
					matchfound = 0;
					if(alphabetfromUser == hangmanword[counter])
					{
						position = counter ;
						matchfound = 1;
					}
					if(matchfound == 1)
					{
						for( i=0 ; i<length ; i++)
						{
							if(i == position)
							{
								output[i] = alphabetfromUser;
							}
							else if (output[i] >= 'a' && output[i] <= 'z')
							{
								continue;
							}
							else
							{
								output[i] = '_';
							}
						}
					
						guessword[position] = alphabetfromUser;
						guessword[length] = '\0';
						winner = strcmp(guessword,hangmanword);
						if(winner == 0)
						{
							printf("\n\n\t CONGRATULATIONS!!!! YOU ARE THE WINNER!!!!!!!");
							printf("\n\n\t The word was %s ", hangmanword);
							printf("\n\n\n\t its EASY HUH....");
							getchar();
							exit(0);
						}
					}	
				}
			}
		}
		printf("\n\n\n");
		for( i=0 ; i<length ; i++)
		{
			printf(" ");
			printf("%c",output[i]);
		}
		getchar();
	}
	while(wrongtry != 0);
	
	if(wrongtry <= 0)
	{
		printf("\n\n\t The word was %s",hangmanword);
		printf("\n\n\t The man is dead you IDIOT!!!!!");
		printf("\n\n\t Better luck next time!!!!");
	}
	getchar();
	exit(0);
}

void showhangman (int chance)
{
	switch (chance)
	{
		case 0:
			system("cls");
		printf("\n\t||===== ");
		printf("\n\t||    | ");
		printf("\n\t||   %cO/",'\\');
		printf("\n\t||    | ");
		printf("\n\t||   / %c",'\\');
		printf("\n\t||      ");
		break;
		
		case 1:
			system("cls");
		printf("\n\t||===== ");
		printf("\n\t||    | ");
		printf("\n\t||   %cO/",'\\');
		printf("\n\t||    | ");
		printf("\n\t||     %c",'\\');
		printf("\n\t||      ");
		break;
		
		case 2:
			system("cls");
		printf("\n\t||===== ");
		printf("\n\t||    | ");
		printf("\n\t||   %cO/",'\\');
		printf("\n\t||    | ");
		printf("\n\t||      ",'\\');
		printf("\n\t||      ");
		break;
		
		case 3:
			system("cls");
		printf("\n\t||===== ");
		printf("\n\t||    | ");
		printf("\n\t||   %cO/",'\\');
		printf("\n\t||      ");
		printf("\n\t||      ",'\\');
		printf("\n\t||      ");
		break;
		
		case 4:
			system("cls");
		printf("\n\t||===== ");
		printf("\n\t||    | ");
		printf("\n\t||   %cO ",'\\');
		printf("\n\t||      ");
		printf("\n\t||      ",'\\');
		printf("\n\t||      ");
		break;
		
		case 5:
			system("cls");
		printf("\n\t||===== ");
		printf("\n\t||    | ");
		printf("\n\t||    O ",'\\');
		printf("\n\t||      ");
		printf("\n\t||      ",'\\');
		printf("\n\t||      ");
		break;
	}
}
