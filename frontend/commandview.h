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
    CommandView(QWidget *parent, int lineNumber, std::function<void(CommandView*)> deleteFunction);

    ~CommandView() override;

    int lineNumber;

    virtual Command *getMyCommand(std::vector<DynamicVariable *> *variables) = 0;

    virtual void updateUi(int linesSize, int lineNumber, std::vector<DynamicVariable *> *variables) = 0;

    bool getDebug();

protected:
    QPushButton *deleteCommand;
    QCheckBox *debug;
    Command *generatedCommand = nullptr;

    std::function<void(CommandView*)> deleteFunction;

    static Variable *findSelectedVariable(std::vector<DynamicVariable *> *variables, const QString& selected) {
        std::string sel = selected.toStdString();
        for (auto variable: *variables) {
            if (variable->getMyVariable()->getVariable() == sel) {
                return variable->getMyVariable();
            }
        }
        return nullptr;
    }

public slots:
    void deleteCommandObject();
};

#endif // COMMANDVIEW_H
