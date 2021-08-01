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

}

void TestQueue::testCasePopItem()
{

}

QTEST_APPLESS_MAIN(TestQueue)

#include "tst_testqueue.moc"
