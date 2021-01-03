#pragma once

#include "decoding/decoding.hpp"
#include "graphical/context.hpp"

#include <QtCore/QObject>
#include <QtGui/QWidget>
#include <QtGui/QLabel>
#include <QtGui/QTextEdit>
#include <QtGui/QGridLayout>
#include <QtGui/QPushButton>

class graphicDecoding : public QWidget
{
    Q_OBJECT
private :
    //Encoded text (made of 0 and 1)
    std::string encoded;
    //Decoded text (if the decoder is able to produce a message from encoded one)
    std::string decoded;
    //Informative message for Tree validity concerning the encoded message.
    std::string checker;

    //Graphical tools to show previous strings.
    QTextEdit *showEncoded;
    QTextEdit *showDecoded;
    QTextEdit *showChecker;
    //Title for each box 
    QLabel *input;
    QLabel *output;
    QLabel *titleChecker;

    //Button to signal something changed
    QPushButton *convert;

    //Organize our Widget
    QGridLayout *layout;

public :
    graphicDecoding();
    ~graphicDecoding();
    QSize sizeHint() const { return QSize(400, 400); }

public slots:
    //Called by buttonPressed (both are distinct for clarity purpose)
    void decoderChanged();
    //Called when button is Clicked
    void buttonPressed();
};
