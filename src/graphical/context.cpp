#include "graphical/context.hpp"

context::context() : huffman() , translater() {}

void context::init()
{
    setHuffman("Just a little typing test to show how the program behave. Note that you can change this text and click on the Button *Convert Text*.");
    setDecoder(huffman.getEncoded());
}

encoder &context::getHuffman(){ return huffman; }
decoder &context::getDecoder(){ return translater; }

context::~context(){}

void context::setHuffman(std::string const &input)    
{
    huffman.setText(input);
    huffman.encode();
    emit huffmanChanged();
}

void context::setDecoder(std::string const &input)
{
    translater.setEncoded(input);
    translater.setTree(huffman.getTree());
    translater.decode();
    translater.verification();

    emit decoderChanged();
}