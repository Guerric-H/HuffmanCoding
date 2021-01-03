#pragma once

#include <QtGui/QWidget>
#include <QtGui/QScrollArea>
#include <QtGui/QGridLayout>


#include "graphical/context.hpp"
#include "graphical/graphicTree.hpp"
#include "graphical/graphicEncoding.hpp"
#include "graphical/graphicDecoding.hpp"

class mainWindow : public QWidget
{
private:
    //Widget made to display a Binary Tree.
    graphicTree *tree;
    //Widget made to display a message, it's encoded version and associated statistics.
    graphicEncoding *encoding;
    //Widget made to display an encoded message, it's decoded version if it can be, and a note to tell if the encoded message was created by the given Tree or not.
    graphicDecoding *decoding ;

    //Organize our widget
    QGridLayout *layout;
    //Put the Binary Tree in a associated Widget to make sure it can be shown properly even if the Tree is too big.
    QScrollArea *scrollbar;

public:
    mainWindow();
    ~mainWindow();
};
