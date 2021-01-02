#pragma once
#include <QtCore/QObject>
#include "encoding/encoding.hpp"
#include "decoding/decoding.hpp"

class Context : public QObject
{
    Q_OBJECT

private:
    encoder huffman;
    decoder translater;

    Context() : huffman() , translater() {}

public:
    static Context &instance()
    {
        static Context singleton;
        return singleton;
    }

    void init()
    {
        setHuffman("Just a little typing test to show how the program behave. Note that you can change this text and click on the Button *Convert Text*.");
        setDecoder(huffman.getEncoded());
    }

    encoder &getHuffman()
    {
        return huffman;
    }

    decoder &getDecoder()
    {
        return translater ;
    }

    ~Context(){};

    Context(Context &) = delete;
    Context &operator=(Context &) = delete;

public slots:
    void setHuffman(std::string const &input)
    {
        huffman.setText(input);
        huffman.encode();
        emit huffmanChanged();
    }

    void setDecoder(std::string const &input)
    {
        translater.setEncoded(input);
        translater.setTree(huffman.getTree());
        translater.decode();
        translater.verification();

        emit decoderChanged();
    }

signals:
    void huffmanChanged();
    void decoderChanged();
};