#include "fonctions_main.h"
#include "utils.h"


void remplissage_grille_mines(char grille_mines[10][10])
{
    int mines = 0;

    while (mines < 10)
    {
        int x = rand() % 10;  // ligne
        int y = rand() % 10;  // colonne

        if (grille_mines[x][y] != '*')  // si pas déjà une mine
        {
            grille_mines[x][y] = '*';
            mines++;
        }
    }
}



void denombrement_mines(char grille_mines[10][10])
{
    for(int i=0; i<10; i++)
    {
        for(int j=0; j<10; j++)
        {
            if(grille_mines[i][j] == '*')
            {
                for(int di=-1; di<2; di++)
                {
                    for(int dj=-1; dj<2; dj++)
                    {
                        if(grille_mines[i+di][j+dj] != '*' && i+di>=0 && i+di<=9 && j+dj>=0 && j+dj<=9)
                        {
                            grille_mines[i+di][j+dj]++;
                        }
                    }
                }
            }
        }
    }
}



void cacher_mines(char grille_mines[10][10], char grille_utilisateur[10][10])
{
    copie_grille_10(grille_mines, grille_utilisateur);

    for(int i=0; i<=9; i++)
    {
        for(int j=0; j<=9; j++)
        {
            grille_utilisateur[i][j] = '#';
        }
    }
}


void reveler_autour(int x, int y, char grille_mines[10][10], char grille_utilisateur[10][10])
{
    if(x<0 || x>9 || y<0 || y>9)
    {
        return;
    }

    if(grille_utilisateur[x][y] != '#')
    {
        return;
    }

    grille_utilisateur[x][y] = grille_mines[x][y];
    
    if(grille_mines[x][y] != '0')
    {
        return;
    }
    
    for(int dx=-1; dx<=1; dx++)
	{
		for(int dy=-1; dy<=1; dy++)
		{
            if(!(x == 0 && y == 0))
            {
                reveler_autour(x+dx, y+dy, grille_mines, grille_utilisateur);
            }
		}
	}
}


int resolution_grille_utilisateur(char saisie_texte[21], char grille_mines[10][10], char grille_utilisateur[10][10])
{
    int x = 0;
    int y = 0;

    for(int i=0; i<5; i++)
    {
        x = saisie_texte[1+4*i] - '0';
        y = saisie_texte[2+4*i] - '0';

        if
        ( ((saisie_texte[4*i] == 'r' || saisie_texte[4*i] == 'R')           ||
             (saisie_texte[4*i] == 'f' || saisie_texte[4*i] == 'F'))        &&
            (x >= 0 || x <= 9 || y >= 0 || y <= 9)                          &&
            ((saisie_texte[3+4*i] == ' ') || (saisie_texte[3+4*i] == '\n'))
        )
        {
            if ((saisie_texte[4*i] == 'r' || saisie_texte[4*i] == 'R'))
            {
                if (grille_mines[x][y] == '*')
                {
                    reveler_case(x, y, grille_mines, grille_utilisateur);
                    return -1;
                }

                else if(grille_mines[x][y] == '0')
                {
                    reveler_autour(x, y, grille_mines, grille_utilisateur);
                    if(saisie_texte[3+4*i] == '\n')
                    {
                        break;
                    }
                }
                
                else
                {
                    reveler_case(x, y, grille_mines, grille_utilisateur);
                    if(saisie_texte[3+4*i] == '\n')
                    {
                        break;
                    }
                }
            }

            else if ((saisie_texte[4*i] == 'f' || saisie_texte[4*i] == 'F') && grille_utilisateur[x][y] == '#')
            {
                if(grille_utilisateur[x][y] == 'F')
                {
                    reveler_case(x, y, grille_mines, grille_utilisateur);
                }

                else 
                {
                    grille_utilisateur[x][y] = 'F';
                }

                if(saisie_texte[3+4*i] == '\n')
                {
                    break;
                }
            } 
        }

        else 
        {
            return -2;
        }
    }   
    return 0;  
}



void grille_solution(char grille_mines[10][10], char solution[10][10])
{
    for(int i=0; i<=9; i++)
    {
        for(int j=0; j<=9; j++)
        {
            if(grille_mines[i][j] == '*')
            {
                solution[i][j] = 'F';
            }
        }
    }
}



void preparation_grille_1er_clic(char saisie_texte[21], char grille_mines[10][10])
{
    int x = saisie_texte[1] - '0';
    int y = saisie_texte[2] - '0';
    
    vider_grille_10(grille_mines);
    remplissage_grille_mines(grille_mines);
    denombrement_mines(grille_mines);
    
    if (grille_mines[x][y] != '0')
    {
        while(grille_mines[x][y] != '0')
        {
            vider_grille_10(grille_mines);
            remplissage_grille_mines(grille_mines);
            denombrement_mines(grille_mines);
        }
    }
}