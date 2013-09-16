#ifndef MENU_H
#define MENU_H

#include <QWidget>
#include <QSignalMapper>

class menu : public QWidget
{
    Q_OBJECT
public:
    explicit menu(QWidget *parent = 0);
    explicit menu(QWidget**,QSignalMapper*);
    
signals:
    
public slots:
    
};

#endif // MENU_H
