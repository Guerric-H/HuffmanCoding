#pragma once


#include <map>
#include "encoding/encoding.hpp"
#include "graphical/context.hpp"

#include <QtCore/QObject>
#include <QtGui/QWidget>
#include <QtGui/QLabel>
#include <QtGui/QTextEdit>
#include <QtGui/QGridLayout>
#include <QtGui/QPushButton>


class graphicEncoding : public QWidget
{
    Q_OBJECT
private:
    //Original message
    std::string text;
    //Encoded message
    std::string encoded;
    //Associated stats from the message 
    std::string stats;

   //Graphical tools to show previous strings.
    QTextEdit *showText;
    QTextEdit *showEncoded;
    QTextEdit *showStats;

    //Title for each box
    QLabel *input;
    QLabel *output;
    QLabel *titleStats;

    //Button to signal something changed
    QPushButton *convert;

    //Organize our widget
    QGridLayout *layout;

public:
    graphicEncoding();
    ~graphicEncoding();
    QSize sizeHint() const { return QSize(400, 400); }

public slots:
    //Called when a button is pressed, refresh data and encode new message.
    void huffmanChanged();
    //Called when button is Clicked
    void buttonPressed();
};