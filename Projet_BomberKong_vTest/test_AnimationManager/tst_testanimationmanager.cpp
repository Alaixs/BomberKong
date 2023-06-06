#include <QtTest>
#include "../../../../SAE-final/bomber-kong/bomberkong/animationmanager.h"
#include "../../../../SAE-final/bomber-kong/bomberkong/animationmanager.cpp"

// add necessary includes here

class testAnimationManager : public QObject
{
    Q_OBJECT

public:
    testAnimationManager();
    ~testAnimationManager();

private slots:
    void test_case1();

};

testAnimationManager::testAnimationManager()
{

}

testAnimationManager::~testAnimationManager()
{

}

void testAnimationManager::test_case1()
{

}

QTEST_APPLESS_MAIN(testAnimationManager)

#include "tst_testanimationmanager.moc"
