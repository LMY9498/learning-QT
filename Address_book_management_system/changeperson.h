#ifndef CHANGEPERSON_H
#define CHANGEPERSON_H

#include <QWidget>
#include "structural_body.h"
#include <QDebug>
#include <QMessageBox>

namespace Ui {
class changeperson;
}

class changeperson : public QWidget
{
    Q_OBJECT

public:
    explicit changeperson(QWidget *parent = nullptr, Addressbooks *abs=nullptr);
    ~changeperson();

private slots:
    int isExist(QString);
    void on_seek_clicked();

    void on_change_clicked();

private:
    Ui::changeperson *ui;
    struct Addressbooks *abspt;
    int ret;
};

#endif // CHANGEPERSON_H
