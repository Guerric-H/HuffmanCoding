#include "tree.hh"
#include "node.hh"
#include <queue>

ArbreB::ArbreB()
{ root = nullptr ; }

ArbreB::ArbreB(Sommet *root)
{ this->root = root ; }

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

Sommet* ArbreB::find (char target)
{
    std::queue fifo ;
    fifo.push(root) ;

    while (!fifo.empty)
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

ArbreB* remove(Sommet *target)
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
            ArbreB *subTree = new ArbreB(current->getLeft() ) ;
            current->setLeft(nullptr) ;
            return subTree ;
        }   
        if(current->getRight() == target )
        {
            ArbreB *subTree = new ArbreB(current->getRight() ) ;
            current->setRight(nullptr) ;
            return subTree ;
        }
        fifo.push(current->getLeft() )  ;
        fifo.push(current->getRight() ) ;
        fifo.pop();
    }
}

ArbreB* remove(char target)
{
    if (root && root->getValue() == target)
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
                    ArbreB *subTree = new ArbreB(current->getLeft() ) ;
                    current->setLeft(nullptr) ;
                    return subTree ;
                }   
            }
            
            Sommet *right = current->getRight() ;
            if(right)
            {
                if(current->getRight->getValue() == target)
                {
                    ArbreB *subTree = new ArbreB(current->getRight() ) ;
                    current->setRight(nullptr)  ;
                    return subTree ;
                }
            }
            fifo.push(left)  ;
            fifo.push(right) ;
        }
        fifo.pop();
    }
} 

