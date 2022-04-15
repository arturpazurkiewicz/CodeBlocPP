#ifndef MAINVIEW_H
#define MAINVIEW_H

#include <QMainWindow>
#include <frontend/dynamicvariable.h>
#include <frontend/outputview.h>
#include <frontend/commandview.h>


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

    void Update_Ui();

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

    void addIfOperation();


private:
    Ui::MainView *ui;
    DynamicVariable *selectedVariable;
    OutputView *outputView;
    std::vector<DynamicVariable*> dynamicVariableList;
    std::vector<int> linesList;
};
#endif // MAINVIEW_H
