
//Basic headers
#include <iostream>
//Tree headers
#include "tree_node/node.hpp"
#include "tree_node/tree.hpp"
//Encoding headers
#include "encoding/encoding.hpp"
//Decoding headers
#include "decoding/decoding.hpp"
//GUI headers
#include "graphical/context.hpp"
#include "graphical/mainwindow.hpp"
#include <QtGui/QApplication>

int main(int argc, char **argv)
{
    QApplication GUI(argc, argv);

    Context &ctxt = Context::instance();
    mainWindow screen;
    ctxt.init();

    //Display everything.
    screen.show();
    return GUI.exec();
}