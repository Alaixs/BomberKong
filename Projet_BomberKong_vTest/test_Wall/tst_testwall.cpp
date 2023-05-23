#include <QtTest>

// add necessary includes here

class testWall : public QObject
{
    Q_OBJECT

public:
    testWall();
    ~testWall();

private slots:
    void test_case1();

};

testWall::testWall()
{

}

testWall::~testWall()
{

}

void testWall::test_case1()
{

}

QTEST_APPLESS_MAIN(testWall)

#include "tst_testwall.moc"
