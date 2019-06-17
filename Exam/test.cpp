#include "test.h"

#include <vector>
#include "sorts.h"

void TestMain::insertSortTest()
{
    {
        std::vector<int> v = {5,3,-1,2,0};
        insertSort(v);
        std::vector<int> exp = {-1,0,2,3,5};
        QCOMPARE(v,exp);
    }

    {

    }
}
