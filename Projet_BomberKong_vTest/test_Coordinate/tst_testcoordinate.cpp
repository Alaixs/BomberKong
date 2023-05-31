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
    // tests operators add
    void test_operatorAdd();
    void test_operatorAddEqual();

    // tests operators minus
    void test_operatorMinus();
    void test_operatorMinusEqual();

    // tests operators multi
    void test_operatorMulti();
    void test_operatorMultiEqual();

    // tests operators div
    void test_operatorDiv();
    void test_operatorDivEqual();

    // tests operators equal
    void test_operatorEqual2();
};

testCoordinate::testCoordinate()
{

}

testCoordinate::~testCoordinate()
{

}

// tests operators add
void testCoordinate::test_operatorAdd()
{
    // création des variables utiles
    Coordinate* aCoordinate1 = new Coordinate();
    Coordinate* aCoordinate2 = new Coordinate(1,1);
    Coordinate* aCoordinate3 = new Coordinate(1,3);
    Coordinate* aFinalCoordinate = new Coordinate();

    // test avec 2 Coordinate à variable > 0
    *aFinalCoordinate = *aCoordinate3 + *aCoordinate2;
    QCOMPARE(aFinalCoordinate->x,2);
    QCOMPARE(aFinalCoordinate->y,4);

    // test avec 1 Coordinate à variable = 0
    *aFinalCoordinate = *aCoordinate1 + *aCoordinate2;
    QCOMPARE(aFinalCoordinate->x,1);
    QCOMPARE(aFinalCoordinate->y,1);

    // suppression des variables
    delete aCoordinate1;
    delete aCoordinate2;
    delete aCoordinate3;
    delete aFinalCoordinate;
}

void testCoordinate::test_operatorAddEqual()
{
    // création des variables utiles
    Coordinate* aCoordinate1 = new Coordinate();
    Coordinate* aCoordinate2 = new Coordinate(1,1);
    Coordinate* aCoordinate3 = new Coordinate(1,3);

    *aCoordinate1 = *aCoordinate2 += *aCoordinate3 += *aCoordinate1;
    // test aCoordinate1
    QCOMPARE(aCoordinate1->x,2);
    QCOMPARE(aCoordinate1->y,4);

    // test aCoordinate1
    QCOMPARE(aCoordinate2->x,2);
    QCOMPARE(aCoordinate2->y,4);

    // test aCoordinate1
    QCOMPARE(aCoordinate3->x,1);
    QCOMPARE(aCoordinate3->y,3);

    // suppression des variables
    delete aCoordinate1;
    delete aCoordinate2;
    delete aCoordinate3;
}

// tests operators minus
void testCoordinate::test_operatorMinus()
{
    // création des variables utiles
    Coordinate* aCoordinate1 = new Coordinate();
    Coordinate* aCoordinate2 = new Coordinate(1,1);
    Coordinate* aCoordinate3 = new Coordinate(1,3);
    Coordinate* aCoordinate4 = new Coordinate(-1,-1);
    Coordinate* aFinalCoordinate = new Coordinate();

    // test renvoie nombre négatif & nul
    *aFinalCoordinate = *aCoordinate2 - *aCoordinate3;
    QCOMPARE(aFinalCoordinate->x,0);
    QCOMPARE(aFinalCoordinate->y,-2);

    // test soustraction avec 1 coordinate 0,0
    *aFinalCoordinate = *aCoordinate3 - *aCoordinate1;
    QCOMPARE(aFinalCoordinate->x,1);
    QCOMPARE(aFinalCoordinate->y,3);

    // test soustraction avec un négatif (augmentation)
    *aFinalCoordinate = *aCoordinate1 - *aCoordinate4;
    QCOMPARE(aFinalCoordinate->x,1);
    QCOMPARE(aFinalCoordinate->y,1);

    // test soustraction passant dans le négatif
    *aFinalCoordinate = *aCoordinate1 - *aCoordinate3;
    QCOMPARE(aFinalCoordinate->x,-1);
    QCOMPARE(aFinalCoordinate->y,-3);

    // suppression des variables
    delete aCoordinate1;
    delete aCoordinate2;
    delete aCoordinate3;
}

void testCoordinate::test_operatorMinusEqual()
{

}

// tests operators multi
void testCoordinate::test_operatorMulti()
{

}

void testCoordinate::test_operatorMultiEqual()
{

}

// tests operators div
void testCoordinate::test_operatorDiv()
{

}

void testCoordinate::test_operatorDivEqual()
{

}

//tests operators equal
void testCoordinate::test_operatorEqual2()
{

}

QTEST_APPLESS_MAIN(testCoordinate)

#include "tst_testcoordinate.moc"
