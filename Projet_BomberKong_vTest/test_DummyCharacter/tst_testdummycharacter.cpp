#include <QtTest>
/*
#include "../../../../SAE-final/bomber-kong/bomberkong/dummycharacter.h"
#include "../../../../SAE-final/bomber-kong/bomberkong/dummycharacter.cpp"
*/
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
