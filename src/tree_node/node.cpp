#include "tree_node/node.hh"


    //Constructors :
    Sommet::Sommet() : count{0}, value{-1} {}

    Sommet::Sommet(char value,int count) : value{value}, count{count} {}

    Sommet::Sommet(Sommet* left, Sommet* right)
    { 
        left->father = right->father = this ;
        this->left = left ; 
        this-> right = right ; 
    }

    Sommet::Sommet(Sommet& deepcopy)
    {
        value = deepcopy.value ;
        count = deepcopy.count ;
        if (deepcopy.left) left = new Sommet(*deepcopy.left) ;
        if (deepcopy.right) right = new Sommet(*deepcopy.right) ;
    }

    //Methods :
    int     Sommet::getCount() {return count ;}
    char    Sommet::getValue() {return value ;}

    Sommet* Sommet::getLeft()   {return left   ;}
    Sommet* Sommet::getRight()  {return right  ;}
    Sommet* Sommet::getFather() {return father ;}

    void    Sommet::incrementCount() {count++ ;}
    void    Sommet::setValue(char value) {this->value = value ;}
    void    Sommet::setCount(int count) {this->count = count ;}
    void    Sommet::setLeft(Sommet *left) {this->left = left ;}
    void    Sommet::setRight(Sommet *right) {this->right = right ;}
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