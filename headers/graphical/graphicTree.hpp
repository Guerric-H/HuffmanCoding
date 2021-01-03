#pragma once

#include <stack>

#include <QtCore/QObject>
#include <QtGui/QWidget>
#include <QtGui/QPainter>

#include "tree_node/tree.hpp"
#include "tree_node/node.hpp"
#include "graphical/context.hpp"

class graphicTree : public QWidget
{
    Q_OBJECT

private:
    ArbreB *tree;

public:
    //Graphical window by default. Using paintEvent will draw the needed content.
    graphicTree();
    //Tree drawer.
    void paintEvent(QPaintEvent *event);
    //Destructor
    ~graphicTree();

    QSize sizeHint() const { return QSize(900, 900); }

public slots:
    //Called when a button is pressed, refresh the Tree with new one.
    void huffmanChanged();
};