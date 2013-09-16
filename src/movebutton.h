#ifndef MOVEBUTTON_H
#define MOVEBUTTON_H

#include <QWidget>
#include <QLabel>
#include <QObject>
#include <QDebug>

class movebutton : public QLabel
{
    Q_OBJECT
private:
    int move_type;

public:
    explicit movebutton(QWidget *parent = 0,int type=1);
    
signals:
    void clicked(int i);

public slots:
    void slotclicked(int i);

protected:
    void mousePressEvent(QMouseEvent *ev);

};

#endif // MOVEBUTTON_H
