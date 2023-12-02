#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>


//typedef struct temps {
//	int minutes;
//	int secondes;
//	int centiemes;
//}temps;


typedef struct Skieur {
	char nom[20];
	int dossard;
	int temps;
	//temps temp_Joueur;
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
	

	//afficher les informations des skieurs avec leurs dossards et leurs temps sous la forme : nom dossard temps et classement ne pas afficher le dernier element de la liste
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

	


	
	

// Fonction qui demande de renseigner les informations d'un skieur et qui renvoie un skieur avec ces informations	
skieur* cree_skieur() {
	skieur* skieur = malloc(sizeof(*skieur));
	skieur->dossard = rand() % (100 - 1 + 1) + 1;
	printf("Veuillez renseigner le nom du skieur : ");
	scanf_s("%s", &skieur->nom, 20);
	printf("Voici le dossard |%d| assigne au skieur  \n", skieur->dossard);

	//gestion d'erreur si le dossard existe deja
	
	printf("Veuillez renseigner le temps du skieur : ");
	scanf_s("%d", &skieur->temps);
	printf("Veuillez renseigner le classement du skieur : ");
	scanf_s("%d", &skieur->classement);
	return skieur;
	
}

// Fonction qui lance le chrono
	int start_chrono() {
		int temps = 0;
		srand(time(NULL));
		temps = rand() % (10 - 5 + 1) + 5;
		return temps;
	}

//fonction qui affiche le classement du premier tour
	void afficher_classement(listskieur *liste) {
		printf("Voici le classement du premier tour : \n");
		afficherListe(liste);
	}	


//foncion annimation terminal 
	void game_annime(listskieur *liste) {
		//affichage des jouers qui participe a la course sous forme de tableau
		printf("--------------------------------------------------\n");
		printf("Voici les skieurs qui participent a la course :\n");
		afficherListe(liste);
		printf("--------------------------------------------------\n");
		//affichage du compte a rebours
		printf("Le compte a rebours commence !\n");
		printf("--------------------------------------------------\n");
		//annimation ascii art dynamique
		printf("3\n");
		Sleep(1000);
		printf("2\n");
		Sleep(1000);
		printf("1\n");
		Sleep(1000);
		printf("GO !\n");
		//indiquer que la course com mence
		printf("La course commence !\n");
		printf("--------------------------------------------------\n");
		printf("La course est terminée !\n");
		Sleep(1000);
		system("cls");
	}

//visualisation des joueur enregister dans la liste
void visualisation_joueur(listskieur *liste, int choix) {
	while (choix != 9) {
		afficherListe(liste);
		//demander si il a fini de regarder la liste
		printf("Avez vous fini de regarder la liste ?\n");

		printf("9 : Oui\n");
		printf("10 : Non\n");

		printf("\nVotre choix :  ");
		scanf_s("%d", &choix);
		system("cls");
	}
	}

//enregistrement des skieurs dans la liste
void enregistrement_skieur(listskieur *liste, int choix) {
	int nbskieurTemp = 0;
	int nbskieur;
	printf("Combien de skieur voulez vous ajouter ? : ");
	scanf_s("%d", &nbskieur);
	while (nbskieurTemp != nbskieur) {

		insertion(liste, *cree_skieur());
		nbskieurTemp++;
	}
	system("cls");
}


//fonction qui trie une liste en fonction du temps dans l'order croissant
void trier_list_crossant(listskieur* liste,listskieur* liste_trier) {
	element *min = malloc(sizeof(*min));
	listskieur* listeTemp = initialisation();
	min = liste->premier;
	while (liste->premier != NULL) {
		if (liste->premier->skieurX.temps < min->skieurX.temps) {
			min = liste->premier;
			insertion(liste_trier, min->skieurX);
		}
		liste->premier = liste->premier->suivant;
	}
		
}


//menu de sélection des actions
void menu() {
		printf("Que voulez vous faire ?\n");
		printf("1 : Ajouter un skieur\n");
		printf("2 : Afficher la liste des skieurs\n");
		printf("3 : Lancer la course\n");
		printf("4 : Afficher le classement du premier tour \n");
		printf("9 : Rentrer le temps de chaque jouer \n");
		printf("8 : Quitter\n");

}

//enregistrement du temps de chaque jouer dans la liste
void enregistrement_temps(listskieur* liste, listskieur* listeclass) {
	while (liste->premier->suivant != NULL) {
		printf("Veuillez renseigner le temps du skieur %s : ", liste->premier->skieurX.nom);
		scanf_s("%d", &liste->premier->skieurX.temps);
		insertion(listeclass, liste->premier->skieurX);
		liste->premier = liste->premier->suivant;

	}
}


//trier une liste en fonction du temps dans l'order croissant 
int main() {
	
	

	// Déclaration des variableszZ

	int choix , nbskieur, nbskieurTemp; //variable 
 	 
	bool etat = true;
	listskieur *liste = initialisation();
	listskieur *listeFirstTour = initialisation();
	
	while (etat) {
		//menu de sélection des actions
		menu();
		printf("\nVotre choix :  ");
		scanf_s("%d", &choix);
		system("cls");

		switch (choix) {

		case 1:
			//enregistrement des skieurs dans la liste
			enregistrement_skieur(liste, choix);
			break;
		case 2:
			//affichage de la liste des skieurs
			if (liste->premier->suivant != NULL) {
				visualisation_joueur(liste, choix);
			}else {
				printf("La liste est vide !\n");
				visualisation_joueur(listeFirstTour, choix);
			}
			

			break;
		case 3:
			//lancement de la course
			game_annime(liste);
			break;
		case 4:
			//affichage du classement
			trier_list(liste);
			break;
		case 5:
			//enregistrement du temps de chaque jouer dans la liste 
			enregistrement_temps(liste,listeFirstTour);
			break;
		case 8:
			etat = false;
			break;
		

		}
	}

	return 0;

}