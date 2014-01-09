#ifndef CITYDIALOG_H
#define CITYDIALOG_H

#include <QDialog>
#include <QPushButton>
#include <QLayout>

class CityDialog : public QDialog
{
    Q_OBJECT
public:
    explicit CityDialog(QString name, QWidget *parent = 0);

private:


signals:

public slots:

};

#endif // CITYDIALOG_H
