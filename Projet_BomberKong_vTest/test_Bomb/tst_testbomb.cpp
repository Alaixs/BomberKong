#include <QtTest>

// add necessary includes here

class testBomb : public QObject
{
    Q_OBJECT

public:
    testBomb();
    ~testBomb();

private slots:
    void test_case1();

};

testBomb::testBomb()
{

}

testBomb::~testBomb()
{

}

void testBomb::test_case1()
{

}

QTEST_APPLESS_MAIN(testBomb)

#include "tst_testbomb.moc"
