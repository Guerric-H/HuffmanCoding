
#include "encoding/encoding.hh"
#include "graphical/display.hh"
#include "tree_node/node.hh"
#include "tree_node/tree.hh"

#include <iostream>
#include <QtGui/QApplication>
#include <QtGui/QWidget>
#include <QtGui/QScrollArea>
#include <QtGui/QGridLayout>

int main(int argc, char **argv)
{
    std::string text = "abqzihjrfầz,d";
    encoder huffman = encoder(text);
    huffman.charMapping();
    huffman.multiMapBuilder();
    huffman.huffmanTree();
    huffman.encodeText();

    std::cout << huffman.getText() << std::endl
              << huffman.getEncoded() << std::endl;

    ArbreB finalTree = huffman.getTree();

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