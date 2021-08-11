#include <QtTest>
#include <QCoreApplication>

#include "../../src/vector.hpp"

using namespace stt;

class TestVector : public QObject
{
    Q_OBJECT
    Vector<int> vector;

    QVector<int> icase;

public:
    TestVector();
    ~TestVector();

private slots:
    void initTestCase();
    void pushTestCase();
    void insertTestCase();
    void flipTestCase();
    void popTestCase();
    void cleanupTestCase();
};

TestVector::TestVector(){}

TestVector::~TestVector() {}

void TestVector::initTestCase()
{
    icase = {9, 10, 13, 14, 15, 17, 18};
}

void TestVector::pushTestCase()
{
    foreach(auto i, icase)
        vector.push_back(i);

    foreach(auto i, icase)
        vector.push_front(i);
}

void TestVector::insertTestCase()
{
    Vector<int> vector_2(1, 2, 3, 4);
    vector_2.insert(1, -10);
    QCOMPARE(vector_2[0], 1);
    QCOMPARE(vector_2[1], -10);
    QCOMPARE(vector_2[2], 2);
    QCOMPARE(vector_2[3], 3);
    QCOMPARE(vector_2[4], 4);
}

void TestVector::flipTestCase()
{
    Vector<int> vector_2 = vector;
    vector_2.flip();
    for(int i = icase.size() - 1; i >= 0; i--)
        QCOMPARE(vector_2.pop_front(), icase[i]);
}

void TestVector::popTestCase()
{
    for(int i = 0; i < icase.size(); i++)
        QCOMPARE(vector.pop_front(), icase[icase.size() - i - 1]);

    for(int i = icase.size() - 1; i >= 0; i--)
        QCOMPARE(vector.pop_back(), icase[i]);
}

void TestVector::cleanupTestCase()
{
    vector.clear();
    QCOMPARE(vector.empty(), true);
}

QTEST_APPLESS_MAIN(TestVector)

#include "tst_testvector.moc"
