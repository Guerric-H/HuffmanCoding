#pragma once

#include "tree_node/tree.hh"
#include "tree_node/node.hh"

#include <QtGui/QWidget>

class window : public QWidget {
private :

public :
    //Graphical window by default. Using methods will draw the needed content. 
    window() ;
    void drawTree(ArbreB& tree) ;
    ~window() ;
};