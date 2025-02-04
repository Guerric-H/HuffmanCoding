#include "tree_node/node.hpp"
#include "tree_node/tree.hpp"

#include <iostream>
#include <queue>

ArbreB::ArbreB() {}

ArbreB::ArbreB(Sommet &root)
{
    if (this->root)
        *this->root = root;
    else
        this->root = new Sommet(root);
}

ArbreB::ArbreB(Sommet *root)
{
    this->root = root;
}

ArbreB::ArbreB(ArbreB const &target)
{
    *this = target;
}

ArbreB::ArbreB(short value, int count)
{
    this->root = new Sommet(value, count);
}

ArbreB &ArbreB::operator=(const ArbreB &target)
{
    if (root)
    {
        delete root;
        root = nullptr;
    }
    if (target.root)
        root = new Sommet(*target.root);
    return *this;
}

Sommet *ArbreB::getRoot()
{
    return root;
}

ArbreB ArbreB::fusion(ArbreB &target)
{
    ArbreB newTree(-1, root->getCount() + target.getRoot()->getCount());
    newTree.root->setLeft(root);
    newTree.root->setRight(target.root);
    return newTree;
}

void ArbreB::insert(short value, int count)
{
    if (!root)
    {
        root = new Sommet(value, count);
        return;
    }

    std::queue<Sommet *> fifo;
    fifo.push(root);

    while (!fifo.empty())
    {
        Sommet *current = fifo.front();
        fifo.pop();

        if (!current)
            continue;

        if (!current->getLeft())
        {
            current->setLeft(new Sommet(value, count));
            current->getLeft()->setFather(current);
            return;
        }
        if (!current->getRight())
        {
            current->setRight(new Sommet(value, count));
            current->getRight()->setFather(current);
            return;
        }
        fifo.push(current->getLeft());
        fifo.push(current->getRight());
    }
}

Sommet *ArbreB::find(short target)
{
    std::queue<Sommet *> fifo;
    fifo.push(root);

    while (!fifo.empty())
    {
        Sommet *current = fifo.front();
        fifo.pop();
        if (!current)
            continue;

        if (current->getValue() == target)
            return current;
        else
        {
            fifo.push(current->getLeft());
            fifo.push(current->getRight());
        }
    }
    return nullptr;
}

ArbreB ArbreB::remove(short target)
{
    if (root && root->getValue() == target)
    {
        ArbreB subtree{root};
        root = nullptr;
        return subtree;
    }

    std::queue<Sommet *> fifo;
    fifo.push(root);

    while (!fifo.empty())
    {
        Sommet *current = fifo.front();
        fifo.pop();
        if (!current)
            continue;

        Sommet *left = current->getLeft();
        if (left)
        {
            if (left->getValue() == target)
            {
                ArbreB subtree(new Sommet(*left));
                current->setLeft(nullptr);
                return subtree;
            }
        }

        Sommet *right = current->getRight();
        if (right)
        {
            if (right->getValue() == target)
            {
                ArbreB subtree(new Sommet(*right));
                current->setRight(nullptr);
                return subtree;
            }
        }
        fifo.push(left);
        fifo.push(right);
    }
    throw std::runtime_error("The character you're looking for isn't in the tree.\n Therefore, it is not possible to return a valid Subtree.\n");
}

void ArbreB::suppress(short target)
{
    remove(target);
}

ArbreB::~ArbreB()
{
    if (root)
        delete root;
}