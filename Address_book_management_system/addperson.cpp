#include "addperson.h"
#include "ui_addperson.h"

addperson::addperson(QWidget *parent,Addressbooks *abs) :
    QWidget(parent),
    ui(new Ui::addperson)
{
    ui->setupUi(this);
    setWindowTitle("addperson");
    abspt=abs;
}

addperson::~addperson()
{
    delete ui;
}

void addperson::on_add_clicked()
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
                                abspt->personArray[abspt->m_Size].m_Name=ui->name->text();
                                //性别
                                abspt->personArray[abspt->m_Size].m_Sex=ui->sex->text();
                                //年龄
                                abspt->personArray[abspt->m_Size].m_Age=ui->age->text();
                                //电话
                                abspt->personArray[abspt->m_Size].m_Phone=ui->phone->text();
                                //住址
                                abspt->personArray[abspt->m_Size].m_Address=ui->address->text();
                                abspt->m_Size++;
                                this->close();
                            }
                        }
                    }
                }
            }
        }
    }
    QMessageBox::information(this,"Information","addperson success !",QMessageBox::Yes);
}
