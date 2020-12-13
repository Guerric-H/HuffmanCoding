#pragma once

#include "tree_node/tree.hpp"

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
    //Constructor and Destructor :
    encoder(std::string text);
    ~encoder();

    //Encoder core :
    void charMapping();
    void multiMapBuilder();
    void buildTree();
    void charToBinary(std::string text, Sommet *current);
    void encodeText();
    void encode();

    //Encoder producing stats from string (% for each char)
    std::map<char, float> createStats();

    //optional : getters
    std::map<char, int> getcharCount();
    std::multimap<int, ArbreB> getSubTree();
    std::string getEncoded();
    std::string getText();
    void setText(std::string str);
    ArbreB &getTree();
};
