#include "contaddbuild.h"
#include <QLabel>
#include <QGridLayout>
#include <QDir>
#include <QPushButton>
#include <QObject>

void contaddbuild::add_build(){
    QString dir1="Content";
    QString dir2="Buildings";

        QDir dir;
        QString path=dir.currentPath();

        if(!QDir(dir1).exists()){
            QDir().mkdir(dir1);
        }
        path.append("/" + dir1 + "/");
        if(!QDir(dir1 + "/" + dir2).exists()){
            QDir(dir1).mkdir(dir2);
        }
        path.append(dir2 + "/");
        path.append("builds.txt");
        QFile file(path);
        if(!file.open(QFile::Append | QFile::Text)){
            qDebug("cant open!");
        }
        else{
            QTextStream fout(&file);
            building_props *build=new building_props(nameinput->text(),
                                            WLVL_CB->currentIndex(),
                                            NLVL_CB->currentIndex(),
                                            GLVL_CB->currentIndex(),
                                            VLVL_CB->currentIndex(),
                                            OLVL_CB->currentIndex(),
                                            KLVL_CB->currentIndex(),
                                            ULVL_CB->currentIndex(),
                                            WlLVL_CB->currentIndex(),
                                            BLVL_CB->currentIndex(),
                                            bk_LE->text(),
                                            uk_LE->text()
                                            );
            build->save(&fout);
            qDebug("Building added!");
            }
        file.close();
}

