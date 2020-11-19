#include "tree_node/node.hh"


    //Constructors :
    Sommet::Sommet() : count{0}, value{-1} {}

    Sommet::Sommet(char value,int count) : value{value}, count{count} {}

    Sommet::Sommet(Sommet* left, Sommet* right)
    { 
        this->left = new Sommet(*left) ; 
        this->right = new Sommet(*right) ; 
        this->left->setFather(this) ;
        this->right->setFather(this) ;
    }

    Sommet::Sommet(Sommet const& deepcopy)
    {
        *this = deepcopy;
    }

    Sommet& Sommet::operator=(Sommet const& deepcopy)
    {
        value = deepcopy.value ;
        count = deepcopy.count ;
        if (deepcopy.left) 
            setLeft(deepcopy.left);
        if (deepcopy.right) 
            setRight(deepcopy.right);
        
        return *this;

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

    void    Sommet::setLeft(Sommet *left) 
    {
        if (left == nullptr)
        {
            if (this->left)
                delete this->left;
            this->left = nullptr;
        } else {
            if (this->left)
                *this->left = *left ;
            else
                this->left = new Sommet(*left);
            left->setFather(this);
        }
    }
    
    void    Sommet::setRight(Sommet *right) 
    {
        if (right == nullptr)
        {
            if (this->right)
                delete this->right;
            this->right = nullptr;
        } else {
            if (this->right)
                *this->right = *right ;
            else
                this->right = new Sommet(*right);
            right->setFather(this);
        }
    }

    void    Sommet::setFather(Sommet *father) 
    {
        this->father = father;
    }


    //Destructor :
    Sommet::~Sommet() 
    {
        /*Call left and right destructor only if they are not nullptr.
         *By doing this, you do the same task again for each left and right son you encounter.
         */
        if (left)  delete left  ;
        if (right) delete right ;
    }