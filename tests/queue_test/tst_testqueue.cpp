#include <QtTest>
#include <QCoreApplication>

#include "../../src/queue.hpp"


class TestQueue : public QObject
{
    Q_OBJECT
    Queue<float> queue;
public:
    TestQueue();
    ~TestQueue();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void testCasePushItem();
    void testCasePopItem();
};

TestQueue::TestQueue() {}

TestQueue::~TestQueue() {}

void TestQueue::initTestCase() {}

void TestQueue::cleanupTestCase() {}

void TestQueue::testCasePushItem()
{
    queue.push(9);
    queue.push(5.55454);
    queue.push(9.1574);
    queue.push(25.74);
    queue.push(0.1574);
}

void TestQueue::testCasePopItem()
{
    queue.pop();
    queue.pop();
    queue.pop();
}

QTEST_APPLESS_MAIN(TestQueue)

#include "tst_testqueue.moc"
