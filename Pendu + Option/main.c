#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <string.h>
#include "dico.h"

char readChar(void);
int win(int findLetter[]);
int searchLetter(char letter, char secretWord[], int findLetter[]);

int main(int argc, const char * argv[])
{
    int i = 0;
    int lives = 10;
    int *findLetter = NULL;
    char letter = 0;
    char secretWord[100] = {0};
    long wordSize = 0;
    int newGame = 0;
    int ChoiceMode = 0;
    int NBErreur = 0;

    printf("Bienvenue dans le Jeu du Pendu !\n");

Debut:
    NBErreur = 0;
    printf("\n\n Mode multi = 1    Mode solo = 2   ");
    scanf("%d",&ChoiceMode);

    if (ChoiceMode == 1)
    {


        printf("\n\n Joueur 1 choisissez un Mot (/!\\ ECRIRE LE MOT EN MAJUSCULE ):  ");
        scanf("%s",&secretWord);

        wordSize = strlen(secretWord);

        //char* strchr(secretWord,findLetter);
       findLetter = malloc(wordSize * sizeof(int));

    } else if (ChoiceMode == 2)
    {

        if (!piocherMot(secretWord ))
        {
            exit(0);
        }

        wordSize = strlen(secretWord);

        findLetter = malloc(wordSize * sizeof(int));
    }else




    if (findLetter == NULL)
    {
        exit(0);
    }

    for (i = 0 ; i < wordSize ; i++)
    {
        findLetter[i] = 0;
    }

    while (lives > 0 && !win(findLetter))
    {
        printf("\n\nIl vous reste %d coups a jouer", lives);
        printf("\nQuel est le mot secret ? ");

        for (i = 0 ; i < wordSize ; i++)
        {
            if (findLetter[i])
            {
                printf("%c", secretWord[i]);
            }
            else
            {
                printf("*");
            }
        }

        printf("\nProposez une lettre : ");
        letter = readChar();
        int lives2 = lives;

        if (!searchLetter(letter, secretWord, findLetter))
        {
            lives--;
        }

        if(lives != lives2 )
        {

                        NBErreur++;
                AFFPendu(NBErreur);
        }
    }

    if (win(findLetter))
    {
        printf("\n\nGagne ! Le mot secret etait bien : %s", secretWord);
    }
    else
    {
        printf("\n\nPerdu ! Le mot secret etait : %s", secretWord);
    }

    free(findLetter);

    printf("\n\n Une autre partie ??    1 = Oui    2 = Non");
    scanf("%d",&newGame);

    if (newGame == 1)
    {
        printf("\n\n C'est repartie");
        lives = 10;
        goto Debut;
    }
    else
    {
        printf("\n\n Merci d'avoir joue");
    }

    return 0;
}

char readChar()
{
    char charLetter = 0;

    charLetter = getchar();
    charLetter = toupper(charLetter);


    while (getchar() != '\n');

    return charLetter;
}

int win(int findLetter[])
{
    int i = 0;
    int playerWin = 1;

    for (i = 0 ; i < 10 ; i++)
    {
        if (findLetter[i] == 0)
            playerWin = 0;
    }

    return playerWin;
}

int searchLetter(char letter, char secretWord[], int findLetter[])
{
    int i = 0;
    int rightLetter = 0;

    for (i = 0 ; secretWord[i] != '\0' ; i++)
    {
        if (letter == secretWord[i])
        {
            rightLetter = 1;
            findLetter[i] = 1;
        }
    }

    return rightLetter;
}

void AFFPendu(int NBErreur)	{
	switch(NBErreur)	{
        case 1:
			printf ("\n");
			printf("            \n");
			printf("              \n");
			printf("              \n");
			printf("              \n");
			printf("              \n");
			printf("              \n");
			printf("              \n");
			printf("      -----   \n");
			printf ("\n");
			break;

        case 2:
			printf ("\n");
			printf("             \n");
			printf("        |     \n");
			printf("        |     \n");
			printf("        |     \n");
			printf("        |     \n");
			printf("        |     \n");
			printf("        |     \n");
			printf("      -----   \n");
			printf ("\n");
			break;
        case 3:
			printf ("\n");
			printf("      __     \n");
			printf("     |  |     \n");
			printf("        |     \n");
			printf("        |     \n");
			printf("        |     \n");
			printf("        |     \n");
			printf("        |     \n");
			printf("      -----   \n");
			printf ("\n");
			break;

		case 4:
			printf ("\n");
			printf("      __     \n");
			printf("     |  |     \n");
			printf("     0  |     \n");
			printf("        |     \n");
			printf("        |     \n");
			printf("        |     \n");
			printf("        |     \n");
			printf("      -----   \n");
			printf ("\n");
			break;
        case 5:
			printf ("\n");
			printf("      __     \n");
			printf("     |  |     \n");
			printf("     0  |     \n");
			printf("    /   |     \n");
			printf("        |     \n");
			printf("        |     \n");
			printf("        |     \n");
			printf("      -----   \n");
			printf ("\n");
			break;

		case 6:
			printf ("\n");
			printf("      __     \n");
			printf("     |  |     \n");
			printf("     0  |     \n");
			printf("    /|  |     \n");
			printf("        |     \n");
			printf("        |     \n");
			printf("        |     \n");
			printf("      -----   \n");
			printf ("\n");
			break;

		case 7:
			printf ("\n");
			printf("      __     \n");
			printf("     |  |     \n");
			printf("     0  |     \n");
			printf("    /|\\ |     \n");
			printf("        |     \n");
			printf("        |     \n");
			printf("        |     \n");
			printf("      -----   \n");
			printf ("\n");
			break;

        case 8:
			printf ("\n");
			printf("      __     \n");
			printf("     |  |     \n");
			printf("     0  |     \n");
			printf("    /|\\ |     \n");
			printf("     -  |     \n");
			printf("        |     \n");
			printf("        |     \n");
			printf("      -----   \n");
			printf ("\n");
			break;

		case 9:
			printf ("\n");
			printf("      __     \n");
			printf("     |  |     \n");
			printf("     0  |     \n");
			printf("    /|\\ |     \n");
			printf("     -  |     \n");
			printf("    /   |     \n");
			printf("        |     \n");
			printf("      -----   \n");
			printf ("\n");
			break;

		case 10:
			printf ("\n");
			printf("      __     \n");
			printf("     |  |     \n");
			printf("     0  |     \n");
			printf("    /|\\ |     \n");
			printf("     -  |     \n");
			printf("    / \\ |     \n");
			printf("        |     \n");
			printf("      -----   \n");
			printf ("\n");
			break;
	}
}
