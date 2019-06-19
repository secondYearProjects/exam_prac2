#pragma once

#include <sorts.h>

#include <QtTest/QtTest>

class TestMain: public QObject
{
    Q_OBJECT
private slots:
    void insertSortTest();
    void quickSortTest();
    void heapSortTest();
};

