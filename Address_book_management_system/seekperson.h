#ifndef SEEKPERSON_H
#define SEEKPERSON_H

#include <QWidget>
#include "structural_body.h"
#include <QDebug>
#include <QMessageBox>
#include <QStandardItemModel>
#include <QTableView>

namespace Ui {
class seekperson;
}

class seekperson : public QWidget
{
    Q_OBJECT

public:
    explicit seekperson(QWidget *parent = nullptr, Addressbooks *abs=nullptr);
    ~seekperson();

private slots:
    void on_seek_clicked();
    int isExist(QString);

private:
    Ui::seekperson *ui;
    struct Addressbooks *abspt;
    QStandardItemModel *model = new QStandardItemModel();   //创建一个标准的条目模型
};

#endif // SEEKPERSON_H
