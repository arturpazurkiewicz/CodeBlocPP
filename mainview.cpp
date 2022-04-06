#include "mainview.h"
#include "./ui_mainview.h"
#include <QLineEdit>
#include <QIntValidator>

MainView::MainView(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainView)
    , selectedVariable(new QPushButton)
{
    ui->setupUi(this);
    QValidator *validator = new QIntValidator(100, 999, this);
    ui->line_value->setValidator(validator);
    QPlainTextEdit *optionsArea = qobject_cast<QPlainTextEdit*>(ui->output_area->itemAt(0)->widget());
    optionsArea->setPlainText("CodeBloc++: \n");
}

MainView::~MainView()
{
    delete ui;
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

    QVBoxLayout *layout = qobject_cast<QVBoxLayout*>(ui->variables_area->layout());

        button->setText("Variable: " + QString::number(button->getVariable()) + " Value: " + QString::number(button->getValue()));

        layout->addWidget(button);

        connect(button, SIGNAL(clicked()), this, SLOT(getVariableData()));

}

void MainView::getVariableData(){
     DynamicVariable *button = (DynamicVariable*) sender();
     selectedVariable = button;
     ui->line_variable->setText(QString::number(button->getVariable()));
     ui->line_value->setText(QString::number(button->getValue()));
}




void MainView::on_deleteVariable_clicked()
{
       for(int i = 0; i < ui->variables_area->count(); i++){

           DynamicVariable *button = qobject_cast<DynamicVariable*>(ui->variables_area->itemAt(i)->widget());

           if(button->getVariable() == ui->line_variable->text().toInt()){
               button->hide();
               delete button;
               ui->line_variable->clear();
               ui->line_value->clear();
           }
       }
}


void MainView::on_saveVariable_clicked()
{
    selectedVariable->setText("Variable: " + ui->line_variable->text() + " Value: " + ui->line_value->text());
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

