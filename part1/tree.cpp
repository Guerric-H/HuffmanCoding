#include "tree.hh"
#include "node.hh"
#include <queue>

void ArbreB::fusion (ArbreB *target) 
{
    Sommet *newRoot = new Sommet() ;

    root.setFather(newRoot) ;
    target->root.setFather(newRoot) ;

    newRoot->setLeft(root) ;
    newRoot->setRight(target->root) ;
}

void ArbreB::insert (Sommet *target) 
{
    if (!root)
    {
        root = target ;
        break ;
    }

    std::queue fifo ;
    fifo.push(root->getLeft() )  ;
    fifo.push(root->getRight() ) ;

    while (!fifo.empty)
    {
        Sommet *current = fifo.front() ;

        if(!current->getLeft() )
        {
            current->getLeft() = target ;
            break ;
        }   
        if(!current->getRight() )
        {
            current->getRight() = target ;
            break ;
        }
        fifo.push(current->getLeft() )  ;
        fifo.push(current->getRight() ) ;
        fifo.pop();
    }
}

void ArbreB::suppress (Sommet *target)
{
    if (root == target)
    {
        delete root ;
        root = nullptr ;
        break ;
    }

    std::queue fifo ;
    fifo.push(root->getLeft() )  ;
    fifo.push(root->getRight() ) ;

    while (!fifo.empty)
    {
        Sommet *current = fifo.front() ;

        if(current->getLeft() == target )
        {
            delete target ;
            current->setLeft(nullptr) ;
            break ;
        }   
        if(current->getRight() == target )
        {
            delete target ;
            current->setRight(nullptr) ;
            break ;
        }
        fifo.push(current->getLeft() )  ;
        fifo.push(current->getRight() ) ;
        fifo.pop();
    }
}

void ArbreB::suppress (char target)
{
    if (root and root->getValue() == target)
    {
        delete root ;
        root = nullptr ;
        break ;
    }

    std::queue fifo ;
    fifo.push(root->getLeft() )  ;
    fifo.push(root->getRight() ) ;

    while (!fifo.empty)
    {
        Sommet *current = fifo.front() ;

        if(current)
        {
            Sommet *left = current->getLeft() ;
            if (left)
            {
                if(current->getLeft->getValue() == target)
                {
                    delete left ;
                    current->setLeft(nullptr) ;
                    break ;
                }   
            }
            
            Sommet *right = current->getRight() ;
            if(right)
            {
                if(current->getRight->getValue() == target)
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
}

Sommet* ArbreB::find (char value)
{
    std::queue fifo ;
    fifo.push(root) ;

    while (!fifo.empty)
    {
        Sommet *current = fifo.front() ;

        if(current)
        {
            if(current->getValue() == value)
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

