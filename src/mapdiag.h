#ifndef MAPDIAG_H
#define MAPDIAG_H

#include <QDialog>
#include <QKeyEvent>
#include "chunk.h"
#include "mapcontainer.h"
#include "building_props.h"
#include "management.h"

namespace Ui {
class mapdiag;
}

class mapdiag : public QDialog
{
    Q_OBJECT
    

public:
    explicit mapdiag(QWidget *parent = 0,management *manager_=NULL);
    void set_coords(int,int);
    void set_mapcont(mapcontainer*);
    ~mapdiag();
    
private:
    int x;
    int y;
    int mapsize;
    int buildcount;
    management *manager;
    mapcontainer *mapcont;
    QGridLayout *mapgrid;
    Ui::mapdiag *ui;

private slots:
    void save();
signals:
    void clicked(int i);

protected:
    void keyPressEvent(QKeyEvent *kev);
};

#endif // MAPDIAG_H
