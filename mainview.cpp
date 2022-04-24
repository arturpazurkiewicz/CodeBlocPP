#include "mainview.h"
#include "./ui_mainview.h"
#include "frontend/commands/ifcommandview.h"
#include "frontend/commands/jumpcommandview.h"
#include "frontend/commands/operationcommandview.h"
#include "frontend/commands/writecommandview.h"
#include "backend/compiler.h"
#include <QLineEdit>
#include <QIntValidator>
#include <QLocale>
#include <QComboBox>
#include <QHBoxLayout>
#include <QLabel>
#include <QCheckBox>
#include <QApplication>
#include <QDoubleSpinBox>

MainView::MainView(QWidget *parent)
        : QMainWindow(parent), ui(new Ui::MainView), selectedVariable(nullptr) {
    ui->setupUi(this);
    QValidator *validator = new QIntValidator(100, 999, this);
    ui->line_value->setValidator(validator);
    QPlainTextEdit *optionsArea = qobject_cast<QPlainTextEdit *>(ui->output_area->itemAt(0)->widget());
    optionsArea->setPlainText("CodeBloc++: \n");
    fillOperationSelect();
}

MainView::~MainView() {
    delete ui;
}

void MainView::Update_Ui() {
    auto *layout = qobject_cast<QVBoxLayout *>(ui->code_flow_layout->layout());
    QList<QObject *> qList = layout->children();

    for (int i = 0; i < qList.size(); ++i) {
        qDebug() << "Update";
        QObject *qItem = qList[i];

        if (instanceof<CommandView>(qItem)) {
            auto *commandView = (CommandView *) qItem;
            commandView->updateUi(qList.size(), i, &dynamicVariableList);
        }
    }
    qDebug() << "Koniec";

}

void MainView::fillOperationSelect() {
    ui->operation_select->addItem("IF");
    ui->operation_select->addItem("JUMP");
    ui->operation_select->addItem("OPERATION");
    ui->operation_select->addItem("WRITE");
}

void MainView::on_actionSave_triggered() {
    qDebug() << "save";
}


void MainView::on_actionLoad_triggered() {
    qDebug() << "load fom file";
}


void MainView::on_actionAbout_triggered() {
    qDebug() << "about us";
}

void MainView::on_addNewVariable_clicked() {
    this->setEnabled(false);
    DynamicVariable *button = new DynamicVariable(this);
    dynamicVariableList.push_back(button);

    for (auto variable: dynamicVariableList) {
        qDebug() << QString::fromStdString(variable->getMyVariable()->getVariable());
    }

    QVBoxLayout *layout = qobject_cast<QVBoxLayout *>(ui->variables_area->layout());

    button->setText("Variable: " + QString::fromStdString(button->getMyVariable()->getVariable()) + " Value: " +
                    QString::number(button->getMyVariable()->getStartValue()));

    layout->addWidget(button);

    connect(button, SIGNAL(clicked()), this, SLOT(getVariableData()));

    Update_Ui();
    this->setEnabled(true);
}

void MainView::getVariableData() {
    DynamicVariable *button = (DynamicVariable *) sender();
    selectedVariable = button;
    ui->line_variable->setText(QString::fromStdString(button->getMyVariable()->getVariable()));
    ui->line_value->setText(QString::number(button->getMyVariable()->getStartValue()));
}


void MainView::on_deleteVariable_clicked() {
    this->setEnabled(false);
    if (selectedVariable != nullptr) {
        for (int i = 0; i < ui->variables_area->count(); i++) {

            DynamicVariable *button = qobject_cast<DynamicVariable *>(ui->variables_area->itemAt(i)->widget());

            if (QString::fromStdString(button->getMyVariable()->getVariable()).toStdString() ==
                selectedVariable->getMyVariable()->getVariable()) {
                button->hide();
                dynamicVariableList.erase(dynamicVariableList.begin() + i);
                delete button;
                ui->line_variable->clear();
                ui->line_value->clear();
                break;
            }
        }
        selectedVariable = nullptr;
    }
    Update_Ui();
    this->setEnabled(true);
}


