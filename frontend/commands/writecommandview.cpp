//
// Created by profe on 20.04.2022.
//

#include "writecommandview.h"

#include <utility>
#include "backend/commands/writecommand.h"

WriteCommandView::WriteCommandView(QWidget *parent, int lineNumber, int linesSize, std::vector<DynamicVariable *> *variables,std::function<void(CommandView*)> deleteFun)
        : CommandView(parent, lineNumber,std::move(deleteFun)), variable1(new QComboBox(parent)),  commandLine(new QLabel(parent)){

    QLabel *label1 = new QLabel("write: ");

    this->addWidget(commandLine);
    this->addWidget(label1);
    this->addWidget(variable1);
    updateUi(linesSize, lineNumber, variables);
}

Command *WriteCommandView::getMyCommand(std::vector<DynamicVariable *> *variables) {
    generatedCommand = new WriteCommand(&generateDebugMarks, findSelectedVariable(variables, variable1->currentText()));
    return generatedCommand;
}

void WriteCommandView::updateUi(int linesSize, int lineNumber, std::vector<DynamicVariable *> *variables) {
    auto selectedVariable1 = variable1->currentText();
    variable1->clear();
    for (auto variable: *variables) {
        variable1->addItem(QString::fromStdString(variable->getMyVariable()->getVariable()));
        if (variable->getMyVariable()->getVariable() == selectedVariable1.toStdString()){
            variable1->setCurrentText(selectedVariable1);
        }
    }
    this->lineNumber = lineNumber;
    commandLine->setText(QString::number(lineNumber));
}
