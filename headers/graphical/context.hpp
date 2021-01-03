#pragma once
#include <QtCore/QObject>
#include "encoding/encoding.hpp"
#include "decoding/decoding.hpp"

class context : public QObject
{
    Q_OBJECT

private:
    encoder huffman;
    decoder translater;
    context();

public:

    //Create a context (named singleton for the representation)
    static context &instance()
    {
        static context singleton;
        return singleton;
    }

    //After creation, initialize our context with simple constructors for encoder and decoder.
    void init();

    //Getters
    encoder &getHuffman();
    decoder &getDecoder();
    
    //Destructor
    ~context();

    //This is made to avoid multiple context in the program with static.
    context(context &) = delete;
    context &operator=(context &) = delete;

//Setters for encoder and decoder
public slots:
    void setHuffman(std::string const &input);
    void setDecoder(std::string const &input);
//Widget's associated methods will be triggered once these signals occur. 
signals:
    void huffmanChanged();
    void decoderChanged();
};