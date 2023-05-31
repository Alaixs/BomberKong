#include <QtTest>
#include <../../../../SAE-final/bomber-kong/bomberkong/coordinate.cpp>
#include <../../../../SAE-final/bomber-kong/bomberkong/coordinate.h>

// add necessary includes here

class testCoordinate : public QObject
{
    Q_OBJECT

public:
    testCoordinate();
    ~testCoordinate();

private slots:
    // Tests setters
    void test_setX();
    void test_setY();

    // Tests getters
    void test_getX();
    void test_getY();
};

testCoordinate::testCoordinate()
{

}

testCoordinate::~testCoordinate()
{

}

// Tests setters
void testCoordinate::test_setX()
{
    Coordinate* aCoordinateTest = new Coordinate(0,0);

    aCoordinateTest->setX(10);
    QCOMPARE(aCoordinateTest->getX(),10);

    delete aCoordinateTest;
}

void testCoordinate::test_setY()
{
    Coordinate* aCoordinateTest = new Coordinate(0,0);

    aCoordinateTest->setY(10);
    QCOMPARE(aCoordinateTest->getY(),10);

    delete aCoordinateTest;
}

// Tests getters
void testCoordinate::test_getX()
{
    Coordinate* aCoordinateTest = new Coordinate(0,1);

    QCOMPARE(aCoordinateTest->getX(),0);

    delete aCoordinateTest;
}
void testCoordinate::test_getY()
{
    Coordinate* aCoordinateTest = new Coordinate(0,1);

    QCOMPARE(aCoordinateTest->getY(),1);

    delete aCoordinateTest;
}

QTEST_APPLESS_MAIN(testCoordinate)

#include "tst_testcoordinate.moc"
