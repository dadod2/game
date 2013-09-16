/********************************************************************************
** Form generated from reading UI file 'mapdiag.ui'
**
** Created by: Qt User Interface Compiler version 5.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAPDIAG_H
#define UI_MAPDIAG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_mapdiag
{
public:

    void setupUi(QDialog *mapdiag)
    {
        if (mapdiag->objectName().isEmpty())
            mapdiag->setObjectName(QStringLiteral("mapdiag"));
        mapdiag->resize(400, 300);

        retranslateUi(mapdiag);

        QMetaObject::connectSlotsByName(mapdiag);
    } // setupUi

    void retranslateUi(QDialog *mapdiag)
    {
        mapdiag->setWindowTitle(QApplication::translate("mapdiag", "Dialog", 0));
    } // retranslateUi

};

namespace Ui {
    class mapdiag: public Ui_mapdiag {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAPDIAG_H
