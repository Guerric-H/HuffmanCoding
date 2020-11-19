#include "tree_node/node.hh"
#include "tree_node/tree.hh"
#include "graphical/display.hh"

#include <iostream>
#include <QtGui/QApplication>

int main(int argc,char **argv)
{
    ArbreB tree ;
    tree.insert('t',10) ;
    tree.insert('p',5) ;
    tree.insert('d',5) ;
    tree.insert('r',10) ;
    tree.insert('l',10) ;
    tree.insert('s',0) ;
    
    /*
    QApplication app(argc,argv);
    window graphical ;

    graphical.drawTree();
    */

 return 0;//app.exec();
}