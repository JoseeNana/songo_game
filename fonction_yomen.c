#include "fonction_yomen.h"


// initialisation des donnees de la structure songo
void commencer(songo *s){
    int i;
    for (i = 0; i < 7; i++)
    {
        s->joueur1[i] = 5;
        s->joueur2[i] = 5;
    }
    s->score1 = 0;
    s->score2 = 0;
    s->tour = 1;
}

// affichage de la disposition du songo a l ecran
void decoration(songo s) {
    printf("\n\n");
    printf("=================================================================\n");
    printf("*                  SCORE %s:%d\tSCORE %s:%d                      *\n", s.nom_joueur1, s.score1, s.nom_joueur2, s.score2);
    printf("=================================================================\n");
    printf("TOUR DE JEU:%s\n", (s.tour == 1 ? s.nom_joueur1 : s.nom_joueur2));
    printf("\n\n||=================================================================||\n\n");
    printf("||(%d)1      (%d)2      (%d)3      (%d)4      (%d)5      (%d)6      (%d)7  ||\n\n", s.joueur1[0], s.joueur1[1], s.joueur1[2], s.joueur1[3], s.joueur1[4], s.joueur1[5], s.joueur1[6]);
    printf("|| ---------------------------------------------------------------- || \n\n");
    printf("||(%d)1      (%d)2      (%d)3      (%d)4      (%d)5      (%d)6      (%d)7 || \n", s.joueur2[6], s.joueur2[5], s.joueur2[4], s.joueur2[3], s.joueur2[2], s.joueur2[1], s.joueur2[0]);
    printf("||=================================================================||\n");
}

// distribution des graines du joueur 1 et prise du joueur 1
void joueur1_joue(songo *s, int troue_jouer) {

    int nb_graine = s->joueur1[troue_jouer];
    int nb_graine1 = s->joueur1[troue_jouer];
    int troue_gene = troue_jouer;
    int i, a, b, troue_final, nb_graine14, score_avant;
    s->joueur1[troue_jouer] = 0;
    int joueur1_0 = s->joueur1[0];
    troue_gene++;
    // petite prise pour le cas de 14 graines
    if (nb_graine == 14)
    {
        s->joueur2[0]--;
        s->score1++;
    }
    // distribution des graines
    while (nb_graine != 0)
    {
        if (troue_gene == 14)
        {
            troue_gene = 0;
        }
        if (troue_gene == troue_jouer)
        {
            troue_gene = 7;
        }

        if (troue_gene < 7)
        {
            s->joueur1[troue_gene]++;
            troue_gene++;
            nb_graine--;
        }
        else
        {
            s->joueur2[troue_gene - 7]++;
            troue_gene++;
            nb_graine--;
        }
    }
    // boucle pour determiner le troue final ou se trouve la graine final
    troue_final = troue_jouer;
    a = 0;
    b = 0;
    if (nb_graine1 == 14)
    {
        nb_graine1 = nb_graine1 - 1;
    }
    for (i = 1; i <= nb_graine1; i++)
    {
        troue_final++;
        if (troue_final > 6)
        {
            troue_final = 0;
            a++;
        }
        if ((troue_final == troue_jouer) && (a > 1) && (a > b + 1))
        {
            troue_final = 0;
            b++;
        }
    }

    // gere la Prise
    if (((a % 2 == 0) && (b % 2 != 0) && (nb_graine1 != 13)) || ((a % 2 != 0) && (b % 2 == 0)) || (troue_jouer == 0) && (joueur1_0 == 13))
    {
        if (((s->joueur2[troue_final] == 2)) || ((s->joueur2[troue_final] == 3)) || ((s->joueur2[troue_final] == 4)))
        {
            s->score1 = s->score1 + s->joueur2[troue_final];
            s->joueur2[troue_final] = 0;
            for (i = troue_final + 1; i <= 6; i++)
            {
                if ((s->joueur2[i] == 2) || (s->joueur2[i] == 3) || (s->joueur2[i] == 4))
                {
                    s->score1 += s->joueur2[i];
                    s->joueur2[i] = 0;
                }
                else
                {
                    i = 7;
                }
            }
        }
    }

    s->tour = 2;
}

