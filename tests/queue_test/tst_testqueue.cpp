#include <QtTest>
#include <QCoreApplication>

#include "../../src/queue.hpp"


class TestQueue : public QObject
{
    Q_OBJECT
    Queue<float> d_queue;
    QVector<float> d_case;

    Queue<int> i_queue;
    QVector<int> i_case;

    Queue<char> c_queue;
    QVector<char> c_case;

public:
    TestQueue();
    ~TestQueue();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void testCaseConstructors();
    void testCasePushItem();
    void testCaseFrontBackItem();
    void testCaseFlip();
    void testCasePopItem();
    void testCaseOperatorPlusEqual();
};

TestQueue::TestQueue()
{

}

TestQueue::~TestQueue() {}

void TestQueue::initTestCase()
{
    d_case = {9.0, 10.0, 13.0, 14.4, 15.6};
    i_case = {9, 10, 13, 14, 15};
    c_case = {'A', 'B', 'C', 'D', 'F'};
}

void TestQueue::testCaseConstructors()
{
    Queue<float> d2_queue(9.0, 10.0, 13.0, 14.4, 15.6);
    foreach(float d, d_case)
        QCOMPARE(d2_queue.pop(), d);
}

void TestQueue::testCasePushItem()
{
    foreach(float d, d_case)
        d_queue.push(d);

    foreach(int i, i_case)
        i_queue.push(i);

    foreach(char c, c_case)
        c_queue.push(c);
}

void TestQueue::testCaseFrontBackItem()
{
    QCOMPARE(d_queue.front(), d_case.first());
    QCOMPARE(d_queue.back(), d_case.last());

    QCOMPARE(i_queue.front(), i_case.first());
    QCOMPARE(i_queue.back(), i_case.last());

    QCOMPARE(c_queue.front(), c_case.first());
    QCOMPARE(c_queue.back(), c_case.last());
}

void TestQueue::testCaseFlip()
{
    Queue<float> d2_queue = d_queue;
    d2_queue.flip();
    for(int i = d_case.size() - 1; i > 0; i--)
        QCOMPARE(d2_queue.pop(), d_case[i]);
}

void TestQueue::testCasePopItem()
{
    foreach(float d, d_case)
        QCOMPARE(d_queue.pop(), d);

    foreach(int i, i_case)
        QCOMPARE(i_queue.pop(), i);

    foreach(char c, c_case)
        QCOMPARE(c_queue.pop(), c);
}

void TestQueue::testCaseOperatorPlusEqual()
{
    d_queue.push(9.0);
    d_queue.push(1.0);
    d_queue = d_queue + d_queue;
    QCOMPARE(d_queue.pop(), 9.0);
    QCOMPARE(d_queue.pop(), 1.0);
    QCOMPARE(d_queue.pop(), 9.0);
    QCOMPARE(d_queue.pop(), 1.0);

    d_queue.push(9.0);
    d_queue.push(1.0);
    d_queue += d_queue;
    QCOMPARE(d_queue.pop(), 9.0);
    QCOMPARE(d_queue.pop(), 1.0);
    QCOMPARE(d_queue.pop(), 9.0);
    QCOMPARE(d_queue.pop(), 1.0);
}


void TestQueue::cleanupTestCase()
{
    d_queue.clear();
    i_queue.clear();
    c_queue.clear();
    QCOMPARE(d_queue.empty(), true);
    QCOMPARE(i_queue.empty(), true);
    QCOMPARE(c_queue.empty(), true);
}

QTEST_APPLESS_MAIN(TestQueue)

#include "tst_testqueue.moc"
