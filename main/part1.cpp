#include "tree_node/node.hh"
#include "tree_node/tree.hh"
#include "graphical/display.hh"

#include <iostream>

//#include <QtGui/QApplication>

int main(int argc,char **argv)
{
    ArbreB tree ;
    tree.insert('t',10) ;
    tree.insert('p',5) ;
    tree.insert('d',5) ;
    tree.insert('r',10) ;
    tree.insert('l',10) ;
    tree.insert('s',0) ;

    Sommet *curr = tree.give_root();

    std::cout << "Racine : " << ( (curr) ? (curr->getValue()) : ('0') ) << ", fils : " << ( (curr->getLeft()) ? (curr->getLeft()->getValue()) : ('0') ) << " | " << ( (curr->getRight()) ? (curr->getRight()->getValue()) : ('0') ) << "\n";
    curr = curr->getLeft();
    std::cout << "Racine : " << ( (curr) ? (curr->getValue()) : ('0') ) << ", fils : " << ( (curr->getLeft()) ? (curr->getLeft()->getValue()) : ('0') ) << " | " << ( (curr->getRight()) ? (curr->getRight()->getValue()) : ('0') ) << "\n";
    curr = curr->getFather()->getRight();
    std::cout << "Racine : " << ( (curr) ? (curr->getValue()) : ('0') ) << ", fils : " << ( (curr->getLeft()) ? (curr->getLeft()->getValue()) : ('0') ) << " | " << ( (curr->getRight()) ? (curr->getRight()->getValue()) : ('0') ) << "\n";
    
    std::cout << "La racine a-t-elle un fils droit ? " << ( ( tree.give_root()->getRight() ) ? ("Oui :") : ("Non :") ) << tree.give_root()->getRight() << "\n";
    /*
    QApplication app(argc,argv);*/
    window graphical ;

    graphical.drawTree(tree);

 return 0;//app.exec();
}