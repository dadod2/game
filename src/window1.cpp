#include "window1.h"
#include "cont1.h"
#include "cont2.h"
#include "cont3.h"
#include "contdelete.h"
#include "contaddbuild.h"
#include "menu.h"
#include <QDebug>
#include <QLayout>
#include <QSizePolicy>

void window1::set_menu(QWidget *menu){
    this->menu_p=menu;
}

void window1::change_cont(QWidget *window){
    int i=0;
    while(*(content+i)){
        (*(content+i))->setVisible(false);
        i++;
    }
    window->setVisible(true);
    window->activateWindow();
}

void window1::add_content(QWidget* addcontent,int size){
    int i=0;
    contentsize=size;
    while(*(content+i))i++;
    if(i==(contentsize-1))qDebug("error max content size");
    else{
        *(content+i)=addcontent;
    }
}

void window1::cont_build(int size){
    int i;
    content=new QWidget*[size];
    for(i=0;i<size;i++){
        *(content+i)=NULL;
    }

}

void window1::set_sizepolicy(int s){
    QSizePolicy policy1=(*content)->sizePolicy();
    policy1.setHorizontalStretch(s);
    int i=0;
    while(*(content+i)){
        (*(content+i))->setSizePolicy(policy1);
        i++;
    }
}

void window1::add_content_to_layout(QHBoxLayout *hblay,int flag){
    int i=0;
    while(*(content+i)){
        hblay->addWidget(*(content+i));
        (*(content+i))->setVisible(false);
        i++;
    }
    (*(content+flag))->setVisible(true);
}

window1::window1(QWidget *parent) :
    QWidget(parent)
{
    cont_build();
    QWidget *cont_one_win=new cont1();
        add_content(cont_one_win);
    QWidget *cont_two_win=new cont2();
        add_content(cont_two_win);
    QWidget *cont_three_win=new cont3();
        add_content(cont_three_win);
    QWidget *cont_four_win=new contdelete();
        add_content(cont_four_win);
    QWidget *cont_five_win=new contaddbuild();
        add_content(cont_five_win);
    QSignalMapper *signalmapper=new QSignalMapper(this);
    QWidget *menu_win=new menu(content,signalmapper);
    QHBoxLayout *mainlayout=new QHBoxLayout;
    QSizePolicy policy=menu_win->sizePolicy();
    policy.setHorizontalStretch(1);
    menu_win->setSizePolicy(policy);
    set_sizepolicy(4);

    mainlayout->addWidget(menu_win);
    menu_win->setVisible(true);
    add_content_to_layout(mainlayout);

    this->setLayout(mainlayout);
    QObject::connect(signalmapper,SIGNAL(mapped(QWidget*)),this,SLOT(change_cont(QWidget*)));


}
