#include "outputview.h"


OutputView::OutputView(QWidget *parent) :
    QPlainTextEdit(parent)
{
    ActualText = "to jest test";
}

OutputView::~OutputView()
{

}

/*QString OutputView::append(QString text)
{
    return QString(this->ActualText + "\n" + text);
}

void OutputView::clear()
{
    ActualText = "";
}
*/
/* Initialize static class variable.
 * Static class variable must be initialized without fail
 * */
QString OutputView::ActualText = "";
