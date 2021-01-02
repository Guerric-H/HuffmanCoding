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
    graphicTree *tree;
    graphicEncoding *encoding;
    graphicDecoding *decoding ;

    QGridLayout *layout;
    QScrollArea *scrollbar;

public:
    mainWindow();
    ~mainWindow();
};
