#include "cont2.h"
#include "chunk.h"
#include "map.h"
#include "mapdiag.h"
#include "management.h"
#include <QPushButton>
#include <QVBoxLayout>
#include <QObject>
#include <QDir>
#include <QDebug>
#include <QString>

void cont2::set_line_edit(QLineEdit *line){
    line_edit=line;
}

void cont2::set_map(chunk*** mapp){
    map=mapp;
    mapsize=0;
    while(*(map+mapsize))mapsize++;
}

chunk ***cont2::get_map(){
    return map;
}

void cont2::load(){
    int i,j;
    if(this->map){
        deletemap(this->map);
        qDebug("map already loaded, was deleted");
    }
    //management *manager;

    QDir dir;
    QString path=dir.currentPath();
    QString buildingspath;
    QString settlpath;
    QString mappath;
    building_props *building_list=NULL;
    building_props *hp;
    settlement *settlementhp;
    settlement *settlementhp2=NULL;
    management *manager=new management();
    if(!QDir("Saves").exists()){
        qDebug("No Saves Folder found");
    }
    else path.append("/Saves/");
    if(!QDir("Saves/" + this->line_edit->text()).exists()){
        qDebug("Map not found");
    }

    else{
        path.append(this->line_edit->text() + "/");
        buildingspath=path;
        settlpath=path;
        mappath=path;
        settlpath.append("settlements.txt");
        mappath.append("map.txt");
        buildingspath.append("builds.txt");
        QFile fp(mappath);
        QFile fp1(settlpath);
        QFile fp2(buildingspath);
        QFile fpsave(mappath);
        QFile fpsavesett(settlpath);

        /*Auslesen der map.txt*/

        if(!fp.open(QFile::ReadOnly | QFile::Text)){
            qDebug("cant open map.txt for read!");
            qDebug() << mappath;
        }
        else{
            qDebug("open succesfull");
            this->set_map(mapload(map,&fp));
        }
        fp.close();

        /*auslesen der settlement.txt*/

        if(!fp1.open(QFile::ReadOnly | QFile::Text)){
            qDebug("cant open settlement.txt for read!");
            qDebug() << settlpath;
        }
        else{
            qDebug("opened settlement.txt succesfully!");
            while(!fp1.atEnd()){//qDebug("test1");fflush(stdout);
                settlementhp=new settlement(&fp1);//qDebug("test2");fflush(stdout);
                manager->add_settlement(settlementhp);//qDebug("test3");fflush(stdout);
            }
        }
        fp1.close();

        /*Settlementpointer zu den entsprechenden chunks hinzufügen*/

        settlementhp=manager->give_settlements();
        while(settlementhp){
            i=settlementhp->give_xcord();
            j=settlementhp->give_ycord();
            (*(*(map+i)+j))->set_settlement(settlementhp);
            settlementhp=settlementhp->give_next();
        }

        /*auslesen der buildings.txt*/

        if(!fp2.open(QFile::ReadOnly | QFile::Text)){
            qDebug("cant open file");
            qDebug() << path;
        }
        else{
            qDebug("open succesfull");
            while(!fp2.atEnd()){
                hp=building_list;
                building_list=new building_props(&fp2);
                building_list->set_next(hp);
            }
            buildcount=0;
            hp=building_list;
            while(hp){
                buildcount++;
                hp->set_IN(buildcount);
                hp=hp->give_next();
            }
        }
        fp2.close();

        /*Mapdialog starten und übergabe der werte*/

        manager->set_buildcount(buildcount);
        manager->set_mapsize(mapsize);
        manager->set_winsize(20);
        manager->set_stepsize(2);
        manager->set_map(map);
        manager->set_savedir(path);
        manager->set_building_props(building_list);
        mapDiag=new mapdiag(this,manager);
        mapDiag->setModal(true);
        mapDiag->exec();

        /*Saving map into file after closing the gamedialog*/

        if(!fpsave.open(QFile::WriteOnly | QFile::Text)){
            qDebug("cant open mapfile to save");
            qDebug() << mappath;
        }
        else{
            qDebug("open mapfile for saving succesfull");
            QTextStream saveout(&fpsave);
            saveout << mapsize << endl;
            for(i=0;i<mapsize;i++){
                for(j=0;j<mapsize;j++){
                    (*(*(map+i)+j))->save(&saveout);
                    delete (*(*(map+i)+j));
                }
            }
            saveout.flush();

        }
        fpsave.close();

        while(*(map+i)){
            delete *(map+i);
        }
        delete map;
        map=NULL;

        /*Saving settlments into file after closing the gamedialog*/

        if(!fpsavesett.open(QFile::WriteOnly | QFile::Text)){
            qDebug("cant open settlementfile to save!");
            qDebug() << settlpath;
        }
        else{
            qDebug("opened settlementfile for saving succesfully!");
            QTextStream settlsaveout(&fpsavesett);
            //settlement *settlmenthp;
            settlementhp2=manager->give_settlements();
            while(settlementhp2){
                settlementhp=settlementhp2;
                settlementhp2->save(&settlsaveout,buildcount);
                settlementhp2=settlementhp2->give_next();
                delete settlementhp;
            }
            settlsaveout.flush();

        }
        fpsavesett.close();
    }
}

cont2::cont2(QWidget *parent) :
    QWidget(parent)
{
    map=NULL;
    //settlments=new settlement();
    QLabel *label=new QLabel("Bitte Namen der Karte eingeben, die geladen werden soll!");
    QLabel *label1=new QLabel();
    QLabel *label2=new QLabel();
    QWidget *Editbutton_win=new QWidget;
    QPushButton *button=new QPushButton("Bestätigen");
    QVBoxLayout *vblay=new QVBoxLayout;
    QHBoxLayout *hblay=new QHBoxLayout;
    QLineEdit *line_edit=new QLineEdit;

    hblay->addWidget(line_edit);
    hblay->addWidget(button);
        hblay->setMargin(0);

    vblay->addStretch();
    vblay->addWidget(label);
    vblay->addWidget(Editbutton_win);
    vblay->addWidget(label1);
    vblay->addWidget(label2);
    vblay->addStretch();


    Editbutton_win->setLayout(hblay);

    this->set_line_edit(line_edit);
    this->setLayout(vblay);
    QObject::connect(button,SIGNAL(clicked()),this,SLOT(load()));
}
