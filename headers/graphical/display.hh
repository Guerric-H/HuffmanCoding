#pragma once

#include "tree_node/tree.hh"
#include "tree_node/node.hh"

#include <QtGui/QWidget>

class window : public QWidget
{
private:
    ArbreB &tree;

public:
    //Graphical window by default. Using paintEvent will draw the needed content.
    window(ArbreB &tree) : tree(tree) { resize(1, 1); }
    void paintEvent(QPaintEvent *event);
    ~window();
};