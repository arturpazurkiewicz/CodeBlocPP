#include "variableview.h"
#include "./mainview.h"
#include "./ui_mainview.h"
#include <QCheckBox>
#include <QLineEdit>

VariableView::VariableView(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::VariableView)
{
    ui->setupUi(nullptr);

    QObject::connect(
                ui->addNewVariable, &QPushButton::clicked,
                this, &VariableView::onAddVariable
                );

}

VariableView::~VariableView(){}

void VariableView::onAddVariable(){
  QVBoxLayout* layout = qobject_cast<QVBoxLayout*>(ui->variables_frame->layout());

  QString variableName = tr("VARIABLE #%1").arg(layout->count());
  QLineEdit* variable = new QLineEdit(variableName, ui->variables_frame);
  layout->insertWidget(0, variable);
  QLineEdit* value = new QLineEdit(ui->variables_frame);
  layout->insertWidget(0, value);

  QPushButton* deleteButton = new QPushButton("DELETE VARIABLE", ui->variables_frame);
  layout->insertWidget(0, deleteButton);

  QObject::connect(
              deleteButton, &QPushButton::clicked,
              this, &VariableView::onRemoveVariable
              );
}

void VariableView::onRemoveVariable(){

}
