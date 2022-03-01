#include <QtTest>
#include "linkedlist.h"
#include "listfullexception.h"
#include "listemptyexception.h"
// add necessary includes here

class listTests : public QObject
{
    Q_OBJECT

public:
    listTests();
    ~listTests();

private slots:
    void testCreateList();
    void testIsEmptyTrue();
    void testIsEmptyFalse();
    void testIsFullTrue();
    void testIsFullFalse();
    void testInsert();
    void testRemove();
    void testReplace();
    void testSize();
    void testPrintList();

};

listTests::listTests() {}
listTests::~listTests() {}

void listTests::testCreateList() {
    LinkedList test = LinkedList(1);
    bool actual;
    actual = test.isEmpty();
    QVERIFY(actual);
}

void listTests::testIsEmptyTrue() {
    LinkedList test = LinkedList(1);
    bool actual = test.isEmpty();
    QVERIFY(actual);
}

void listTests::testIsEmptyFalse() {
    LinkedList test = LinkedList(1);
    double item = 100;
    test.insert(item, 0);
    bool actual = test.isEmpty();
    bool expected = false;
    QCOMPARE(actual, expected);
}

void listTests::testIsFullTrue() {
    LinkedList test = LinkedList(1);
    double item = 100;
    test.insert(item, 0);
    bool actual = test.isFull();
    bool expected = true;
    QCOMPARE(actual, expected);

}

void listTests::testIsFullFalse() {
    LinkedList test = LinkedList(2);
    double item = 100;
    test.insert(item, 0);
    bool actual = test.isFull();
    bool expected = false;
    QCOMPARE(actual, expected);
}

void listTests::testInsert() {
    LinkedList test = LinkedList(1);
    double expected = 123.456;
    test.insert(expected, 0);
    double actual = test.get(0);
    QCOMPARE(actual, expected);
}

void listTests::testRemove() {
    LinkedList test = LinkedList(2);
    double item = 100;
    double expected = 0;
    test.insert(item, 0);
    test.remove(item);
    double actual = test.get(0);
    QCOMPARE(actual, expected);

}

void listTests::testReplace() {
    LinkedList test = LinkedList(2);
    double item = 100;
    test.insert(item + 1, 0);
    test.insert(item, 0);
    test.replace(item, item+5);
    double actual = test.get(0);
    double expected = 105;
    QCOMPARE(actual, expected);
}

void listTests::testSize() {
    int expected = 2;
    LinkedList test = LinkedList(expected);
    test.insert(1, 0);
    test.insert(2, 0);
    int actual = test.size();
    QCOMPARE(actual, expected);
}

void listTests::testPrintList() {
    LinkedList test = LinkedList(4);
    test.insert(10, 0);
    test.insert(20, 0);
    test.insert(30, 0);
    test.insert(40, 0);
    string expected = "40\n30\n20\n10\n";
    string actual = test.printList();
    QVERIFY(expected.compare(actual));
}


QTEST_APPLESS_MAIN(listTests)

#include "tst_listtests.moc"
