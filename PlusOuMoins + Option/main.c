#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, const char * argv[])
{

    int nbRandom = 0;
    int nbEntree = 0;
    int nbCoup = 1;
    int MAX = 100, MIN = 1;
    int NewGame = 0;
    int modeJeu = 0;
    int Diffi = 0 ;


    printf("Jeu du plus ou moins!\n");


Partie:

    printf("Choix du mode de jeux : \n 1 pour le mode Solo \n 2 pour le mode Multi  \n");
    scanf("%d",&modeJeu);

    if (modeJeu == 1)
    {
        printf("Choix de la difficulte : \n 1 = Facile \n 2 = Moyen \n 3 = Difficile  \n");
        scanf("%d",&Diffi);
        if (Diffi == 1)
        {
            MAX = 100;
        }
        else if (Diffi == 2)
        {
            MAX = 1000;
        }
        else if (Diffi == 3)
        {
            MAX = 10000;
        }

        srand(time(NULL));
        nbRandom = (rand() % (MAX - MIN - 1)) + MIN;

    }
    else if (modeJeu == 2)
    {

        printf("Joueur 1 : Choisir un chiffre entre 1 et %d\n", MAX);
        scanf("%d",&nbRandom);
        if (nbRandom > 100)
        {
            printf("Erreur chiffre non compris entre 0 et 100\n");
            goto Partie;

        }
    }


    do
    {
        printf("Nombre de coups: %d \n", nbCoup);
        printf("Quel est le nombre mystere ? (entre 1 - %d) : ", MAX);
        scanf("%d",&nbEntree);

        nbCoup++;

        if (nbEntree < nbRandom)
        {
            printf("C'est plus!\n");
        }
        else if (nbEntree > nbRandom)
        {
            printf("C'est moins!\n");
        }
        else
        {
            printf("Bravo vous avez trouve en %d coup !!\n",nbCoup-1);
        }
    }
    while(nbEntree != nbRandom);

    printf("\nUne autre partie ? \n   1 : Oui \n   2 : Non merci    ",NewGame);
    scanf("%d",&NewGame);
    if (NewGame == 1)
    {
        printf("\n\n C'est repartie ! \n");
        printf("\n \n");
        nbCoup = 1;
        MAX = 100;
        goto Partie;
    }
    else
    printf("\n\n Merci d'avoir joue ! \n");
        return 0;
}
