#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <postaladdress.h>
#include <slcircularlist.h>
#include <bplustree.h>
#include <avltree.h>
#include <hashtable.h>
#include <sorts.h>

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
