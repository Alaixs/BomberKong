#include <QtTest>

// add necessary includes here

class testDestructibleWall : public QObject
{
    Q_OBJECT

public:
    testDestructibleWall();
    ~testDestructibleWall();

private slots:
    void test_case1();

};

testDestructibleWall::testDestructibleWall()
{

}

testDestructibleWall::~testDestructibleWall()
{

}

void testDestructibleWall::test_case1()
{

}

QTEST_APPLESS_MAIN(testDestructibleWall)

#include "tst_testdestructiblewall.moc"
