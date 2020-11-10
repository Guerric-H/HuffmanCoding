#include "node.hh"

    //Constructors :
    Sommet::Sommet() : count{0}, value{''} {}

    Sommet::Sommet(int count,char value) : count{count}, value{value} {}

    //Methods :
    int     Sommet::getCount() {return count ;}
    char    Sommet::getValue() {return value ;}

    Sommet* Sommet::getLeft()   {return left   ;}
    Sommet* Sommet::getRight()  {return right  ;}
    Sommet* Sommet::getFather() {return father ;}

    void    Sommet::incrementCount() {count++ ;}
    void    Sommet::setLeft(Sommet *left) {this->left = left ;}
    void    Sommet::setLeft(Sommet *right) {this->right = right ;}
    void    Sommet::setFather(Sommet *father) {this->father = father ;}


    //Destructor :
    Sommet::~Sommet() 
    {
        /*Call left and right destructor only if they are not nullptr.
         *By doing this, you do the same task again for each left and right son you encounter.
         */
        if (left)  delete left  ;
        if (right) delete right ;
    }