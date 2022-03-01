//William Thomas, wdthomas2@dmacc.edu, 11/30/2021
//The below program will use multithreading to calculate the sum of a 1000x1000 array

//This program will use each thread to calculate 1/4 of the array (250 rows each in order)

#include <iostream>
#include <array>
#include <QThread>
#include <QString>
#include <QDebug>
#include <QMutex>
using namespace std;

const int SIZE = 10000;

class SumThread: public QThread {
private:
    array<array<long, SIZE>, SIZE> &table;
    size_t startRow;
    size_t skipRows;
    static QMutex mutex;
    static long total;
public:

    //altered to only accept array and start position as passed args
    SumThread(array<array<long, SIZE>, SIZE> &table, size_t startRow):
        table(table), startRow(startRow) {
        total = 0;
    }

    //the below function will calculate a section of the array designated by the start position and
    //limited by SIZE divided by 4 for number of threads used (this could also be changed to a constant)
//    void run() {
//        for (size_t row = startRow; row < (startRow + (SIZE/4)); row++) {
//            long rowTotal = 0;
//            for (size_t column = 0; column < table[0].size(); column++) {
//                rowTotal += table[row][column];
//            }
//            //mutex lock created to prevent threads from miscalculating the total
//            mutex.lock();
//            total += rowTotal;
//            mutex.unlock();
//        }
//    }
        //ORIGINAL BELOW

    SumThread(array<array<long, SIZE>, SIZE> &table, size_t startRow, size_t skipRows):
        table(table), startRow(startRow), skipRows(skipRows) {
        total = 0;
    }

    void run() {
        for (size_t row=startRow; row<table.size(); row+=skipRows) {
            long rowTotal = 0;
            for (size_t column=0; column<table[0].size(); column++) {
                rowTotal += table[row][column];
            }
            mutex.lock();
            total += rowTotal;
            mutex.unlock();
        }
    }

    static long getTotal() {
        return total;
    }
};
QMutex SumThread::mutex;

long SumThread::total;
array<array<long, SIZE>, SIZE> bigTable;

int main() {
    for (size_t i=0; i<bigTable.size(); i++) {
        for (size_t j=0; j<bigTable[0].size(); j++) {
            bigTable[i][j] = static_cast<long>(i + j);
        }
    }

    for (int i=0; i<100; i++) {
        SumThread thread1(bigTable, 0, 12);
        SumThread thread2(bigTable, 1, 12);
        SumThread thread3(bigTable, 2, 12);
        SumThread thread4(bigTable, 3, 12);
        SumThread thread5(bigTable, 4, 12);
        SumThread thread6(bigTable, 5, 12);
        SumThread thread7(bigTable, 6, 12);
        SumThread thread8(bigTable, 7, 12);
        SumThread thread9(bigTable, 8, 12);
        SumThread thread10(bigTable, 9, 12);
        SumThread thread11(bigTable, 10, 12);
        SumThread thread12(bigTable, 11, 12);

        thread1.start();
        thread2.start();
        thread3.start();
        thread4.start();
        thread5.start();
        thread6.start();
        thread7.start();
        thread8.start();
        thread9.start();
        thread10.start();
        thread11.start();
        thread12.start();

        thread1.wait();
        thread2.wait();
        thread3.wait();
        thread4.wait();
        thread5.wait();
        thread6.wait();
        thread7.wait();
        thread8.wait();
        thread9.wait();
        thread10.wait();
        thread11.wait();
        thread12.wait();

        cout << SumThread::getTotal() << " " << endl;
    }
    return 0;
}


//Tested and received same result as ORIGINAL version
