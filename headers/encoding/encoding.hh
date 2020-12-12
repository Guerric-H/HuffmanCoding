#pragma once

#include "tree_node/tree.hh"

#include <iostream>
#include <utility>
#include <iterator>
#include <map>

class encoder
{
private:
    std::string text = "";
    std::string encoded = "";
    std::map<char, int> charCount;
    std::map<char, std::string> charCoded;
    std::multimap<int, ArbreB> TreeMap;
    ArbreB tree;

public:
    //Constructor :
    encoder(std::string text);

    //Encoder core :
    void charMapping();
    void multiMapBuilder();
    void huffmanTree();
    void charToBinary(std::string text, Sommet *current);
    void encodeText();
    void encode();

    //optional : getters
    std::map<char, int> getcharCount();
    std::multimap<int, ArbreB> getSubTree();
    std::string getEncoded();
    std::string getText();
    ArbreB getTree();
};
