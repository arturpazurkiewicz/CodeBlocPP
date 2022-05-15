#include "commandview.h"

#include <utility>
#include "mainview.h"


CommandView::~CommandView() {
    this->QHBoxLayout::~QHBoxLayout();
    delete generatedCommand;

}

CommandView::CommandView(QWidget *parent, int lineNumber, std::function<void(CommandView*)> deleteFunction) : QHBoxLayout(parent), lineNumber(lineNumber),
                                                            debug(new QCheckBox(parent)), activeDebugLine(new QCheckBox(parent)),
                                                            deleteCommand(new QPushButton(parent)), deleteFunction(std::move(deleteFunction)) {
    connect(deleteCommand, SIGNAL(clicked()), this, SLOT(deleteCommandObject()));
    deleteCommand->setText("DELETE");
    this->addWidget(activeDebugLine);
    activeDebugLine->setEnabled(false);
    activeDebugLine->resize(10, activeDebugLine->width());
    this->addWidget(deleteCommand);
    this->addWidget(debug);
    generateDebugMarks = [this](const bool data) -> void {
        if (data) {
            activeDebugLine->setChecked(true);
            activeDebugLine->setStyleSheet("QCheckBox { background-color: green }");
            activeDebugLine->repaint();
        }
        if (!data) {
            activeDebugLine->setChecked(false);
            activeDebugLine->setStyleSheet("QCheckBox { background-color: none }");
            activeDebugLine->repaint();
        }
//        qDebug() << this->lineNumber;
//        qDebug() << data;
    };
}

void CommandView::deleteCommandObject(){
    deleteFunction(this);
}

bool CommandView::getDebug() {
    return debug->isChecked();
}

