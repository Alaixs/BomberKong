#include <QtTest>
#include "../../../../SAE-final/bomber-kong/bomberkong/soundmanager.h"
#include "../../../../SAE-final/bomber-kong/bomberkong/soundmanager.cpp"

// add necessary includes here

class testSoundManager : public QObject
{
    Q_OBJECT

public:
    testSoundManager();
    ~testSoundManager();

private slots:
    void test_case1();

};

testSoundManager::testSoundManager()
{

}

testSoundManager::~testSoundManager()
{

}

void testSoundManager::test_case1()
{

}

QTEST_APPLESS_MAIN(testSoundManager)

#include "tst_testsoundmanager.moc"
