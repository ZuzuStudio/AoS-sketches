#include "citydialog.h"
#include <QFile>

CityDialog::CityDialog(QString name, QWidget *parent) :
    QDialog(parent)
{
    setWindowTitle(name);
    QFile styleSheet(":/files/CityDialogStyle.css");

    if (!styleSheet.open(QIODevice::ReadOnly)) {
        qWarning("Unable to open :/files/CityDialogStyle.css");
        return;
    }

    setStyleSheet(styleSheet.readAll());
}
