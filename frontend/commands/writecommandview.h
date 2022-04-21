//
// Created by profe on 20.04.2022.
//

#ifndef CODEBLOCPP_WRITECOMMANDVIEW_H
#define CODEBLOCPP_WRITECOMMANDVIEW_H


#include <QComboBox>
#include <QLabel>
#include "frontend/commandview.h"

class WriteCommandView : public CommandView {
public:
    WriteCommandView(QWidget *parent, int lineNumber, int linesSize, std::vector<DynamicVariable *> *variables);

    Command *getMyCommand(std::vector<DynamicVariable *> *variables) override;

    void updateUi(int linesSize,int lineNumber, std::vector<DynamicVariable *> *variables) override;

private:
    QComboBox *variable1;
    QLabel *commandLine;
};

#endif //CODEBLOCPP_WRITECOMMANDVIEW_H
