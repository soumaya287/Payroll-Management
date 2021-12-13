#include <stdio.h>
#include "employer.h"
#include <string.h>

 int entier(char chaine[])
 {
      int correct = 1;
       int indice = 0;
       int c=strlen(chaine);
       while(chaine[indice] != '\0')
       {
          if ((isdigit(chaine[indice])==0)|| (c!=8))
               correct = 0;
          indice++;
       }
       if (correct == 0)
           printf("erreur, recommencer!\n");
        return correct;
 }



emp saisir_emp()
{ emp e;int i=0,j=0,k=0;
      color(12,0);
      printf("\n taper le numero de cnss composer de 8 chiffres : \n ");
       do
          { color(14,0);
             scanf("%s",e.numc);
          }while(entier(e.numc)==0);
      color(12,0);
      printf("\n taper le nom : \n ");
      do
       {  if (i==1)
            {printf("le nom doit etre compose des alphabets reecris un autre \n");
            i-=1;}
            color(14,0);
           scanf("%s",e.nom);
           i+=1;
           }while(verif1_chaine(e.nom)==1);
       color(12,0);
       printf("\n taper le prenom : \n ");
        do
       {  if (j==1)
            {printf("le prenom doit etre compose des alphabets reecris un autre \n");
            j-=1;}
            color(14,0);
           scanf("%s",e.prenom);
           j+=1;
           }while(verif1_chaine(e.prenom)==1);
      color(12,0);
       printf("\n taper le grade: \n ");
        do
       {  if (k==1)
            {printf("le grade doit etre compose des alphabets reecris un autre \n");
            k-=1;}
            color(14,0);
           scanf("%s",e.grade);
           k+=1;
           }while(verif1_chaine(e.grade)==1);
       return e ;
}
void affiche_emp(emp e)
    {
          printf("\n  le numero de cnss : %s \n " ,e.numc);
          printf("\n  le nom: %s \n ",e.nom);
          printf("\n le prenom: %s \n ",e.prenom);
          printf("\n le grade: %s \n ",e.grade);
    }
int verif1_chaine(char chaine[])
{int i;
    for(i=0;i<strlen(chaine);i++)
    {
        if (isalpha(chaine[i])==0 )
            return 1;

    }
 return 0; }


