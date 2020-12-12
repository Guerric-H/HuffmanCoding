#pragma once

#include "node.hh"

//Création d'une classe pour un arbre binaire. Il commence par un noeud racine.

class ArbreB
{
private:
  //Racine de l'arbre.
  Sommet *root{nullptr};
  ArbreB(Sommet *root);

public:
  //Constructors :
  ArbreB();
  ArbreB(short value, int count);
  ArbreB(Sommet &root);
  ArbreB(ArbreB const &target);

  //Overloaded operator= for deepcopy purpose.
  ArbreB &operator=(const ArbreB &target);

  //Methods :
  Sommet *getRoot();
  // Set the two roots's father deepcopy to a new Sommet, then return the associated ArbreB. ! This does not modify any param ArbreB.
  ArbreB fusion(ArbreB &target);
  // Add the target Sommet to the first available left/right Sommet.
  void insert(short value, int count);
  // Delete the actual target from the ArbreB and the others letf/right downwards. Exist with Sommet * or char research.
  void suppress(short value);
  // Check each Sommet until we find a matching char. Return the associated pointer to the Sommet.
  Sommet *find(short value);
  // Suppress the target Sommet from the tree and return a new ArbreB with the removed Sommet being the root. if no such Sommet is found, return a ArbreB by default.
  ArbreB remove(short target);

  ~ArbreB();
};