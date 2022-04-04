#ifndef ADDPERSON_H
#define ADDPERSON_H

#include <QWidget>
#include "structural_body.h"
#include <QDebug>
#include <QMessageBox>

namespace Ui {
class addperson;
}

class addperson : public QWidget
{
    Q_OBJECT

public:
    explicit addperson(QWidget *parent = nullptr, Addressbooks *abs=nullptr);
    ~addperson();

private slots:
    void on_add_clicked();

private:
    Ui::addperson *ui;
    struct Addressbooks *abspt;
};

#endif // ADDPERSON_H
