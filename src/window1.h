#ifndef WINDOW1_H
#define WINDOW1_H
#include <QHBoxLayout>
#include <QSignalMapper>
#include <QWidget>
#include <QSize>

class window1 : public QWidget
{
    Q_OBJECT
public:
    explicit window1(QWidget *parent = 0);
    
signals:
    
private slots:
    void change_cont(QWidget*);
    
private:
    QWidget **content;
    int contentsize;
    QWidget *menu_p;
    QSignalMapper *signalmapper;
    void set_window(QWidget *,int i);
    void set_menu(QWidget*);
    void add_content(QWidget*,int size=10);
    QWidget *give_window(int i);
    void cont_build(int size=10);
    void set_sizepolicy(int s=4);
    void add_content_to_layout(QHBoxLayout*,int flag=0);

};

#endif // WINDOW1_H
