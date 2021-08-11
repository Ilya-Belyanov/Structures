#include <QtTest>
#include <QCoreApplication>

#include "../../src/stack.hpp"


class TestStack : public QObject
{
    Q_OBJECT
    Stack<float> d_stack;
    QVector<float> d_case;

    Stack<int> i_stack;
    QVector<int> i_case;

    Stack<char> c_stack;
    QVector<char> c_case;

public:
    TestStack();
    ~TestStack();

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

TestStack::TestStack()
{

}

TestStack::~TestStack() {}

void TestStack::initTestCase()
{
    d_case = {9.0, 10.0, 13.0, 14.4, 15.6};
    i_case = {9, 10, 13, 14, 15};
    c_case = {'A', 'B', 'C', 'D', 'F'};
}

void TestStack::testCaseConstructors()
{
    Stack<float> d2_stack(9.0, 10.0, 13.0, 14.4, 15.6);
    foreach(float d, d_case)
        QCOMPARE(d2_stack.pop(), d);
}

void TestStack::testCasePushItem()
{
    foreach(float d, d_case)
        d_stack.push(d);

    foreach(int i, i_case)
        i_stack.push(i);

    foreach(char c, c_case)
        c_stack.push(c);
}

void TestStack::testCaseFrontBackItem()
{
    QCOMPARE(d_stack.front(), d_case.last());
    QCOMPARE(d_stack.back(), d_case.first());

    QCOMPARE(i_stack.front(), i_case.last());
    QCOMPARE(i_stack.back(), i_case.first());

    QCOMPARE(c_stack.front(), c_case.last());
    QCOMPARE(c_stack.back(), c_case.first());
}

void TestStack::testCaseFlip()
{
    Stack<float> d2_stack = d_stack;
    d2_stack.flip();
    foreach(float d, d_case)
        QCOMPARE(d2_stack.pop(), d);
}

void TestStack::testCasePopItem()
{
    for(int i = d_case.size() - 1; i >= 0; i--)
        QCOMPARE(d_stack.pop(), d_case[i]);

    for(int i = i_case.size() - 1; i >= 0; i--)
        QCOMPARE(i_stack.pop(), i_case[i]);

    for(int i = c_case.size() - 1; i >= 0; i--)
        QCOMPARE(c_stack.pop(), c_case[i]);
}

void TestStack::testCaseOperatorPlusEqual()
{
    d_stack.push(9.0);
    d_stack.push(1.0);
    d_stack = d_stack + d_stack;
    QCOMPARE(d_stack.pop(), 1.0);
    QCOMPARE(d_stack.pop(), 9.0);
    QCOMPARE(d_stack.pop(), 1.0);
    QCOMPARE(d_stack.pop(), 9.0);

    d_stack.push(9.0);
    d_stack.push(1.0);
    d_stack += d_stack;
    QCOMPARE(d_stack.pop(), 1.0);
    QCOMPARE(d_stack.pop(), 9.0);
    QCOMPARE(d_stack.pop(), 1.0);
    QCOMPARE(d_stack.pop(), 9.0);
}


void TestStack::cleanupTestCase()
{
    d_stack.clear();
    i_stack.clear();
    c_stack.clear();
    QCOMPARE(d_stack.empty(), true);
    QCOMPARE(i_stack.empty(), true);
    QCOMPARE(c_stack.empty(), true);
}

QTEST_APPLESS_MAIN(TestStack)

#include "tst_teststack.moc"
