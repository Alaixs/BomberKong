#include <QtTest>
#include "../../../../SAE-final/bomber-kong/bomberkong/bombergirl.h"
#include "../../../../SAE-final/bomber-kong/bomberkong/bombergirl.cpp"

// add necessary includes here

class testBomberGirl : public QObject
{
    Q_OBJECT

public:
    testBomberGirl();
    ~testBomberGirl();

private slots:
    void test_case1();

};

testBomberGirl::testBomberGirl()
{

}

testBomberGirl::~testBomberGirl()
{

}

void testBomberGirl::test_case1()
{

}

QTEST_APPLESS_MAIN(testBomberGirl)

#include "tst_testbombergirl.moc"
