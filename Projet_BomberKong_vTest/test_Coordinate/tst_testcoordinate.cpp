#include <QtTest>
#include <QCoreApplication>
#include <QMap>
#include <QThread>
#include <QTimer>
#include <QSoundEffect>
#include <QWidget>
#include <QPainter>
#include "../../../../SAE-final/bomber-kong/build-bomberkong-Desktop-Debug/ui_widget.h"
#include "../../../../SAE-final/bomber-kong/bomberkong/entity.h"
#include "../../../../SAE-final/bomber-kong/bomberkong/entity.cpp"
#include "../../../../SAE-final/bomber-kong/bomberkong/widget.h"
#include "../../../../SAE-final/bomber-kong/bomberkong/widget.cpp"
#include "../../../../SAE-final/bomber-kong/bomberkong/animationmanager.h"
#include "../../../../SAE-final/bomber-kong/bomberkong/animationmanager.cpp"
#include "../../../../SAE-final/bomber-kong/bomberkong/barrel.h"
#include "../../../../SAE-final/bomber-kong/bomberkong/barrel.cpp"
#include "../../../../SAE-final/bomber-kong/bomberkong/wall.h"
#include "../../../../SAE-final/bomber-kong/bomberkong/wall.cpp"
#include "../../../../SAE-final/bomber-kong/bomberkong/indestructiblewall.h"
#include "../../../../SAE-final/bomber-kong/bomberkong/indestructiblewall.cpp"
#include "../../../../SAE-final/bomber-kong/bomberkong/bomb.h"
#include "../../../../SAE-final/bomber-kong/bomberkong/bomb.cpp"
#include "../../../../SAE-final/bomber-kong/bomberkong/bombergirl.h"
#include "../../../../SAE-final/bomber-kong/bomberkong/bombergirl.cpp"
#include "../../../../SAE-final/bomber-kong/bomberkong/coordinate.h"
#include "../../../../SAE-final/bomber-kong/bomberkong/coordinate.cpp"
//#include "../../../../SAE-final/bomber-kong/bomberkong/dummycharacter.h"
//#include "../../../../SAE-final/bomber-kong/bomberkong/dummycharacter.cpp"
#include "../../../../SAE-final/bomber-kong/bomberkong/donkeykong.h"
#include "../../../../SAE-final/bomber-kong/bomberkong/donkeykong.cpp"
#include "../../../../SAE-final/bomber-kong/bomberkong/explosion.h"
#include "../../../../SAE-final/bomber-kong/bomberkong/explosion.cpp"
#include "../../../../SAE-final/bomber-kong/bomberkong/guielement.h"
#include "../../../../SAE-final/bomber-kong/bomberkong/guielement.cpp"
#include "../../../../SAE-final/bomber-kong/bomberkong/input.h"
#include "../../../../SAE-final/bomber-kong/bomberkong/input.cpp"
#include "../../../../SAE-final/bomber-kong/bomberkong/playercharacter.h"
#include "../../../../SAE-final/bomber-kong/bomberkong/playercharacter.cpp"
#include "../../../../SAE-final/bomber-kong/bomberkong/soundmanager.h"
#include "../../../../SAE-final/bomber-kong/bomberkong/soundmanager.cpp"
#include "../../../../SAE-final/bomber-kong/bomberkong/wall.h"
#include "../../../../SAE-final/bomber-kong/bomberkong/wall.cpp"

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

    // tests operator ==
    void test_operatorEqualEqual();
};

testCoordinate::testCoordinate()
{

}

testCoordinate::~testCoordinate()
{

}

//=====================================================
//      Tests des surcharges + & +=
//=====================================================

//test operator+
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

