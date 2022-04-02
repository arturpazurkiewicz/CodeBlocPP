#ifndef MAINVIEW_H
#define MAINVIEW_H

#include <QMainWindow>

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


    void on_actionSave_triggered();

    void on_actionLoad_triggered();

    void on_actionAbout_triggered();


private:
    Ui::MainView *ui;
};
#endif // MAINVIEW_H
