#include <QtTest>

// add necessary includes here

class testExplosion : public QObject
{
    Q_OBJECT

public:
    testExplosion();
    ~testExplosion();

private slots:
    void test_case1();

};

testExplosion::testExplosion()
{

}

testExplosion::~testExplosion()
{

}

void testExplosion::test_case1()
{

}

QTEST_APPLESS_MAIN(testExplosion)

#include "tst_testexplosion.moc"
