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
          ifYes(new QComboBox(parent)), ifNo(new QComboBox(parent)), commandLine(new QLabel(parent)), comparator(new QComboBox(parent)) {

    QLabel *label1 = new QLabel("if: ");
    QLabel *label2 = new QLabel("is: ");
    QLabel *label3 = new QLabel("to: ");
    QLabel *label4 = new QLabel("then: ");
    QLabel *label5 = new QLabel("else: ");

    comparator->addItem("!=");
    comparator->addItem("==");
    comparator->addItem("<");
    comparator->addItem(">");
    comparator->addItem("<=");
    comparator->addItem(">=");

    this->addWidget(commandLine);
    this->addWidget(label1);
    this->addWidget(variable1);
    this->addWidget(label2);
    this->addWidget(comparator);
    this->addWidget(label3);
    this->addWidget(variable2);
    this->addWidget(label4);
    this->addWidget(ifNo);
    this->addWidget(label5);
    this->addWidget(ifYes);
    updateUi(linesSize, lineNumber, variables);
}

Comparator IfCommandView::findComparator(const QString& comparator){
        if(comparator == "!=") return NEQ;
        else if(comparator == "==") return EQ;
        else if(comparator == "<") return LT;
        else if(comparator == ">") return GT;
        else if(comparator == "<=") return LE;
        else return GE;
}

Command *IfCommandView::getMyCommand(std::vector<DynamicVariable *> *variables) {
    generatedCommand = new IfCommand(nullptr, findSelectedVariable(variables, variable1->currentText()),
                                     findSelectedVariable(variables, variable2->currentText()), ifYes->currentText().toInt(),
                                     ifNo->currentText().toInt(), findComparator(comparator->currentText()));
    return generatedCommand;
}

void IfCommandView::updateUi(int linesSize, int lineNumber, std::vector<DynamicVariable *> *variables) {
    auto selectedVariable1 = variable1->currentText();
    auto selectedVariable2 = variable2->currentText();
    auto selectedIfNo = ifNo->currentText();
    auto selectedIfYes = ifYes->currentText();
    variable1->clear();
    variable2->clear();
    for (auto variable: *variables) {
        variable1->addItem(QString::fromStdString(variable->getMyVariable()->getVariable()));
        variable2->addItem(QString::fromStdString(variable->getMyVariable()->getVariable()));
        if (variable->getMyVariable()->getVariable() == selectedVariable1.toStdString()){
            variable1->setCurrentText(selectedVariable1);
        }
        if (variable->getMyVariable()->getVariable() == selectedVariable2.toStdString()){
            variable2->setCurrentText(selectedVariable2);
        }
    }
    ifNo->clear();
    ifYes->clear();
    for (int i = 0; i <= linesSize; ++i) {
        if (i != lineNumber) {
            ifNo->addItem(QString::number(i));
            ifYes->addItem(QString::number(i));
        }
        if (QString::number(i) == selectedIfNo){
            ifNo->setCurrentText(selectedIfNo);
        }
        if (QString::number(i) == selectedIfYes){
            ifYes->setCurrentText(selectedIfYes);
        }
    }
    this->lineNumber = lineNumber;
    commandLine->setText(QString::number(lineNumber));
}






