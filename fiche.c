#include <stdio.h>
#include "fiche.h"
#include "employer.h"
#include <string.h>
#include<ctype.h>
#include <windows.h>

int entier2(char chaine[])
 {
      int correct = 1;
       int indice = 0;
       while(chaine[indice] != '\0')
       {
          if (isdigit(chaine[indice])==0)
               correct = 0;
          indice++;
       }
       if (correct == 0)
           printf("erreur, recommencer!\n");
        return correct;
 }
int salaire(char chaine[])
 {
      int correct = 1;
       int indice = 0;
       while(chaine[indice] != '\0')
       {
          if ((isdigit(chaine[indice])==0)&&((chaine[indice])!='.'))
               correct = 0;
          indice++;
       }
       if (correct == 0)
           printf("erreur, recommencer!\n");
        return correct;
 }

int verif_chaine(char chaine[])
{int i;
    for(i=0;i<strlen(chaine);i++)
    {
       if (isalpha(chaine[i])==0)
            return 1;

    }
 return 0; }


 int mois1(char k[])
{
char mois[12][10]={"janvier","fevrier","mars","avril","mai","juin",
              "juillet","aout","septembre","octobre",
              "novembre","decembre"};
int rep=0;
int i;


  for (i=0;i<12;i++)
  {
      if (strcmp(mois[i],k)==0)
      {
          rep=1;
          break;
      }
  }

  return rep ;

}


fcp saisir_fcp(list li)
{ fcp f;int i=0;
      color(12,0);
      printf("\n taper le numero de fiche  : \n ");
      do
          {color(14,0);
             scanf("%s",f.num);
          }while((entier2(f.num)==0)||(Recherche_fiche2( li,f.num)==1));
     color(12,0);
      printf("\n taper le salaire : \n ");
      do
    {color(14,0);
        scanf("%s",f.salaire);}while(salaire(f.salaire)==0);

      color(12,0);
      printf("\n taper le mois : \n ");

      do
       {color(14,0);
       if (i==1)
            {printf("le mois est incorrecte reecrie un autre \n");
            i-=1;}
           scanf("%s",f.mois);
           i+=1;
           }while(mois1(f.mois)==0);
      color(6,0);
      printf("\n taper des informations sur l'employer: \n ");
      f.employer=saisir_emp();
      return f ;
}
 void affiche_fcp(fcp f)
    {     color(7,0);
          printf("\n  le numero de fiche de paie  : %s \n " ,f.num);
          printf("\n  le salaire : %s \n ",f.salaire);
          printf("\n le mois : %s \n ",f.mois);
          affiche_emp(f.employer);
    }

 list saisir_liste_fcp(list li)
    {
        fcp e;
    char rep[3];

        e=saisir_fcp(li);
        //tab[i]=e; **
        listElement *element;
        element= malloc(sizeof(*element));
        if (element== NULL)
        {
            printf("Erreur : Probl�me allocation dynamique");
            exit(1);
        }
        element->value=e;
        if (li==NULL)
        {
           element->next=NULL;
        }
        else {
            element->next=li;
        }
        li=element;


        do
        {
            printf("Voulez-vous ajouter un etd oui/non \n");
            scanf("%s",rep);
            if (!strcmp(rep,"oui"))
            {
                listElement  *elt;
                elt= malloc(sizeof(*elt));

                if (elt== NULL)
                {
                    printf("Erreur : Probl�me allocation dynamique");
                    exit(1);
                }
                fcp e=saisir_fcp(li);
                elt->value=e;
                if(li==NULL)
                {
                elt->next=NULL;
                }
                else {
                elt->next=li;
                }

                li=elt;}

        } while(!strcmp(rep,"oui"));



    return li;
}

  void affiche_liste_fcp(list li)
    {
        if (li==NULL)
        {   color(14,0);
            printf("la liste est vide \n");
            return;
  }

  else{

    while(li!=NULL)
    {

      affiche_fcp(li->value);
      printf("#######################################################");
      li=li->next ;
    }
        }
        printf("\n");
    }

  void afficheR(list li,char num[])
  { color(14,0);
      int existe=-1;
  if(li==NULL)

  {printf("la liste est vide \n");
  return;
  }

  else{

    while(li!=NULL)
    {
      if( strcmp(li->value.num,num)==0)

      {
          affiche_fcp(li->value);
          existe=1;
      }
       li=li->next ;
    }
    if (existe==-1)
    {
        printf("la fiche de paie n'existe pas \n ");
    }
  }
  }
void Recherche_fcp(list li,char numc[])
{
int i=0;
int rep=0;
  while(li!=NULL)
        {
            if( strcmp(li->value.employer.numc,numc)==0)

               {i+=1;
                printf("la fiche de paie existe a la position : %d  \n ",i);
                rep=1;
                 }
                 li=li->next;
        }


    if (rep==0)
        printf("le fiche de paie n'existe pas \n ");

}
int Recherche_fiche2(list li,char num[])
{
int existe=-1;
  if(li==NULL)

  {
  return existe;
  }

  else{

    while(li!=NULL)
    {
        if( strcmp(li->value.num,num)==0)

      {
          existe=1;
          printf("le numero de fiche existe deja reecrie un autre ");
          break;
      }
       li=li->next ;
    }
return existe;
}
}
int Recherche_fiche(list li,char num[])
{
int existe=-1;
  if(li==NULL)

  {printf("la liste est vide \n");
  return existe;
  }

  else{

    while(li!=NULL)
    {
        if( strcmp(li->value.num,num)==0)

      {
          existe=1;
          break;
      }
       li=li->next ;
    }
return existe;
}
}


