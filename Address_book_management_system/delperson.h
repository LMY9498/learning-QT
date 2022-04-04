#ifndef DELPERSON_H
#define DELPERSON_H

#include <QWidget>
#include "structural_body.h"
#include <QDebug>
#include <QMessageBox>

namespace Ui {
class delperson;
}

class delperson : public QWidget
{
    Q_OBJECT

public:
    explicit delperson(QWidget *parent = nullptr, Addressbooks *abs=nullptr);
    ~delperson();

private slots:
    void on_delperson_2_clicked();
    int isExist(QString);

private:
    Ui::delperson *ui;
    struct Addressbooks *abspt;
};

#endif // DELPERSON_H
