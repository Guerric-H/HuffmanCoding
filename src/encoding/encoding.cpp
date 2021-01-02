#include <iostream>
#include <map>

#include "encoding/encoding.hpp"
#include "tree_node/tree.hpp"
#include "tree_node/node.hpp"

//Constructors
encoder::encoder(){}

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

void encoder::buildTree()
{
    if (TreeMap.size() == 1)
    {
        auto tmp = TreeMap.begin()->second;
        TreeMap.clear();
        ArbreB test(-1, 0);
        TreeMap.emplace(tmp.getRoot()->getCount(), tmp.fusion(test));
    }
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
    if (not current)
        return;
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

void encoder::encode()
{
    if (text.empty())
        return;
    charMapping();
    multiMapBuilder();
    buildTree();
    encodeText();
    createStats();
}

void encoder::createStats()
{
    std::stringstream display ;
    for (auto &i : charCount)
    {
        float percentage = (float)(i.second * 100) / (float)text.size();
        statsMap[i.first] = percentage;
        display << i.first
                << " : " << percentage
                << "%"   << std::endl << std::endl ;
    }
    stats = display.str();
}

//Getters
std::map<char, int> encoder::getcharCount()
{
    return charCount;
}
std::multimap<int, ArbreB> encoder::getSubTree() { return TreeMap; }
std::string encoder::getEncoded() { return encoded; }
std::string encoder::getText() { return text; }
std::string encoder::getStats(){ return stats; }
ArbreB &encoder::getTree() { return tree; }

void encoder::setText(std::string newText)
{
    text = newText;
    tree = ArbreB();
    stats.clear();
    encoded.clear();
    charCount.clear();
    statsMap.clear();
    charCoded.clear();
    TreeMap.clear();
}

//Destructor
encoder::~encoder() {}