void Modifier_fcp(list li ,char num[] )
{  color(6,0);
    int choix;
    char nvsalaire[20];
    char nvn[20],nvcnss[20];char nvnom[20],nvprenom [20] ,nvmois[20],nvgrade[30];
    int rech=Recherche_fiche(li,num);
    if (rech==-1)
        {printf("la fiche de paie  que vous voulez modifer n'existe pas ! \n");}
    else
    {

    do
    {
        printf("***       que vous voulez modifier ?                           ***\n");
        printf("***       tapez 1 pour modifier le numero de fiche de paie     *** \n");
        printf("***       tapez 2 pour modifier le salaire                     *** \n");
        printf("***       tapez 3 pour modifier le mois                        ***\n");
        printf("***       tapez 4 pour modifier le nom de l'employer           *** \n");
        printf("***       tapez 5 pour modifier le prenom de l'employer        *** \n");
        printf("***       tapez 6 pour modifier le grade de l'employer         *** \n");
        printf("***       tapez 7 pour modifier le numero de cnss              *** \n");
        printf("0.annuler \n");
         do
          {

        scanf("%d",&choix);}
        while (( choix>7) || (choix<0));
        switch (choix)
        {
            case 1: {color(14,0);
            printf("taper le nouveau numero de fiche de paie \n");
            do
          {   color(12,0);
              scanf("%s",nvn);;}while(entier2(nvn)==0);

            while(li!=NULL)
                 {
                    if( strcmp(li->value.num,num)==0)


                        {
                            strcpy(li->value.num,nvn);


                        }
                    li=li->next ;
                 }
            break;}
            case 2: {color(14,0);
            printf("taper le nouveau salaire \n");
            do
          {   color(12,0);
             scanf("%s",nvsalaire);}while(salaire(nvsalaire)==0);

            while(li!=NULL)
                 {
                    if( strcmp(li->value.num,num)==0)


                        {
                            strcpy(li->value.salaire,nvsalaire);


                        }
                    li=li->next ;
                 }
            break;}
            case 3:{color(14,0);
            printf("taper le nouveau mois \n");
            do
       {    color(12,0);
           scanf("%s",nvmois);
           }while(mois1(nvmois)==0);
            while(li!=NULL)
                 {
                    if( strcmp(li->value.num,num)==0)


                        {

                          strcpy(li->value.mois,nvmois);
                        }
                    li=li->next ;
                 }
            break;}
             case 4: {
                 color(14,0);
                 printf("taper le nouveau nom \n");
            do
       {    color(12,0);
           scanf("%s",nvnom);
           }while(verif_chaine(nvnom)==1);
            while(li!=NULL)
                 {
                    if( strcmp(li->value.num,num)==0)


                        {

                          strcpy(li->value.employer.nom,nvnom);
                        }
                    li=li->next ;
                 }
            break;}
            case 5: {
                color(14,0);
                printf("taper le nouveau prenom \n");
            do
       {    color(12,0);
           scanf("%s",nvprenom);
           }while(verif_chaine(nvprenom)==1);
            while(li!=NULL)
                 {
                    if( strcmp(li->value.num,num)==0)


                        {

                          strcpy(li->value.employer.prenom,nvprenom);
                        }
                    li=li->next ;
                 }
            break;}
            case 6: {color(14,0);
                printf("taper le nouveau grade \n");
            do
       {   color(12,0);
           scanf("%s",nvgrade);
           }while(verif_chaine(nvgrade)==1);
            while(li!=NULL)
                 {
                    if( strcmp(li->value.num,num)==0)


                        {

                          strcpy(li->value.employer.grade,nvgrade);
                        }
                    li=li->next ;
                 }
            break;}
            case 7: {color(14,0);
            printf("taper le nouveau numero de cnss  \n");
            do
          {   color(12,0);
              scanf("%s",nvcnss);;}while(entier(nvcnss));

            while(li!=NULL)
                 {
                    if( strcmp(li->value.num,num)==0)


                        {
                            strcpy(li->value.employer.numc,nvcnss);


                        }
                    li=li->next ;
                 }
            break;}
            case 0:
                {
                   break;
                }break;
                color(14,0);
             default:printf("invalide\n");
        }}while(choix!=0);
        }}

  list supprimer_fcp(list li,char num[])
{

int rech=Recherche_fiche( li,num);
if (rech==-1)
{printf("la fiche de paie  que vous voulez supprimer n'existe pas ! \n");}
else
{
   if(li==NULL)
        printf("La liste est vide");
    if((li->next==NULL)&&(strcmp(li->value.num,num)==0))
    {
        free(li);
        li=NULL;

        return NULL;
    }
    listElement *temp=li;
    listElement *before=li;

    while((temp->next != NULL)&&strcmp(temp->value.num,num)!=0)
    {
        before=temp;
        temp=temp->next;
    }
    before->next =temp->next;
    free(temp);
 return li;
}

}


float calculer(list li ,char mois[])
{

    double s=0;
    while(li!=NULL)
    {
           if(strcmp(li->value.mois,mois)==0)
        {s+=atof(li->value.salaire);}
       li=li->next;
    }
    return s;

}



