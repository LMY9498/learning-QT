#include "showperson.h"
#include "ui_showperson.h"

showperson::showperson(QWidget *parent,Addressbooks *abs) :
    QWidget(parent),
    ui(new Ui::showperson)
{
    ui->setupUi(this);
    setWindowTitle("showperson");
    abspt=abs;
    QStandardItemModel *model = new QStandardItemModel();   //创建一个标准的条目模型
    ui->tableView->setModel(model);//将tableview设置成model这个标准条目模型的模板, model设置的内容都将显示在tableview上
    model->setHorizontalHeaderItem(0, new QStandardItem("姓名") );
    model->setHorizontalHeaderItem(1, new QStandardItem("性别"));
    model->setHorizontalHeaderItem(2, new QStandardItem("年龄"));
    model->setHorizontalHeaderItem(3, new QStandardItem("电话"));
    model->setHorizontalHeaderItem(4, new QStandardItem("住址"));
    ui->tableView->setColumnWidth(0, 100);    //设置列的宽度
    ui->tableView->setColumnWidth(1, 50);
    ui->tableView->setColumnWidth(2, 50);
    ui->tableView->setColumnWidth(3, 150);
    ui->tableView->setColumnWidth(4, 400);

    /*setItem设置条目栏中的一个格子的信息*/
    model->setItem(1, 4, new QStandardItem("hello world" ) );

    model->setRowCount(abspt->m_Size);
    for(int i=0;i<abspt->m_Size;i++)
    {
        model->setItem(i, 0, new QStandardItem(abspt->personArray[i].m_Name) );
        model->setItem(i, 1, new QStandardItem(abspt->personArray[i].m_Sex ) );
        model->setItem(i, 2, new QStandardItem(abspt->personArray[i].m_Age) );
        model->setItem(i, 3, new QStandardItem(abspt->personArray[i].m_Phone ) );
        model->setItem(i, 4, new QStandardItem(abspt->personArray[i].m_Address ) );
    }

}

showperson::~showperson()
{
    delete ui;
}
