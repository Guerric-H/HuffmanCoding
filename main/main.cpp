//#include <iostream>

#include "tree_node/node.hpp"
#include "tree_node/tree.hpp"

#include "encoding/encoding.hpp"
#include "decoding/decoding.hpp"

#include "graphical/context.hpp"
#include "graphical/mainwindow.hpp"
#include <QtGui/QApplication>

int main(int argc, char **argv)
{
    QApplication GUI(argc, argv);

    context &ctxt = context::instance();
    mainWindow screen;
    ctxt.init();

    //Display everything.
    screen.show();
    return GUI.exec();
}