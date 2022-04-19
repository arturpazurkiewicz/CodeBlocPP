#include "mainview.h"
#include "backend/variable.h"
#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include "backend/commands/writecommand.h"
#include "backend/commands/jumpcommand.h"
#include "backend/commands/operationcommand.h"
#include "backend/commands/ifcommand.h"
#include "backend/compiler.h"


void myCout(const std::string input) {
    qInfo() << qPrintable(QString::fromStdString(input));
}


int main(int argc, char *argv[]) {
//    Generating variables
    auto *va = new Variable("a", 0);
    auto *vb = new Variable("b", 1);
    auto *v1 = new Variable("1", 1);
    auto *vp = new Variable("p", 12);
    auto *vi = new Variable("i", 0);


//    Unnecessary step
    std::vector<Variable *> variables;
    variables.push_back(va);
    variables.push_back(vb);
    variables.push_back(v1);
    variables.push_back(vp);
    variables.push_back(vi);

//    Generating commands
    Command *c0 = new IfCommand(nullptr, vi, vp, 1, 5, GT);
    Command *c1 = new OperationCommand(nullptr, vb, va, vb, PLUS);
    Command *c2 = new OperationCommand(nullptr, vb, va, va, MINUS);
    Command *c3 = new OperationCommand(nullptr, vi, v1, vi, PLUS);
    Command *c4 = new JumpCommand(nullptr, 0);
    Command *c5 = new WriteCommand(nullptr, va);

//     Inserting commands
    std::vector<Command *> commands;
    commands.push_back(c0);
    commands.push_back(c1);
    commands.push_back(c2);
    commands.push_back(c3);
    commands.push_back(c4);
    commands.push_back(c5);

    std::set<int> breakpoints;

    auto *compiler = new Compiler(commands, &breakpoints, NORMAL, &myCout);

    qDebug() << compiler->run();

    return 0;
}
