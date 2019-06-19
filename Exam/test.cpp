#include "test.h"

#include <vector>
#include <iostream>

#include "sorts.h"
#include "postaladdress.h"
#include "slcircularlist.h"
#include "bplustree.h"
#include "avltree.h"


bool isSorted(std::vector<PostalAddress> &v){
    for (size_t i=1;i<v.size();i++){
        if(v[i-1].Apartment > v[i].Apartment)
            return false;
    }
    return true;
}

void TestMain::listTest()
{
    std::vector<int> v = {5,3,0,-1,2,0};
    SLCircularList<int> lst;
    for (auto el: v)
        lst.add(el);

    //SLLIterator<Node<int>> ::iterator a(lst.begin());
    //QCOMPARE(5, *a);
}

void TestMain::treeTest()
{

}

void TestMain::insertSortTest()
{
    {
        std::vector<int> v = {5,3,0,-1,2,0};
        insertSort<int>(v,[](int&a,int&b){return a<b;});
        std::vector<int> exp = {-1,0,0,2,3,5};
        QCOMPARE(v,exp);
    }

    {
        std::vector<PostalAddress> v;
        for (int i=0;i<10;i++){
            auto el = AdressGenerator::getAddress(RandomAdressProperties());
        }
        insertSort<PostalAddress>(v,[](PostalAddress&a,PostalAddress&b){return a.Apartment<b.Apartment;});
        QCOMPARE(isSorted(v), true);
    }
}

void TestMain::quickSortTest()
{
    {
        std::vector<int> v2 = {5,3,0,-1,2,0};
        quickSort(v2);
        std::vector<int> exp2 = {-1,0,0,2,3,5};
        QCOMPARE(v2,exp2);
    }

    {
        std::vector<PostalAddress> v;
        for (int i=0;i<10;i++){
            auto el = AdressGenerator::getAddress(RandomAdressProperties());
        }
        quickSort<PostalAddress>(v,[](PostalAddress&a,PostalAddress&b){return a.Apartment<b.Apartment;});
        QCOMPARE(isSorted(v), true);
    }
}

void TestMain::heapSortTest(){
    {
        std::vector<int> v2 = {5,3,0,-1,2,0};
        heapSort(v2);
        std::vector<int> exp2 = {-1,0,0,2,3,5};
        QCOMPARE(v2,exp2);
    }

    {
        std::vector<PostalAddress> v;
        for (int i=0;i<10;i++){
            auto el = AdressGenerator::getAddress(RandomAdressProperties());
        }
        heapSort<PostalAddress>(v,[](PostalAddress&a,PostalAddress&b){return a.Apartment<b.Apartment;});
        QCOMPARE(isSorted(v), true);
    }
}
