#ifndef MAINVIEW_H
#define MAINVIEW_H

#include <QMainWindow>
#include <frontend/dynamicvariable.h>
#include <frontend/outputview.h>
#include <frontend/commandview.h>
#include <set>
#include "backend/compiler.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainView; }
QT_END_NAMESPACE

template<typename Base, typename T>
inline bool instanceof(const T *ptr) {
    return dynamic_cast<const Base*>(ptr) != nullptr;
}

class MainView : public QMainWindow
{
    Q_OBJECT

public:
    MainView(QWidget *parent = nullptr);
    ~MainView();


    void Update_Ui();

private slots:

    void fillOperationSelect();

    void getVariableData();

    void on_addNewVariable_clicked();

    void on_deleteVariable_clicked();

    void on_saveVariable_clicked();

    void on_runButton_clicked();

    void on_clearButton_clicked();

    void on_select_operation_button_clicked();

    void addIfOperation();

    void addJumpOperation();

    void addOperationOperation();

    void addWriteOperation();

    void on_debugButton_clicked();

    void on_nextButton_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainView *ui;
    DynamicVariable *selectedVariable;
    OutputView *outputView;
    std::vector<DynamicVariable *> dynamicVariableList;
    std::vector<int> linesList;

    void reloadOnEndVariables();

    void reloadOnNextVariables();

    std::function<void(CommandView *)> deleteFun;
    std::function<void(CommandView*)> debugFun;
    std::function<void(const std::string)> outputFunction;
    QPushButton *nextButton;
    Compiler *compiler = nullptr;
    std::set<int> breakpoints;
    void reinterpretBreakpoints();

    void clearAllDebug(bool clearFullData);
};
#endif // MAINVIEW_H
