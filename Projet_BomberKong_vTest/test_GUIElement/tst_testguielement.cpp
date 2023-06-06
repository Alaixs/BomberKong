#include <QtTest>
#include "../../../../SAE-final/bomber-kong/bomberkong/guielement.h"
#include "../../../../SAE-final/bomber-kong/bomberkong/guielement.cpp"

// add necessary includes here

class testGUIElement : public QObject
{
    Q_OBJECT

public:
    testGUIElement();
    ~testGUIElement();

private slots:
    void test_case1();

};

testGUIElement::testGUIElement()
{

}

testGUIElement::~testGUIElement()
{

}

void testGUIElement::test_case1()
{

}

QTEST_APPLESS_MAIN(testGUIElement)

#include "tst_testguielement.moc"