// distribution des graines du joueur 2 et prise
void joueur2_joue(songo *s, int troue_jouer2){
    int nb_graine = s->joueur2[troue_jouer2];
    int troue_gene = troue_jouer2;
    int i, a, b, troue_final;
    int nb_graine14;
    int nb_graine1 = nb_graine;
    s->joueur2[troue_jouer2] = 0;
    troue_gene++;
    int joueur2_0 = s->joueur2[0];
    // petite prise pour le cas de 14 graines
    if (nb_graine == 14)
    {
        s->joueur1[0]--;
        s->score2++;
    }
    // distribution des graines
    while (nb_graine != 0)
    {
        if (troue_gene == 14)
        {
            troue_gene = 0;
        }
        if (troue_gene == troue_jouer2)
        {
            troue_gene = 7;
        }

        if (troue_gene < 7)
        {
            s->joueur2[troue_gene]++;
            troue_gene++;
            nb_graine--;
        }
        else
        {
            s->joueur1[troue_gene - 7]++;
            troue_gene++;
            nb_graine--;
        }
    }
    // boucle pour determiner le trou final
    troue_final = troue_jouer2;
    a = 0;
    b = 0;

    if (nb_graine1 == 14)
    {
        nb_graine1 = nb_graine1 - 1;
    }

    for (i = 1; i <= nb_graine1; i++)
    {
        troue_final++;
        if (troue_final > 6)
        {
            troue_final = 0;
            a++;
        }
        if ((troue_final == troue_jouer2) && (a > 1) && (a > b + 1))
        {
            troue_final = 0;
            b++;
        }
    }

    // gere la prise

    if (((a % 2 == 0) && (b % 2 != 0) && (nb_graine1 != 13)) || ((a % 2 != 0) && (b % 2 == 0)) || ((joueur2_0 == 13) && (troue_jouer2 == 0)))
    {

        if (((s->joueur1[troue_final] == 2)) || ((s->joueur1[troue_final] == 3)) || ((s->joueur1[troue_final] == 4)))
        {

            s->score2 = s->score2 + s->joueur1[troue_final];
            s->joueur1[troue_final] = 0;
            for (i = troue_final - 1; i >= 0; i--)
            {
                if (((s->joueur1[i] == 2)) || ((s->joueur1[i] == 3)) || ((s->joueur1[i] == 4)))
                {
                    s->score2 = s->score2 + s->joueur1[i];
                    s->joueur1[i] = 0;
                }
                else
                {
                    i = -1;
                }
            }
        }
    }

    // passe le tour au joueur 1
    s->tour = 1;
}

// permet au joueur 1 d entrer sont coup et verifie certaine regles et verfie si le jeux n est pas fini
void tour_joueur1(songo *s){
    int i = 7;
    int a, c, troue_jouer;
    // verifie si le jeu est fini
    if (s->joueur2[0] + s->joueur2[2] + s->joueur2[3] + s->joueur2[4] + s->joueur2[5] + s->joueur2[6] == 0)
    {
        while (s->joueur1[7 - i] < i)
        {
            i--;
        }
        if ((i == 0))
        {
            s->terminer = 1; // 1 jeu fini

            return;
        }
        if ((s->score2 >= 35) || (s->score1 >= 35))
        {
            s->terminer = 1; // 1 jeu fini

            return;
        }
    }
    // permet au joueur de jouer son coup
    printf("\n%s VEUILLEZ JOUER VOTRE COUP:\t", s->nom_joueur1);
    scanf("%d", &troue_jouer);
    while ((troue_jouer < 1) || (troue_jouer > 7))
    {
        printf("\nVEUILLEZ ENTREZ UN NOMBRE COMPRIS ENTRE 1 ET 7:\t");
        scanf("%d", &troue_jouer);
    }
    while (s->joueur1[troue_jouer - 1] == 0)
    {
        printf("\nVEUILLER JOUER UNE CASE NON VIDE:\t");
        scanf("%d", &troue_jouer);
    }
    // verifi une regle
    if ((s->joueur1[6] == 1) && (troue_jouer == 7))
    {
        while ((troue_jouer < 1) || (troue_jouer > 6))
        {
            printf("\nCECI EST INTERDIT VEUILLEZ ENTREZ UN NOMBRE COMPRIS ENTRE 1 ET 6:\t");
            scanf("%d", &troue_jouer);

            while (s->joueur1[troue_jouer - 1] == 0)

            {
                printf("\nVEUILLER JOUER UNE CASE NON VIDE:\t");
                scanf("%d", &troue_jouer);
            }
        }
    }
    a = 0;
    // oblige l utilisateur a jouer sa case ayant le plus de graine
    if (s->joueur2[0] + s->joueur2[2] + s->joueur2[3] + s->joueur2[4] + s->joueur2[5] + s->joueur2[6] == 0)
    {
        for (i = 0; i < 7; i++)
        {
            if ((i == 0) || (c < s->joueur1[i]))
            {
                c = s->joueur1[i];
                a = i;
            }
        }
        while (troue_jouer != a + 1)
        {
            printf("\nCHICHE! JOUER VOTRE CASE AYANT LE PLUS DE GRAINE:\t");
            scanf("%d", &troue_jouer);
        }
    }
    // verifie une regle
    int score_avant;
    int joueur1_6 = s->joueur1[6];
    score_avant = s->score1;
    joueur1_joue(s, troue_jouer - 1);
    if ((troue_jouer == 7) && (joueur1_6 == 2))
    {
        while ((score_avant == s->score1) && (troue_jouer == 7))
        {
            s->joueur2[0] -= 1;
            s->joueur2[1] -= 1;
            s->joueur1[6] += 2;
            while ((troue_jouer < 1) || (troue_jouer > 6))
            {
                printf("\nCECI EST UN INTERDIT VEUILLEZ ENTREZ UN NOMBRE COMPRIS ENTRE 1 ET 6:\t");
                scanf("%d", &troue_jouer);

                while (s->joueur1[troue_jouer - 1] == 0)

                {
                    printf("\nVEUILLER JOUER UNE CASE NON VIDE:\t");
                    scanf("%d", &troue_jouer);
                }
            }
        }
        joueur1_joue(s, troue_jouer - 1);
    }
}

