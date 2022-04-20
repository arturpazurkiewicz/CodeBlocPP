#include "commandview.h"

//CommandView::CommandView(QWidget *parent, Command *command) : QHBoxLayout(parent)
CommandView::CommandView(QWidget *parent) : QHBoxLayout(parent)
{
    lineNumber++;
}

CommandView::~CommandView()
{
    this->QHBoxLayout::~QHBoxLayout();
    if (generatedCommand != nullptr){
        delete generatedCommand;
    }
}

Command* CommandView::getMyCommand(){
   // return command;
}
