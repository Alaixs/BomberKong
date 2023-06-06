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

class testDummyCharacter : public QObject
{
    Q_OBJECT

public:
    testDummyCharacter();
    ~testDummyCharacter();

private slots:
    void test_case1();

};

testDummyCharacter::testDummyCharacter()
{

}

testDummyCharacter::~testDummyCharacter()
{

}

void testDummyCharacter::test_case1()
{

}

QTEST_APPLESS_MAIN(testDummyCharacter)

#include "tst_testdummycharacter.moc"
