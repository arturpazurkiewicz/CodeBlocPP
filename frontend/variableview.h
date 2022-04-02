#ifndef VARIABLEVIEW_H
#define VARIABLEVIEW_H

#include "ui_mainview.h"
#include "./mainview.h"
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class VariableView: public Ui_MainView {};}
QT_END_NAMESPACE

class VariableView: public QWidget
{

    Q_OBJECT

public:
    VariableView(QWidget *parent = nullptr);
    ~VariableView();

    void onAddVariable();

    void onRemoveVariable();

private:
    Ui::VariableView *ui;

};

#endif // VARIABLEVIEW_H
