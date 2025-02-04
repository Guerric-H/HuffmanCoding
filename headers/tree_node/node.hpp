#pragma once

/*This class is meant to be implemented on a binary tree object.
 *Therefore, we could put this whole code in the tree.hh, but we will keep these on separated files for clarity.
 *Note that we could even include the code IN the class ArbreB.
 *
 *   It must contains : (in order to use it for the Huffman coding)
 *      -The associated char to the node.
 *      -The amount of time this char is read in a file.
 *  
 *   The class needs to :
 *      -Give the reference to both left and right Sommet pointers.
 *      -Return it's own char and int.
 *      -Give the reference of the father's Sommet. (null if the selected Sommet is the tree's root.)
 *   
 *   Important !!!
 *      When using the Destructor, it will recursively delete every left and right pointer.
 */

class Sommet
{
private:
    //Frequence of the character.
    int count;
    //Associated character of the node.
    short value;

    //Pointer to father node.
    Sommet *father{nullptr};
    //Pointer to left node.
    Sommet *left{nullptr};
    //Pointer to right node.
    Sommet *right{nullptr};

public:
    // Constructors :
    Sommet();
    Sommet(short value, int count);
    Sommet(Sommet *left, Sommet *right);
    Sommet(Sommet const &deepcopy);

    Sommet &operator=(Sommet const &deepcopy);

    //Getters :
    int getCount();
    short getValue();
    Sommet *getLeft();
    Sommet *getRight();
    Sommet *getFather();

    //Increase the frequency by one.
    void incrementCount();

    //Setters :
    void setLeft(Sommet *left);
    void setRight(Sommet *right);
    void setFather(Sommet *father);
    void setValue(short value);
    void setCount(int count);

    //Destructor :
    ~Sommet();
};