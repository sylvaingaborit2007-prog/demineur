#include "utils.h"




void print_grille_10(char tab[10][10])
{
	printf("       0 1 2 3 4 5 6 7 8 9\n");
	for(int i=0; i<10; i++)
	{
		printf("     %d|", i);
		for(int j=0; j<10; j++)
		{
			if(tab[i][j] == 'F' || tab[i][j] == '*')
			{
				printf("\033[31m%c\033[0m", tab[i][j]); //Rouge
				printf("|");
			}

			else if(tab[i][j] == '0')
			{
				printf(".|");
			}

			else if(tab[i][j] == '1')
			{
				printf("\033[32m%c\033[0m", tab[i][j]); //Vert
				printf("|");
			}

			else if(tab[i][j] == '2')
			{
				printf("\033[34m%c\033[0m", tab[i][j]); //Bleu
				printf("|");
			}

			else if(tab[i][j] == '3')
			{
				printf("\033[33m%c\033[0m", tab[i][j]); //Jaune
				printf("|");
			}

			else if(tab[i][j] == '4')
			{
				printf("\033[36m%c\033[0m", tab[i][j]); //Cyan
				printf("|");
			}

			else if(tab[i][j] == '5')
			{
				printf("\033[35m%c\033[0m", tab[i][j]); //Magenta
				printf("|");
			}
			
			else
			{
				printf("%c|", tab[i][j]);
			}
		}
		printf("\n");
	}
}


void print_grille_3(char tab[3][3])
{
	for(int i=0; i<3; i++)
	{
		printf("     |");
		for(int j=0; j<3; j++)
		{
			printf("%c|", tab[i][j]);
		}
		printf("\n");
	}
}


void copie_grille_10(char source[10][10], char dest[10][10])
{
	for(int i=0; i<=9; i++)
	{
		for(int j=0; j<=9; j++)
		{
			dest[i][j] = source[i][j];
		}
	}
}


void reveler_case(int x, int y, char grille_mines[10][10], char grille_utilisateur[10][10])
{
	for(int i=0; i<=9; i++)
	{
		for(int j=0; j<=9; j++)
		{
			if(i == x && j == y)
			{
				grille_utilisateur[i][j] = grille_mines[i][j];
			}
		}
	}
}



int compare_grille(char grille_utilisateur[10][10], char solution[10][10])
{
	for(int i=0; i<=9; i++)
	{
		for(int j=0; j<=9; j++)
		{
			if(grille_utilisateur[i][j] != solution[i][j])
			{
				return 0;
			}

			else if(grille_utilisateur[i][j] == '*')
			{
				return -1;
			}
		}
	}
	return 1;
}



void convert_minutes(time_t res)
{
	time_t minutes = res / 60;
	time_t secondes = res % 60;

	printf("Vous avez résolu la grille en %ldmin %ldsec\n", minutes, secondes);
}


void vider_grille_10(char grille[10][10])
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			grille[i][j] = '0';
		}
	}
}


void grille_depart()
{
	char grille_depart[10][10] =
	{
		"##########",
		"##########",
		"##########",
		"##########",
		"##########",
		"##########",
		"##########",
		"##########",
		"##########",
		"##########",
	};

	print_grille_10(grille_depart);
	printf("\n");
}