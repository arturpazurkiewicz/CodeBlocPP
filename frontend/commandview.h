#ifndef COMMANDVIEW_H
#define COMMANDVIEW_H

#include <QLocale>
#include <QHBoxLayout>
#include <QCheckBox>
#include "./backend/command.h"
#include "dynamicvariable.h"

class CommandView : public QHBoxLayout {
Q_OBJECT
public:
    //explicit CommandView(QWidget *parent = nullptr, Command *command = nullptr);
    CommandView(QWidget *parent, int lineNumber);

    ~CommandView() override;

    int lineNumber;

    virtual Command *getMyCommand(std::vector<DynamicVariable *> *variables) = 0;

    virtual void updateUi(int linesSize, int lineNumber, std::vector<DynamicVariable *> *variables) = 0;


protected:
    QPushButton *deleteCommand;
    QCheckBox *debug;
    Command *generatedCommand = nullptr;

    static Variable *findSelectedVariable(std::vector<DynamicVariable *> *variables, const QString& selected) {
        std::string sel = selected.toStdString();
        for (auto variable: *variables) {
            if (variable->getMyVariable()->getVariable() == sel) {
                return variable->getMyVariable();
            }
        }
        return nullptr;
    }

    void deleteCommandObject(QWidget layout, int layoutIndex);
};
// TODO fill rest of commands
// TODO add delete on commands
#endif // COMMANDVIEW_H