//test operator +=
void testCoordinate::test_operatorAddEqual()
{
    // création des variables utiles
    Coordinate* aCoordinate1 = new Coordinate();
    Coordinate* aCoordinate2 = new Coordinate(1,1);
    Coordinate* aCoordinate3 = new Coordinate(1,3);
    Coordinate* aCoordinate4 = new Coordinate(-1,-1);

    *aCoordinate1 = *aCoordinate2 += *aCoordinate3 += *aCoordinate1;
    *aCoordinate1 += *aCoordinate4;

    // test aCoordinate1
    QCOMPARE(aCoordinate1->x,1);
    QCOMPARE(aCoordinate1->y,3);

    // test aCoordinate2
    QCOMPARE(aCoordinate2->x,2);
    QCOMPARE(aCoordinate2->y,4);

    // test aCoordinate3
    QCOMPARE(aCoordinate3->x,1);
    QCOMPARE(aCoordinate3->y,3);

    // suppression des variables
    delete aCoordinate1;
    delete aCoordinate2;
    delete aCoordinate3;
    delete aCoordinate4;
}


//=====================================================
//      Tests des surcharges - & -=
//=====================================================

// test operator -
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
    delete aCoordinate4;
    delete aFinalCoordinate;
}

//test operator -=
void testCoordinate::test_operatorMinusEqual()
{
    // création des variables utiles
    Coordinate* aCoordinate1 = new Coordinate();
    Coordinate* aCoordinate2 = new Coordinate(1,1);
    Coordinate* aCoordinate3 = new Coordinate(1,3);
    Coordinate* aCoordinate4 = new Coordinate(-1,-1);

    *aCoordinate1 = *aCoordinate2 -= *aCoordinate3 -= *aCoordinate1;
    *aCoordinate1 -= *aCoordinate4;

    // test aCoordinate1
    QCOMPARE(aCoordinate1->x,1);
    QCOMPARE(aCoordinate1->y,-1);

    // test aCoordinate2
    QCOMPARE(aCoordinate2->x,0);
    QCOMPARE(aCoordinate2->y,-2);

    // test aCoordinate3
    QCOMPARE(aCoordinate3->x,1);
    QCOMPARE(aCoordinate3->y,3);

    // suppression des variables
    delete aCoordinate1;
    delete aCoordinate2;
    delete aCoordinate3;
    delete aCoordinate4;
}


//=====================================================
//      Tests des surcharges * & *=
//=====================================================
// test operator *
void testCoordinate::test_operatorMulti()
{
    // création des variables utiles
    Coordinate* aCoordinate1 = new Coordinate(1,2);
    Coordinate* aFinalCoordinate = new Coordinate();

    // test multiplication par 0
    *aFinalCoordinate = *aCoordinate1 * 0;
    QCOMPARE(aFinalCoordinate->x,0);
    QCOMPARE(aFinalCoordinate->y,0);

    // test multiplication par un nombre > 0
    *aFinalCoordinate = *aCoordinate1 * 10;
    QCOMPARE(aFinalCoordinate->x,10);
    QCOMPARE(aFinalCoordinate->y,20);

    // test multiplication par un nombre < 0
    *aFinalCoordinate = *aCoordinate1 * -10;
    QCOMPARE(aFinalCoordinate->x,-10);
    QCOMPARE(aFinalCoordinate->y,-20);

    // suppression des variables
    delete aCoordinate1;
    delete aFinalCoordinate;
}

//test operator *=
void testCoordinate::test_operatorMultiEqual()
{
    // création des variables utiles
    Coordinate* aCoordinate1 = new Coordinate(1,2);
    Coordinate* aFinalCoordinate = new Coordinate();

    // test multiplication par un nombre > 0
    *aFinalCoordinate = *aCoordinate1 *= 10;
    QCOMPARE(aFinalCoordinate->x,10);
    QCOMPARE(aFinalCoordinate->y,20);
    QCOMPARE(aCoordinate1->x,10);
    QCOMPARE(aCoordinate1->y,20);

    // test multiplication par un nombre < 0
    *aFinalCoordinate = *aCoordinate1 *= -10;
    QCOMPARE(aFinalCoordinate->x,-100);
    QCOMPARE(aFinalCoordinate->y,-200);
    QCOMPARE(aCoordinate1->x,-100);
    QCOMPARE(aCoordinate1->y,-200);

    // test multiplication par 0
    *aFinalCoordinate = *aCoordinate1 *= 0;
    QCOMPARE(aFinalCoordinate->x,0);
    QCOMPARE(aFinalCoordinate->y,0);
    QCOMPARE(aCoordinate1->x,0);
    QCOMPARE(aCoordinate1->y,0);

    // suppression des variables
    delete aCoordinate1;
    delete aFinalCoordinate;
}


