#include <QtTest>
#include "../../../../SAE-final/bomber-kong/bomberkong/input.h"
#include "../../../../SAE-final/bomber-kong/bomberkong/input.cpp"

// add necessary includes here

class testInput : public QObject
{
    Q_OBJECT

public:
    testInput();
    ~testInput();

private slots:
    void test_case1();

};

testInput::testInput()
{

}

testInput::~testInput()
{

}

void testInput::test_case1()
{

}

QTEST_APPLESS_MAIN(testInput)

#include "tst_testinput.moc"
