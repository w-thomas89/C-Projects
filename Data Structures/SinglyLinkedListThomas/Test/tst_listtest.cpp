#include <QtTest>
#include "listemptyexception.h"
#include "listfullexception.h"
#include "linkedlist.h"
#include "can.h"

// add necessary includes here
using namespace std;

class listTest : public QObject
{
    Q_OBJECT

public:
    listTest();
    ~listTest();

private slots:
    void testIsEmptyTrue();
    void testIsEmptyFalse();
    void testInsert();
    void testRemove();
    void testSize();
    void testPrintList();
    void testRemoveFromEmpty();

};

listTest::listTest(){}

listTest::~listTest(){}

void listTest::testIsEmptyTrue() {
    LinkedList test = LinkedList();
    QVERIFY(test.isEmpty());
}

void listTest::testIsEmptyFalse() {
    LinkedList test = LinkedList();
    Can can = Can();
    test.insert(can);
    bool expected = false;
    bool actual = test.isEmpty();
    QCOMPARE(actual, expected);
}

void listTest::testInsert() {
    LinkedList test = LinkedList();
    Can can = Can();
    test.insert(can);
    string expected = can.toString();
    string actual = test.printList();
    QVERIFY(expected.compare(actual));
}

void listTest::testRemove() {
    LinkedList test = LinkedList();
    Can can = Can();
    Can argCan = Can("RED", "BEAN", 5, 10);
    string expected = can.toString();
    test.insert(can);
    test.insert(argCan);
    test.remove(0);
    string actual = test.printList();
    QVERIFY(expected.compare(actual));
}

void listTest::testSize() {
    LinkedList test = LinkedList();
    Can can = Can();
    test.insert(can);
    int expected = 1;
    int actual = test.size();
    QCOMPARE(actual, expected);
}

void listTest::testPrintList() {
    LinkedList test = LinkedList();
    Can can1 = Can("A", "A", 1, 1);
    Can can2 = Can("B", "B", 2, 2);
    test.insert(can1);
    test.insert(can2);
    string expected = can1.toString() + can2.toString();
    string actual = test.printList();
    QVERIFY(expected.compare(actual));
}

void listTest::testRemoveFromEmpty() {
    LinkedList test = LinkedList();
    QVERIFY_EXCEPTION_THROWN(test.remove(0), listEmptyException);
}

QTEST_APPLESS_MAIN(listTest)

#include "tst_listtest.moc"
