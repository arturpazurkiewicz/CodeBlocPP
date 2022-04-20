#include "commandview.h"


CommandView::~CommandView() {
    this->QHBoxLayout::~QHBoxLayout();
    delete generatedCommand;

}

CommandView::CommandView(QWidget *parent, int lineNumber) : QHBoxLayout(parent), lineNumber(lineNumber), debug(new QCheckBox(parent)) {
    this->addWidget(debug);
}




