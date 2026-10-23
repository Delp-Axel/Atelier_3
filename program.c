#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

//Bilan de la partie: étape 2
void afficher_bilan(int scoreJoueur, int scoreOrdi) {
    printf("=== FIN DE LA PARTIE ===\n");
    printf("Score final -> Vous: %d | Ordi: %d\n", scoreJoueur, scoreOrdi);
    
    if (scoreJoueur > scoreOrdi) {
        printf("Bravo, vous avez gagné la partie !\n");
    }
    else if (scoreOrdi > scoreJoueur) {
        printf("L'ordinateur remporte la partie...\n");
    }
    else {
        printf("Match nul parfait !\n");
    }
}

//Affichage textuel d'un choix: étape 3
void afficher_choix(int choix) {
    if (choix == 1) printf("Pierre");
    else if (choix == 2) printf("Feuille");
    else if (choix == 3) printf("Ciseaux");
    else if (choix == 4) printf("Lézard");
    else if (choix == 5) printf("Spock");
}
// Détermine si la partie doit continuer
bool partie_en_cours(int manche, int scoreJoueur, int scoreOrdi) {
    return (manche <= 7 && (scoreJoueur - scoreOrdi) < 2 && (scoreOrdi - scoreJoueur) < 2);
}

// Gère l'affichage du menu et la saisie sécurisée du joueur
int saisie_joueur() {
    int choixJoueur;
    bool incorrect;
    do {
        printf("Choix ( ");
        for (int i = 1; i <= 5; i++) {
            printf("%d=", i);
            afficher_choix(i);
            if (i < 5) printf(", ");
        }
        printf(") : ");
        
        scanf("%d", &choixJoueur);
        incorrect = (choixJoueur < 1 || choixJoueur > 5);
        
        if (incorrect) {
            printf("Non valide, valeurs de 1 à 5 acceptées\n");
        }
    } while (incorrect);
    
    return choixJoueur;
}

// Détermine si le joueur 1 remporte la manche
bool joueur1_gagne(int choixJoueur, int choixOrdi) {
    if ((choixJoueur == 1 && (choixOrdi == 3 || choixOrdi == 4)) ||
        (choixJoueur == 2 && (choixOrdi == 1 || choixOrdi == 5)) ||
        (choixJoueur == 3 && (choixOrdi == 2 || choixOrdi == 4)) ||
        (choixJoueur == 4 && (choixOrdi == 2 || choixOrdi == 5)) ||
        (choixJoueur == 5 && (choixOrdi == 1 || choixOrdi == 3))) 
    {
        return true;
    }
    return false;
}

int main()
{
    int scoreJoueur = 0;
    int scoreOrdi = 0;
    int manche = 1;
    int choixJoueur;
    int choixOrdi;

    printf("=== PIERRE, FEUILLE, CISEAUX, LEZARD, SPOCK (7 Manches / avantage décisif de 2) ===\n");

    // Utilisation de la fonction partie_en_cours
    while (partie_en_cours(manche, scoreJoueur, scoreOrdi))
    {
        printf("--- Manche %d/7---\n", manche);
        
        // Utilisation de la fonction saisie_joueur
        choixJoueur = saisie_joueur();

        // Choix aléatoire de l'ordinateur
        choixOrdi = (rand() % 5) + 1;
        printf("L'ordinateur a choisi: ");
        afficher_choix(choixOrdi);
        printf("\n");

        // Utilisation de la fonction joueur1_gagne
        if (choixJoueur == choixOrdi)
        {
            printf("Égalité !\n");
        }
        else if (joueur1_gagne(choixJoueur, choixOrdi))
        {
            printf("Vous gagnez cette manche !\n");
            scoreJoueur = scoreJoueur + 1;
        }
        else
        {
            printf("L'ordinateur gagne cette manche !\n");
            scoreOrdi = scoreOrdi + 1;
        }
        
        printf("Score actuel -> Vous: %d | Ordi: %d\n\n", scoreJoueur, scoreOrdi);
        manche = manche + 1;
    }

    // Utilisation de la fonction afficher_bilan
    afficher_bilan(scoreJoueur, scoreOrdi);

    return 0;
}