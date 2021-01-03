#pragma once

#include <sstream>
#include <map>
#include "tree_node/tree.hpp"

class encoder
{
private:
    //Original text
    std::string text = "";
    //Encoded text (made of 0 and 1)
    std::string encoded = "";
    //Statistics of the message (percentage of each character)
    std::string stats = "";
    //Occurence map for characters
    std::map<char, int> charCount;
    //Percentage map for characters
    std::map<char, float> statsMap;
    //Associated encoding for each char
    std::map<char, std::string> charCoded;
    //Tree with their associated number of characters.
    std::multimap<int, ArbreB> TreeMap;
    //Final Tree representing the encoding.
    ArbreB tree;

public:
    //Constructor and Destructor :
    encoder();
    ~encoder();

    //Mapping each char with their associated frequence of appearance.
    void charMapping();
    //Creating a specific map containing every SubTree.
    void multiMapBuilder();
    //Using multimap to create our final Tree.
    void buildTree();
    //Associating an encoding for each char.
    void charToBinary(std::string text, Sommet *current);
    //Taking the original message and creating an encoded one with it.
    void encodeText();
    //Gathering every steps in one big method. Basically encoding from a string.
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
