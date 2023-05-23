#include <QtTest>

// add necessary includes here

class testPlayerCharacter : public QObject
{
    Q_OBJECT

public:
    testPlayerCharacter();
    ~testPlayerCharacter();

private slots:
    void test_case1();

};

testPlayerCharacter::testPlayerCharacter()
{

}

testPlayerCharacter::~testPlayerCharacter()
{

}

void testPlayerCharacter::test_case1()
{

}

QTEST_APPLESS_MAIN(testPlayerCharacter)

#include "tst_testplayercharacter.moc"
