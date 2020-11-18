#include "tree_node/node.hh"
#include "tree_node/tree.hh"
#include "graphical/display.hh"

#include <QtGui/QApplication>

int main(int argc,char **argv)
{
    QApplication app(argc,argv);
    QWidget window ;
    window.show();
    
 return app.exec();
}