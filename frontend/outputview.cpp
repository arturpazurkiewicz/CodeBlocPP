#include "outputview.h"


OutputView::OutputView(QWidget *parent) :
    QPlainTextEdit(parent)
{
    ActualText = "to jest test";
}

OutputView::~OutputView()
{

}

QString OutputView::ActualText = "";
