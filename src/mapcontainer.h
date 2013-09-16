#ifndef MAPCONTAINER_H
#define MAPCONTAINER_H

#include "chunk.h"
#include "chunkcontent.h"

class mapcontainer : public QWidget
{
    Q_OBJECT    
private:
    QGridLayout *layout;
    chunk ***map;
    chunkcontent *chunkcont;
    int mapsize;
    int winsize;
    int step;
    int x;
    int y;

public:
    explicit mapcontainer(QWidget *parent =0,management *manager_=NULL,QGridLayout *gridlay=NULL,chunkcontent *chunkcont_=NULL,int x_=0,int y_=0);

signals:
    
public slots:
    void moved(int);
    
};

#endif // MAPCONTAINER_H
