#include "mainwindow.h"
#include "window1.h"
#include <QApplication>
#include <QDesktopWidget>
#include <QSize>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QDesktopWidget dw;
    MainWindow *w=new MainWindow;
    int x=dw.width()*0.7;
    int y=dw.height()*0.7;
    QSize *size=new QSize(x,y);
    window1 *win1=new window1();
    w->setFixedSize(*size);
    w->setCentralWidget(win1);
    w->show();
    
    return a.exec();
}
