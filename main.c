#include <stdio.h>
#include <stdlib.h>
#include "fiche.h"
#include "employer.h"
#include <windows.h>
#include<ctype.h>


void color(int t,int f)
{
        HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(H,f*16+t);
}

int main()
{
    color(6,0);



    double s;
    list listfcp=NULL;
   char numc[20],cnss[20],num[20];
    int choix;
    int recherche=-1;
    char mois[20];

    /*FILE *FICHIER=NULL;
    FICHIER=fopen("fiche","r");
     if(!FICHIER)
     {
         printf("\a erreur :impossible d'ouvrir le fichier");
         exit(-1);
     }
     while(!feof(FICHIER))
     {
         fcp e;
         fscanf(FICHIER,"%s %s %s %s %s %s %s \n",e.num,e.salaire,e.mois,e.employer.numc,e.employer.nom,e.employer.prenom,e.employer.grade);

          list->value=e;

     }
    fclose(FICHIER);
     fflush(stdin);*/
    system("cls");
    color(11,0);
    printf(" \n   ***************************************************************************\n ");
    color(6,0);
    printf(" \n *****                                                                     ***** \n ");
    printf(" \n *****                        BIENVENUE!                                   ***** \n ");
    printf(" \n *****                                                                     ***** \n ");
    color(11,0);
    printf(" \n   ***************************************************************************\n ");
    system("PAUSE");
    system("cls");

    while (1)
    {

    color(11,0);
    printf(" \n   ***************************************************************************\n ");
    color(6,0);
    printf(" \n *****        pour ajouter une fiche de paie tapez 1                       ***** \n ");
    printf("*****        pour rechercher une fiche de paie tapez 2                    ***** \n ");
    printf("*****        pour modifier une information dans le fiche de paie tapez 3  ***** \n ");
    printf("*****        pour supprimer une  fiche de paie tapez 4                    ***** \n ");
    printf("*****        pour calculer les salaires d'un mois correspondant tapez 5   ***** \n ");
    printf("*****        pour afficher une fiche de paie tapez  6                     ***** \n ");
    printf("*****        pour listez  tout les fiches de paie tapez  7                ***** \n ");
    printf("*****        pour sortir tapez 0                                          ***** \n ");

    color(11,0);
    printf(" \n   ***************************************************************************\n ");
    do
   {
    color(7,0);
    scanf("%d",&choix);}
    while (( choix>7) || (choix<0));
    switch(choix) {

   case 1:{system("cls");
          listfcp=saisir_liste_fcp(listfcp);
          system("PAUSE");
          system("cls");
            break;}

   case 2:{ system("cls");
      color(12,0);
       printf("tapez le numero de cnss(compose de 8 chiffre)  correspandant aux fiches  que vous voulez rechercher \n");


    do{color(14,0);
   scanf("%s",cnss);}while(entier(cnss)==0);
   Recherche_fcp(listfcp,cnss);
   system("PAUSE");
   system("cls");


        break;}
    case 3:{system("cls");
      color(12,0);
        printf("tapez le numero  de fiche que vous voulez modifier \n");
     do
    {color(14,0);
   scanf("%s",num);}while(entier2(num)==0);
    Modifier_fcp(listfcp,num );
    system("PAUSE");
    system("cls");
    break;}
    case 4: {system("cls");
    color(12,0);
        printf("tapez le numero de fiche correspandant �  la fiche de paie que vous voulez supprimer \n");
    do
    {color(14,0);
   scanf("%s",num);}while(entier2(num)==0);
   listfcp=supprimer_fcp(listfcp,num);
   system("PAUSE");
    system("cls");
    break;}
     case 5:{system("cls");
        color(12,0);
         printf("tapez le mois \n");
     int i=0;
        do
       {color(14,0);

         if (i==1)
            {printf("le mois est incorrecte reecrie un autre \n");
            i-=1;}
           scanf("%s",mois);
            i+=1;
           }while(mois1(mois)==0);



    s= calculer(listfcp,mois);
    printf("la somme des salaire de %s = %f \n" ,mois,s);
    system("PAUSE");
    system("cls");

    }break;

   case 6:{system("cls");
   color(12,0);
   printf("tapez le numero de la fiche de paie  que vous voulez affiche \n");
    do
    {color(14,0);
   scanf("%s",numc);}while(entier2(numc)==0);

   afficheR(listfcp,numc);


           system("PAUSE");
           system("cls");
           break;}
   case 7 :{system("cls");
       affiche_liste_fcp(listfcp);
       system("PAUSE");
       system("cls");
       break;}
    case 0 :{/*FICHIER =fopen("fiche","w");
            if (!FICHIER)
            {
                printf("\aERREUR:impossible d'ouvrir le fichier");
                exit(-1);

            }
            int j;

            while(li!=NULL)
            {
                fprintf(FICHIER,"%s %s %s %s %s %s %s \n",li->value.num,li->value.salaire,li->value.mois,li->value.employer.numc,li->value.employer.nom,li->value.employer.prenom,li->value.employer.grade);

            }
            fclose(FICHIER);*/
            exit(0);}
   default :printf(" erreur");





}}
return 0;
}

