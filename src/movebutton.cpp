#include "movebutton.h"

movebutton::movebutton(QWidget *parent,int type) :
    QLabel(parent)
{
    move_type=type;
    switch(type){
    case 1:
        this->setStyleSheet(QString::fromUtf8("background-color:red"));
        break;
    case 2:
        this->setStyleSheet(QString::fromUtf8("background-color:red"));
        break;
    case 3:
        this->setStyleSheet(QString::fromUtf8("background-color:red"));
        break;
    case 4:
        this->setStyleSheet(QString::fromUtf8("background-color:red"));
        break;
    default:
        break;

    }
}

void movebutton::slotclicked(int i){
    qDebug() << i;
}

void movebutton::mousePressEvent(QMouseEvent *ev){
    if(ev)emit clicked(move_type);
}

