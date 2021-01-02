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
    std::string encoded;
    std::string decoded;
    std::string checker;

    QTextEdit *showEncoded;
    QTextEdit *showDecoded;
    QTextEdit *showChecker;
    QLabel *input;
    QLabel *output;
    QLabel *titleChecker;
    QGridLayout *layout;
    QPushButton *convert;

public :
    graphicDecoding();
    ~graphicDecoding();
    QSize sizeHint() const { return QSize(400, 400); }

public slots:
    void decoderChanged();
    void buttonPressed();
signals:
};
