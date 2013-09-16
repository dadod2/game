#ifndef CONTADDBUILD_H
#define CONTADDBUILD_H

#include <QWidget>
#include <QLineEdit>
#include <QTextStream>
#include <QComboBox>
#include <QLineEdit>
#include "building_props.h"

class contaddbuild : public QWidget
{
    Q_OBJECT
private:
    QLineEdit *nameinput;
    QComboBox *WLVL_CB;
    QComboBox *NLVL_CB;
    QComboBox *GLVL_CB;
    QComboBox *VLVL_CB;
    QComboBox *OLVL_CB;
    QComboBox *KLVL_CB;
    QComboBox *ULVL_CB;
    QComboBox *WlLVL_CB;
    QComboBox *BLVL_CB;
    QLineEdit *bk_LE;
    QLineEdit *uk_LE;


public:
    explicit contaddbuild(QWidget *parent = 0);
    
signals:
    
public slots:
    void add_build();
};

#endif // CONTADDBUILD_H
