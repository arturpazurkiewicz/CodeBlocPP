#ifndef OUTPUTVIEW_H
#define OUTPUTVIEW_H

#include <QPlainTextEdit>
#include <QString>

class OutputView: public QPlainTextEdit
{
     Q_OBJECT
public:
    explicit OutputView(QWidget *parent = nullptr);
       ~OutputView();
       static QString ActualText;

      // QString append(QString text = nullptr);
      // void clear();

public slots:

private:
    QString actualText = "";
};
#endif // OUTPUTVIEW_H
