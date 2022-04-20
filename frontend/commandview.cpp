#include "commandview.h"
#include "mainview.h"


CommandView::~CommandView() {
    this->QHBoxLayout::~QHBoxLayout();
    delete generatedCommand;

}

CommandView::CommandView(QWidget *parent, int lineNumber) : QHBoxLayout(parent), lineNumber(lineNumber),
                                                            debug(new QCheckBox(parent)),
                                                            deleteCommand(new QPushButton(parent)) {
    //connect(deleteCommand, SIGNAL(clicked()), this, SLOT(deleteCommandObject(parent, indexOf(deleteCommand)))); //not working
    deleteCommand->setText("DELETE");
    this->addWidget(deleteCommand);
    this->addWidget(debug);
}

void CommandView::deleteCommandObject(QWidget layout, int layoutIndex){
   qDebug() << "delete";
}


