#include "menu.h"
#include "utils.h"
#include "fonctions_main.h"
#include <stdio.h>  
#include <time.h>


int main()
{
	srand(time(NULL));

	char grille_mines[10][10] = 
    {
        "0000000000",
        "0000000000",
        "0000000000",
        "0000000000",
        "0000000000",
        "0000000000",
        "0000000000",
        "0000000000",
        "0000000000",
        "0000000000",
    };

    char grille_utilisateur[10][10] = 
    {
        "0000000000",
        "0000000000",
        "0000000000",
        "0000000000",
        "0000000000",
        "0000000000",
        "0000000000",
        "0000000000",
        "0000000000",
        "0000000000",
    };

    char solution[10][10] = 
    {
        "0000000000",
        "0000000000",
        "0000000000",
        "0000000000",
        "0000000000",
        "0000000000",
        "0000000000",
        "0000000000",
        "0000000000",
        "0000000000",
    };

    char saisie_texte[21];
    int resolution = 0;
    int comparaison = 0;
    int count = 0;


    while(1)
    {
        while(count < 1)
        {
            system("clear");
            menu();
            printf("\n");
            printf("\n");
            grille_depart();

            fgets(saisie_texte, 21, stdin);
            system("clear");

            //remplissage aléatoire des mines et définition de la solution
            preparation_grille_1er_clic(saisie_texte, grille_mines);
            cacher_mines(grille_mines, grille_utilisateur);
            copie_grille_10(grille_mines, solution);
            grille_solution(grille_mines, solution);
            reveler_autour(saisie_texte[1]-'0', saisie_texte[2]-'0', grille_mines, grille_utilisateur);
            
            count++;
        }
        
        //début du timer
        time_t start = time(NULL);

        //boucle utilsateur
        while(1)
        {
            inteface_utilisateur(grille_utilisateur);
            comparaison = compare_grille(grille_utilisateur, solution);

            //Comparaison pour voir si l'utilisateur a gagné
            if(comparaison > 0)
            {
                printf("Bravo, vous avez gagné!\n");
                time_t end = time(NULL);
                time_t res = end - start;
                convert_minutes(res);
                break;
            }
            
            //Saisie utilisateur
            printf("Saisissez : "); 
            fgets(saisie_texte, 21, stdin);
            resolution = resolution_grille_utilisateur(saisie_texte, grille_mines, grille_utilisateur);
            
            //résolution de la grille en fonction de la saisie
            if(resolution == -1)
            {
                system("clear");
                inteface_utilisateur(grille_utilisateur);
                printf("BOOOMMM, vous avez délogé une mine\n");
                break;
            }

            else if (resolution == -2)
            {
                printf("\n");
                printf("Mauvaise syntaxe\n");
                system("sleep 2");
            }

            //Effacement de l'ancien contenu
            system("clear");
        }

        printf("Voulez vous jouez a nouveau? (y/n) : ");
        fgets(saisie_texte, 21, stdin);

        if (saisie_texte[0] == 'n' && saisie_texte[1] == '\n')
        {
            break;
        }
        else if(saisie_texte[0] == 'y' && saisie_texte[1] == '\n')
        {
            count = 0;
            continue;
        }
        else break;
    }
}



//TODO : Interface graphique
//BONUS : Sauvegarde du record
//BONUS : Animation explosion