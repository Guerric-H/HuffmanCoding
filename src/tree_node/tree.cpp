#include "tree_node/node.hh"
#include "tree_node/tree.hh"

#include<iostream>
#include <queue>

ArbreB::ArbreB()
{ root = nullptr ; }

ArbreB::ArbreB(Sommet *root)
{ this->root = root ; }

void ArbreB::fusion (ArbreB& target) 
{
    Sommet *newRoot = new Sommet() ;

    root->setFather(newRoot) ;
    target.root->setFather(newRoot) ;

    newRoot->setLeft(root) ;
    newRoot->setRight(target.root) ;
}

void ArbreB::insert (char value,int count) 
{
    if (!root)
    {
        Sommet *root = new Sommet(value, count) ;
        return ;
    }

    std::queue<Sommet*> fifo ;
    fifo.push(root->getLeft() )  ;
    fifo.push(root->getRight() ) ;

    while (!fifo.empty())
    {
        Sommet *current = fifo.front() ;

        if(!current->getLeft() )
        {
            current->setLeft(new Sommet(value, count)) ;
            break ;
        }   
        if(!current->getRight() )
        {
            current->setRight(new Sommet(value, count)) ;
            break ;
        }
        fifo.push(current->getLeft() )  ;
        fifo.push(current->getRight() ) ;
        fifo.pop();
    }
}

void ArbreB::suppress (char target)
{
    if (root && root->getValue() == target)
    {
        delete root ;
        root = nullptr ;
        return ;
    }

    std::queue<Sommet*> fifo ;
    fifo.push(root->getLeft() )  ;
    fifo.push(root->getRight() ) ;

    while (!fifo.empty())
    {
        Sommet *current = fifo.front() ;

        if(current)
        {
            Sommet *left = current->getLeft() ;
            if (left)
            {
                if(current->getLeft()->getValue() == target)
                {
                    delete left ;
                    current->setLeft(nullptr) ;
                    break ;
                }   
            }
            
            Sommet *right = current->getRight() ;
            if(right)
            {
                if(current->getRight()->getValue() == target)
                {
                    delete right ;
                    current->setRight(nullptr)  ;
                    break ;
                }
            }
            fifo.push(left)  ;
            fifo.push(right) ;
        }
        fifo.pop();
    }
    if (!fifo.empty())
        std::cout << "The character you're looking for isn't in the tree.\n" ;

}

Sommet* ArbreB::find (char target)
{
    std::queue<Sommet*> fifo ;
    fifo.push(root) ;

    while (!fifo.empty())
    {
        Sommet *current = fifo.front() ;

        if(current)
        {
            if(current->getValue() == target)
                return current ;
            else 
            {
                fifo.push(current->getLeft() )  ;
                fifo.push(current->getRight() ) ;
            }
        }
        fifo.pop();

    }
    return nullptr ;
}

ArbreB ArbreB::remove(char target)
{
    if (root && root->getValue() == target)
    {
        ArbreB subtree ;
        subtree.root = root ;
        root = nullptr ;
        return subtree;
    }

    std::queue<Sommet*> fifo ;
    fifo.push(root->getLeft() )  ;
    fifo.push(root->getRight() ) ;

    while (!fifo.empty())
    {
        Sommet *current = fifo.front() ;

        if(current)
        {
            Sommet *left = current->getLeft() ;
            if (left)
            {
                if(left->getValue() == target)
                {
                    ArbreB subtree ;
                    subtree.root = left ;
                    current->setLeft(nullptr) ;
                    return subtree;
                }   
            }
            
            Sommet *right = current->getRight() ;
            if(right)
            {
                if(right->getValue() == target)
                {
                    ArbreB subtree ;
                    subtree.root = right ;
                    current->setRight(nullptr) ;
                    return subtree;
                }
            }
            fifo.push(left)  ;
            fifo.push(right) ;
        }
        fifo.pop();
    }
    return ArbreB() ;
} 

ArbreB::~ArbreB() 
{ if (root) delete root ; }