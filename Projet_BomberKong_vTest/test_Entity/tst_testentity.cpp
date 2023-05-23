#include <QtTest>

// add necessary includes here

class testEntity : public QObject
{
    Q_OBJECT

public:
    testEntity();
    ~testEntity();

private slots:
    void test_case1();

};

testEntity::testEntity()
{

}

testEntity::~testEntity()
{

}

void testEntity::test_case1()
{

}

QTEST_APPLESS_MAIN(testEntity)

#include "tst_testentity.moc"
