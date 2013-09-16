 #include "chunklabel.h"
#include "chunk.h"

chunklabel::chunklabel(QWidget *parent,chunk* chp,chunkcontent *chunkcon_,char c,int x_,int y_) :
    QLabel(parent)
{
    chunk_p=chp;
    x=x_;
    y=y_;
    refresh_tooltip(c);
    QObject::connect(this,SIGNAL(clicked(chunk*/*,QLabel**/)),chunkcon_,SLOT(change_cont(chunk*/*,QLabel**/)));
}

void chunklabel::refresh_tooltip(int type_){
    if(type_!=0)type=type_;
    QString tooltip;
    tooltip.append(QString::number(x) + " " + QString::number(y));
    switch(type){
    case 'a':
        this->setStyleSheet(QString::fromUtf8("background-color:blue"));
        tooltip.append(" Wasser");
        break;
    case 'b':
        this->setStyleSheet(QString::fromUtf8("background-color:#228B22"));
        tooltip.append(" Flachland");
        break;
    case 'c':
        this->setStyleSheet(QString::fromUtf8("background-color:grey"));
        tooltip.append(" Gebirge");
        break;
    case 'd':
        this->setStyleSheet(QString::fromUtf8("background-color:green"));
        tooltip.append(" Wald");
        break;
    default:
        this->setStyleSheet(QString::fromUtf8("background-color:black"));
        tooltip.append(" typ unbekannt");
        break;
    }
    if(chunk_p->give_settlement()){
        switch((chunk_p->give_settlement())->give_settl_type()){
        case 'a':
            tooltip.append(" Feuerstelle");
            break;
        case 'b':
            tooltip.append(" Handelsposten");
            break;
        case 'c':
            tooltip.append(" Dorf");
            break;
        default:
            tooltip.append(" error");
            break;
        }
    }
    else {
        tooltip.append(" unbewohnt");
    }
    this->setToolTip(tooltip);


}

void chunklabel::set_type(char c){
    type=c;
}

void chunklabel::mousePressEvent(QMouseEvent *ev){
    if(ev)emit clicked(chunk_p/*,this*/);
}

