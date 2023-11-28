#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


struct skieur {
	char nom[20];
	int dossard;
	int temps;
	int classement;

} typedef skieur;


struct element {
	skieur skieur;
	struct element *suivant;
} typedef element;

struct	ListSkieur
{
	skieur *premier;
};typedef skieur_list;
 

	skieur_list* initialisation()
	{
		skieur_list* liste_skieur = malloc(sizeof(*liste_skieur));
		element* skieurX = malloc(sizeof(*skieurX));

		if (liste_skieur == NULL || skieurX == NULL)
		{
			exit(EXIT_FAILURE);
		}

		//initialisation du skieur
		strcpy_s(skieurX->skieur.nom,sizeof(skieurX->skieur.nom), "nom");
		skieurX->skieur.temps = NULL;
		skieurX->skieur.classement = NULL;
		skieurX->skieur.dossard = NULL;

		//initialisation de la liste
		liste_skieur->premier = skieurX;

		return liste_skieur;
	}

	void insertion(skieur_list* liste, skieur nvSkieur)
	{
		/* Création du nouvel skieur */
		element* nouveauSkieur = malloc(sizeof(*nouveauSkieur));
		if (liste == NULL || nouveauSkieur == NULL)
		{
			exit(EXIT_FAILURE);
		}
		nouveauSkieur->skieur = nvSkieur;

		/* Insertion de l'élément au début de la liste */
		nouveauSkieur->suivant = liste->premier;
		liste->premier = nouveauSkieur;
	}

	//afficher la liste
	void afficherListe(skieur_list* liste)
	{
		if (liste == NULL)
		{
			exit(EXIT_FAILURE);
		}

		element* actuel = liste->premier;

		while (actuel != NULL)
		{
			printf("-------- %c --------\n", actuel->skieur.nom);
			printf("------- %d ---------\n", actuel->skieur.dossard);
			printf("------- %d ---------\n", actuel->skieur.temps);
			printf("------- %d ---------\n", actuel->skieur.classement);

			actuel = actuel->suivant;
		}

		printf("\n");
	}



	// Fonction qui permet de créer un skieur
	skieur* cree_skieur(skieur skieur1) {
		printf("Nom du skieur : ");
		scanf_s("%c", &skieur1.nom);
		printf("Dossard du skieur : ");
		scanf_s("%d", &skieur1.dossard);
		printf("Temps du skieur : ");
		scanf_s("%d", &skieur1.temps);
		return &skieur1;
	}

int main() {
	
	

	// Déclaration des variables
	int etat; //nombre de manche


	etat = 1;
	skieur_list liste = initialisation();


	while (etat != 2) {
		skieur skieur1;	
		insertion(liste,*cree_skieur(skieur1));
		



	}
	afficherListe(liste);
	return 0;

}