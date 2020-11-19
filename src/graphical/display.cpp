#include "graphical/display.hh"
#include <iostream>

    window::window() {}
    window::~window() {}
    void window::drawTree(ArbreB& tree) {

        int x{0}, y{0};
        char keep_going{1}, step_backward{0};
        Sommet *current{tree.give_root()}, *prec{tree.give_root()};

        while (keep_going) {

            while (current->getLeft() && !step_backward) {

                x++;
                y++;
                for (int i=0;i<x;i++) {
                    std::cout << "\t";
                }
                current = current->getLeft();
                std::cout << "[" << current->getValue() << "]\n";

            }

            if ( ( (current->getRight()) ? (current->getRight() != prec) : (0) ) ) {

                x++;
                y++;
                step_backward = 0;
                for (int i=0;i<x;i++) {
                    std::cout << "\t";
                }
                current = current->getRight();
                std::cout << "[" << current->getValue() << "]\n";

            } else {

                x--;
                step_backward = 1;
                prec = current;
                current = current->getFather();

            }

            if (current == tree.give_root() && step_backward && ( (current->getRight()) ? (current->getRight() == prec) : 1 )) keep_going = 0;


        }

        std::cout << "sortit de l'abre\n";
    }


