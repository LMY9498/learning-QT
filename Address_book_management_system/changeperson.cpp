#include "changeperson.h"
#include "ui_changeperson.h"

changeperson::changeperson(QWidget *parent,Addressbooks *abs) :
    QWidget(parent),
    ui(new Ui::changeperson)
{
    ui->setupUi(this);
    setWindowTitle("changeperson");
    abspt=abs;
    ui->change->setDisabled(true);
}

changeperson::~changeperson()
{
    delete ui;
}
//检测联系人是否存在，如果存在返回联系人所在数组中的具体位置，不存在返回-1
int changeperson::isExist(QString name)
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

void changeperson::on_seek_clicked()
{
    QString changename=ui->lineEdit->text();
    ret=isExist(changename);
    if(ret==-1)
    {
        ui->lineEdit->clear();
        QString msg=changename+" did not exist";
        QMessageBox::information(this,"Information",msg,QMessageBox::Yes);
    }
    else
    {
        ui->name->setText(abspt->personArray[ret].m_Name);
        ui->age->setText(abspt->personArray[ret].m_Age);
        ui->sex->setText(abspt->personArray[ret].m_Sex);
        ui->phone->setText(abspt->personArray[ret].m_Phone);
        ui->address->setText(abspt->personArray[ret].m_Address);
        QString msg=changename+" exist,please change the information";
        QMessageBox::information(this,"Information",msg,QMessageBox::Yes);
        ui->change->setDisabled(false);
    }
}

void changeperson::on_change_clicked()
{
    if(ui->name->text().isEmpty())
    {
        QMessageBox::information(this,"Information","Name is Empty!Please Enter Name",QMessageBox::Yes);
    }
    else
    {
        if(ui->sex->text().isEmpty())
        {
            QMessageBox::information(this,"Information","Sex is Empty!Please Enter Sex",QMessageBox::Yes);
        }
        else
        {
            if(!(ui->sex->text()=="man"||ui->sex->text()=="woman"))
            {
                 QMessageBox::information(this,"Information","sex:please enter'man' or 'woman'",QMessageBox::Yes);
                 ui->sex->text().clear();
            }
            else
            {
                if(ui->age->text().isEmpty())
                {
                    QMessageBox::information(this,"Information","Age is Empty!Please Enter Age",QMessageBox::Yes);
                }
                else
                {
                    if(ui->age->text().toInt()<0)
                    {
                        QMessageBox::information(this,"Information","Age should > 0",QMessageBox::Yes);
                        ui->age->text().clear();
                    }
                    else
                    {
                        if(ui->phone->text().isEmpty())
                        {
                            QMessageBox::information(this,"Information","Phone is Empty!Please Enter Phone",QMessageBox::Yes);
                        }
                        else
                        {
                            if(ui->address->text().isEmpty())
                            {
                                QMessageBox::information(this,"Information","Address is Empty!Please Enter Address",QMessageBox::Yes);
                            }
                            else
                            {
                                //姓名
                                abspt->personArray[ret].m_Name=ui->name->text();
                                //性别
                                abspt->personArray[ret].m_Sex=ui->sex->text();
                                //年龄
                                abspt->personArray[ret].m_Age=ui->age->text();
                                //电话
                                abspt->personArray[ret].m_Phone=ui->phone->text();
                                //住址
                                abspt->personArray[ret].m_Address=ui->address->text();

                            }
                        }
                    }
                }
            }
        }
    }
    this->close();
    QMessageBox::information(this,"Information","changeperson success !",QMessageBox::Yes);
}
