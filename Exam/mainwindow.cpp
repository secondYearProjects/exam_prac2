#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateWidget(QListWidget *widget, std::vector<std::string> values)
{
    widget->clear();
    for (auto el:values){
        widget->addItem(QString::fromStdString(el));
    }
}

void MainWindow::addListItem()
{

}

void MainWindow::addTreeItem()
{

}

void MainWindow::addHashItem()
{

}

void MainWindow::addSortItem()
{

}

void MainWindow::on_AddButtonList_clicked()
{
    listObj.add((ui->inputList->text()).toStdString());
    updateWidget(ui->listWidget,listObj.toVector());
}

void MainWindow::on_DeleteButtonList_clicked()
{
    listObj.del((ui->inputList->text()).toStdString());
    updateWidget(ui->listWidget,listObj.toVector());
}
