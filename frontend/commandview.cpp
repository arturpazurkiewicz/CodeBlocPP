#include "commandview.h"

//CommandView::CommandView(QWidget *parent, Command *command) : QHBoxLayout(parent)
CommandView::CommandView(QWidget *parent) : QHBoxLayout(parent)
{
    LineNumber++;
    lineNumber = LineNumber;
}

CommandView::~CommandView()
{

}

Command* CommandView::getMyCommand(){
   // return command;
}

int CommandView::getCommandLine() const{
    return lineNumber;
}

int CommandView::LineNumber = 0;
