//
// Created by profe on 20.04.2022.
//

#ifndef CODEBLOCPP_OPERATIONCOMMANDVIEW_H
#define CODEBLOCPP_OPERATIONCOMMANDVIEW_H


#include "frontend/commandview.h"
#include "backend/commands/operationcommand.h"

class OperationCommandView : public CommandView {
public:
    OperationCommandView(QWidget *parent, int lineNumber, int linesSize, std::vector<DynamicVariable *> *variables);

    Command *getMyCommand(std::vector<DynamicVariable *> *variables) override;

    void updateUi(int linesSize,int lineNumber, std::vector<DynamicVariable *> *variables) override;

private:
    QComboBox *variable1;
    QComboBox *variable2;
    QComboBox *variable3;
    QComboBox *operation;
    QLabel *commandLine;

    static Operation findOperation(const QString& comparator);
};


#endif //CODEBLOCPP_OPERATIONCOMMANDVIEW_H