// permet au joueur 2 d entrer sont coup et verifie certaine regles et verfie si le jeux n est pas fini
void tour_joueur2(songo *s,int choix){
    int i = 7;
    int a, c, troue_jouer2;
    // verifie si le jeu est fini
    if (s->joueur1[0] + s->joueur1[1] + s->joueur1[2] + s->joueur1[3] + s->joueur1[4] + s->joueur1[5] + s->joueur1[6] == 0)
    {
        while (s->joueur1[7 - i] < i)
        {
            i--;
        }
        if (i == 0)
        {
            s->terminer = 1;

            return;
        }
    }
    if ((s->score2 >= 35) || (s->score1 >= 35))
    {
        s->terminer = 1;

        return;
    }
    // permet au joueur 2 de jouer son coup
    if(choix == 2){
        printf("\n%s VEUILLEZ JOUER VOTRE COUP:\t", s->nom_joueur2);
        scanf("%d", &troue_jouer2);
        while ((troue_jouer2 < 1) || (troue_jouer2 > 7))
        {
            printf("\nVEUILLEZ ENTREZ UN NOMBRE COMPRIS ENTRE 1 ET 7:\t");
            scanf("%d", &troue_jouer2);
        }
        while (s->joueur2[7 - troue_jouer2] == 0)
        {
            printf("\nVEUILLER JOUER UNE CASE NON VIDE:\t");
            scanf("%d", &troue_jouer2);
        }
    }else{
        srand(time(0));
        troue_jouer2 = rand() % 7;
        while ((troue_jouer2 < 1) || (troue_jouer2 > 7))
        {
           troue_jouer2 = rand() % 7;
        }
        while (s->joueur2[7 - troue_jouer2] == 0)
        {
            troue_jouer2 = rand() % 7;
        }
    }
    
    // verifie une regle
    if ((s->joueur2[6] == 1) && (troue_jouer2 == 1))
    {
        while ((troue_jouer2 < 2) || (troue_jouer2 > 7))
        {
            printf("\nCECI EST INTERDIT VEUILLEZ ENTREZ UN NOMBRE COMPRIS ENTRE 2 ET 7:\t");
            scanf("%d", &troue_jouer2);

            while (s->joueur2[7 - troue_jouer2] == 0)
            {
                printf("\nVEUILLER JOUER UNE CASE NON VIDE:\t");
                scanf("%d", &troue_jouer2);
            }
        }
    }
    // verifie une regle
    if (s->joueur1[0] + s->joueur1[1] + s->joueur1[2] + s->joueur1[3] + s->joueur1[4] + s->joueur1[5] + s->joueur1[6] == 0)
    {
        for (i = 0; i < 7; i++)
        {
            if ((i == 0) || (c < s->joueur2[i]))
            {
                c = s->joueur2[i];
                a = i;
            }
        }
        while (troue_jouer2 != 7 - i)
        {
            printf("\nCHICHE! JOUER VOTRE CASE AYANT LE PLUS DE GRAINE:\t");
            scanf("%d", &troue_jouer2);
        }
    }
    int score_initial = s->score2;
    int joueur2_6 = s->joueur2[6];
    joueur2_joue(s, 7 - troue_jouer2);
    if ((troue_jouer2 == 1) && (joueur2_6 == 2))
    {
        while ((score_initial == s->score2) && (troue_jouer2 == 1))
        {
            s->joueur1[0] = s->joueur1[0] - 1;
            s->joueur1[1] = s->joueur1[1] - 1;
            s->joueur2[6] = s->joueur2[6] + 2;
            while ((troue_jouer2 < 2) || (troue_jouer2 > 7))
            {
                printf("\nCECI EST UN INTERDIT VEUILLEZ ENTREZ UN NOMBRE COMPRIS ENTRE 2 ET 7:\t");
                scanf("%d", &troue_jouer2);

                while (s->joueur2[7 - troue_jouer2] == 0)
                {
                    printf("\nVEUILLER JOUER UNE CASE NON VIDE:\t");
                    scanf("%d", &troue_jouer2);
                }
            }
        }
        joueur2_joue(s, 7 - troue_jouer2);
    }
}

// affiche le gagnant
void affiche_gagnant(songo *s){
    if (s->score1 > s->score2)
    {
        printf("LE GAGNANT EST  %s FELICITATION", s->nom_joueur1);
    }
    else if (s->score1 < s->score2)
    {
        printf("LE GAGNANT EST  %s FELICITATION", s->nom_joueur2);
    }
    else
    {
        printf("FELICITATIONS A VOUS 2 :JEUX EGAL");
    }
}
