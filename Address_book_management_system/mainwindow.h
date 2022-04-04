#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include "structural_body.h"
#include <QMessageBox>
#include "addperson.h"
#include "showperson.h"
#include "delperson.h"
#include "seekperson.h"
#include "changeperson.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_add_clicked();
    void on_show_clicked();
    void on_remove_clicked();
    void on_seek_clicked();
    void on_change_clicked();
    void on_clear_clicked();


private:
    Ui::MainWindow *ui;
    struct Addressbooks abs;
    addperson *addui;
    showperson *showui;
    delperson *delui;
    seekperson *seekui;
    changeperson *changeui;
};

#endif // MAINWINDOW_H
