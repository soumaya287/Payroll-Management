#ifndef EMPLOYER_H_INCLUDED
#define EMPLOYER_H_INCLUDED

typedef struct employer
 {
    char numc[20] ;
    char nom [25];
    char prenom [25];
     char grade [25];

 }emp;
emp saisir_emp();
void affiche_emp(emp e);
int verif1_chaine(char chaine[]);
int entier(char chaine[]);

#endif // EMPLOYER_H_INCLUDED
