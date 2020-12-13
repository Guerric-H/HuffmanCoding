
#include "encoding/encoding.hpp"
#include "graphical/display.hpp"
#include "graphical/Context.hpp"
#include "tree_node/node.hpp"
#include "tree_node/tree.hpp"

#include <iostream>
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