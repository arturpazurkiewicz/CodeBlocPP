//
// Created by profe on 20.04.2022.
//

#ifndef CODEBLOCPP_JUMPCOMMANDVIEW_H
#define CODEBLOCPP_JUMPCOMMANDVIEW_H


#include <QComboBox>
#include <QLabel>
#include "frontend/dynamicvariable.h"
#include "backend/command.h"
#include "frontend/commandview.h"

class JumpCommandView : public CommandView{
public:
    JumpCommandView(QWidget *parent, int lineNumber, int linesSize, std::vector<DynamicVariable *> *variables);

    Command *getMyCommand(std::vector<DynamicVariable *> *variables) override;

    void updateUi(int linesSize,int lineNumber, std::vector<DynamicVariable *> *variables) override;

private:
    QComboBox *jumpTo;
    QLabel *commandLine;
};


#endif //CODEBLOCPP_JUMPCOMMANDVIEW_H
