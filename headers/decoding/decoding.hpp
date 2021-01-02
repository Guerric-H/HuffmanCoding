#pragma once

#include <iostream>
#include <map>
#include "tree_node/tree.hpp"
#include "tree_node/node.hpp"

class decoder
{
private:
    std::string encoded = "";
    std::string decoded = "";
    std::string checker = "";
    ArbreB *tree ;
public:
    decoder();
    ~decoder();

    //Decoder core :
    void decode();
    void verification();

    //optional : getters
    std::string getEncoded();
    std::string getDecoded();
    std::string getChecker();

    //Useful setter :
    void setTree(ArbreB &newTree);
    void setEncoded(std::string newEncoded);
};