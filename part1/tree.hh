#pragma once

#include "node.hh"

//Création d'une classe pour un arbre binaire. Il commence par un noeud racine.


class ArbreB {
private:
    //Racine de l'arbre.
    Sommet *root ;

public:

  //Constructors :
    ArbreB() ;
    ArbreB(Sommet *root) ;

  //Functions :
    // Set the two roots's father to a new Sommet, then reassign the actual Root to the new one.
    void fusion(ArbreB const& target) ;
    // Add the target Sommet to the first available left/right Sommet.
    void insert(char value, int count) ;
    // Delete the actual target from the ArbreB and the others letf/right downwards. Exist with Sommet * or char research.
    void suppress(char value) ;
    // Check each Sommet until we find a matching char. Return the associated pointer to the Sommet.
    Sommet* find (char value) ;
};