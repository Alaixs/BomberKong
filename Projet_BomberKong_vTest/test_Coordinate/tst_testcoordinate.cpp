#include <QtTest>

// add necessary includes here

class testCoordinate : public QObject
{
    Q_OBJECT

public:
    testCoordinate();
    ~testCoordinate();

private slots:
    void test_case1();

};

testCoordinate::testCoordinate()
{

}

testCoordinate::~testCoordinate()
{

}

void testCoordinate::test_case1()
{

}

QTEST_APPLESS_MAIN(testCoordinate)

#include "tst_testcoordinate.moc"
