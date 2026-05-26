#include "menu.h"
#include "utils.h"
#include "fonctions_main.h"



void menu()
{
    printf("       ====Demineur====\n");
    printf("\n");
    printf("\n");
    printf("Veuillez rentrez votre saisie, sous la forme Rxy ou Fxy.\n");
    printf("Vous pouvez réaliser plusieurs commandes, au maximum 3.\n");
    printf("Chaque commande doit être séparée par un espace.\n");
}



void inteface_utilisateur(char grille_utilisateur[10][10])
{
    printf("F : Flag\n");
    printf("R : Reveal\n");
    printf("\n");
    printf("\n");
    print_grille_10(grille_utilisateur);
    printf("\n");
}