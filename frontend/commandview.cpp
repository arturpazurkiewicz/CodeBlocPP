#include "commandview.h"
#include "mainview.h"


CommandView::~CommandView() {
    this->QHBoxLayout::~QHBoxLayout();
    delete generatedCommand;

}

CommandView::CommandView(QWidget *parent, int lineNumber) : QHBoxLayout(parent), lineNumber(lineNumber),
                                                            debug(new QCheckBox(parent)),
                                                            deleteCommand(new QPushButton(parent)) {
    connect(deleteCommand, SIGNAL(clicked()), this, SLOT(deleteCommandObject()));
    deleteCommand->setText("DELETE");
    this->addWidget(deleteCommand);
    this->addWidget(debug);
}

void CommandView::deleteCommandObject(){
//    auto *deleteButton = (QPushButton *) sender();
//    MainView::Delete_Command(deleteButton);
    deleteFunction(this);
   /* for (int i = 0; i < ui->code_flow_layout->count(); i++) {
        QLayout *command = qobject_cast<QLayout *>(ui->code_flow_layout->itemAt(i)->widget());
        if(command->itemAt(0)->widget() == deleteButton){
            qDebug() << "delete" + QString::number(i);
        }
    }*/
}


