#include "cont1.h"
#include <QLabel>
#include <QVBoxLayout>

cont1::cont1(QWidget *parent) :
    QWidget(parent)
{
    QLabel *label=new QLabel("Test1");
    QVBoxLayout *vblay=new QVBoxLayout;
    vblay->addWidget(label);
    this->setLayout(vblay);
}