void MainView::on_saveVariable_clicked() {
    if (selectedVariable != nullptr){
        this->setEnabled(false);
        selectedVariable->getMyVariable()->setVariable(ui->line_variable->text().toStdString());
        selectedVariable->getMyVariable()->setStartValue(ui->line_value->text().toInt());
        selectedVariable->setText("Variable: " + ui->line_variable->text() + " Value: " + ui->line_value->text());
        std::string newValue = ui->line_variable->text().toStdString();

        for (int i = 0; i < ui->variables_area->count(); i++) {
            auto *button = qobject_cast<DynamicVariable *>(ui->variables_area->itemAt(i)->widget());
            if (newValue == button->getMyVariable()->getVariable() && selectedVariable != button) {
                newValue += "_copy";
                selectedVariable->getMyVariable()->setVariable(newValue);
                selectedVariable->getMyVariable()->setStartValue(ui->line_value->text().toInt());
                selectedVariable->setText(
                        "Variable: " + QString::fromStdString(selectedVariable->getMyVariable()->getVariable()) +
                        " Value: " + ui->line_value->text());
                qDebug() << "1";
                i = -1;
            }
        }

        Update_Ui();
        this->setEnabled(true);
    }
}


void MainView::on_runButton_clicked() {
    QPlainTextEdit *optionsArea = qobject_cast<QPlainTextEdit *>(ui->output_area->itemAt(0)->widget());
    std::vector<Command *> commands;
    std::set<int> breakpoints;
    auto resultFunction = [optionsArea](const std::string& data) -> void {
        optionsArea->appendPlainText(QString::fromStdString(data));
    };
    auto *compiler = new Compiler(commands, &breakpoints, NORMAL, nullptr);
    compiler->check(resultFunction);

    optionsArea->appendPlainText("run");

}


void MainView::on_clearButton_clicked() {
    QPlainTextEdit *optionsArea = qobject_cast<QPlainTextEdit *>(ui->output_area->itemAt(0)->widget());

    optionsArea->setPlainText("CodeBloc++: \n");
}


void MainView::on_select_operation_button_clicked() {
    qDebug() << ui->operation_select->currentText();
    if (ui->operation_select->currentText().toStdString() == "IF") {
        addIfOperation();
    } else if (ui->operation_select->currentText().toStdString() == "JUMP") {
        addJumpOperation();
    }
    else if (ui->operation_select->currentText().toStdString() == "OPERATION") {
        addOperationOperation();
    }
    else if (ui->operation_select->currentText().toStdString() == "WRITE") {
        addWriteOperation();
    }
    else {
        qDebug() << ui->operation_select->currentText();
    }
    Update_Ui();
}

void MainView::addIfOperation() {
    QVBoxLayout *layout = qobject_cast<QVBoxLayout *>(ui->code_flow_layout->layout());
    auto deleteFun = [layout](CommandView *command) -> void {
        layout->removeItem(command);
    };
    CommandView *ifOperation = new IfCommandView(this, layout->count(), layout->count(), &dynamicVariableList);
//    TODO to constructor
    ifOperation->deleteFunction = deleteFun;
    layout->addLayout(ifOperation);
}

void MainView::addJumpOperation() {
    QVBoxLayout *layout = qobject_cast<QVBoxLayout *>(ui->code_flow_layout->layout());
    CommandView *jumpOperation = new JumpCommandView(this, layout->count(), layout->count(), &dynamicVariableList);
    qDebug() << "foengworngrjn";
    layout->addLayout(jumpOperation);
}

void MainView::addOperationOperation() {
    QVBoxLayout *layout = qobject_cast<QVBoxLayout *>(ui->code_flow_layout->layout());
    CommandView *operationOperation = new OperationCommandView(this, layout->count(), layout->count(), &dynamicVariableList);
    layout->addLayout(operationOperation);
}

void MainView::addWriteOperation() {
    QVBoxLayout *layout = qobject_cast<QVBoxLayout *>(ui->code_flow_layout->layout());
    CommandView *writeOperation = new WriteCommandView(this, layout->count(), layout->count(), &dynamicVariableList);
    layout->addLayout(writeOperation);
}

void MainView::Delete_Command(QPushButton *deleteButton) { //not working
    qDebug() << "delete" + QString::number(getInstance().ui->code_flow_layout->children().count());
    QVBoxLayout *layout = qobject_cast<QVBoxLayout *>(getInstance().ui->code_flow_layout->layout());
    for (int i = 0; i < getInstance().ui->code_flow_layout->count(); i++) {
        qDebug() << "delete";
        QLayout *command = qobject_cast<QLayout *>(getInstance().ui->code_flow_layout->itemAt(i)->widget());
        qDebug() << command->itemAt(0)->widget()->windowIconText();
        if (command->itemAt(0)->widget() == deleteButton) {
            qDebug() << "delete" + QString::number(i);
        }
    }
}