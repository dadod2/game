#include "mapcontainer.h"
#include "chunk.h"
#include "chunklabel.h"
#include "chunkcontent.h"
#include <QDebug>

mapcontainer::mapcontainer(QWidget *parent, management *manager_,QGridLayout *gridlay,chunkcontent *chunkcont_,int x_,int y_):QWidget(parent){
    chunklabel *hp;
    map=manager_->give_map();
    winsize=manager_->give_winsize();
    step=manager_->give_stepsize();
    layout=gridlay;
    chunkcont=chunkcont_;
    x=x_;
    y=y_;
    mapsize=0;
    int i=0,j=0;
    for(i=0;i<winsize;i++){
        for(j=0;j<winsize;j++){
                hp=new chunklabel(this,*(*(map+(i+x_))+(j+y_)),chunkcont,(*(*(map+(i+x_))+(j+y_)))->give_type(),i+x_,j+y_);
            layout->addWidget(hp,i,j);
        }
    }
    i=0;
    while(*(map+i)){
        mapsize++;
        i++;
    }
    layout->setHorizontalSpacing(0);
    layout->setVerticalSpacing(0);
    this->setLayout(layout);
}

void mapcontainer::moved(int k){
    QLayoutItem *lhp;
    chunklabel *hp;
    int i,j;
    int x_,y_;
    switch(k){
    case 1:
        x_=x-step;
        y_=0+y;
        if(x_<0)x_=0;
        else if(y_<0)y_=0;
        else {
            if(x_>(mapsize-winsize-step))x_=(mapsize-winsize-step);
            else if(y_>(mapsize-winsize-step))y_=(mapsize-winsize-step);
            else {
                for(i=0;i<winsize;i++){
                    for(j=0;j<step;j++){
                        lhp=layout->itemAtPosition(j+winsize-step,i);//winsize-(1+j)
                        layout->removeItem(lhp);
                        delete (lhp->widget());
                    }
                }
                for(i=winsize-(step+1);i>=0;i--){
                    for(j=0;j<winsize;j++){
                        lhp=layout->itemAtPosition(i,j);
                        layout->removeItem(lhp);
                        layout->addWidget(lhp->widget(),i+step,j);
                    }
                }
                for(j=0;j<winsize;j++){
                    for(i=0;i<step;i++){
                        hp=new chunklabel(this,*(*(map+(i+x_))+(j+y_)),chunkcont,(*(*(map+(i+x_))+(j+y_)))->give_type(),i+x_,j+y_);
                        layout->addWidget(hp,i,j);
                    }
                }
            }
        }
        x=x_;
        y=y_;
        break;
    case 2:
        x_=0+x;
        y_=y-step;

        if(x_<0)x_=0;
        else if(y_<0)y_=0;
        else {
            if(x_>(mapsize-winsize-step))x_=(mapsize-winsize-step);
            else if(y_>(mapsize-winsize-step))y_=(mapsize-winsize-step);
            else {
                for(i=0;i<winsize;i++){
                    for(j=0;j<step;j++){
                        lhp=layout->itemAtPosition(i,j+winsize-step);
                        layout->removeItem(lhp);
                        delete (lhp->widget());
                    }
                }
                for(i=winsize-(step+1);i>=0;i--){
                    for(j=0;j<winsize;j++){
                        lhp=layout->itemAtPosition(j,i);
                        layout->removeItem(lhp);
                        layout->addWidget(lhp->widget(),j,i+step);
                    }
                }
                for(j=0;j<winsize;j++){
                    for(i=0;i<step;i++){
                        hp=new chunklabel(this,*(*(map+(j+x_))+(i+y_)),chunkcont,(*(*(map+(j+x_))+(i+y_)))->give_type(),j+x_,i+y_);
                        layout->addWidget(hp,j,i);
                    }
                }
            }
        }
        x=x_;
        y=y_;
        break;
    case 3:
        x_=x+step;
        y_=0+y;

        if(x_<0)x_=0;
        else if(y_<0)y_=0;
        else {
            if(x_>(mapsize-winsize-step))x_=(mapsize-winsize-step);
            else if(y_>(mapsize-winsize-step))y_=(mapsize-winsize-step);
            else {
                for(i=0;i<winsize;i++){
                    for(j=0;j<step;j++){
                        lhp=layout->itemAtPosition(j,i);
                        layout->removeItem(lhp);
                        delete (lhp->widget());
                    }
                }
                for(i=step;i<winsize;i++){
                    for(j=0;j<winsize;j++){
                        lhp=layout->itemAtPosition(i,j);
                        layout->removeItem(lhp);
                        layout->addWidget(lhp->widget(),i-step,j);
                    }
                }
                for(j=0;j<winsize;j++){
                    for(i=winsize-(step);i<winsize;i++){
                        hp=new chunklabel(this,*(*(map+(i+x_))+(j+y_)),chunkcont,(*(*(map+(i+x_))+(j+y_)))->give_type(),i+x_,j+y_);
                        layout->addWidget(hp,i,j);
                    }
                }
            }
        }
        x=x_;
        y=y_;
        break;
    case 4:
        x_=0+x;
        y_=y+step;

        if(x_<0)x_=0;
        else if(y_<0)y_=0;
        else {
            if(x_>(mapsize-winsize-step))x_=(mapsize-winsize-step);
            else if(y_>(mapsize-winsize-step))y_=(mapsize-winsize-step);
            else {
                for(i=0;i<winsize;i++){
                    for(j=0;j<step;j++){
                        lhp=layout->itemAtPosition(i,j);
                        layout->removeItem(lhp);
                        delete (lhp->widget());
                    }
                }
                for(i=step;i<winsize;i++){
                    for(j=0;j<winsize;j++){
                        lhp=layout->itemAtPosition(j,i);
                        layout->removeItem(lhp);
                        layout->addWidget(lhp->widget(),j,i-step);
                    }
                }
                for(j=0;j<winsize;j++){
                    for(i=winsize-step;i<winsize;i++){
                        hp=new chunklabel(this,*(*(map+(j+x_))+(i+y_)),chunkcont,(*(*(map+(j+x_))+(i+y_)))->give_type(),j+x_,i+y_);
                        layout->addWidget(hp,j,i);
                    }
                }
            }
        }
        x=x_;
        y=y_;
        break;
    default:
        break;
    }
    x=x_;
    y=y_;
}



