#include "graphical/display.hh"
#include <iostream>

    window::window() {}
    window::~window() {}
    void window::drawTree(ArbreB& tree) {
        //correspondent à la position où afficher les sommets, 
        int x{0}, //ici leur distance horizontale à la racine, qui varie avec la profondeur du sommet dans l'arbre
            y{0}; //là leur profondeur dans l'affichage, qui augmente pour chaque sommet affiché
        char keep_going{1}, step_backward{0};
        Sommet *current{tree.give_root()}, *prec{tree.give_root()};

        std::cout << "Racine :\n[" << current->getValue() << "]\n";//draw

        //si l'arbre n'as que sa racine, on l'affiche et on ne parcours pas l'arbre
        if ( !current->getRight() && !current->getLeft() ) keep_going = 0;

        //on vas parcourir l'arbre en profondeur par la gauche
        while (keep_going) {

            while (current->getLeft() && //on cherche à entré dans le fils gauche
                    !step_backward) {    //si l'on remonte à ce sommet, on a alors forcément déjà visité son fils gauche

                x++;       //on s'enfoncez dans l'arbre, donc on augmente x;
                y++;       //on entre dans un nouveau sommet, donc on augmente y

                current = current->getLeft();

                for (int i=0;i<x;i++) {                          //draw
                    std::cout << "\t";                           // draw correspond au moment où les variables
                }                                                // "x", "y" et "current" sont sauvegardées/utilisée
                std::cout << "[" << current->getValue() << "]\n";// pour afficher le sommet courant

            }
            //si le fils gauche n'existe pas ou que le fils que l'on vient de visiter n'est pas le droit
            if ( ( (current->getRight()) ? (current->getRight() != prec) : (0) ) ) {

                x++;
                y++;

                step_backward = 0;  //on remet la variable à 0 pour pouvoir visiter les fils (si il y'a) de ce fils droit

                current = current->getRight();

                for (int i=0;i<x;i++) {                          //draw
                    std::cout << "\t";                           //
                }                                                //
                std::cout << "[" << current->getValue() << "]\n";//

            //si on a déjà visité les fils, ou qu'il(s) n'existe(nt) pas, on remonte au père
            } else {

                x--;    //on remonte dans l'abre, donc on fait décroitre x
                step_backward = 1;  //On annote que l'on remonte et
                prec = current;     //on annote d'où on remente
                current = current->getFather();

            }
            
            if ( current == tree.give_root() && step_backward && //si l'on vient de remonter jusqu'à la racine
                ( (current->getRight()) ? (current->getRight() == prec) : 1 )//et que le fils droit a été visité ou n'existe pas
            ) keep_going = 0;                                    //alors on finit de visiter l'arbre                   
            
            }

        std::cout << "sortit de l'abre\n";
    }


