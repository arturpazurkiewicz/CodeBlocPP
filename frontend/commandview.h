#ifndef COMMANDVIEW_H
#define COMMANDVIEW_H

#include <QLocale>
#include <QHBoxLayout>
#include "./backend/command.h"

class CommandView : public QHBoxLayout {
Q_OBJECT
public:
    //explicit CommandView(QWidget *parent = nullptr, Command *command = nullptr);
    explicit CommandView(QWidget *parent = nullptr);

    ~CommandView() override;

    int lineNumber;

    virtual Command *getMyCommand() = 0;
    virtual void updateUi() = 0;

private:
public:


protected:
    Command *generatedCommand = nullptr;
};

#endif // COMMANDVIEW_H
