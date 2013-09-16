#ifndef CONTDELETE_H
#define CONTDELETE_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QDir>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QObject>

class contdelete : public QWidget
{
    Q_OBJECT
private:
    QLineEdit *line_edit;

public:
    explicit contdelete(QWidget *parent = 0);
    
signals:
    
public slots:
    void delete_map();
};

#endif // CONTDELETE_H
