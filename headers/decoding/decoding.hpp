#pragma once

#include <map>
#include "tree_node/tree.hpp"
#include "tree_node/node.hpp"

class decoder
{
private:
    //Encoded message (must only contains 1 and 0)
    std::string encoded = "";
    //Decoded message (cannot ensure validity)
    std::string decoded = "";
    //Changing message, informing wether or not the Tree is possibly the one who created the encoded message.
    std::string checker = "";
    //Required Tree to try to decode the encoded message.
    ArbreB *tree ;
public:
    //Constructor and destructor :
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