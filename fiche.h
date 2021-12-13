#ifndef FICHE_H_INCLUDED
#define FICHE_H_INCLUDED
#include "employer.h"
typedef struct fiche
 {
    char num[20] ;
   char  salaire[30] ;
    char mois [25];
     emp employer;

 }fcp;



 typedef struct listElement
 {
     fcp value;
     struct listElement *next;
 }listElement,*list;




fcp saisir_fcp();
list saisir_liste_fcp(list li);
void afficheR(list li,char num[]);
void Recherche_fcp(list li,char numc[]);
int Recherche_fiche(list li,char num[] );
void Modifier_fcp(list li ,char num[] );
list supprimer_fcp(list li,char num[]);
float calculer(list li ,char mois[]);
int verif_chaine(char chaine[]);
int mois1(char k[]);
int salaire(char chaine[]);
int entier2(char chaine[]);
int Recherche_fiche2(list li,char num[]);

#endif // FICHE_H_INCLUDED
