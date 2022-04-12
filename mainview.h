#ifndef MAINVIEW_H
#define MAINVIEW_H

#include <QMainWindow>
#include <frontend/dynamicvariable.h>
#include <frontend/outputview.h>
#include <set>


QT_BEGIN_NAMESPACE
namespace Ui { class MainView; }
QT_END_NAMESPACE

class MainView : public QMainWindow
{
    Q_OBJECT

public:
    MainView(QWidget *parent = nullptr);
    ~MainView();



private slots:

    void fillOperationSelect();

    void getVariableData();

    void on_actionSave_triggered();

    void on_actionLoad_triggered();

    void on_actionAbout_triggered();

    void on_addNewVariable_clicked();

    void on_deleteVariable_clicked();

    void on_saveVariable_clicked();

    void on_runButton_clicked();

    void on_clearButton_clicked();

    void on_select_operation_button_clicked();

private:
    Ui::MainView *ui;
    DynamicVariable *selectedVariable;
    OutputView *outputView;
    std::set<DynamicVariable> dynamicVariableList;
};
#endif // MAINVIEW_H
