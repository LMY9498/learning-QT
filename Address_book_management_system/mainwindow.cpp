#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("AddressBook Management System");
    abs.m_Size=0;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_add_clicked()
{

    qDebug()<<"add";
    //判断通讯录是否已满，如果满了就不再添加
    if(abs.m_Size==MAX)
    {
        QMessageBox::information(this,"Information","addressbook is full,can't be added!",QMessageBox::Yes);
    }
    else
    {
       addui=new addperson(nullptr,&abs);
       addui->show();
    }

}

void MainWindow::on_show_clicked()
{
    qDebug()<<"show";
    //判断通讯录为空
    if(abs.m_Size==0)
    {
        QMessageBox::information(this,"Information","addressbook is empty!",QMessageBox::Yes);
    }
    else
    {
       showui=new showperson(nullptr,&abs);
       showui->show();
    }
}

void MainWindow::on_remove_clicked()
{
     qDebug()<<"remove";
     //判断通讯录为空
     if(abs.m_Size==0)
     {
         QMessageBox::information(this,"Information","addressbook is empty!",QMessageBox::Yes);
     }
     else
     {
        delui=new delperson(nullptr,&abs);
        delui->show();
     }
}

void MainWindow::on_seek_clicked()
{
     qDebug()<<"seek";
     seekui=new seekperson(nullptr,&abs);
     seekui->show();
}

void MainWindow::on_change_clicked()
{
     qDebug()<<"change";
     changeui=new changeperson(nullptr,&abs);
     changeui->show();
}

void MainWindow::on_clear_clicked()
{
     qDebug()<<"clear";
     abs.m_Size=0;
     QMessageBox::information(this,"Information","empty addressbook sucess !",QMessageBox::Yes);
}
