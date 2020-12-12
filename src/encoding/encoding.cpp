#include <iostream>
#include <utility>
#include <map>

#include "encoding/encoding.hh"
#include "tree_node/tree.hh"
#include "tree_node/node.hh"

//Constructors
encoder::encoder(std::string p_text) : text{p_text} {}

void encoder::charMapping()
{
    for (short i : text)
        if (charCount.count(i))
            charCount[i]++;
        else
            charCount[i] = 1;
}

void encoder::multiMapBuilder()
{
    for (auto &i : charCount)
        TreeMap.emplace(i.second, ArbreB((unsigned char)i.first, i.second));
}

void encoder::huffmanTree()
{
    while (TreeMap.size() > 1)
    {
        int countLeft = TreeMap.begin()->first;
        ArbreB left = TreeMap.begin()->second;
        TreeMap.erase(TreeMap.begin());

        int countRight = TreeMap.begin()->first;
        ArbreB right = TreeMap.begin()->second;
        TreeMap.erase(TreeMap.begin());

        TreeMap.emplace(countLeft + countRight, left.fusion(right));
    }
    tree = TreeMap.begin()->second;
}

void encoder::charToBinary(std::string text, Sommet *current)
{
    if (current->getValue() == -1)
    {
        charToBinary(text + '0', current->getLeft());
        charToBinary(text + '1', current->getRight());
    }
    else
        charCoded[current->getValue()] = text;
}

void encoder::encodeText()
{
    charToBinary("", tree.getRoot());
    for (char i : text)
        encoded += charCoded[i];
}

//Getters
std::map<char, int> encoder::getcharCount()
{
    return charCount;
}
std::multimap<int, ArbreB> encoder::getSubTree() { return TreeMap; }
std::string encoder::getEncoded() { return encoded; }
std::string encoder::getText() { return text; }
ArbreB encoder::getTree() { return tree; }