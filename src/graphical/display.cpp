#include "graphical/display.hh"
#include "tree_node/node.hh"
#include "tree_node/tree.hh"


#include <iostream>
#include <stack>
#include <QtGui/QPainter>
#include <sstream>
#include <functional>

void window::paintEvent(QPaintEvent *event)
{
    QPainter paint(this);

    struct coordinate {
        unsigned int depth;
        int x;
        int y;
        coordinate(int const& depth, int const& x, int const& y)
        {
            this->depth = depth;
            this->x = x;
            this->y = y;
        }
    };


    //QT uses QT string to print content, we need to make the appropriate conversion each time we draw.
    std::stringstream tmp;

    //Ces valeurs sont choisies par soucis d'élégance.
    //Theses values are chosen in order to obtain a classy tree.
    int sep = 3 ;
    int root_coord = 50 ;
    int root_depth = 0  ;
    int y = root_coord  ;
    int police_size = paint.fontMetrics().height() ;
    
    //Size of the window.
    int sizeX_window = 0 ; 

    //Increment between each X and Y in the end.
    int delta_x = 100, delta_y = 20 ;
    
    //IMPORTANT Stack : contains the pointer for a Sommet and the coordinate for it's father.
    std::stack<std::pair<Sommet*, coordinate>> filo ;

    filo.push(std::make_pair(tree.getRoot(), coordinate(root_depth, root_coord, root_coord))) ;

    while (!filo.empty())
    {
        std::pair<Sommet*, coordinate> pair = filo.top() ;
        Sommet *current = pair.first ;
        unsigned int current_depth = pair.second.depth ;
        int x = root_coord +  current_depth * delta_x ;

        filo.pop();

        if (!current)
            continue ;
        
        if (current->getValue() != -1)
            tmp << current->getValue() << " | " ;

        tmp << current->getCount() ;
        paint.drawText(x, y, QString::fromStdString(tmp.str())) ;

        if (current->getFather())
            paint.drawLine(x - sep, y - police_size/3 , pair.second.x, pair.second.y) ;

        filo.push(std::make_pair(current->getLeft(), coordinate(current_depth + 1, x + sep, y + sep))) ;
        filo.push(std::make_pair(current->getRight(), coordinate(current_depth + 1, x + sep, y + sep))) ;
        
        y += delta_y ;
        
        //Resetting the stringstream.
        tmp.str("") ;
        
        //Checking if the size in X is greater than previously defined. If so, we'll fix the size at the end.
        if (x > sizeX_window)
            sizeX_window = x ;
    }
    resize(sizeX_window + delta_x, y) ;
}

window::~window() {}