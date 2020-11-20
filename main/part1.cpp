#include "tree_node/node.hh"
#include "tree_node/tree.hh"
#include "graphical/display.hh"

#include <iostream>
#include <QtGui/QApplication>
#include <QtGui/QWidget>
#include <QtGui/QScrollArea>
#include <QtGui/QGridLayout>

int main(int argc,char **argv)
{
    ArbreB tree ;
    for (int i = 0 ; i < 300 ; i++)
        tree.insert(i,i);

    QApplication GUI(argc,argv);
    QWidget mainWindow ;
    QGridLayout layout;
    QScrollArea scrollbar;

    mainWindow.setLayout(&layout);
    layout.addWidget(&scrollbar, 0, 0);

    window graphical(tree) ;
    mainWindow.show();
    
    scrollbar.setWidget(&graphical);
    scrollbar.resize(500, 500);
    scrollbar.show();
    
    graphical.show();

 return GUI.exec() ;
}