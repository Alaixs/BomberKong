#include <QtTest>
#include "../../../../SAE-final/bomber-kong/bomberkong/widget.h"
#include "../../../../SAE-final/bomber-kong/bomberkong/widget.cpp"

// add necessary includes here

class testWidget : public QObject
{
    Q_OBJECT

public:
    testWidget();
    ~testWidget();

private slots:
    void test_case1();

};

testWidget::testWidget()
{

}

testWidget::~testWidget()
{

}

void testWidget::test_case1()
{

}

QTEST_APPLESS_MAIN(testWidget)

#include "tst_testwidget.moc"
