#include <QtTest>
#include "../../../../SAE-final/bomber-kong/bomberkong/donkeykong.h"
#include "../../../../SAE-final/bomber-kong/bomberkong/donkeykong.cpp"

// add necessary includes here

class testDonkeyKong : public QObject
{
    Q_OBJECT

public:
    testDonkeyKong();
    ~testDonkeyKong();

private slots:
    void test_case1();

};

testDonkeyKong::testDonkeyKong()
{

}

testDonkeyKong::~testDonkeyKong()
{

}

void testDonkeyKong::test_case1()
{

}

QTEST_APPLESS_MAIN(testDonkeyKong)

#include "tst_testdonkeykong.moc"
