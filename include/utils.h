#include <stdio.h>
#include <stdlib.h>
#include <time.h>



//imprime une grille 10*10, avec les couleures sur les chiffres de 0 a 6
void print_grille_10(char tab[10][10]);


//imprime une grille 3*3
void print_grille_3(char tab[3][3]);


//copie d'une grille source 10*10 dans une grille dest 10*10
void copie_grille_10(char source[10][10], char dest[10][10]);


//reveler les 8 cases autour d'une case x,y de grille_utilisateur
void reveler_autour(int x, int y, char grille_mines[10][10], char grille_utilisateur[10][10]);


//compare la grille utilisateur a la grille solution a chaque saisie
int compare_grille(char grille_utilisateur[10][10], char solution[10][10]);


//convertit le temps de secondes en minutes
void convert_minutes(time_t res);


//remplit la grille de 0
void vider_grille_10(char grille[10][10]);


//remplit la grille de # et l'imprime (départ)
void grille_depart();
