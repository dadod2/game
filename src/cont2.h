#ifndef cont2_H
#define cont2_H

#include "mapdiag.h"
#include "chunk.h"
#include <QWidget>
#include <QLineEdit>
#include <QDialog>

class cont2 : public QWidget
{
    Q_OBJECT

private:
    QLineEdit *line_edit;
    chunk ***map;
    QDialog *mapdialog;
    mapdiag *mapDiag;
    //settlement *settlments;
    int mapsize;
    int buildcount;

public:
    explicit cont2(QWidget *parent = 0);
    void set_line_edit(QLineEdit*);
    void set_map(chunk***);
    chunk ***get_map();

signals:
    
private slots:
    void load();
    
};

#endif // cont2_H
