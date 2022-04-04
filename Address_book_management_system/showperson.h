#ifndef SHOWPERSON_H
#define SHOWPERSON_H

#include <QWidget>
#include "structural_body.h"
#include <QDebug>
#include <QMessageBox>
#include <QStandardItemModel>
#include <QTableView>

namespace Ui {
class showperson;
}

class showperson : public QWidget
{
    Q_OBJECT

public:
    explicit showperson(QWidget *parent = nullptr, Addressbooks *abs=nullptr);
    ~showperson();

private:
    Ui::showperson *ui;
    struct Addressbooks *abspt;
};

#endif // SHOWPERSON_H
