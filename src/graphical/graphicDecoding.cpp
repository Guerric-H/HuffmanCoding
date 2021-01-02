#include "graphical/graphicDecoding.hpp"

graphicDecoding::graphicDecoding()
{
    layout = new QGridLayout();
    setLayout(layout);

    input = new QLabel("Input : ");
    layout->addWidget(input, 0, 0);

    showEncoded = new QTextEdit(this);
    showEncoded->setText(QString::fromStdString(encoded));
    layout->addWidget(showEncoded,1,0);

    convert = new QPushButton("Convert encoded");
    layout->addWidget(convert, 2, 0);

    output = new QLabel("Output : ");
    layout->addWidget(output, 3, 0);

    showDecoded = new QTextEdit(this);
    showDecoded->setReadOnly(true);
    showDecoded->setText(QString::fromStdString(decoded));
    layout->addWidget(showDecoded,4,0);

    titleChecker = new QLabel("Verification : ");
    layout->addWidget(titleChecker, 5, 0);

    showChecker = new QTextEdit(this);
    showChecker->setReadOnly(true);
    showChecker->setText(QString::fromStdString(checker));
    layout->addWidget(showChecker,6,0);

    connect(&Context::instance(), SIGNAL(decoderChanged()), this, SLOT(decoderChanged()));
    connect(convert, SIGNAL(clicked()), this, SLOT(buttonPressed()));
}

void graphicDecoding::decoderChanged()
{
    auto &ctxt = Context::instance();
    encoded = ctxt.getDecoder().getEncoded();
    decoded = ctxt.getDecoder().getDecoded();
    checker = ctxt.getDecoder().getChecker();

    showEncoded->setText(QString::fromStdString(encoded));
    showDecoded->setText(QString::fromStdString(decoded));
    showChecker->setText(QString::fromStdString(checker));
    update();
}

void graphicDecoding::buttonPressed()
{
    Context::instance().setDecoder(showEncoded->toPlainText().toStdString());
}

graphicDecoding::~graphicDecoding(){}