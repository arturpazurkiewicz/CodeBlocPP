#include "mainview.h"
#include "./ui_mainview.h"
#include <QLineEdit>
#include <QIntValidator>
#include <QLocale>
#include <QComboBox>

MainView::MainView(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainView)
    , selectedVariable(new DynamicVariable)
{
    ui->setupUi(this);
    QValidator *validator = new QIntValidator(100, 999, this);
    ui->line_value->setValidator(validator);
    QPlainTextEdit *optionsArea = qobject_cast<QPlainTextEdit*>(ui->output_area->itemAt(0)->widget());
    optionsArea->setPlainText("CodeBloc++: \n");
    fillOperationSelect();
}

MainView::~MainView()
{
    delete ui;
}

void MainView::fillOperationSelect(){
    ui->operation_select->addItem("IF");
    ui->operation_select->addItem("JUMP");
    ui->operation_select->addItem("OPERATION");
    ui->operation_select->addItem("WRITE");
}

void MainView::on_actionSave_triggered()
{
    qDebug() << "save";
}


void MainView::on_actionLoad_triggered()
{
     qDebug() << "load fom file";
}


void MainView::on_actionAbout_triggered()
{
     qDebug() << "about us";
}

void MainView::on_addNewVariable_clicked(){

    DynamicVariable *button = new DynamicVariable(this);
    //dynamicVariableList.insert(*button);

    QVBoxLayout *layout = qobject_cast<QVBoxLayout*>(ui->variables_area->layout());

        button->setText("Variable: " + QString::fromStdString(button->getMyVariable()->getVariable()) + " Value: " + QString::number(button->getMyVariable()->getStartValue()));

        layout->addWidget(button);

        connect(button, SIGNAL(clicked()), this, SLOT(getVariableData()));

}

void MainView::getVariableData(){
     DynamicVariable *button = (DynamicVariable*) sender();
     selectedVariable = button;
     ui->line_variable->setText(QString::fromStdString(button->getMyVariable()->getVariable()));
     ui->line_value->setText(QString::number(button->getMyVariable()->getStartValue()));
}




void MainView::on_deleteVariable_clicked()
{
       for(int i = 0; i < ui->variables_area->count(); i++){

           DynamicVariable *button = qobject_cast<DynamicVariable*>(ui->variables_area->itemAt(i)->widget());

           if(QString::fromStdString(button->getMyVariable()->getVariable()).toStdString() == selectedVariable->getMyVariable()->getVariable()){
               button->hide();
               delete button;
               ui->line_variable->clear();
               ui->line_value->clear();
           }
       }
        //dynamicVariableList.erase(*selectedVariable);
}


void MainView::on_saveVariable_clicked()
{
      selectedVariable->getMyVariable()->setVariable(ui->line_variable->text().toStdString());
      selectedVariable->getMyVariable()->setStartValue(ui->line_value->text().toInt());
      selectedVariable->setText("Variable: " + ui->line_variable->text() + " Value: " + ui->line_value->text());

   /*  for(int i = 0; i < ui->variables_area->count(); i++){
          DynamicVariable *button = qobject_cast<DynamicVariable*>(ui->variables_area->itemAt(i)->widget());
          if(QString::fromStdString(button->getMyVariable()->getVariable()) == ui->line_variable->text()){
              selectedVariable->getMyVariable()->setVariable(ui->line_variable->text().toStdString() + "_copy");
              selectedVariable->getMyVariable()->setStartValue(ui->line_value->text().toInt());
              selectedVariable->setText("Variable: " + ui->line_variable->text()+ "_copy" + " Value: " + ui->line_value->text());
              qDebug() << "1";
          }
     }*/

}


void MainView::on_runButton_clicked()
{
    QPlainTextEdit *optionsArea = qobject_cast<QPlainTextEdit*>(ui->output_area->itemAt(0)->widget());

    optionsArea->appendPlainText("run");

}


void MainView::on_clearButton_clicked()
{
    QPlainTextEdit *optionsArea = qobject_cast<QPlainTextEdit*>(ui->output_area->itemAt(0)->widget());

    optionsArea->setPlainText("CodeBloc++: \n");
}


void MainView::on_select_operation_button_clicked()
{
    qDebug() << ui->operation_select->currentText();
}

