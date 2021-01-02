#include "graphical/graphicTree.hpp"

graphicTree::graphicTree() : tree(nullptr)
{
    connect(&Context::instance(), SIGNAL(huffmanChanged()), this, SLOT(huffmanChanged()));
}

void graphicTree::huffmanChanged()
{
    tree = &Context::instance().getHuffman().getTree();
    update();
}

void graphicTree::paintEvent(QPaintEvent *event)
{
    QPainter paint(this);

    struct coordinate
    {
        Sommet *son;
        unsigned int depth;
        int x;
        int y;
        coordinate(Sommet *son, int const &depth, int const &x, int const &y)
        {
            this->son = son;
            this->depth = depth;
            this->x = x;
            this->y = y;
        }
    };

    //QT uses QT string to print content, we need to make the appropriate conversion each time we draw.
    std::stringstream converter;

    //Ces valeurs sont choisies par soucis d'élégance.
    //Theses values are chosen in order to obtain a classy tree.
    int sep = 3;
    int root_coord = 50;
    int root_depth = 0;
    int y = root_coord;
    int police_size = paint.fontMetrics().height();

    //Size of the window.
    int sizeX_window = 0;

    //Increment between each X and Y in the end.
    int delta_x = 100, delta_y = 20;

    //IMPORTANT Stack : contains the pointer for a Sommet and the coordinate for it's father.
    std::stack<coordinate> filo;

    if (not tree or not tree->getRoot())
        return;
    filo.push(coordinate(tree->getRoot(), root_depth, root_coord, root_coord));

    while (!filo.empty())
    {
        struct coordinate current = filo.top();
        int x = root_coord + current.depth * delta_x;

        filo.pop();

        if (!current.son)
            continue;

        if (current.son->getValue() != -1)
            converter << (char)current.son->getValue() << " | ";

        converter << current.son->getCount();
        paint.drawText(x, y, QString::fromStdString(converter.str()));

        if (current.son != tree->getRoot())
            paint.drawLine(x - sep, y - police_size / 3, current.x, current.y);

        filo.push(coordinate(current.son->getLeft(), current.depth + 1, x + sep, y + sep));
        filo.push(coordinate(current.son->getRight(), current.depth + 1, x + sep, y + sep));

        y += delta_y;

        //Resetting the stringstream.
        converter.str("");

        //Checking if the size in X is greater than previously defined. If so, we'll fix the size at the end.
        if (x > sizeX_window)
            sizeX_window = x;
    }
    resize(sizeX_window + delta_x, y);
}

graphicTree::~graphicTree() {}