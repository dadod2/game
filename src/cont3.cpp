#include "cont3.h"
#include "map.h"
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QDebug>
#include <QObject>
#include <QDir>

void cont3::set_line_edit(QLineEdit *line){
    line_edit=line;
}

void cont3::set_combo_box(QComboBox *box){
    combo_box=box;
}

void cont3::create()
    {
    float t1,t2,t3,t4;
    switch(type1->currentIndex()){
    case 0:t1=0.2;break;
    case 1:t1=0.4;break;
    case 2:t1=0.6;break;
    case 3:t1=0.8;break;
    default:qDebug("Error, type1 c-box index doas not match any candidate!");break;
    }
    switch(type2->currentIndex()){
    case 0:t2=0.2;break;
    case 1:t2=0.4;break;
    case 2:t2=0.6;break;
    case 3:t2=0.8;break;
    default:qDebug("Error, type2 c-box index doas not match any candidate!");break;
    }
    switch(type3->currentIndex()){
    case 0:t3=0.2;break;
    case 1:t3=0.4;break;
    case 2:t3=0.6;break;
    case 3:t3=0.8;break;
    default:qDebug("Error, type3 c-box index doas not match any candidate!");break;
    }
    switch(type4->currentIndex()){
    case 0:t4=0.2;break;
    case 1:t4=0.4;break;
    case 2:t4=0.6;break;
    case 3:t4=0.8;break;
    default:qDebug("Error, type4 c-box index doas not match any candidate!");break;
    }
    int size_index=combo_box->currentIndex();
    int buildcount=0;
    QDir dir;
    QString puffer;
    QString path=dir.currentPath();
    QString mapdir;
    QString builddir=dir.currentPath();

    /*Überprüfen ob Content Ordner existiert, ggf erstellen, und pfad für build.txt einfügen*/

    if(!QDir("Content").exists()){
        QDir().mkdir("Content");
    }

    if(!QDir("Content/Buildings").exists()){
        QDir("Content").mkdir("Buildings");
    }
    builddir.append("/Content/Buildings/builds.txt");

    /*Überprüfen ob Saves und mapordner existiert, ggf erstellen und pfad hinzufügen*/

    if(!QDir("Saves").exists()){
        QDir().mkdir("Saves");
    }

    if(!QDir("Saves/" + this->line_edit->text()).exists()){
        QDir("Saves").mkdir(this->line_edit->text());
    }
    path.append("/Saves/" + this->line_edit->text() + "/");

    /*buildings.txt in den Mapordner kopieren*/

    mapdir=path;
    mapdir.append("builds.txt");
    QFile copyfile(mapdir);
    if(copyfile.copy(builddir,mapdir)){
        qDebug("build copy succesfull!");
    }
    else
        qDebug("error at build copy process!");

    /*gebäudeanzahl bestimmen*/

    QFile countfile(mapdir);
    if(!countfile.open(QFile::ReadOnly | QFile::Text))
        qDebug("cant open mapdir for count");
    else
        while(!countfile.atEnd()){
            puffer=countfile.readLine(20);
            buildcount++;
        }
    //qDebug() << buildcount;
    countfile.close();
    buildcount=buildcount/2;

    /*settlement.txt erstellen*/



    /*map.txt erstellen*/

    path.append("map.txt");
    QFile file(path);

    if(file.exists()){
        qDebug("already existing");
    }
    else{
        if(!file.open(QFile::WriteOnly | QFile::Text)){
            qDebug("cant open!");
        }
        else{
            mapgen(size_index,&file,t1,t2,t3,t4);
        }
        file.close();
    }
}

cont3::cont3(QWidget *parent) :
    QWidget(parent)
{
    QWidget *frame=new QWidget;
    QLabel *label1=new QLabel("Gewünschten Kartennamen eingeben!");
    QLabel *label2=new QLabel("Gewünschte Kartengröße auswählen!");
    QLabel *label3=new QLabel("Einstellungen für Geländetypen vornehmen!");
    QVBoxLayout *vblay=new QVBoxLayout;
    QHBoxLayout *hblay=new QHBoxLayout;
    QLineEdit *input=new QLineEdit;
    QPushButton *button=new QPushButton("Bestätigen");
    QComboBox *choose_size=new QComboBox;
    QComboBox *choose_type1=new QComboBox;
    type1=choose_type1;
    QComboBox *choose_type2=new QComboBox;
    type2=choose_type2;
    QComboBox *choose_type3=new QComboBox;
    type3=choose_type3;
    QComboBox *choose_type4=new QComboBox;
    type4=choose_type4;

    choose_size->addItem("50");
    choose_size->addItem("100");
    choose_size->addItem("200");
    choose_size->addItem("500");

    choose_type1->addItem("sehr wenig typ1");
    choose_type1->addItem("wenig typ1");
    choose_type1->addItem("mittelmäßig viel typ1");
    choose_type1->addItem("viel typ1");

    choose_type2->addItem("sehr wenig typ2");
    choose_type2->addItem("wenig typ2");
    choose_type2->addItem("mittelmäßig viel typ2");
    choose_type2->addItem("viel typ2");

    choose_type3->addItem("sehr wenig typ1");
    choose_type3->addItem("wenig typ3");
    choose_type3->addItem("mittelmäßig viel typ3");
    choose_type3->addItem("viel typ3");

    choose_type4->addItem("sehr wenig typ4");
    choose_type4->addItem("wenig typ4");
    choose_type4->addItem("mittelmäßig viel typ4");
    choose_type4->addItem("viel typ4");

    hblay->addWidget(choose_type1);
    hblay->addWidget(choose_type2);
    hblay->addWidget(choose_type3);
    hblay->addWidget(choose_type4);
    frame->setLayout(hblay);

    vblay->addWidget(label1);
    vblay->addWidget(input);
    vblay->addWidget(label2);
    vblay->addWidget(choose_size);
    vblay->addWidget(label3);
    vblay->addWidget(frame);
    vblay->addWidget(button);
    this->set_line_edit(input);
    this->set_combo_box(choose_size);
    this->setLayout(vblay);
    QObject::connect(button,SIGNAL(clicked()),this,SLOT(create()));
}
