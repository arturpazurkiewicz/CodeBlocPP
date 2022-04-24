//
// Created by profe on 20.04.2022.
//

#include <QComboBox>
#include <QLabel>
#include "operationcommandview.h"

OperationCommandView::OperationCommandView(QWidget *parent, int lineNumber, int linesSize, std::vector<DynamicVariable *> *variables)
        : CommandView(parent, lineNumber), variable1(new QComboBox(parent)), variable2(new QComboBox(parent)), variable3(new QComboBox(parent)),
          commandLine(new QLabel(parent)), operation(new QComboBox(parent)) {

    QLabel *label1 = new QLabel("=");

    operation->addItem("+");
    operation->addItem("-");
    operation->addItem("*");
    operation->addItem("/");

    this->addWidget(commandLine);
    this->addWidget(variable1);
    this->addWidget(label1);
    this->addWidget(variable2);
    this->addWidget(operation);
    this->addWidget(variable3);

    updateUi(linesSize, lineNumber, variables);
}

Operation OperationCommandView::findOperation(const QString& comparator){
    if(comparator == "+") return PLUS;
    else if(comparator == "-") return MINUS;
    else if(comparator == "*") return MULTIPLY;
    else return DIVIDE;
}

Command *OperationCommandView::getMyCommand(std::vector<DynamicVariable *> *variables) {
    generatedCommand = new OperationCommand(nullptr, findSelectedVariable(variables, variable2->currentText()),
                                     findSelectedVariable(variables, variable3->currentText()),
                                     findSelectedVariable(variables, variable1->currentText()), findOperation(operation->currentText()));
    return generatedCommand;
}

void OperationCommandView::updateUi(int linesSize, int lineNumber, std::vector<DynamicVariable *> *variables) {
    auto selectedVariable1 = variable1->currentText();
    auto selectedVariable2 = variable2->currentText();
    auto selectedVariable3 = variable3->currentText();
    variable1->clear();
    variable2->clear();
    variable3->clear();
    for (auto variable: *variables) {
        variable1->addItem(QString::fromStdString(variable->getMyVariable()->getVariable()));
        variable2->addItem(QString::fromStdString(variable->getMyVariable()->getVariable()));
        variable3->addItem(QString::fromStdString(variable->getMyVariable()->getVariable()));
        if (variable->getMyVariable()->getVariable() == selectedVariable1.toStdString()){
            variable1->setCurrentText(selectedVariable1);
        }
        if (variable->getMyVariable()->getVariable() == selectedVariable2.toStdString()){
            variable2->setCurrentText(selectedVariable2);
        }
        if (variable->getMyVariable()->getVariable() == selectedVariable3.toStdString()){
            variable3->setCurrentText(selectedVariable3);
        }
    }

    this->lineNumber = lineNumber;
    commandLine->setText(QString::number(lineNumber));
}
