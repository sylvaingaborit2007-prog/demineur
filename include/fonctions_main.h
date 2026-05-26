#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//remplit une grille de 10*10 de mines ou de 0, aléatoirement
void remplissage_grille_mines(char grille_mines[10][10]);


//incremente de 1 les 8 cases autour des mines
void denombrement_mines(char grille_mines[10][10]);


//prepare la grille utilisateur
void cacher_mines(char grille_mines[10][10], char grille_utilisateur[10][10]);


//reveler une case x,y de la grille_utilisateur a partir de grille_mines
void reveler_case(int x, int y, char grille_mines[10][10], char grille_utilisateur[10][10]);


//resoud la grille utilisateur au fur et a mesure des saisies de texte
int resolution_grille_utilisateur(char saisie_texte[21], char grille_mines[10][10], char grille_utilisateur[10][10]);


//définition de la grille solution, remplace les mines par les F attendus
void grille_solution(char grille_mines[10][10], char solution[10][10]);


//préparation de la grille aléatoire au premier clic
void preparation_grille_1er_clic(char saisie_texte[21], char grille_mines[10][10]);