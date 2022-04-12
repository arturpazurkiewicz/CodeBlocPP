#include "mainview.h"
#include "./ui_mainview.h"
#include <QLineEdit>
#include <QIntValidator>
#include <QLocale>
#include <QComboBox>
#include <QHBoxLayout>
#include <QLabel>
#include <QCheckBox>

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

}

void MainView::getVariableData() {
    DynamicVariable *button = (DynamicVariable *) sender();
    selectedVariable = button;
    ui->line_variable->setText(QString::fromStdString(button->getMyVariable()->getVariable()));
    ui->line_value->setText(QString::number(button->getMyVariable()->getStartValue()));
}


void MainView::on_deleteVariable_clicked() {
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

}


void MainView::on_saveVariable_clicked() {
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

}


void MainView::on_runButton_clicked() {
    QPlainTextEdit *optionsArea = qobject_cast<QPlainTextEdit *>(ui->output_area->itemAt(0)->widget());

    optionsArea->appendPlainText("run");

}


void MainView::on_clearButton_clicked() {
    QPlainTextEdit *optionsArea = qobject_cast<QPlainTextEdit *>(ui->output_area->itemAt(0)->widget());

    optionsArea->setPlainText("CodeBloc++: \n");
}


void MainView::on_select_operation_button_clicked() {
    qDebug() << ui->operation_select->currentText();
    if (ui->operation_select->currentText().toStdString() == "IF"){
        addIfOperation();
    }
    else {
        qDebug() << ui->operation_select->currentText();
    }
}

void MainView::addIfOperation()
{
    QVBoxLayout *layout = qobject_cast<QVBoxLayout *>(ui->code_flow_layout->layout());
    CommandView *ifOperation = new CommandView(this);
    linesList.push_back(ifOperation->getCommandLine());
    QLabel *commandLine = new QLabel(this);
    QCheckBox *debug = new QCheckBox(this);
    QComboBox *variable1 = new QComboBox(this);
    QComboBox *variable2 = new QComboBox(this);
    QComboBox *ifOperator = new QComboBox(this);

     for (auto variable: dynamicVariableList){
         variable1->addItem(QString::fromStdString(variable->getMyVariable()->getVariable()));
         variable2->addItem(QString::fromStdString(variable->getMyVariable()->getVariable()));
     }

     ifOperator->addItem("NEQ");
     ifOperator->addItem("EQ");
     ifOperator->addItem("LT");
     ifOperator->addItem("GT");
     ifOperator->addItem("LE");
     ifOperator->addItem("GE");

    commandLine->setText(QString::number(ifOperation->getCommandLine()));

   ifOperation->addWidget(debug);
   ifOperation->addWidget(commandLine);
   ifOperation->addWidget(variable1);
   ifOperation->addWidget(ifOperator);
   ifOperation->addWidget(variable2);

   layout->addLayout(ifOperation);

}
