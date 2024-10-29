#include "fonction_yomen.h"

int main(){
    int choix;
    songo s;
    printf("\nBIENVENUE AU JEU DU SONGO\n");

    printf("CHOISISSEZ UN MODE DE JEU :\n");
    printf("\n\n1.Jouer avec la machine\n2.Jouer avec un autre joueur\t ");
    scanf("%d",&choix);

    do{
        if(choix == 2){
            printf("NOM JOUEUR 1:\t");
            scanf("%s", s.nom_joueur1);
            printf("NOM JOUEUR 2:\t");
            scanf("%s", s.nom_joueur2);
            commencer(&s);
            decoration(s);
            s.terminer = 0;
            while (s.terminer == 0)
            {
                tour_joueur1(&s);
                decoration(s);
                if (s.terminer == 0)
                {
                    tour_joueur2(&s,choix);
                    decoration(s);
                }
            }
            affiche_gagnant(&s);
        }else if(choix == 1){
            printf("NOM JOUEUR 1:\t");
            scanf("%s", s.nom_joueur1);
            strcpy(s.nom_joueur2, "machine");
            commencer(&s);
            decoration(s);
            s.terminer = 0;
            while (s.terminer == 0)
            {
                tour_joueur1(&s);
                decoration(s);
                if (s.terminer == 0)
                {
                    tour_joueur2(&s,choix);
                    decoration(s);
                }
            }
            affiche_gagnant(&s);
        }else{
            printf("\nEntrez un chiffre correct");
        }
    }while(choix != 1 || choix != 2);
    

    return 0;
}