#include "delperson.h"
#include "ui_delperson.h"

delperson::delperson(QWidget *parent,Addressbooks *abs) :
    QWidget(parent),
    ui(new Ui::delperson)
{
    ui->setupUi(this);
    setWindowTitle("delperson");
    abspt=abs;
}

delperson::~delperson()
{
    delete ui;
}

void delperson::on_delperson_2_clicked()
{
    QString delname=ui->lineEdit->text();
    int ret=isExist(delname);
    if(ret==-1)
    {
        ui->lineEdit->clear();
        QString msg=delname+" did not exist";
        QMessageBox::information(this,"Information",msg,QMessageBox::Yes);
    }
    else
    {
       //要删除delname,将delname后的数据前移，且abspt->m_Size-1
        for(int i=ret;i<abspt->m_Size;i++)
       {
            abspt->personArray[i]=abspt->personArray[i+1];
       }
        abspt->m_Size--;
        this->close();
        QString msg=delname+"delete success !";
        QMessageBox::information(this,"Information",msg,QMessageBox::Yes);
    }
    qDebug()<<"delperson";

}
//检测联系人是否存在，如果存在返回联系人所在数组中的具体位置，不存在返回-1
int delperson::isExist(QString name)
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
