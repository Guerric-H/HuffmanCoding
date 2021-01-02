#include "graphical/mainwindow.hpp"

mainWindow::mainWindow()
{
    layout = new QGridLayout();
    setLayout(layout);

    scrollbar = new QScrollArea();
    layout->addWidget(scrollbar, 0, 0);

    tree = new graphicTree();
    scrollbar->setWidget(tree);

    encoding = new graphicEncoding();
    layout->addWidget(encoding, 0, 1);

    decoding = new graphicDecoding();
    layout->addWidget(decoding,0,2);
}

mainWindow::~mainWindow() {}