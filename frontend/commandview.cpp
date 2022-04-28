#include "commandview.h"

#include <utility>
#include "mainview.h"


CommandView::~CommandView() {
    this->QHBoxLayout::~QHBoxLayout();
    delete generatedCommand;

}

CommandView::CommandView(QWidget *parent, int lineNumber, std::function<void(CommandView*)> deleteFunction) : QHBoxLayout(parent), lineNumber(lineNumber),
                                                            debug(new QCheckBox(parent)),
                                                            deleteCommand(new QPushButton(parent)), deleteFunction(std::move(deleteFunction)) {
    connect(deleteCommand, SIGNAL(clicked()), this, SLOT(deleteCommandObject()));
    deleteCommand->setText("DELETE");
    this->addWidget(deleteCommand);
    this->addWidget(debug);
    generateDebugMarks = [this](const bool data) -> void {
        qDebug() << this->lineNumber;
        qDebug() << data;
    };
}

void CommandView::deleteCommandObject(){
    deleteFunction(this);
}

bool CommandView::getDebug() {
    return debug->isChecked();
}

