//
// Created by profe on 20.04.2022.
//

#include <QLabel>
#include <QCheckBox>
#include <QComboBox>
#include "ifcommandview.h"
#include "backend/commands/ifcommand.h"

IfCommandView::IfCommandView(QWidget *parent, int lineNumber, int linesSize, std::vector<DynamicVariable *> *variables)
        : CommandView(parent, lineNumber), variable1(new QComboBox(parent)), variable2(new QComboBox(parent)),
          ifYes(new QComboBox(parent)), ifNo(new QComboBox(parent)), commandLine(new QLabel(parent)) {
    auto *ifOperator = new QComboBox(parent);


    ifOperator->addItem("NEQ");
    ifOperator->addItem("EQ");
    ifOperator->addItem("LT");
    ifOperator->addItem("GT");
    ifOperator->addItem("LE");
    ifOperator->addItem("GE");

    this->addWidget(commandLine);
    this->addWidget(variable1);
    this->addWidget(ifOperator);
    this->addWidget(variable2);
    this->addWidget(ifNo);
    this->addWidget(ifYes);
    updateUi(linesSize, lineNumber, variables);
}

Command *IfCommandView::getMyCommand(std::vector<DynamicVariable *> *variables) {
//    TODO enums on operation
    generatedCommand = new IfCommand(nullptr, findSelectedVariable(variables, variable1->currentText()),
                                     findSelectedVariable(variables, variable2->currentText()), ifYes->currentText().toInt(),
                                     ifNo->currentText().toInt(), NEQ);
    return generatedCommand;
}

void IfCommandView::updateUi(int linesSize, int lineNumber, std::vector<DynamicVariable *> *variables) {
//    TODO - should remember selected
    variable1->clear();
    variable2->clear();
    for (auto variable: *variables) {
        variable1->addItem(QString::fromStdString(variable->getMyVariable()->getVariable()));
        variable2->addItem(QString::fromStdString(variable->getMyVariable()->getVariable()));
    }
    ifNo->clear();
    ifYes->clear();
    for (int i = 0; i <= linesSize; ++i) {
        if (i != lineNumber) {
            ifNo->addItem(QString::number(i));
            ifYes->addItem(QString::number(i));
        }
    }
    this->lineNumber = lineNumber;
    commandLine->setText(QString::number(lineNumber));
}






