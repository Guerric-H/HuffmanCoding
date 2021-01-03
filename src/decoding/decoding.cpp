#include "decoding/decoding.hpp"

decoder::decoder(): tree(nullptr) {}

void decoder::decode()
{
    if (!tree->getRoot())
    {
        decoded = "ERROR : No existing Tree.\nPlease create one by encoding a first message before trying to decode something." ;
        checker = "No given Tree.";
        return ;
    }
    Sommet *current = tree->getRoot();

    for (int i = 0 ; i < encoded.size() ; i++)
    {
        if (!current->getLeft() || !current->getRight())    //Only one condition is mandatory, we could choose between these but it's not important.
        {
            decoded += current->getValue();
            current = tree->getRoot();
        }
        if(encoded[i] == '0')
        {
            current = current->getLeft();
        } else if (encoded[i] == '1')
        {
            current = current->getRight();
        } else
        {
            decoded = "ERROR : Invalid encoded message.\nIt must contains only 0 or 1." ;
            checker = "The message was not created by the given Tree.";
            return ;
        }
    }
    if (!current->getLeft() || !current->getRight()) 
    {
        decoded += current->getValue();
        current = tree->getRoot();
    }
    else
    {
        decoded = "ERROR : Invalid Tree.\nThe decoding ends on a non-character associated node." ;
        checker = "The message was not created by the given Tree.";
        return ;
    }
}

void decoder::verification()
{
    if (checker != "")
        return ;

    if (decoded.size() != tree->getRoot()->getCount())
    {
        checker = "The message was not created by the given Tree, however it can be decoded by it (decoding validity cannot be granted).";
        return ;
    }   

    std::map<char,int>charCount ;
    for (int i = 0 ; i < decoded.size() ; i++)
    {
        if(charCount.count(decoded[i]))
            charCount[decoded[i]]++ ;
        else 
            charCount.emplace(decoded[i],1);
    }
    for ( auto i : charCount)
    {
        if (!tree->find(i.first)->getCount())
        {
            checker = "The message was not created by the given Tree, however it can be decoded by it (decoding validity cannot be granted).";
            return ;
        }
    }
    checker = "The message might have been created by the given Tree, (each char has matching frequency).\nNote that this cannot be ensured, as we have no way to check if characters are the same as the original Tree, and in the same order.";
}

std::string decoder::getEncoded() { return encoded; }
std::string decoder::getDecoded() { return decoded; }
std::string decoder::getChecker() { return checker; }

void decoder::setTree(ArbreB &newTree) {tree = &newTree; }
void decoder::setEncoded(std::string newEncoded) 
{
    encoded = newEncoded;
    decoded = "";
    checker = "";
}

decoder::~decoder(){}