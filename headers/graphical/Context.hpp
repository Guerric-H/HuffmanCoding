#pragma once
#include <QtCore/QObject>
#include "encoding/encoding.hpp"

class Context : public QObject
{
    Q_OBJECT

private:
    encoder huffman;

    Context() : huffman("") {}

public:
    static Context &instance()
    {
        static Context singleton;
        return singleton;
    }

    void init()
    {
        setHuffman("Just a little typing test to show how the program behave. Note that you can change this text and click on the Button *Convert Text*.");
    }

    encoder &getHuffman()
    {
        return huffman;
    }

    ~Context(){};

    Context(Context &) = delete;
    Context &operator=(Context &) = delete;

public slots:
    void setHuffman(std::string const &input)
    {
        huffman.setText(input);
        huffman.encode();
        for (auto &i : huffman.createStats())
            std::cout << "Lettre : \'" << i.first << "\' Occurence : " << i.second << "%" << std::endl;
        emit huffmanChanged();
    }

signals:
    void huffmanChanged();
};