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
