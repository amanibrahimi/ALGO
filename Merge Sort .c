#include <stdio.h>
#include <stdlib.h>



// Fusionne deux sous-tableaux de arr[]
// Le premier sous-tableau est arr[l..m]
// Le second sous-tableau est arr[m+1..r]
void fusion(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    // Création de sous-tableaux temporaires
    int L[n1], R[n2];

    // Copie des données dans les sous-tableaux temporaires L[] et R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // Fusion des sous-tableaux temporaires dans arr[l..r]
    i = 0; // Index initial du premier sous-tableau
    j = 0; // Index initial du second sous-tableau
    k = l; // Index initial du tableau fusionné
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copie des éléments restants de L[], s'il y en a
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copie des éléments restants de R[], s'il y en a
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Fonction principale qui trie arr[l..r] en utilisant le tri par fusion
// l est l'indice de début tableau
// r est l'indice de la derniére case
void triFusion(int arr[], int l, int r) {
    if (l < r) {
        // Trouver le point médian
        int m = l + (r - l) / 2;

        // Trier la première et la deuxième moitié
        triFusion(arr, l, m);
        triFusion(arr, m + 1, r);

        // Fusionner les moitiés triées
        fusion(arr, l, m, r);
    }
}

// Fonction utilitaire pour afficher un tableau donné
void afficherTableau(int arr[], int taille) {
    int i;

    for (i = 0; i < taille; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
// Exemple d'utilisation
int main() {
    int arr[100];
    int taille;
     printf (" donner la taille du tableau");
     scanf("%d",&taille);
      for (int i = 0; i < taille; i++) {
        printf("Element %d : ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("Tableau original :\n");
    afficherTableau(arr, taille);

    triFusion(arr, 0, taille - 1);

    printf("\nTableau trier :\n");
    afficherTableau(arr, taille);
    return 0;
}
