#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Produit {
    int ID;
    char Nom[20];
    int Prix;
} Produit;

typedef struct Node {
    Produit Prod;
    struct Node *suivant;
} Node;

//crée une vide liste

Node* creeListe() {
    return NULL;  // ça veut dire la liste est vide
}

//vérifier si la liste est vide

int estVide(Node* tete) {
    return (tete == NULL);
}

//insertion des products au début

Node* insertDebut(Node* tete, Produit p) {
    Node* nouvNode = (Node*) malloc(sizeof(Node));
    nouvNode->Prod = p;

    if (tete == NULL) {               // si la liste est vide
        tete = nouvNode;
        nouvNode->suivant = nouvNode;      
    } else {
        nouvNode->suivant = tete->suivant;   
        tete->suivant = nouvNode;         
    }

    return tete;
}

//insertion des produits à la fin

Node* insertFin(Node* tete, Produit p) {
    Node* nouvNode = (Node*) malloc(sizeof(Node));
    nouvNode->Prod = p;

    if (tete == NULL) { //si la liste est vide
        tete = nouvNode;
        nouvNode->suivant = nouvNode;     
    } else {
        nouvNode->suivant = tete->suivant;   
        tete->suivant = nouvNode;         
        tete = nouvNode;               
    }

    return tete;
}

//Afficher les éléments d'une seule cycle

void displayList(Node* tete ) {
    if (tete == NULL) {
        printf("List est vide.\n");
        return;
    }

    Node* temp = tete->suivant; 
    do {
        printf("ID: %d | Nom: %s | Prix: %d\n",
               temp->Prod.ID,
               temp->Prod.Nom,
               temp->Prod.Prix);
        temp = temp->suivant;
    } while (temp != tete->suivant);  

    printf("\n");
}


//exemple pour tester

int main() {
    Node* tete = creeListe();

    Produit p1 = {1, "Lait", 120};
    Produit p2 = {2, "Sucre", 200};
    Produit p3 = {3, "Ouef", 450};

    tete = insertDebut(tete , p1);
    tete = insertFin(tete , p2);
    tete = insertDebut(tete , p3);

    printf("Liste cercuit est:\n");
    displayList(tete);

    return 0;
}