contaddbuild::contaddbuild(QWidget *parent) :
    QWidget(parent)
{


    QGridLayout *gridlay=new QGridLayout;
    QPushButton *button=new QPushButton("Abschicken");
    QLabel *label1=new QLabel("Name des Gebäudes festlegen");
    nameinput=new QLineEdit;

    QLabel *label2=new QLabel("Wasserleveleinfluss festlegen (in %)");
    WLVL_CB=new QComboBox;
        WLVL_CB->addItem("-30");
        WLVL_CB->addItem("-20");
        WLVL_CB->addItem("-10");
        WLVL_CB->addItem("-5");
        WLVL_CB->addItem("0");
        WLVL_CB->addItem("+5");
        WLVL_CB->addItem("+10");
        WLVL_CB->addItem("+20");
        WLVL_CB->addItem("+30");
    QLabel *label3=new QLabel("Nahrungsleveleinfluss festlegen (in %)");
    NLVL_CB=new QComboBox;
        NLVL_CB->addItem("-30");
        NLVL_CB->addItem("-20");
        NLVL_CB->addItem("-10");
        NLVL_CB->addItem("-5");
        NLVL_CB->addItem("0");
        NLVL_CB->addItem("+5");
        NLVL_CB->addItem("+10");
        NLVL_CB->addItem("+20");
        NLVL_CB->addItem("+30");
    QLabel *label4=new QLabel("Gesundheitsleveleinfluss festlegen (in %)");
    GLVL_CB=new QComboBox;
        GLVL_CB->addItem("-30");
        GLVL_CB->addItem("-20");
        GLVL_CB->addItem("-10");
        GLVL_CB->addItem("-5");
        GLVL_CB->addItem("0");
        GLVL_CB->addItem("+5");
        GLVL_CB->addItem("+10");
        GLVL_CB->addItem("+20");
        GLVL_CB->addItem("+30");
    QLabel *label5=new QLabel("Verschmutzungsleveleinfluss festlegen (in %)");
    VLVL_CB=new QComboBox;
        VLVL_CB->addItem("-30");
        VLVL_CB->addItem("-20");
        VLVL_CB->addItem("-10");
        VLVL_CB->addItem("-5");
        VLVL_CB->addItem("0");
        VLVL_CB->addItem("+5");
        VLVL_CB->addItem("+10");
        VLVL_CB->addItem("+20");
        VLVL_CB->addItem("+30");
    QLabel *label6=new QLabel("Ordnungsleveleinfluss festlegen (in %)");
    OLVL_CB=new QComboBox;
        OLVL_CB->addItem("-30");
        OLVL_CB->addItem("-20");
        OLVL_CB->addItem("-10");
        OLVL_CB->addItem("-5");
        OLVL_CB->addItem("0");
        OLVL_CB->addItem("+5");
        OLVL_CB->addItem("+10");
        OLVL_CB->addItem("+20");
        OLVL_CB->addItem("+30");
    QLabel *label7=new QLabel("Kulturleveleinfluss festlegen (in %)");
    KLVL_CB=new QComboBox;
        KLVL_CB->addItem("-30");
        KLVL_CB->addItem("-20");
        KLVL_CB->addItem("-10");
        KLVL_CB->addItem("-5");
        KLVL_CB->addItem("0");
        KLVL_CB->addItem("+5");
        KLVL_CB->addItem("+10");
        KLVL_CB->addItem("+20");
        KLVL_CB->addItem("+30");
    QLabel *label8=new QLabel("Unterhaltungsleveleinfluss festlegen (in %)");
    ULVL_CB=new QComboBox;
        ULVL_CB->addItem("-30");
        ULVL_CB->addItem("-20");
        ULVL_CB->addItem("-10");
        ULVL_CB->addItem("-5");
        ULVL_CB->addItem("0");
        ULVL_CB->addItem("+5");
        ULVL_CB->addItem("+10");
        ULVL_CB->addItem("+20");
        ULVL_CB->addItem("+30");
    QLabel *label9=new QLabel("Wohlstandsleveleinfluss festlegen (in %)");
    WlLVL_CB=new QComboBox;
        WlLVL_CB->addItem("-30");
        WlLVL_CB->addItem("-20");
        WlLVL_CB->addItem("-10");
        WlLVL_CB->addItem("-5");
        WlLVL_CB->addItem("0");
        WlLVL_CB->addItem("+5");
        WlLVL_CB->addItem("+10");
        WlLVL_CB->addItem("+20");
        WlLVL_CB->addItem("+30");
    QLabel *label10=new QLabel("Bildungsleveleinfluss festlegen (in %)");
    BLVL_CB=new QComboBox;
        BLVL_CB->addItem("-30");
        BLVL_CB->addItem("-20");
        BLVL_CB->addItem("-10");
        BLVL_CB->addItem("-5");
        BLVL_CB->addItem("0");
        BLVL_CB->addItem("+5");
        BLVL_CB->addItem("+10");
        BLVL_CB->addItem("+20");
        BLVL_CB->addItem("+30");
    QLabel *label11=new QLabel("Baukosten festlegen");
    bk_LE=new QLineEdit;
    QLabel *label12=new QLabel("Unterhaltskosten festlegen");
    uk_LE=new QLineEdit;

    gridlay->addWidget(label1,0,0);
    gridlay->addWidget(label2,1,0);
    gridlay->addWidget(label3,2,0);
    gridlay->addWidget(label4,3,0);
    gridlay->addWidget(label5,4,0);
    gridlay->addWidget(label6,5,0);
    gridlay->addWidget(label7,6,0);
    gridlay->addWidget(label8,7,0);
    gridlay->addWidget(label9,8,0);
    gridlay->addWidget(label10,9,0);
    gridlay->addWidget(label11,10,0);
    gridlay->addWidget(label12,11,0);
    gridlay->addWidget(nameinput,0,1);
    gridlay->addWidget(WLVL_CB,1,1);
    gridlay->addWidget(NLVL_CB,2,1);
    gridlay->addWidget(GLVL_CB,3,1);
    gridlay->addWidget(VLVL_CB,4,1);
    gridlay->addWidget(OLVL_CB,5,1);
    gridlay->addWidget(KLVL_CB,6,1);
    gridlay->addWidget(ULVL_CB,7,1);
    gridlay->addWidget(WlLVL_CB,8,1);
    gridlay->addWidget(BLVL_CB,9,1);
    gridlay->addWidget(bk_LE,10,1);
    gridlay->addWidget(uk_LE,11,1);
    gridlay->addWidget(button,12,1);

    QObject::connect(button,SIGNAL(clicked()),this,SLOT(add_build()));

    this->setLayout(gridlay);
}
