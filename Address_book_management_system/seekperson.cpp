#include "seekperson.h"
#include "ui_seekperson.h"

seekperson::seekperson(QWidget *parent,Addressbooks *abs) :
    QWidget(parent),
    ui(new Ui::seekperson)
{
    ui->setupUi(this);
    setWindowTitle("seekperson");
    abspt=abs;

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

}

seekperson::~seekperson()
{
    delete ui;
}

void seekperson::on_seek_clicked()
{
    QString seekname=ui->lineEdit->text();
    int ret=isExist(seekname);
    if(ret==-1)
    {
        ui->lineEdit->clear();
        QString msg=seekname+" did not exist";
        QMessageBox::information(this,"Information",msg,QMessageBox::Yes);
    }
    else
    {
        /*setItem设置条目栏中的一个格子的信息*/
        model->setItem(0, 0, new QStandardItem(abspt->personArray[ret].m_Name) );
        model->setItem(0, 1, new QStandardItem(abspt->personArray[ret].m_Sex ) );
        model->setItem(0, 2, new QStandardItem(abspt->personArray[ret].m_Age) );
        model->setItem(0, 3, new QStandardItem(abspt->personArray[ret].m_Phone ) );
        model->setItem(0, 4, new QStandardItem(abspt->personArray[ret].m_Address ) );
    }

}
//检测联系人是否存在，如果存在返回联系人所在数组中的具体位置，不存在返回-1
int seekperson::isExist(QString name)
{
   for(int i=0;i<abspt->m_Size;i++)
   {
       //找到用户输入的姓名了
       if(abspt->personArray[i].m_Name==name)
       {
           return i;//找到了，返回这个人在数组中的下标
       }
   }
   return -1;//没有找到，返回-1
}
