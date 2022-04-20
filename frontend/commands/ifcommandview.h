//
// Created by profe on 20.04.2022.
//

#ifndef CODEBLOCPP_IFCOMMANDVIEW_H
#define CODEBLOCPP_IFCOMMANDVIEW_H


#include <QComboBox>
#include <QLabel>
#include "frontend/commandview.h"

class IfCommandView : public CommandView {
public:
    IfCommandView(QWidget *parent, int lineNumber, int linesSize, std::vector<DynamicVariable *> *variables);

    Command *getMyCommand(std::vector<DynamicVariable *> *variables) override;

    void updateUi(int linesSize,int lineNumber, std::vector<DynamicVariable *> *variables) override;

private:
    QComboBox *variable1;
    QComboBox *variable2;
    QComboBox *ifYes;
    QComboBox *ifNo;
    QLabel *commandLine;
};


#endif //CODEBLOCPP_IFCOMMANDVIEW_H
