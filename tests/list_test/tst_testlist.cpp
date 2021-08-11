#include <QtTest>
#include <QCoreApplication>

#include "../../src/list.hpp"

using namespace stt;

class TestList : public QObject
{
    Q_OBJECT
    List<int> list;

    QVector<int> icase;

public:
    TestList();
    ~TestList();

private slots:
    void initTestCase();
    void pushTestCase();
    void insertTestCase();
    void flipTestCase();
    void popTestCase();
    void cleanupTestCase();
};

TestList::TestList()
{

}

TestList::~TestList() {}

void TestList::initTestCase()
{
    icase = {9, 10, 13, 14, 15, 17, 18};
}

void TestList::pushTestCase()
{
    foreach(auto i, icase)
        list.push_back(i);

    foreach(auto i, icase)
        list.push_front(i);
}


void TestList::insertTestCase()
{
    List<int> list_2(1, 2, 3, 4);
    list_2.insert(1, -10);
    QCOMPARE(list_2[0], 1);
    QCOMPARE(list_2[1], -10);
    QCOMPARE(list_2[2], 2);
    QCOMPARE(list_2[3], 3);
    QCOMPARE(list_2[4], 4);
}

void TestList::flipTestCase()
{
    List<int> list_2 = list;
    list_2.flip();
    for(int i = icase.size() - 1; i >= 0; i--)
        QCOMPARE(list_2.pop_front(), icase[i]);
}

void TestList::popTestCase()
{
    for(int i = 0; i < icase.size(); i++)
        QCOMPARE(list.pop_front(), icase[icase.size() - i - 1]);

    for(int i = icase.size() - 1; i >= 0; i--)
        QCOMPARE(list.pop_back(), icase[i]);
}

void TestList::cleanupTestCase()
{
    list.clear();
    QCOMPARE(list.empty(), true);
}

QTEST_APPLESS_MAIN(TestList)

#include "tst_testlist.moc"
