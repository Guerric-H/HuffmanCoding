#include "graphical/graphicEncoding.hpp"

graphicEncoding::graphicEncoding()
{
    layout = new QGridLayout();
    setLayout(layout);

    input = new QLabel("Input : ");
    layout->addWidget(input, 0, 0);

    showText = new QTextEdit(this);
    showText->setText(QString::fromStdString(text));
    layout->addWidget(showText, 1, 0);
    
    convert = new QPushButton("Convert text");
    layout->addWidget(convert, 2, 0);

    output = new QLabel("Output : ");
    layout->addWidget(output, 3, 0);

    showEncoded = new QTextEdit(this);
    showEncoded->setReadOnly(true);
    showEncoded->setText(QString::fromStdString(encoded));
    layout->addWidget(showEncoded, 4, 0);

    titleStats = new QLabel("Statistics : ");
    layout->addWidget(titleStats, 5, 0);

    showStats = new QTextEdit(this);
    showStats->setReadOnly(true);
    showStats->setText(QString::fromStdString("test"));
    layout->addWidget(showStats, 6, 0);

    connect(&Context::instance(), SIGNAL(huffmanChanged()), this, SLOT(huffmanChanged()));
    connect(convert, SIGNAL(clicked()), this, SLOT(buttonPressed()));
}

void graphicEncoding::huffmanChanged()
{
    auto &ctxt = Context::instance();

    text = ctxt.getHuffman().getText();
    encoded = ctxt.getHuffman().getEncoded();
    stats = ctxt.getHuffman().getStats();

    showText->setText(QString::fromStdString(text));
    showEncoded->setText(QString::fromStdString(encoded));
    showStats->setText(QString::fromStdString(stats));
}

void graphicEncoding::buttonPressed()
{
    Context::instance().setHuffman(showText->toPlainText().toStdString());
}

graphicEncoding::~graphicEncoding() {}