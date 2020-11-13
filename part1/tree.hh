#pragma once

#include "node.hh"

//Création d'une classe pour un arbre binaire. Il commence par un noeud racine.


class ArbreB {
private:
    //Racine de l'arbre.
    Sommet *root ;

public:

    // Set the two roots's father to a new Sommet, then reassign the actual Root to the new one.
    void fusion(ArbreB *target) ;
    // Add the target Sommet to the first available left/right Sommet.
    void insert(Sommet* target) ;
    // Delete the actual target from the ArbreB and the others letf/right downwards. Exist with Sommet * or char research.
    void suppress(Sommet* target) ;
    void suppress(char value) ;
    // Check each Sommet until we find a matching char. Return the associated pointer to the Sommet.
    Sommet* find (char value) ;
    // Separate the targeted Sommet from the ArbreB but instead of deleting it, creating a new ArbreB using the target as a root.
    ArbreB* remove(Sommet* target) ;

}