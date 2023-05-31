#include <QtTest>
#include <../../../../SAE-final/bomber-kong/bomberkong/coordinate.cpp>
#include <../../../../SAE-final/bomber-kong/bomberkong/coordinate.h>
#include <../../../../SAE-final/bomber-kong/bomberkong/entity.cpp>
#include <../../../../SAE-final/bomber-kong/bomberkong/entity.h>
// add necessary includes here

class testEntity : public QObject
{
    Q_OBJECT

public:
    testEntity();
    ~testEntity();

private slots:
    // Test getter
    void test_getPos();

};

testEntity::testEntity()
{

}

testEntity::~testEntity()
{

}

void testEntity::test_getPos()
{

}

QTEST_APPLESS_MAIN(testEntity)

#include "tst_testentity.moc"
