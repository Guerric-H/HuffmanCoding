#include "tree_node/node.hh"
#include "tree_node/tree.hh"
#include "graphical/display.hh"

#include <iostream>
#include <QtGui/QApplication>
#include <QtGui/QWidget>
#include <QtGui/QScrollArea>
#include <QtGui/QGridLayout>

int main(int argc, char **argv)
{
    ArbreB tree;
    for (int i = 0; i < 30; i++)
        tree.insert(97 + i, i);

    tree.suppress(120);

    ArbreB otherTree;
    for (int i = 0; i < 20; i++)
        otherTree.insert(50 + i, i);

    ArbreB finalTree = tree.fusion(otherTree);

    QApplication GUI(argc, argv);
    QWidget mainWindow;
    QGridLayout layout;
    QScrollArea scrollbar;

    mainWindow.setLayout(&layout);
    layout.addWidget(&scrollbar, 0, 0);

    window graphical(finalTree);
    mainWindow.show();

    scrollbar.setWidget(&graphical);
    scrollbar.resize(500, 500);
    scrollbar.show();

    graphical.show();

    return GUI.exec();
}