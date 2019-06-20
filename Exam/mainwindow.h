#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <postaladdress.h>
#include <slcircularlist.h>
#include <bplustree.h>
#include <avltree.h>
#include <hashtable.h>
#include <sorts.h>

#include <functional>

#include <QMainWindow>
#include <QListWidget>

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

    SLCircularList<std::string> listObj;
    //BPlusTree<std::string, PostalAddress> treeObj(3);
    HashTable hashObj;
    std::vector<std::string> sortObj;


    void updateWidget(QListWidget *widget, std::vector<std::string> values);

public slots:
    void addListItem();
    void addTreeItem();
    void addHashItem();
    void addSortItem();
private slots:
    void on_AddButtonList_clicked();
    void on_DeleteButtonList_clicked();
};

#endif // MAINWINDOW_H
