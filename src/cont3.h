#ifndef cont3_H
#define cont3_H

#include <QWidget>
#include <QLineEdit>
#include <QComboBox>

class cont3 : public QWidget
{
    Q_OBJECT
private:
    QLineEdit *line_edit;
    QComboBox *combo_box;
    QComboBox *type1;
    QComboBox *type2;
    QComboBox *type3;
    QComboBox *type4;
    void set_line_edit(QLineEdit*);
    void set_combo_box(QComboBox*);

public:
    explicit cont3(QWidget *parent = 0);
    
signals:
    
private slots:
    void create();

};

#endif // cont3_H
