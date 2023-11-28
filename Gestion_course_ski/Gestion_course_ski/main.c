#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


typedef struct Skieur {
	char nom[20];
	int dossard;
	int temps;
	int classement;

}skieur;

typedef struct Element {
	skieur skieurX;
	struct element* suivant;
}element;

typedef struct ListSkieur
{
	element *premier;
}listskieur;
 
	//initialisation de la liste
	listskieur* initialisation()
	{
		listskieur* liste = malloc(sizeof(*liste));
		element* element = malloc(sizeof(*element));

		if (liste == NULL || element == NULL)
		{
			exit(EXIT_FAILURE);
		}

		element->skieurX;
		element->suivant = NULL;
		
		liste->premier = element;

		return liste;
	}
	
	void insertion(listskieur* liste, skieur nvSkieur)
	{
		/* Création du nouvel skieur */
		element* nouveauSkieur = malloc(sizeof(*nouveauSkieur));
		if (liste == NULL || nouveauSkieur == NULL)
		{
			exit(EXIT_FAILURE);
		}
		nouveauSkieur->skieurX = nvSkieur;

		/* Insertion de l'élément au début de la liste */
		nouveauSkieur->suivant = liste->premier;
		liste->premier = nouveauSkieur;
	}

	//afficher la liste des skieurs avec leurs dossards et leurs temps sous la forme : nom dossard temps et classement 
	void afficherListe(listskieur* liste)
	{
		if (liste == NULL)
		{
			exit(EXIT_FAILURE);
		}

		element* actuel = liste->premier;

		while (actuel != NULL)
		{
			printf("%s %d %d %d\n", actuel->skieurX.nom, actuel->skieurX.dossard, actuel->skieurX.temps, actuel->skieurX.classement);
			actuel = actuel->suivant;
		}

		printf("\n");
	}
	 
	

	// Fonction qui permet de créer un skieur
	skieur* cree_skieur() {
		skieur skieur1;
		printf("Nom du skieur : ");
		scanf_s("%s", &skieur1.nom);
		printf("Dossard du skieur : ");
		scanf_s("%d", &skieur1.dossard);
		printf("Temps du skieur : ");
		scanf_s("%d", &skieur1.temps);
		return &skieur1;
	}

int main() {
	
	

	// Déclaration des variables
	int etat,nbskieur; //nombre de manch
	etat = 1;
	listskieur *liste = initialisation();
	printf("Combien de skieur voulez vous ajouter ? : ");
	scanf_s("%d", &nbskieur);


	while (etat != 2) {
		
		insertion(liste,*cree_skieur());
		printf("Voulez vous ajouter un skieur ? (1 = oui / 2 = non) : ");
		scanf_s("%d", &etat);





	}
	afficherListe(liste);
	return 0;

}