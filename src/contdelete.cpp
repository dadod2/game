#include "contdelete.h"

void contdelete::delete_map(){
    QDir dir;
    QString path=dir.currentPath();
    if(!QDir("Saves").exists()){
        qDebug("No Saves Folder found");
    }
    else
        path.append("/Saves/");
    if(!QDir("Saves/" + this->line_edit->text()).exists()){
        qDebug("Map not found");
    }
    else{
        path.append(this->line_edit->text() + "/");
        QString mappath=path;
        QString buildpath=path;
        path.append("map.txt");
        buildpath.append("builds.txt");
        if(dir.remove(path)){
            qDebug("removed map.txt succesfully!");
            if(dir.remove(buildpath)){
                qDebug("removed builds.txt succesfully!");
                    if(dir.rmdir(mappath))
                        qDebug("remove of mapfolder succesfully!");
                    else
                        qDebug("remove of mapfolder failed!");
            }
            else
                qDebug("removing of builds.txt failed!");
        }
        else
            qDebug("removing of map.txt failed!");
    }
}

contdelete::contdelete(QWidget *parent) :
    QWidget(parent)
{
    QLabel *label=new QLabel("Bitte den namen der zu löschenden Karte eingeben!");
    QVBoxLayout *vblay=new QVBoxLayout;
    QHBoxLayout *hblay=new QHBoxLayout;
    QWidget *window2=new QWidget;
    line_edit=new QLineEdit;
    QPushButton *button=new QPushButton;

    hblay->addWidget(line_edit);
    hblay->addWidget(button);
    window2->setLayout(hblay);
    vblay->addStretch();
    vblay->addWidget(label);
    vblay->addWidget(window2);
    vblay->addStretch();

    this->setLayout(vblay);
    QObject::connect(button,SIGNAL(clicked()),this,SLOT(delete_map()));
}
