#include "mainwindow.h"
#include <QApplication>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <fstream>
#include <QTest>
#include <QtDebug>
#include <QString>

#include "test.h"

void printTestLog(){
    std::string line;
    std::ifstream myfile ("testing.log");
    if (myfile.is_open())
    {
      while (! myfile.eof() )
      {
        getline (myfile,line);
        qDebug() << QString::fromStdString(line);
      }
      myfile.close();
    }

    else
        qDebug() << "Unable to open file";

    myfile.close();
}

int main(int argc, char *argv[])
{
    auto testFile = freopen("testing.log", "w", stdout);
    QTest::qExec(new TestMain, argc, argv);
    fclose(testFile);

    printTestLog();

    QApplication a(argc, argv);

    MainWindow w;
    w.show();

    return a.exec();
}
