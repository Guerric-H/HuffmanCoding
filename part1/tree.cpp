#include "tree.hh"
#include "node.hh"

#include <queue>

ArbreB::ArbreB()
{ root = nullptr ; }

ArbreB::ArbreB(Sommet *root)
{ this->root = root ; }

void ArbreB::fusion (ArbreB& target) 
{
    Sommet *newRoot = new Sommet() ;

    root.setFather(newRoot) ;
    target->root.setFather(newRoot) ;

    newRoot->setLeft(root) ;
    newRoot->setRight(target->root) ;
}

void ArbreB::insert (char value,int count) 
{
    if (!root)
    {
        Sommet *root = new Sommet(value, count) ;
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
            current->getLeft() = new Sommet(value, count) ;
            break ;
        }   
        if(!current->getRight() )
        {
            current->getRight() = new Sommet(value, count) ;
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
    if (!fifo.empty)
        std::cout << "The character you're looking for isn't in the tree.\n" ;

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

Sommet* remove(char target)
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
                if(left->getValue() == target)
                {
                    current->setLeft(nullptr) ;
                    return left;
                }   
            }
            
            Sommet *right = current->getRight() ;
            if(right)
            {
                if(right->getValue() == target)
                {
                    current->setRight(nullptr)  ;
                    return right ;
                }
            }
            fifo.push(left)  ;
            fifo.push(right) ;
        }
        fifo.pop();
    }
} 

ArbreB::~ArbreB() 
{ if (root) delete root ; }