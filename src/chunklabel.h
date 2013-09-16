#ifndef CHUNKLABEL_H
#define CHUNKLABEL_H

#include "chunk.h"
#include "chunkcontent.h"

class chunklabel : public QLabel
{
    Q_OBJECT
private:
    int x;
    int y;
    int type;
    chunk *chunk_p;

public:
    explicit chunklabel(QWidget *parent = 0,chunk *chunk_p=NULL,chunkcontent *chunkcon=NULL, char = 'e',int x=0,int y=0);
    void set_type(char);
    void refresh_tooltip(int i=0);

signals:
    void clicked(chunk*/*,QLabel**/);
    
public slots:
    //void slotclicked();

protected:
    void mousePressEvent(QMouseEvent *ev);

};

#endif // CHUNKLABEL_H
