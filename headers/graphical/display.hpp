#pragma once

#include <map>
#include <QtGui/QApplication>
#include <QtGui/QWidget>
#include <QtGui/QScrollArea>
#include <QtGui/QGridLayout>
#include <QtGui/QTextEdit>
#include <QtGui/QPainter>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtCore/QObject>

#include "tree_node/tree.hpp"
#include "tree_node/node.hpp"
#include "encoding/encoding.hpp"
#include "graphical/Context.hpp"

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
    void huffmanChanged();
signals:
};

class graphicText : public QWidget
{
    Q_OBJECT
private:
    std::string text;
    std::string encoded;
    std::map<char, float> stats;

    QTextEdit *showText;
    QTextEdit *showEncoded;
    QLabel *input;
    QLabel *output;
    QGridLayout *layout;
    QPushButton *convert;

public:
    //Constructor
    graphicText();
    ~graphicText();
    QSize sizeHint() const { return QSize(900, 900); }

public slots:
    void huffmanChanged();
    void buttonPressed();
signals:
};

class mainWindow : public QWidget
{
private:
    graphicTree *tree;
    graphicText *text;

    QGridLayout *layout;
    QScrollArea *scrollbar;

public:
    mainWindow();
    ~mainWindow();
};
