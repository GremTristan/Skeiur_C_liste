
#ifndef _VARIABLE_H_
#define _VARIABLE_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
 
struct skieur {
	char nom[20];
	int dossard;
	int temps;
	int classement;

}; typedef skieur;


struct element {
	skieur skieur;
	struct element* suivant;
}; typedef element;

