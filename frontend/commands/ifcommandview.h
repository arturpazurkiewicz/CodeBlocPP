//
// Created by profe on 20.04.2022.
//

#ifndef CODEBLOCPP_IFCOMMANDVIEW_H
#define CODEBLOCPP_IFCOMMANDVIEW_H


#include "frontend/commandview.h"

class IfCommandView: public CommandView{
public:
    IfCommandView();

    Command *getMyCommand() override;
    void updateUi() override;

};


#endif //CODEBLOCPP_IFCOMMANDVIEW_H
