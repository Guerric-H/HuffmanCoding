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
    std::string text;
    std::string encoded;
    std::string stats;

    QTextEdit *showText;
    QTextEdit *showEncoded;
    QTextEdit *showStats;
    QLabel *input;
    QLabel *output;
    QLabel *titleStats;
    QGridLayout *layout;
    QPushButton *convert;

public:
    graphicEncoding();
    ~graphicEncoding();
    QSize sizeHint() const { return QSize(400, 400); }

public slots:
    void huffmanChanged();
    void buttonPressed();
signals:
};