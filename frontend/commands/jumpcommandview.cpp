//
// Created by profe on 20.04.2022.
//

#include "jumpcommandview.h"
#include "backend/commands/jumpcommand.h"

JumpCommandView::JumpCommandView(QWidget *parent, int lineNumber, int linesSize, std::vector<DynamicVariable *> *variables)
        : CommandView(parent, lineNumber), jumpTo(new QComboBox(parent)), commandLine(new QLabel(parent)) {

    this->addWidget(commandLine);
    this->addWidget(jumpTo);
    updateUi(linesSize, lineNumber, variables);
}

Command *JumpCommandView::getMyCommand(std::vector<DynamicVariable *> *variables) {
    generatedCommand = new JumpCommand(nullptr, jumpTo->currentText().toInt());
    return generatedCommand;
}

void JumpCommandView::updateUi(int linesSize, int lineNumber, std::vector<DynamicVariable *> *variables) {
    auto selectedJumpTo = jumpTo->currentText();
    jumpTo->clear();
    for (int i = 0; i <= linesSize; ++i) {
        if (i != lineNumber) {
            jumpTo->addItem(QString::number(i));
        }
        if (QString::number(i) == selectedJumpTo){
            jumpTo->setCurrentText(selectedJumpTo);
        }
    }
    this->lineNumber = lineNumber;
    commandLine->setText(QString::number(lineNumber));
}