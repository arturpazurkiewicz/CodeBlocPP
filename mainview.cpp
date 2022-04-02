#include "mainview.h"
#include "./ui_mainview.h"
#include "./frontend/variableview.h"

MainView::MainView(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainView)
{
    ui->setupUi(this);

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
