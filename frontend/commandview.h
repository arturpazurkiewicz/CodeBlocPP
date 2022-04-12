#ifndef COMMANDVIEW_H
#define COMMANDVIEW_H

#include <QLocale>
#include <QHBoxLayout>
#include "./backend/command.h"

class CommandView: public QHBoxLayout
{
     Q_OBJECT
public:
    //explicit CommandView(QWidget *parent = nullptr, Command *command = nullptr);
     explicit CommandView(QWidget *parent = nullptr);
       ~CommandView();
       static int LineNumber;
       Command* getMyCommand();
       int getCommandLine() const;

public slots:

private:
    //int value = 0;
    int lineNumber = 0;
    //Command* myCommand = new Command("", 0);
};

#endif // COMMANDVIEW_H