//=====================================================
//      Tests des surcharges / & /=
//=====================================================

// test operator /
void testCoordinate::test_operatorDiv()
{

    // création des variables utiles
    Coordinate* aCoordinate1 = new Coordinate(10,20);
    Coordinate* aFinalCoordinate = new Coordinate();

    // test multiplication par 0
    *aFinalCoordinate = *aCoordinate1 / 0;
    QCOMPARE(aFinalCoordinate->x,0);
    QCOMPARE(aFinalCoordinate->y,0);

    // test multiplication par un nombre > 0
    *aFinalCoordinate = *aCoordinate1 / 10;
    QCOMPARE(aFinalCoordinate->x,1);
    QCOMPARE(aFinalCoordinate->y,2);

    // test multiplication par un nombre < 0
    *aFinalCoordinate = *aCoordinate1 / -10;
    QCOMPARE(aFinalCoordinate->x,-1);
    QCOMPARE(aFinalCoordinate->y,-2);

    // suppression des variables
    delete aCoordinate1;
    delete aFinalCoordinate;
}

//test operator /
void testCoordinate::test_operatorDivEqual()
{
    // création des variables utiles
    Coordinate* aCoordinate1 = new Coordinate(8,4);
    Coordinate* aFinalCoordinate = new Coordinate();

    // test multiplication par un nombre > 0
    *aFinalCoordinate = *aCoordinate1 /= 2;
    QCOMPARE(aFinalCoordinate->x,4);
    QCOMPARE(aFinalCoordinate->y,2);
    QCOMPARE(aCoordinate1->x,4);
    QCOMPARE(aCoordinate1->y,2);

    // test multiplication par un nombre < 0
    *aFinalCoordinate = *aCoordinate1 /= -2;
    QCOMPARE(aFinalCoordinate->x,-2);
    QCOMPARE(aFinalCoordinate->y,-1);
    QCOMPARE(aCoordinate1->x,-2);
    QCOMPARE(aCoordinate1->y,-1);

    // test multiplication par 0
    *aFinalCoordinate = *aCoordinate1 /= 0;
    QCOMPARE(aFinalCoordinate->x,-2);
    QCOMPARE(aFinalCoordinate->y,-1);
    QCOMPARE(aCoordinate1->x,-2);
    QCOMPARE(aCoordinate1->y,-1);

    // suppression des variables
    delete aCoordinate1;
    delete aFinalCoordinate;
}


//=====================================================
//      Tests de surcharge ==
//=====================================================

//test operator ==
void testCoordinate::test_operatorEqualEqual()
{
    // création des variables utiles
    Coordinate* aCoordinate1 = new Coordinate(1,1);
    Coordinate* aCoordinate2 = new Coordinate(1,1);
    Coordinate* aCoordinate3 = new Coordinate();

    // tests valides
    QVERIFY(*aCoordinate1 == *aCoordinate2);
    QVERIFY(*aCoordinate3 == Coordinate());

    // test invalide
    QVERIFY(!(*aCoordinate1 == *aCoordinate3));

    // suppression des variables
    delete aCoordinate1;
    delete aCoordinate2;
    delete aCoordinate3;
}

QTEST_APPLESS_MAIN(testCoordinate)

#include "tst_testcoordinate.moc"
