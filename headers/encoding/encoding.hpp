#pragma once

#include "tree_node/tree.hpp"

#include <iostream>
#include <sstream>
#include <utility>
#include <iterator>
#include <map>

class encoder
{
private:
    std::string text = "";
    std::string encoded = "";
    std::string stats = "";
    std::map<char, int> charCount;
    std::map<char, float> statsMap;
    std::map<char, std::string> charCoded;
    std::multimap<int, ArbreB> TreeMap;
    ArbreB tree;

public:
    //Constructor and Destructor :
    encoder();
    ~encoder();

    //Encoder core :
    void charMapping();
    void multiMapBuilder();
    void buildTree();
    void charToBinary(std::string text, Sommet *current);
    void encodeText();
    void encode();

    //Encoder producing stats from string (% for each char)
    void createStats();

    //optional : getters
    std::map<char, int> getcharCount();
    std::multimap<int, ArbreB> getSubTree();
    std::string getEncoded();
    std::string getText();
    std::string getStats();
    ArbreB &getTree();

    //Useful setter :
    void setText(std::string newText);
};
