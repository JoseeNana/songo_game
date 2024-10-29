#ifndef FONCTION_YOMEN_H_INCLUDED
#define FONCTION_YOMEN_H_INCLUDED


    #include <stdio.h>
    #include <stdlib.h>
    #include <time.h>
    #include <string.h>

    // definition de la structure songo
    typedef struct {
        char nom_joueur1[50];
        char nom_joueur2[50];
        int joueur1[7];
        int joueur2[7];
        int score1;
        int score2;
        int tour;
        int terminer;
    } songo;

    void commencer(songo *s);
    void decoration(songo s);
    void joueur1_joue(songo *s, int troue_jouer);
    void joueur2_joue(songo *s, int troue_jouer2);
    void tour_joueur1(songo *s);
    void tour_joueur2(songo *s,int choix);
    void affiche_gagnant(songo *s);

#endif