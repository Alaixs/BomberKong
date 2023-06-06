#include <QtTest>
#include <QCoreApplication>
#include

// add necessary includes here

class testBarrel : public QObject
{
    Q_OBJECT

public:
    testBarrel();
    ~testBarrel();

private slots:
    void test_case1();

};

testBarrel::testBarrel()
{

}

testBarrel::~testBarrel()
{

}

void testBarrel::test_case1()
{

}

QTEST_MAIN(testBarrel)

#include "tst_testbarrel.moc"
